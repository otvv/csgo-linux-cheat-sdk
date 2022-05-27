//
// csgo sdk
//

#pragma once

#include <array>

#include "render.hpp"
#include "interfaces.hpp"

#include "../menu/menu.hpp"
#include "../helpers/vmt.hpp"

namespace prototypes
{
  struct paint_traverse
  {
    using fn = void(std::int32_t *, unsigned long long, bool, bool);
    static fn hooked;
    static fn *original;
  };

  struct create_move
  {
    using fn = bool(std::int32_t*, float, CUserCmd*);
    static fn hooked;
    static fn *original;
  };

  struct override_mouse_input
  {
    using fn = void(std::int32_t *, float *, float *);
    static fn hooked;
    static fn *original;
  };

  struct draw_model_execute
  {
    using fn = void(std::int32_t *, IMatRenderContext *, void *, const ModelRenderInfo_t &, matrix_t<float, 3, 4> *);
    static fn hooked;
    static fn *original;
  };

  struct in_keyevent
  {
    using fn = int(std::int32_t *, int, ButtonCode_t, const char *);
    static fn hooked;
    static fn *original;
  };

  struct frame_stage_notify
  {
    using fn = void(std::int32_t *, ClientFrameStage_t);
    static fn hooked;
    static fn *original;
  };

  struct reset_font_caches
  {
    using fn = void(std::int32_t *);
    static fn hooked;
    static fn *original;
  };

  struct lock_cursor
  {
    using fn = void(std::int32_t *);
    static fn hooked;
    static fn *original;
  };

  struct send_net_msg
  {
    using fn = bool(std::int32_t *, INetMessage &, bool, bool);
    static fn hooked;
    static fn *original;
  };

  struct run_command
  {
    using fn = void(std::int32_t*, IClientEntity*, CUserCmd*, IMoveHelper*);
    static fn hooked;
    static fn *original;
  };

} // namespace prototypes

enum hook_tables_t
{
  VGUI_PANEL = 0,
  CLIENT_MODE = 1,
  MODEL_RENDER = 2,
  BASE_CLIENT = 3,
  VGUI_SURFACE = 4,
  NETCHANNEL_INFO = 5,
  PREDICTION = 6,
  MAX_TABLES
};
std::array<vmt, hook_tables_t::MAX_TABLES> g_tables;

// originals
decltype(&prototypes::paint_traverse::hooked) prototypes::paint_traverse::original;
decltype(&prototypes::create_move::hooked) prototypes::create_move::original;
decltype(&prototypes::override_mouse_input::hooked) prototypes::override_mouse_input::original;
decltype(&prototypes::draw_model_execute::hooked) prototypes::draw_model_execute::original;
decltype(&prototypes::in_keyevent::hooked) prototypes::in_keyevent::original;
decltype(&prototypes::frame_stage_notify::hooked) prototypes::frame_stage_notify::original;
decltype(&prototypes::lock_cursor::hooked) prototypes::lock_cursor::original;
decltype(&prototypes::reset_font_caches::hooked) prototypes::reset_font_caches::original;
decltype(&prototypes::send_net_msg::hooked) prototypes::send_net_msg::original;
decltype(&prototypes::run_command::hooked) prototypes::run_command::original;

inline void prototypes::paint_traverse::hooked(std::int32_t *thisptr, unsigned long long _panel, bool _force_repaint, bool _allow_force)
{
  // call original function
  original(thisptr, _panel, _force_repaint, _allow_force);

  static unsigned int panel_id = 0;

  if (!panel_id)
  {
    // get panel name
    const std::string &panel_name = csgo::vgui_panel->GetName(_panel);

    if (panel_name.compare("MatSystemTopPanel") == 0)
    {
      panel_id = _panel;
    }
  }

  if (panel_id == _panel)
  {
    // watermark
    render::text(5, 5, fonts::watermark, {255, 255, 255}, "csgo-sdk");

    // menu
    Widgets::Container->Render();
  }
}

inline bool prototypes::create_move::hooked(std::int32_t *thisptr, float _sample_time, CUserCmd* _cmd)
{
  original(thisptr, _sample_time, _cmd);

  if (!_cmd || !_cmd->command_number)
  { 
    return false;
  }

  // get net channel info pointer
  INetChannelInfo *channel_info = csgo::engine_client->GetNetChannelInfo();

  // sendnetmsg hook
  static void *old_pointer = nullptr;
  
  if (old_pointer != channel_info)
  {
    old_pointer = channel_info;

    if (g_tables.at(hook_tables_t::NETCHANNEL_INFO).initialize_and_hook(channel_info))
    {
      g_tables.at(hook_tables_t::NETCHANNEL_INFO).apply_hook<prototypes::send_net_msg>(40);
    }
  }

  return true;
}

inline void prototypes::override_mouse_input::hooked(std::int32_t *thisptr, float *_x, float *_y)
{
  // call original function
  original(thisptr, _x, _y);
}

inline void prototypes::draw_model_execute::hooked(std::int32_t *thisptr, IMatRenderContext *_render_context, void *_state, const ModelRenderInfo_t &_info, matrix_t<float, 3, 4> *_custom_bone_to_world)
{
  // check if something is trying to override the materials
  if (csgo::model_render->IsForcedMaterialOverride())
  {
    original(thisptr, _render_context, _state, _info, _custom_bone_to_world);
  }

  // call original function
  original(thisptr, _render_context, _state, _info, _custom_bone_to_world);

  // restore materials after we are done
  csgo::model_render->ForceOverrideMaterial(nullptr);
}

inline int prototypes::in_keyevent::hooked(std::int32_t *thisptr, int _event_code, ButtonCode_t _button_code, const char *_current_binding)
{
  // block input when menu is opened
  if (Widgets::Container->GetState())
  {
    return ButtonCode_t::KEY_INVALID;
  }

  // call original function
  return original(thisptr, _event_code, _button_code, _current_binding);
}

inline void prototypes::frame_stage_notify::hooked(std::int32_t *thisptr, ClientFrameStage_t _stage)
{
  // perform replacements during FRAME_RENDER_START
  if (_stage == ClientFrameStage_t::FRAME_RENDER_START)
  {
  }

  // perform replacements during FRAME_NET_UPDATE_POSTDATAUPDATE_START
  if (_stage == ClientFrameStage_t::FRAME_NET_UPDATE_POSTDATAUPDATE_START)
  {
  }

  // call original function
  original(thisptr, _stage);
}

inline void prototypes::lock_cursor::hooked(std::int32_t *thisptr)
{
  if (Widgets::Container->GetState())
  {
    csgo::vgui_surface->UnlockCursor();
    return;
  }

  // call original function
  original(thisptr);
}

inline void prototypes::reset_font_caches::hooked(std::int32_t *thisptr)
{
  // call original function
  original(thisptr);

  // re-create fonts here
}

inline bool prototypes::send_net_msg::hooked(std::int32_t *thisptr, INetMessage &_msg, bool _foce_reliable = false, bool _voice = false)
{
  // return false if the user tries to send a crc file check to the server (sv_pure bypass)
  //if (_msg.GetType() == CLC_Messages::clc_FileCRCCheck)
  //{
  //  return false;
  //}

  // fix voice transmission lag when using fake-lag
  //if (_msg.GetGroup() == INetChannelInfo::VOICE)
  //{
  //  _voice = true;
  //}

  // call original function
  return original(thisptr, _msg, _foce_reliable, _voice);
}

inline void prototypes::run_command::hooked(std::int32_t *thisptr, IClientEntity* _entity, CUserCmd* _cmd, IMoveHelper* _move)
{
  if (!csgo::move_helper)
  {
    csgo::move_helper = _move;
  }

  original(thisptr, _entity, _cmd, _move);
}

struct hooks_t
{
  hooks_t()
  {
    // hook functions
    if (g_tables.at(hook_tables_t::VGUI_PANEL).initialize_and_hook(csgo::vgui_panel))
    {
      g_tables.at(hook_tables_t::VGUI_PANEL).apply_hook<prototypes::paint_traverse>(42);
    }

    if (g_tables.at(hook_tables_t::CLIENT_MODE).initialize_and_hook(csgo::client_mode))
    {
      g_tables.at(hook_tables_t::CLIENT_MODE).apply_hook<prototypes::override_mouse_input>(24);
      g_tables.at(hook_tables_t::CLIENT_MODE).apply_hook<prototypes::create_move>(25);
    }

    if (g_tables.at(hook_tables_t::MODEL_RENDER).initialize_and_hook(csgo::model_render))
    {
      g_tables.at(hook_tables_t::MODEL_RENDER).apply_hook<prototypes::draw_model_execute>(21);
    }

    if (g_tables.at(hook_tables_t::BASE_CLIENT).initialize_and_hook(csgo::base_client))
    {
      g_tables.at(hook_tables_t::BASE_CLIENT).apply_hook<prototypes::in_keyevent>(21);
      g_tables.at(hook_tables_t::BASE_CLIENT).apply_hook<prototypes::frame_stage_notify>(37);
    }

    if (g_tables.at(hook_tables_t::VGUI_SURFACE).initialize_and_hook(csgo::vgui_surface))
    {
      g_tables.at(hook_tables_t::VGUI_SURFACE).apply_hook<prototypes::lock_cursor>(67);
      g_tables.at(hook_tables_t::VGUI_SURFACE).apply_hook<prototypes::reset_font_caches>(141);
    }

    if (g_tables.at(hook_tables_t::PREDICTION).initialize_and_hook(csgo::prediction))
    {
      g_tables.at(hook_tables_t::PREDICTION).apply_hook<prototypes::run_command>(19);
    }
  }
};
extern hooks_t hooks;
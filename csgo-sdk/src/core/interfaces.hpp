//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

// interfaces
#include "../interfaces/cbaseclientstate.hpp"
#include "../interfaces/cclientclass.hpp"
#include "../interfaces/cglobalvars.hpp"
#include "../interfaces/cinput.hpp"
#include "../interfaces/cmodelinfo.hpp"
#include "../interfaces/crecvproxydata.hpp"
#include "../interfaces/crenderview.hpp"
#include "../interfaces/cusercmd.hpp"
#include "../interfaces/ibaseclient.hpp"
#include "../interfaces/icliententitylist.hpp"
#include "../interfaces/iclientmode.hpp"
#include "../interfaces/iclientnetworkable.hpp"
#include "../interfaces/iclientrenderable.hpp"
#include "../interfaces/icvar.hpp"
#include "../interfaces/ivengineclient.hpp"
#include "../interfaces/inetchannelinfo.hpp"
#include "../interfaces/ienginetrace.hpp"
#include "../interfaces/iinputinternal.hpp"
#include "../interfaces/iinputsystem.hpp"
#include "../interfaces/imaterial.hpp"
#include "../interfaces/imaterialsystem.hpp"
#include "../interfaces/imatrendercontext.hpp"
#include "../interfaces/ipanel.hpp"
#include "../interfaces/isurface.hpp"
#include "../interfaces/ivdebugoverlay.hpp"
#include "../interfaces/iviewrender.hpp"
#include "../interfaces/ivmodelrender.hpp"
#include "../interfaces/viewshared.hpp"
#include "../interfaces/panoramauiengine.hpp"
#include "../interfaces/iprediction.hpp"
#include "../interfaces/imodelcache.hpp"
#include "../interfaces/cbasehudchat.hpp"

namespace csgo
{
  inline ISurface *vgui_surface;
  inline IPanel *vgui_panel;
  inline IVEngineClient *engine_client;
  inline IInputSystem *input_system;
  inline IInputInternal *input_internal;
  inline IVDebugOverlay *debug_overlay;
  inline IBaseClientDLL *base_client;
  inline IClientEntityList *entity_list;
  inline IClientMode *client_mode;
  inline CBaseClientState *client_state;
  inline ICVar *cvar;
  inline IMaterialSystem *material_system;
  inline CGlobalVars *global_vars;
  inline CInput *input;
  inline IVModelRender *model_render;
  inline CModelInfo *model_info;
  inline CRenderView *render_view;
  inline IGameMovement* game_movement;
  inline IPrediction *prediction;
  inline IViewRender *view_render;
  inline IEngineTrace *engine_trace;
  inline IPanoramaUIEngine *panorama_engine;
  inline IModelCache* model_cache;
  inline IMoveHelper* move_helper;
  inline CBaseHudChat* base_hud_chat;

} // namespace csgo

struct interfaces_t
{
  interfaces_t()
  {
    // initialize exposed interfaces
    csgo::vgui_surface = memory::get_interface<ISurface>("vguimatsurface_client.so->VGUI_Surface0");
    csgo::vgui_panel = memory::get_interface<IPanel>("vgui2_client.so->VGUI_Panel0");
    csgo::engine_client = memory::get_interface<IVEngineClient>("engine_client.so->VEngineClient0");
    csgo::input_system = memory::get_interface<IInputSystem>("inputsystem_client.so->InputSystemVersion0");
    csgo::input_internal = memory::get_interface<IInputInternal>("vgui2_client.so->VGUI_InputInternal0");
    csgo::debug_overlay = memory::get_interface<IVDebugOverlay>("engine_client.so->VDebugOverlay0");
    csgo::base_client = memory::get_interface<IBaseClientDLL>("client_client.so->VClient0");
    csgo::entity_list = memory::get_interface<IClientEntityList>("client_client.so->VClientEntityList0");
    csgo::cvar = memory::get_interface<ICVar>("materialsystem_client.so->VEngineCvar0");
    csgo::material_system = memory::get_interface<IMaterialSystem>("materialsystem_client.so->VMaterialSystem0");
    csgo::model_render = memory::get_interface<IVModelRender>("engine_client.so->VEngineModel0");
    csgo::model_info = memory::get_interface<CModelInfo>("engine_client.so->VModelInfoClient0");
    csgo::render_view = memory::get_interface<CRenderView>("engine_client.so->VEngineRenderView0");
    csgo::game_movement = memory::get_interface<IGameMovement>("client_client.so->GameMovement0");
    csgo::engine_trace = memory::get_interface<IEngineTrace>("engine_client.so->EngineTraceClient0");
    csgo::panorama_engine = memory::get_interface<IPanoramaUIEngine>("panorama_client.so->PanoramaUIEngine0");
    csgo::prediction = memory::get_interface<IPrediction>("client_client.so->VClientPrediction0");
    csgo::model_cache = memory::get_interface<IModelCache>("datacache_client.so->MDLCache0");

    // function addresses
    std::uintptr_t HudProcessInput = reinterpret_cast<std::uintptr_t>(memory::get_vtable(csgo::base_client)[10]);
    std::uintptr_t HudUpdate = reinterpret_cast<std::uintptr_t>(memory::get_vtable(csgo::base_client)[11]);
    std::uintptr_t IN_ActivateMouse = reinterpret_cast<std::uintptr_t>(memory::get_vtable(csgo::base_client)[16]);

    // initialize non exposed classes, interfaces & pointersq
    csgo::client_mode = reinterpret_cast<IClientMode *(*)(void)>(memory::get_absolute_address(HudProcessInput + 0xB, 0x1, 0x5))();
    csgo::global_vars = **reinterpret_cast<CGlobalVars ***>(memory::get_absolute_address(HudUpdate + 0xD, 0x3, 0x7));
    csgo::input = **reinterpret_cast<CInput ***>(memory::get_absolute_address(IN_ActivateMouse, 0x3, 0x7));

    // init chat hud element
    std::uintptr_t LevelInit = reinterpret_cast<std::uintptr_t>(memory::get_vtable(csgo::client_mode)[100]);
    csgo::base_hud_chat = reinterpret_cast<CBaseHudChat*>(memory::get_absolute_address(LevelInit + 0x7, 0x3, 0x7));
  }
};
extern interfaces_t interfaces;
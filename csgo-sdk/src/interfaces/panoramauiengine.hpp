//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class IUIPanel;

using CPanoramaSymbol = unsigned short;

struct panel_wrapper_t
{
  char pad0[0x4];
  IUIPanel *panel;
};

class IUIPanel
{
public:
  const char *GetID()
  {
    return memory::vfunc<10, const char *>(this);
  }

  bool LoadLayoutFromString(const char *xml_layout, bool unk1, bool unk2)
  {
    return memory::vfunc<19, bool>(this, xml_layout, unk1, unk2);
  }

  void SetParent(IUIPanel *parent)
  {
    return memory::vfunc<25, void>(this, parent);
  }

  IUIPanel *GetParent()
  {
    return memory::vfunc<26, IUIPanel *>(this);
  }

  void SetVisible(bool state)
  {
    return memory::vfunc<28, void>(this, state);
  }

  IUIPanel *FindChild(const char *child_panel)
  {
    return memory::vfunc<39, IUIPanel *>(this, child_panel);
  }

  bool HasBeenLayedOut()
  {
    return memory::vfunc<316, bool>(this);
  }
};

class IUIEngine
{
public:
  bool IsValidPanelPointer(const IUIPanel *panel)
  {
    return memory::vfunc<37, bool>(this, panel);
  }

  IUIPanel *GetLastDispatchedEventTargetPanel()
  {
    return memory::vfunc<57, IUIPanel *>(this);
  }

  int RunScript(IUIPanel *panel, const char *entire_js_code, const char *path_to_xml_context, int unk1, int unk2, bool already_compiled)
  {
    return memory::vfunc<114, int>(this, panel, entire_js_code, path_to_xml_context, unk1, unk2, already_compiled);
  }

  panel_wrapper_t *CreatePanel(CPanoramaSymbol *panel_type, const char *panel_id, IUIPanel *create_in_this_parent)
  {
    return memory::vfunc<149, panel_wrapper_t *>(this, panel_type, panel_id, create_in_this_parent);
  }

  CPanoramaSymbol MakeSymbol(const char *symbol)
  {
    return memory::vfunc<155, CPanoramaSymbol>(this, symbol);
  }
};

class IPanoramaUIEngine
{
public:
  IUIEngine *AccessUIEngine()
  {
    return memory::vfunc<11, IUIEngine *>(this);
  }
};
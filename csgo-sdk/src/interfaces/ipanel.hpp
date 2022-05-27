//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class IPanel
{
public:
  const char *GetName(unsigned long long vgui_panel)
  {
    return memory::vfunc<37, const char *>(this, vgui_panel);
  }
};
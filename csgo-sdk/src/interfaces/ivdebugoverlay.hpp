//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class IVDebugOverlay
{
public:
  bool ScreenPosition(const vec3_t &in, vec3_t &out)
  {
    return memory::vfunc<11, bool>(this, &in, &out);
  }
};
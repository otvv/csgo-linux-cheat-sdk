//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class CRenderView
{
public:
  void SetBlend(float alpha)
  {
    return memory::vfunc<4, void>(this, alpha);
  }

  void SetColorModulation(const float *color)
  {
    return memory::vfunc<6, void>(this, color);
  }
};
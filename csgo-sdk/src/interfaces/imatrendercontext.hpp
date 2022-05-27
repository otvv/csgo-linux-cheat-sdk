//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class IMaterial;

using ShaderStencilOp_t = int;
using ShaderStencilFunc_t = int;

struct ShaderStencilState_t
{
  bool enable;
  ShaderStencilOp_t fail;
  ShaderStencilOp_t zfail;
  ShaderStencilOp_t pass;
  ShaderStencilFunc_t compare;
  int ref;
  unsigned int mask1;
  unsigned int mask2;
};

class ITexture
{
public:
  int GetActualWidth()
  {
    return memory::vfunc<3, int>(this);
  }

  int GetActualHeight()
  {
    return memory::vfunc<4, int>(this);
  }
};

class IMatRenderContext
{
public:
  int Release() { return memory::vfunc<1, int>(this); }

  void SetRenderTarget(ITexture *p_texture)
  {
    return memory::vfunc<6, void>(this, p_texture);
  }

  void DrawScreenSpaceRectangle(
      IMaterial *p_material, int dest_x, int dest_y, int width, int height,
      float src_texture_x1, float src_texture_y1, float src_texture_x2,
      float src_texture_y2, int src_texture_width, int src_texture_height,
      void *p_client_renderable = nullptr, int x_dice = 1, int y_dice = 1)
  {
    return memory::vfunc<113, void>(
        this, p_material, dest_x, dest_y, width, height, src_texture_x1,
        src_texture_y1, src_texture_x2, src_texture_y2, src_texture_width,
        src_texture_height, p_client_renderable, x_dice, y_dice);
  }

  void PushRenderTargetAndViewport()
  {
    return memory::vfunc<115, void>(this);
  }

  void PopRenderTargetAndViewport()
  {
    return memory::vfunc<119, void>(this);
  }

  void SetStencilState(const ShaderStencilState_t &state)
  {
    return memory::vfunc<127, void>(this, &state);
  }
};
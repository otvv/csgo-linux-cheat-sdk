//
// csgo sdk
//

#pragma once

enum DrawFlags_t
{
  DF_RENDER_REFRACTION = 0x1,
  DF_RENDER_REFLECTION = 0x2,
  DF_CLIP_Z = 0x4,
  DF_CLIP_BELOW = 0x8,
  DF_RENDER_UNDERWATER = 0x10,
  DF_RENDER_ABOVEWATER = 0x20,
  DF_RENDER_WATER = 0x40,
  DF_SSAO_DEPTH_PASS = 0x100,
  DF_WATERHEIGHT = 0x200,
  DF_DRAW_SSAO = 0x400,
  DF_DRAWSKYBOX = 0x800,
  DF_FUDGE_UP = 0x1000,
  DF_DRAW_ENTITITES = 0x2000,
  DF_UNUSED3 = 0x4000,
  DF_UNUSED4 = 0x8000,
  DF_UNUSED5 = 0x10000,
  DF_SAVEGAMESCREENSHOT = 0x20000,
  DF_CLIP_SKYBOX = 0x40000,
  DF_SHADOW_DEPTH_MAP = 0x100000
};

class IViewRender
{
public:
};
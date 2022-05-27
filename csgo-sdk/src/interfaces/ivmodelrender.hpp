//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class IMaterial;
class IClientRenderable;

using ModelInstanceHandle_t = unsigned short;

struct ModelRenderInfo_t
{
  vec3_t origin;
  vec3_t angles;
  char pad0[0x4];
  IClientRenderable *renderable;
  const model_t *model;
  const matrix_t<float, 3, 4> *model_to_world;
  const matrix_t<float, 3, 4> *lighting_offset;
  const vec3_t *lighting_origin;
  int flags;
  int entity_index;
  int skin;
  int body;
  int hitbox_set;
  ModelInstanceHandle_t instance;
};

class IVModelRender
{
public:
  void ForceOverrideMaterial(IMaterial *material, int null1 = 0, int null2 = 0)
  {
    return memory::vfunc<1, void>(this, material, null1, null2);
  }

  bool IsForcedMaterialOverride()
  {
    return memory::vfunc<2, bool>(this);
  }
};
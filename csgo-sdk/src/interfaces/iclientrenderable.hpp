//
// csgo sdk
//

#pragma once

#include "../helpers/matrix.hpp"
#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

struct model_t;

class IClientRenderable
{
public:
  virtual ~IClientRenderable(){};

  model_t *GetModel()
  {
    return memory::vfunc<8, model_t *>(this);
  }

  int DrawModel(int flags, unsigned char alpha)
  {
    return memory::vfunc<9, int>(this, flags, alpha);
  }

  bool SetupBones(matrix_t<float, 3, 4> *bone_matrix, int max_bones, int bone_mask, float curtime = 0)
  {
    return memory::vfunc<13, bool>(this, bone_matrix, max_bones, bone_mask, curtime);
  }

  void GetRenderBounds(vec3_t &mins, vec3_t &maxs)
  {
    return memory::vfunc<17, void>(this, &mins, &maxs);
  }
};
//
// csgo sdk
//

#pragma once

#include <assert.h>

#include "../helpers/matrix.hpp"
#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

struct model_t;
class IMaterial;

struct mstudiobone_t
{
  int name_index;

  inline const char *Name() const
  {
    return (char *)(this) + name_index;
  }

  int parent;
  int bone_controller[6];
  vec3_t position;
  float q_quaternion[4];
  float rotation[3];
  vec3_t position_scale;
  vec3_t rotation_scale;
  matrix_t<float, 3, 4> pose_to_bone;
  float alignment[4];
  int flags;
  int proc_type;
  int proc_index;

  mutable int physics_bone;

  inline void *Procedure() const
  {
    if (proc_index == 0)
    {
      return nullptr;
    }
    else
    {
      return (void *)((unsigned char *)(this) + proc_index);
    }
  };

  int surface_prop_index;

  inline const char *SurfacePropName() const
  {
    return (char *)(this) + surface_prop_index;
  }

  inline int GetSurfaceProp(void) const
  {
    return surface_prop_lookup;
  }

  int contents;
  int surface_prop_lookup;
  int pad0[0x7];
};

struct mstudiobbox_t
{
  int bone;
  int group;
  vec3_t bbmin;
  vec3_t bbmax;
  int hitbox_index;
  int pad0[0x3];
  float m_flRadius;
  int pad1[0x4];

  const char *GetName()
  {
    if (!hitbox_index)
    {
      return nullptr;
    }

    return (const char *)((unsigned char *)this + hitbox_index);
  }
};

struct mstudiohitboxset_t
{
  int name_index;

  inline const char *Name() const
  {
    return ((char *)this) + name_index;
  }

  int number_of_hitboxes;
  int hitbox_index;

  inline mstudiobbox_t *HitBox(std::size_t index) const
  {
    return reinterpret_cast<mstudiobbox_t *>(((unsigned char *)this) + hitbox_index) + index;
  };
};

struct studiohdr_t
{
  int id;
  int version;
  int checksum;
  char name[64];
  int length;
  vec3_t eye_position;
  vec3_t illumination_position;
  vec3_t hull_min;
  vec3_t hull_max;
  vec3_t view_bbmin;
  vec3_t view_bbmax;
  int flags;
  int number_of_bones;
  int bone_index;

  inline mstudiobone_t *Bone(std::size_t index) const
  {
    assert(static_cast<int>(index) >= 0 && static_cast<int>(index) < number_of_bones);

    return reinterpret_cast<mstudiobone_t *>(((unsigned char *)this) + bone_index) + index;
  };

  int RemapBoneSequence(int sequence, int local_bone) const;
  int RemapBoneAnimation(int animation, int local_bone) const;

  int number_of_bone_controllers;
  int bone_controller_index;
  int number_of_hitbox_sets;
  int hitbox_set_index;

  mstudiohitboxset_t *HitBoxSet(std::size_t index) const
  {
    return reinterpret_cast<mstudiohitboxset_t *>(((unsigned char *)this) + hitbox_set_index) + index;
  };

  inline mstudiobbox_t *HitBox(std::size_t index, int set) const
  {

    const mstudiohitboxset_t *studio_hitbox_set = HitBoxSet(set);

    if (!studio_hitbox_set)
    {
      return nullptr;
    }

    return studio_hitbox_set->HitBox(index);
  };

  inline int HitBoxCount(int set) const
  {
    const mstudiohitboxset_t *studio_hitbox_set = HitBoxSet(set);

    if (!studio_hitbox_set)
    {
      return 0;
    }

    return studio_hitbox_set->number_of_hitboxes;
  };
};

class CModelInfo
{
public:
  void *GetModel(int index)
  {
    return memory::vfunc<2, void *>(this, index);
  }

  int GetModelIndex(const char *file_name)
  {
    return memory::vfunc<3, int>(this, file_name);
  }

  const char *GetModelName(const void *model_name)
  {
    return memory::vfunc<4, const char *>(this, model_name);
  }

  void GetModelMaterials(const model_t *model, int count, IMaterial **pp_material)
  {
    return memory::vfunc<18, void>(this, model, count, pp_material);
  }

  studiohdr_t *GetStudioModel(const model_t *model)
  {
    return memory::vfunc<31, studiohdr_t *>(this, model);
  }
};
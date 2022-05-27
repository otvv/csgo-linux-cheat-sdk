//
// csgo sdk
//

#pragma once

#include "entities.hpp"
#include "math.hpp"
#include "matrix.hpp"
#include "vector.hpp"

#include "../core/interfaces.hpp"

struct box_dimension_t
{
  int m_left;
  int m_right;
  int m_width;
  int m_height;
};

namespace utilities
{

  inline vec2_t angle_to_pixels(vec2_t _angle)
  {
    // m_yaw convar
    static ConVar *m_yaw = csgo::cvar->FindVar("m_yaw");
    static ConVar *m_pitch = csgo::cvar->FindVar("m_pitch");

    float x = _angle.m_x / m_pitch->GetFloat();
    float y = _angle.m_y / m_yaw->GetFloat();

    return {-y, x};
  }

  inline vec2_t pixels_to_angle(vec2_t _pixel)
  {
    static ConVar *m_yaw = csgo::cvar->FindVar("m_yaw");
    static ConVar *m_pitch = csgo::cvar->FindVar("m_pitch");

    float x = _pixel.m_x * m_pitch->GetFloat();
    float y = _pixel.m_y * m_yaw->GetFloat();

    return vec2_t(-y, x).clamp();
  }

  inline vec3_t get_hitbox_position(IClientEntity *_entity, unsigned int _hitbox_id)
  {
    matrix_t<float, 3, 4> bone_matrix[128];

    if (_entity->SetupBones(bone_matrix, 128, 0x100, 0.0f))
    {
      studiohdr_t *studio_model = csgo::model_info->GetStudioModel(_entity->GetModel());

      if (studio_model)
      {
        // search for the hitbox that we are looking for
        mstudiobbox_t *hitbox = studio_model->HitBoxSet(0)->HitBox(_hitbox_id);

        // if we have a valid hitbox
        if (hitbox)
        {
          vec3_t min = {0.f, 0.f, 0.f};
          vec3_t max = {0.f, 0.f, 0.f};

          math::vector_transform(hitbox->bbmin, bone_matrix[hitbox->bone], min);
          math::vector_transform(hitbox->bbmax, bone_matrix[hitbox->bone], max);

          return (min + max) / 2.f;
        }
      }
    }

    return {0.f, 0.f, 0.f};
  }

} // namespace utilities
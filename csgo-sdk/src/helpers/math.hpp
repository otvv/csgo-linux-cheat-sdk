//
// csgo sdk
//

#pragma once

#include <algorithm>
#include <cmath>

#include "matrix.hpp"
#include "vector.hpp"

namespace math
{
  inline void vector_angles(vec3_t &_forward, angl_t &_angles)
  {
    if (_forward[1] == 0.f && _forward[0] == 0.f)
    {
      _angles[0] = (_forward[2] > 0.f) ? 270.f : 90.f;
      _angles[1] = 0.f;
    }
    else
    {
      _angles[0] = std::atan2(-_forward[2], _forward.length_2d()) * (-180.f / static_cast<float>(M_PI));
      _angles[1] = std::atan2(_forward[1], _forward[0]) * (180.f / static_cast<float>(M_PI));

      if (_angles[1] > 90.f)
      {
        _angles[1] -= 180.f;
      }

      else if (_angles[1] < 90.f)
      {
        _angles[1] += 180.f;
      }

      else if (_angles[1] == 90.f)
      {
        _angles[1] = 0.f;
      }
    }

    _angles[2] = 0.f;
  }

  inline vec3_t calculate_angle(const vec3_t &_src, const vec3_t &_dst)
  {
    angl_t angles = {0.f, 0.f, 0.f};
    vec3_t delta = (_src - _dst);

    math::vector_angles(delta, angles);

    delta.normalize();

    return angles;
  }

  inline vec3_t vector_transform(vec3_t &_in, matrix_t<float, 3, 4> &_matrix, vec3_t &_out)
  {
    for (std::size_t i = 0; i < 3; i++)
    {
      _out[i] = _in.dot_product(&_matrix[i].at(0)) + _matrix[i][3];
    }

    return _out;
  }

} // namespace math
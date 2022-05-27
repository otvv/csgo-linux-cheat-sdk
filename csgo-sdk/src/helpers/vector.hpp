//
// csgo sdk
//

#pragma once

#include <algorithm>
#include <cmath>

template <typename t>
class vector
{
public:
  t m_x, m_y, m_z;

  vector() = default;
  vector(t _x, t _y) : m_x(_x), m_y(_y), m_z(0.f) {}
  vector(t _x, t _y, t _z) : m_x(_x), m_y(_y), m_z(_z) {}
  vector(const vector &_v) : m_x(_v.m_x), m_y(_v.m_y), m_z(_v.m_z) {}

  // helpers
  inline float length_3d() const
  {
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
  }

  inline float length_2d() const
  {
    return std::sqrt(m_x * m_x + m_y * m_y);
  }

  inline vector clamp()
  {
    m_x = std::clamp(m_x, -89.f, 89.f);
    m_y = std::clamp(std::remainder(m_y, 360.f), -180.f, 180.f);
    m_z = std::clamp(m_z, -50.f, 50.f);

    return *this;
  }

  inline vector normalize()
  {
    if (length_3d() != 0.f)
    {
      *this /= length_3d();
    }
    else
    {
      m_x = 0.f;
      m_y = 0.f;
      m_z = 0.f;
    }

    return *this;
  }

  inline t dot_product(const vector &_rhs)
  {
    return (m_x * _rhs.m_x + m_y * _rhs.m_y + m_z * _rhs.m_z);
  }

  inline t dot_product(const float *_rhs)
  {
    vector temp = *this;

    return (temp.m_x * _rhs[0] + temp.m_y * _rhs[1] + temp.m_z * _rhs[2]);
  }

  //
  // operators
  //
  vector &operator+=(const vector &_rhs) const
  {
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;
    m_z += _rhs.m_z;

    return *this;
  }

  vector &operator=(const vector &_rhs)
  {
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;
    m_z = _rhs.m_z;

    return *this;
  }

  vector &operator-=(const vector &_rhs)
  {
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;
    m_z -= _rhs.m_z;
    return *this;
  }

  vector &operator*=(t _rhs)
  {
    m_x *= _rhs;
    m_y *= _rhs;
    m_z *= _rhs;
    return *this;
  }

  vector &operator/=(t _rhs)
  {
    m_x /= _rhs;
    m_y /= _rhs;
    m_z /= _rhs;
    return *this;
  }

  vector operator+(const vector &_rhs) const
  {
    return vector(m_x + _rhs.m_x, m_y + _rhs.m_y, m_z + _rhs.m_z);
  }

  vector operator-(const vector &_rhs) const
  {
    return vector(m_x - _rhs.m_x, m_y - _rhs.m_y, m_z - _rhs.m_z);
  }

  vector operator*(const t &_rhs) const
  {
    return vector(m_x * _rhs, m_y * _rhs, m_z * _rhs);
  }

  vector operator/(const t &_rhs) const
  {
    return vector(m_x / _rhs, m_y / _rhs, m_z / _rhs);
  }

  t &operator[](std::size_t _index)
  {
    return *(reinterpret_cast<t *>(this) + _index);
  }
};

template <typename t>
class vector_aligned : public vector<float>
{
public:
  vector_aligned() = default;
  vector_aligned(t _x, t _y, t _z)
  {
    m_x = _x;
    m_y = _y;
    m_z = _z;
  }
  vector_aligned(const vector &_v)
  {
    m_x = _v.m_x;
    m_y = _v.m_y;
    m_z = _v.m_z;
  }
};

using vec3_t = vector<float>;
using vec2_t = vector<float>;
using angl_t = vector<float>;
using vec3_aligned_t = vector_aligned<float>;
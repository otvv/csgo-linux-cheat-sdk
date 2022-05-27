//
// csgo sdk
//

#pragma once

#include <cstring>

struct wrapper_t
{
  wrapper_t(const char *_string) : m_string(_string) {}

  const char *m_string;
};

class fnv_hash
{
public:
  fnv_hash(wrapper_t _wrapper) : m_hash_value(hash(_wrapper.m_string)) {}

  operator unsigned int() const
  {
    return m_hash_value;
  }

protected:

  static unsigned int hash(const char *_string)
  {
    // string length
    const unsigned long length = std::strlen(_string) + 1;

    // hash basis formula
    unsigned int hash = m_basis;

    for (std::size_t i = 0; i < length; ++i)
    {
      hash ^= *_string++;
      hash *= m_prime;
    }

    return hash;
  }

private:
  static const unsigned int m_prime = 16777619u;
  static const unsigned int m_basis = 2166136261u;
  unsigned int m_hash_value;
};
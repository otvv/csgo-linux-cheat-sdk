//
// csgo sdk
//

#pragma once

#include <cassert>
#include <cstdint>
#include <cstring>

class vmt
{
public:
  constexpr vmt() : m_new_vmt(nullptr), m_old_vmt(nullptr) {}

  inline void initialize(void **_original_table)
  {
    m_old_vmt = _original_table;

    static std::size_t size = 0;

    while (m_old_vmt[size])
    {
      ++size;
    }

    m_new_vmt = (new void *[size + 1]) + 1;
    std::memcpy(m_new_vmt - 1, m_old_vmt - 1, sizeof(void *) * (size + 1));
  }

  inline void hook_instance(void *_instance)
  {
    // vtable address
    void **&vtable = *reinterpret_cast<void ***>(_instance);

    assert(vtable == m_old_vmt || vtable == m_new_vmt);

    // swap vtables
    vtable = m_new_vmt;
  }

  inline bool initialize_and_hook(void *_instance)
  {
    // vtable address
    void **&vtable = *reinterpret_cast<void ***>(_instance);

    bool initialized = [&]() {
      initialize(vtable);

      return true;
    }();

    // hook instance
    hook_instance(_instance);

    return initialized;
  }

  //
  //

  template <typename fn>
  inline fn hook_function(fn _hooked_function, const std::size_t &_index)
  {
    m_new_vmt[_index] = reinterpret_cast<void *>(_hooked_function);
    return reinterpret_cast<fn>(m_old_vmt[_index]);
  }

  template <typename fn>
  inline void apply_hook(std::size_t _index)
  {
    fn::original = hook_function(&fn::hooked, _index);
  }

private:
  void **m_new_vmt;
  void **m_old_vmt;
};
//
// csgo sdk
//

#pragma once

template <class t, class m = int>
class utl_memory
{
public:
  t &operator[](m _index) { return m_memory[_index]; }

protected:
  t *m_memory;
  int m_allocation_count;
  int m_grow_size;
};

template <class t, class a = utl_memory<t>>
class utl_vector
{
  using allocator = a;

public:
  t &operator[](int _index) { return m_memory[_index]; }

  int count() const { return m_size; }

  void set_size(int _value) { m_size = _value; }

protected:
  allocator m_memory;
  int m_size;
  t *m_elements;
};
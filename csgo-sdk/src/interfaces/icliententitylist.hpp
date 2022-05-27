//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class IClientEntityList
{
public:
  void *GetClientEntity(int index)
  {
    return memory::vfunc<3, void *>(this, index);
  }

  void *GetClientEntityFromHandle(void *handle)
  {
    return memory::vfunc<4, void *>(this, handle);
  }

  int GetHighestEntityIndex()
  {
    return memory::vfunc<6, int>(this);
  }

  int GetMaxEntities()
  {
    return memory::vfunc<8, int>(this);
  }
};
//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class CClientClass;

class IClientNetworkable
{
public:
  virtual ~IClientNetworkable(){};

  void Release()
  {
    return memory::vfunc<1, void>(this);
  }

  CClientClass *GetClientClass()
  {
    return memory::vfunc<2, CClientClass *>(this);
  }

  bool IsDormant()
  {
    return memory::vfunc<9, bool>(this);
  }

  int GetIndex()
  {
    return memory::vfunc<10, int>(this);
  }

  void SetDestroyedOnRecreateEntities()
  {
    return memory::vfunc<13, void>(this);
  }
};
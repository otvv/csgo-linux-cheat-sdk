//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/utlvector.hpp"

class ConVar;
class ICVar;

using change_callback_t = void (*)(ConVar *cvar, const char *sz_old_value, float old_value);

class ConCommandBase
{
  friend class ConVar;
  friend class ICVar;
public:

  void AddFlags(int flags)
  {
    return memory::vfunc<3, void>(this, flags);
  }

  void RemoveFlags(int flags)
  {
    return memory::vfunc<4, void>(this, flags);
  }

  int GetFlags()
  {
    return memory::vfunc<5, int>(this);
  }

  const char* GetName()
  {
    return memory::vfunc<6, const char*>(this);
  }

  const char* GetHelpText()
  {
    return memory::vfunc<7, const char*>(this);
  }

  bool IsRegistered()
  {
    return memory::vfunc<8, bool>(this);
  }
public:

  char pad1[0x4]; // this might be useless idk
  ConVar* next;
  int registered;
  const char* name;
  const char* help_string;
  int flags;
  char pad2[0x4]; // this as well
  ConCommandBase* con_command_bases;
};

class ConVar : public ConCommandBase
{
public:
  float GetFloat()
  {
    return memory::vfunc<15, float>(this);
  }

  int GetInt()
  {
    return memory::vfunc<16, int>(this);
  }

  void SetValue(const char *value)
  {
    return memory::vfunc<17, void>(this, value);
  }

  void SetValue(float value)
  {
    return memory::vfunc<18, void>(this, value);
  }

  void SetValue(int value)
  {
    return memory::vfunc<19, void>(this, value);
  }

public:

  struct CVValue_t
  {
    char* string;
    int	string_length;
    float float_value;
    int int_Value;
  };

  ConVar* parent;
  const char *default_value;
  CVValue_t value;
  bool has_min;
  float min_val;
  bool has_max;
  float max_val;
  utl_vector<change_callback_t> change_callback;
};

class ICVar
{
public:
  void RegisterConCommand(ConCommandBase *command)
  {
    return memory::vfunc<10, void>(this, command);
  }

  void UnRegisterConCommand(ConCommandBase*command)
  {
    return memory::vfunc<11, void>(this, command);
  }

  ConCommandBase * FindCommandBase(const char *name)
  {
    return memory::vfunc<14, ConCommandBase*>(this, name);
  }

  ConVar* FindVar(const char* var_name)
  {
    return memory::vfunc<16, ConVar*>(this, var_name);
  }

  ConCommandBase *Spoof(ConCommandBase* cvar, const char *new_name)
  {
    UnRegisterConCommand(cvar);
    cvar->name = const_cast<char *>(new_name);
    RegisterConCommand(cvar);

    return cvar;
  }

  void ConsoleColorPrintf(const unsigned char color[4], const char *message, ...)
  {
    return memory::vfunc<25, void>(this, &color, message);
  }
};
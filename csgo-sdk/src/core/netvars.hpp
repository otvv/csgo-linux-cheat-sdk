//
// csgo sdk
//

#pragma once

#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

#include "interfaces.hpp"
#include "../helpers/fnv.hpp"

std::map<unsigned int, RecvProp *> g_netvar_map;

// macros
#define CNetworkVar(_type, _function_name, _hash)                                       \
  _type _function_name()                                                                \
  {                                                                                     \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;               \
    return *reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset); \
  };

#define CNetworkVarPtr(_type, _function_name, _hash)                                   \
  _type *_function_name()                                                              \
  {                                                                                    \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;              \
    return reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset); \
  };

#define CNetworkVarRef(_type, _function_name, _hash)                                    \
  _type &_function_name()                                                               \
  {                                                                                     \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;               \
    return *reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset); \
  };

#define CNetworkVarPadded(_type, _function_name, _hash, _pad)                                  \
  _type _function_name()                                                                       \
  {                                                                                            \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;                      \
    return *reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset + _pad); \
  };

#define CNetworkVarPtrPadded(_type, _function_name, _hash, _pad)                              \
  _type *_function_name()                                                                     \
  {                                                                                           \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;                     \
    return reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset + _pad); \
  };

#define CNetworkVarRefPadded(_type, _function_name, _hash, _pad)                               \
  _type &_function_name()                                                                      \
  {                                                                                            \
    static std::uintptr_t offset = g_netvar_map[fnv_hash(_hash)]->offset;                      \
    return *reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + offset + _pad); \
  };

#define COffset(_type, _function_name, _offset)                                          \
  _type _function_name()                                                                 \
  {                                                                                      \
    return *reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + _offset); \
  };

#define COffsetPtr(_type, _function_name, _offset)                                      \
  _type *_function_name()                                                               \
  {                                                                                     \
    return reinterpret_cast<_type *>(reinterpret_cast<std::uintptr_t>(this) + _offset); \
  };

namespace manager
{
  inline void collect(RecvTable *_table)
  {
    // loop tables and netvars
    for (int i = 0; i < _table->num_props; ++i)
    {
      // current netvar
      RecvProp *current_netvar = &_table->p_props[i];

      // sanity checks
      if (!current_netvar || std::isdigit(current_netvar->name[0]))
      {
        continue;
      }

      if (std::strcmp(current_netvar->name, "baseclass") == 0)
      {
        continue;
      }

      // if the table has at least one netvar, store it
      if (current_netvar->data_table && current_netvar->data_table->name[0] == 'D' && current_netvar->type == SendPropType::DPT_DATA_TABLE)
      {
        collect(current_netvar->data_table);
      }

      // copy table name to a temporary variable
      char temporary_buffer[128]; // TODO: maybe use a smaller buffer size?
      std::strcpy(temporary_buffer, _table->name);

      // append string
      std::strcat(temporary_buffer, "->");
      std::strcat(temporary_buffer, current_netvar->name);

      // populate networked variable map
      g_netvar_map[fnv_hash(temporary_buffer)] = current_netvar;
    }
  }

  inline void dump(RecvTable *_table, std::ofstream &_file)
  {
    std::stringstream ss;

    // table name
    ss << std::endl << '[' << _table->name << ']' << std::endl;

    for (int i = 0; i < _table->num_props; i++)
    {
      // current netvar
      RecvProp *current_netvar = &_table->p_props[i];

      // sanity checks
      if (!current_netvar || std::isdigit(current_netvar->name[0]))
      {
        continue;
      }

      if (std::strcmp(current_netvar->name, "baseclass") == 0)
      {
        continue;
      }

      // repeat
      if (current_netvar->data_table && current_netvar->data_table->name[0] == 'D' && current_netvar->type == SendPropType::DPT_DATA_TABLE)
      {
        dump(current_netvar->data_table, _file);
      }

      // offset
      ss << current_netvar->name << " =" << " 0x" << std::uppercase << std::hex << current_netvar->offset << std::endl;

      _file << ss.rdbuf();
    }
  }

} // namespace manager

struct netvars_t
{
  netvars_t()
  {
    // client class pointer
    CClientClass *client_class = csgo::base_client->GetAllClasses();

    // set this variables to true if you want to dump netvars into a file
    constexpr bool DUMP_NETVARS = true;

    for (CClientClass *data = client_class; data; data = data->next)
    {
      if (data->table)
      {
        // populate container
        manager::collect(data->table);

        if (DUMP_NETVARS)
        {
          // file name
          static std::ofstream file("netvars.dump");

          manager::dump(data->table, file);
        }
      }
    }
  }
};
extern netvars_t netvars;
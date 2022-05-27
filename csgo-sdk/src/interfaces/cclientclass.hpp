//
// csgo sdk
//

#pragma once

#include "crecvproxydata.hpp"
#include "iclientnetworkable.hpp"

using CreateClientClassFn = IClientNetworkable *(*)(int entity_num, int serial_num);
using CreateEventFn = IClientNetworkable *(*)();

class CClientClass
{
public:
  CreateClientClassFn create_client;
  CreateEventFn create_event;
  char *network_name;
  RecvTable *table;
  CClientClass *next;
  int class_id;
};
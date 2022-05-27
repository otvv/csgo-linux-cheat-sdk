//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

#define MAX_PLAYER_NAME_LENGTH 128
#define SIGNED_GUID_LEN 32
#define MAX_CUSTOM_FILES 4

class INetChannelInfo;

struct player_info_s
{
  unsigned long version;
  unsigned long xuid;
  char name[MAX_PLAYER_NAME_LENGTH];
  int user_id;
  char guid[SIGNED_GUID_LEN + 1];
  unsigned int steam3_id;
  char friends_name[MAX_PLAYER_NAME_LENGTH];
  bool is_fake_player;
  bool is_hltv;
  unsigned int custom_files[MAX_CUSTOM_FILES];
  unsigned char files_downloaded;
};

class IVEngineClient
{
public:
  bool GetPlayerInfo(int ent_num, player_info_s *info)
  {
    return memory::vfunc<8, bool>(this, ent_num, info);
  }

  int GetPlayerForUserID(int user_id)
  {
    return memory::vfunc<9, int>(this, user_id);
  }

  int GetLocalPlayer()
  {
    return memory::vfunc<12, int>(this);
  }

  void GetViewAngles(angl_t *angles)
  {
    return memory::vfunc<18, void>(this, angles);
  }

  void SetViewAngles(angl_t *angles)
  {
    return memory::vfunc<19, void>(this, angles);
  }

  int GetMaxClients()
  {
    return memory::vfunc<20, int>(this);
  }

  bool IsInGame()
  {
    return memory::vfunc<26, bool>(this);
  }

  bool IsConnected()
  {
    return memory::vfunc<27, bool>(this);
  }

  INetChannelInfo* GetNetChannelInfo()
  {
    return memory::vfunc<78, INetChannelInfo*>(this);
  }

  bool IsTakingScreenshot()
  {
    return memory::vfunc<92, bool>(this);
  }

  void ExecuteClientCmd(const char *command)
  {
    return memory::vfunc<108, void>(this, command);
  }

  void ClientCmdUnrestricted(const char *command)
  {
    return memory::vfunc<113, void>(this, command);
  }
};
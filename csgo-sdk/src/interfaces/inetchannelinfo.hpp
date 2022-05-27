//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

enum CLC_Messages
{
  clc_ClientInfo = 8,        // client info (table CRC etc)
  clc_Move = 9,              // [CUserCmd]
  clc_VoiceData = 10,        // Voicestream data from a client
  clc_BaselineAck = 11,      // client acknowledges a new baseline seqnr
  clc_ListenEvents = 12,     // client acknowledges a new baseline seqnr
  clc_RespondCvarValue = 13, // client is responding to a svc_GetCvarValue message.
  clc_FileCRCCheck = 14,     // client is sending a file's CRC to the server to be verified.
  clc_LoadingProgress = 15,  // client loading progress
  clc_SplitPlayerConnect = 16,
  clc_ClientMessage = 17,
  clc_CmdKeyValues = 18,
  clc_HltvReplay = 20
};

class INetMessage
{
public:
  
  int GetType()
  {
    return memory::vfunc<7, int>(this);
  }
  
  int GetGroup()
  {
    return memory::vfunc<8, int>(this);
  }
};

class INetChannelInfo
{
public:
  enum
  {
    GENERIC = 0,  // must be first and is default group
    LOCALPLAYER,  // bytes for local player entity update
    OTHERPLAYERS, // bytes for other players update
    ENTITIES,     // all other entity bytes
    SOUNDS,       // game sounds
    EVENTS,       // event messages
    TEMPENTS,     // temp entities
    USERMESSAGES, // user messages
    ENTMESSAGES,  // entity messages
    VOICE,        // voice data
    STRINGTABLE,  // a stringtable update
    MOVE,         // client move cmds
    STRINGCMD,    // string command
    SIGNON,       // various signondata
    TOTAL,        // must be last and is not a real group
  };
};
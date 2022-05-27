//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class CClientClass;

enum ClientFrameStage_t
{
  FRAME_UNDEFINED = -1,
  FRAME_START,
  FRAME_NET_UPDATE_START,
  FRAME_NET_UPDATE_POSTDATAUPDATE_START,
  FRAME_NET_UPDATE_POSTDATAUPDATE_END,
  FRAME_NET_UPDATE_END,
  FRAME_RENDER_START,
  FRAME_RENDER_END
};

enum ECstrike15UserMessages
{
  CS_UM_VGUIMenu = 1,
  CS_UM_Geiger = 2,
  CS_UM_Train = 3,
  CS_UM_HudText = 4,
  CS_UM_SayText = 5,
  CS_UM_SayText2 = 6,
  CS_UM_TextMsg = 7,
  CS_UM_HudMsg = 8,
  CS_UM_ResetHud = 9,
  CS_UM_GameTitle = 10,
  CS_UM_Shake = 12,
  CS_UM_Fade = 13, // Fade HUD in/out
  CS_UM_Rumble = 14,
  CS_UM_CloseCaption = 15,
  CS_UM_CloseCaptionDirect = 16,
  CS_UM_SendAudio = 17,
  CS_UM_RawAudio = 18,
  CS_UM_VoiceMask = 19,
  CS_UM_RequestState = 20,
  CS_UM_Damage = 21,
  CS_UM_RadioText = 22,
  CS_UM_HintText = 23,
  CS_UM_KeyHintText = 24,
  CS_UM_ProcessSpottedEntityUpdate = 25,
  CS_UM_ReloadEffect = 26,
  CS_UM_AdjustMoney = 27,
  CS_UM_UpdateTeamMoney = 28,
  CS_UM_StopSpectatorMode = 29,
  CS_UM_KillCam = 30,
  CS_UM_DesiredTimescale = 31,
  CS_UM_CurrentTimescale = 32,
  CS_UM_AchievementEvent = 33,
  CS_UM_MatchEndConditions = 34,
  CS_UM_DisconnectToLobby = 35,
  CS_UM_PlayerStatsUpdate = 36,
  CS_UM_DisplayInventory = 37,
  CS_UM_WarmupHasEnded = 38,
  CS_UM_ClientInfo = 39,
  CS_UM_XRankGet = 40, // get ELO rank value from client
  CS_UM_XRankUpd = 41, // update ELO rank value on client
  CS_UM_CallVoteFailed = 45,
  CS_UM_VoteStart = 46,
  CS_UM_VotePass = 47,
  CS_UM_VoteFailed = 48,
  CS_UM_VoteSetup = 49,
  CS_UM_ServerRankRevealAll = 50,
  CS_UM_SendLastKillerDamageToClient = 51,
  CS_UM_ServerRankUpdate = 52,
  CS_UM_ItemPickup = 53,
  CS_UM_ShowMenu = 54, // show hud menu
  CS_UM_BarTime = 55,  // for the C4 progress bar.
  CS_UM_AmmoDenied = 56,
  CS_UM_MarkAchievement = 57,
  CS_UM_MatchStatsUpdate = 58,
  CS_UM_ItemDrop = 59,
  CS_UM_GlowPropTurnOff = 60,
  CS_UM_SendPlayerItemDrops = 61,
  CS_UM_RoundBackupFilenames = 62,
  CS_UM_SendPlayerItemFound = 63,
  CS_UM_ReportHit = 64,
  CS_UM_XpUpdate = 65,
  CS_UM_QuestProgress = 66,
  CS_UM_ScoreLeaderboardData = 67
};

class IBaseClientDLL
{
public:
  CClientClass *GetAllClasses()
  {
    return memory::vfunc<8, CClientClass *>(this);
  }

  void IN_ActivateMouse()
  {
    return memory::vfunc<15, void>(this);
  }

  void IN_DeactivateMouse()
  {
    return memory::vfunc<16, void>(this);
  }

  bool DispatchUserMessage(int msg_type, unsigned int arg1, unsigned int length, const void *data = nullptr)
  {
    return memory::vfunc<38, bool>(this, msg_type, arg1, length, data);
  }
};
//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class IClientEntity;

class CMoveData
{
public:
  bool first_run_of_functions : 1;
  bool game_code_moved_player : 1;
  bool no_air_control : 1;
  int player_handle;
  int impulse_command;
  angl_t view_angles;
  angl_t abs_viewangles;
  int buttons;
  int old_buttons;
  float forward_move;
  float side_move;
  float up_move;
  float max_speed;
  float client_max_speed;
  vec3_t velocity;
  vec3_t trailing_velocity;
  float trailing_velocity_time;
  angl_t angles;
  angl_t old_angles;
  float out_step_height;
  vec3_t out_wish_vel;
  vec3_t out_jump_vel;
  vec3_t constraint_center;
  float constraint_radius;
  float constraint_width;
  float constraint_speed_factor;
  bool constraint_past_radius;
  vec3_t abs_origin;
};

class IMoveHelper
{
public:
  void SetHost(IClientEntity* host)
  {
    return memory::vfunc<1, void>(this, host);
  }

  void ProcessImpacts()
  {
    return memory::vfunc<4, void>(this);
  }
};

class CPrediction
{
public:
  char pad1[0x8]; // m_hLastGround
  bool m_bInPrediction;
  bool m_bOldCLPredictValue;
  bool m_bEnginePaused;
  int	 m_nPreviousStartFrame;
  int	 m_nIncomingPacketNumber;
  float m_flLastServerWorldTimeStamp;
  bool m_bFirstTimePredicted;
  int	m_nCommandsPredicted;
  int	m_nServerCommandsAcknowledged;
  int	m_bPreviousAckHadErrors;
  float	m_flIdealPitch;
  int	m_nLastCommandAcknowledged;
  bool m_bPreviousAckErrorTriggersFullLatchReset;
  char pad2[0x2E];
  bool m_bPerformedTickShift;
};

class IPrediction : public CPrediction
{
public:
  void Update(int start_frame, bool valid_frame, int inc_ack, int out_cmd)
  {
    return memory::vfunc<3, void>(this, start_frame, valid_frame, inc_ack, out_cmd);
  }

  void GetViewOrigin(vec3_t& angle)
  {
    return memory::vfunc<12, void>(this, &angle);
  }

  void SetViewOrigin(vec3_t& angle)
  {
    return memory::vfunc<13, void>(this, &angle);
  }

  void GetLocalViewAngles(vec3_t& angle)
  {
    return memory::vfunc<16, void>(this, &angle);
  }

  void SetLocalViewAngles(vec3_t& angle)
  {
    return memory::vfunc<17, void>(this, &angle);
  }

  void CheckMovingGround(IClientEntity* entity, double frame_time)
  {
    return memory::vfunc<18, void>(this, entity, frame_time);
  }

  void RunCommand(IClientEntity* entity, CUserCmd* ucmd, IMoveHelper move)
  {
    return memory::vfunc<19, void>(this, entity, ucmd, move);
  }

  void SetupMove(IClientEntity* entity, CUserCmd* cmd, IMoveHelper* helper, CMoveData* move)
  {
    return memory::vfunc<20, void>(this, entity, cmd, helper, move);
  }

  void FinishMove(IClientEntity* entity, CUserCmd* cmd, CMoveData* move)
  {
    return memory::vfunc<21, void>(this, entity, cmd, move);
  }
};

class IGameMovement
{
public:
  
  void ProcessMovement(IClientEntity* player, CMoveData* move)
  {
    return memory::vfunc<1, void>(this, player, move);
  }

  void Reset()
  {
    return memory::vfunc<2, void>(this);
  }

  void StartTrackPredictionErrors(IClientEntity* player)
  {
    return memory::vfunc<3, void>(this, player);
  }

  void FinishTrackPredictionErrors(IClientEntity* player)
  {
    return memory::vfunc<4, void>(this, player);
  }

  void DiffPrint(const char* fmt, ...)
  {
    return memory::vfunc<5, void>(this, fmt);
  }

  const vec3_t& GetPlayerMins(bool ducked)
  {
    return memory::vfunc<6, const vec3_t&>(this, ducked);
  }

  const vec3_t& GetPlayerMaxs(bool ducked)
  {
    return memory::vfunc<7, const vec3_t&>(this, ducked);
  }

  const vec3_t& GetPlayerViewOffset(bool ducked)
  {
    return memory::vfunc<8, const vec3_t&>(this, ducked);
  }

  bool IsMovingPlayerStuck()
  {
    return memory::vfunc<9, bool>(this);
  }

  const IClientEntity* GetMovingPlayer()
  {
    return memory::vfunc<10, IClientEntity*>(this);
  }
   
  void UnblockPusher(IClientEntity* player, IClientEntity* pusher)
  {
    return memory::vfunc<11, void>(this, player, pusher);
  }

  void SetupMovementBounds(CMoveData* move)
  {
    return memory::vfunc<12, void>(this, move);
  }
};
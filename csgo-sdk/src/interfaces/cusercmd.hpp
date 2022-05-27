//
// csgo sdk
//

#pragma once

#include "../helpers/vector.hpp"

#define IN_ATTACK (1 << 0)
#define IN_JUMP (1 << 1)
#define IN_DUCK (1 << 2)
#define IN_FORWARD (1 << 3)
#define IN_BACK (1 << 4)
#define IN_USE (1 << 5)
#define IN_CANCEL (1 << 6)
#define IN_LEFT (1 << 7)
#define IN_RIGHT (1 << 8)
#define IN_MOVELEFT (1 << 9)
#define IN_MOVERIGHT (1 << 10)
#define IN_ATTACK2 (1 << 11)
#define IN_RUN (1 << 12)
#define IN_RELOAD (1 << 13)
#define IN_ALT1 (1 << 14)
#define IN_ALT2 (1 << 15)
#define IN_SCORE (1 << 16)   // used by client.dll for when scoreboard is held down
#define IN_SPEED (1 << 17)   // player is holding the speed key
#define IN_WALK (1 << 18)    // player holding walk key
#define IN_ZOOM (1 << 19)    // zoom key for HUD zoom
#define IN_WEAPON1 (1 << 20) // weapon defines these bits
#define IN_WEAPON2 (1 << 21) // weapon defines these bits
#define IN_BULLRUSH (1 << 22)
#define IN_GRENADE1 (1 << 23) // grenade 1
#define IN_GRENADE2 (1 << 24) // grenade 2
#define IN_LOOKSPIN (1 << 25)

class CUserCmd
{
public:
  virtual ~CUserCmd(){};

  int command_number;
  int tick_count;
  angl_t view_angles;
  vec3_t aim_direction;
  float forward_move;
  float side_move;
  float up_move;
  int buttons;
  unsigned char impulse;
  int weapon_select;
  int weapon_subtype;
  int random_seed;
  short mouse_dx;
  short mouse_dy;
  bool has_been_predicted;
  angl_t head_angles;
  vec3_t head_offset;
};
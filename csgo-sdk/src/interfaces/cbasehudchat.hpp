//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

enum ChatFilters : int
{
  CHAT_FILTER_NONE = 0,
  CHAT_FILTER_JOINLEAVE = 0x000001,
  CHAT_FILTER_NAMECHANGE = 0x000002,
  CHAT_FILTER_PUBLICCHAT = 0x000004,
  CHAT_FILTER_SERVERMSG = 0x000008,
  CHAT_FILTER_TEAMCHANGE = 0x000010,
  CHAT_FILTER_ACHIEVEMENT = 0x000020,
};

enum TextColor
{
	COLOR_NORMAL = 1,
	COLOR_USEOLDCOLORS = 2,
	COLOR_PLAYERNAME = 3,
	COLOR_LOCATION = 4,
	COLOR_ACHIEVEMENT = 5,
	COLOR_AWARD = 6,
	COLOR_PENALTY = 7,
	COLOR_SILVER = 8,
	COLOR_GOLD = 9,
	COLOR_RARITY_FIRST = 10,
	COLOR_COMMON = COLOR_RARITY_FIRST,
	COLOR_UNCOMMON = 11,
	COLOR_RARE = 12,
	COLOR_MYTHICAL = 13,
	COLOR_LEGENDARY = 14,
	COLOR_ANCIENT = 15,
	COLOR_IMMORTAL = 16,
	COLOR_RARITY_LAST = COLOR_IMMORTAL,
	COLOR_MAX
};

class CBaseHudChat
{
public:
  void ChatPrintf(int player_index, int filter, const char* fmt, ...)
  {
    return memory::vfunc<27, void>(this, player_index, filter, fmt);
  }
};
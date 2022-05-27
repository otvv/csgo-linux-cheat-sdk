//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

enum AnalogCode_t
{
  ANALOG_CODE_INVALID = -1,
  MOUSE_X = 0,
  MOUSE_Y,
  MOUSE_XY, // invoked when either x or y changes
  MOUSE_WHEEL,
  ANALOG_CODE_LAST = 10,
};

enum ButtonCode_t
{
  KEY_INVALID = 0x0,
  KEY_0 = 0x1,
  KEY_1 = 0x2,
  KEY_2 = 0x3,
  KEY_3 = 0x4,
  KEY_4 = 0x5,
  KEY_5 = 0x6,
  KEY_6 = 0x7,
  KEY_7 = 0x8,
  KEY_8 = 0x9,
  KEY_9 = 0xA,
  KEY_A = 0xB,
  KEY_B = 0xC,
  KEY_C = 0xD,
  KEY_D = 0xE,
  KEY_E = 0xF,
  KEY_F = 0x10,
  KEY_G = 0x11,
  KEY_H = 0x12,
  KEY_I = 0x13,
  KEY_J = 0x14,
  KEY_K = 0x15,
  KEY_L = 0x16,
  KEY_M = 0x17,
  KEY_N = 0x18,
  KEY_O = 0x19,
  KEY_P = 0x1A,
  KEY_Q = 0x1B,
  KEY_R = 0x1C,
  KEY_S = 0x1D,
  KEY_T = 0x1E,
  KEY_U = 0x1F,
  KEY_V = 0x20,
  KEY_W = 0x21,
  KEY_X = 0x22,
  KEY_Y = 0x23,
  KEY_Z = 0x24,
  KEY_PAD_0 = 0x25,
  KEY_PAD_1 = 0x26,
  KEY_PAD_2 = 0x27,
  KEY_PAD_3 = 0x28,
  KEY_PAD_4 = 0x29,
  KEY_PAD_5 = 0x2A,
  KEY_PAD_6 = 0x2B,
  KEY_PAD_7 = 0x2C,
  KEY_PAD_8 = 0x2D,
  KEY_PAD_9 = 0x2E,
  KEY_PAD_DIVIDE = 0x2F,
  KEY_PAD_MULTIPLY = 0x30,
  KEY_PAD_MINUS = 0x31,
  KEY_PAD_PLUS = 0x32,
  KEY_PAD_ENTER = 0x33,
  KEY_PAD_DECIMAL = 0x34,
  KEY_LBRACKET = 0x35,
  KEY_RBRACKET = 0x36,
  KEY_SEMICOLON = 0x37,
  KEY_APOSTROPHE = 0x38,
  KEY_BACKQUOTE = 0x39,
  KEY_COMMA = 0x3A,
  KEY_PERIOD = 0x3B,
  KEY_SLASH = 0x3C,
  KEY_BACKSLASH = 0x3D,
  KEY_MINUS = 0x3E,
  KEY_EQUAL = 0x3F,
  KEY_ENTER = 0x40,
  KEY_SPACE = 0x41,
  KEY_BACKSPACE = 0x42,
  KEY_TAB = 0x43,
  KEY_CAPSLOCK = 0x44,
  KEY_NUMLOCK = 0x45,
  KEY_ESCAPE = 0x46,
  KEY_SCROLLLOCK = 0x47,
  KEY_INSERT = 0x48,
  KEY_DELETE = 0x49,
  KEY_HOME = 0x4A,
  KEY_END = 0x4B,
  KEY_PAGEUP = 0x4C,
  KEY_PAGEDOWN = 0x4D,
  KEY_BREAK = 0x4E,
  KEY_LSHIFT = 0x4F,
  KEY_RSHIFT = 0x50,
  KEY_LALT = 0x51,
  KEY_RALT = 0x52,
  KEY_LCONTROL = 0x53,
  KEY_RCONTROL = 0x54,
  KEY_LWIN = 0x55,
  KEY_RWIN = 0x56,
  KEY_APP = 0x57,
  KEY_UP = 0x58,
  KEY_LEFT = 0x59,
  KEY_DOWN = 0x5A,
  KEY_RIGHT = 0x5B,
  KEY_F1 = 0x5C,
  KEY_F2 = 0x5D,
  KEY_F3 = 0x5E,
  KEY_F4 = 0x5F,
  KEY_F5 = 0x60,
  KEY_F6 = 0x61,
  KEY_F7 = 0x62,
  KEY_F8 = 0x63,
  KEY_F9 = 0x64,
  KEY_F10 = 0x65,
  KEY_F11 = 0x66,
  KEY_F12 = 0x67,
  KEY_MOUSE_1 = 0x6B,
  KEY_MOUSE_2 = 0x6C,
  KEY_MOUSE_3 = 0x6D,
  KEY_MOUSE_4 = 0x6E,
  KEY_MOUSE_5 = 0x6F
};

class IInputSystem
{
public:
  void EnableInput(bool state)
  {
    return memory::vfunc<11, void>(this, state);
  }

  bool IsButtonDown(int code)
  {
    return memory::vfunc<15, bool>(this, code);
  }

  int GetAnalogValue(AnalogCode_t code)
  {
    return memory::vfunc<18, int>(this, code);
  }

  int GetAnalogDelta(AnalogCode_t code)
  {
    return memory::vfunc<19, int>(this, code);
  }

  const char *ButtonCodeToString(int code)
  {
    return memory::vfunc<40, const char *>(this, code);
  }

  void GetCursorPosition(int *x, int *y)
  {
    return memory::vfunc<56, void>(this, x, y);
  }
};
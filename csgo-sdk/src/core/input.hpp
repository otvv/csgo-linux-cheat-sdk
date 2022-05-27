//
// csgo sdk
//

#pragma once

#include <array>
#include "interfaces.hpp"

// fgui library
#define FGUI_IMPLEMENTATION
#include <FGUI/FGUI.hpp>

inline std::array<bool, 256> g_current_pressed_keys, g_old_pressed_keys;
inline FGUI::POINT g_cursor_position, g_cursor_position_delta;
inline int g_cursor_wheel_delta;

namespace input
{
  inline void pull_input()
  {
    static FGUI::POINT last_known_position = {0, 0};

    // copy new keys (current being pressed) to old keys (already pressed)
    std::copy(g_current_pressed_keys.begin(), g_current_pressed_keys.end(), g_old_pressed_keys.begin());

    for (std::size_t i = 0; i < 256; i++)
    {
      g_current_pressed_keys.at(i) = csgo::input_system->IsButtonDown(i);
    }

    // get cursor wheel delta
    g_cursor_wheel_delta = csgo::input_system->GetAnalogDelta(AnalogCode_t::MOUSE_WHEEL);

    // get cursor position
    csgo::input_system->GetCursorPosition(&g_cursor_position.m_iX, &g_cursor_position.m_iY);

    // calculate the cursor position delta
    g_cursor_position_delta = {(g_cursor_position.m_iX - last_known_position.m_iX), (g_cursor_position.m_iY - last_known_position.m_iY)};

    // get last known position of the cursor
    last_known_position = g_cursor_position;
  }

  inline bool get_key_held(unsigned int _key_code)
  {
    return g_current_pressed_keys.at(_key_code);
  }

  inline bool get_key_release(unsigned int _key_code)
  {
    return (!g_current_pressed_keys.at(_key_code) && g_old_pressed_keys.at(_key_code));
  }

  inline bool get_key_press(unsigned int _key_code)
  {
    return (g_current_pressed_keys.at(_key_code) && !g_old_pressed_keys.at(_key_code));
  }

  inline FGUI::POINT get_cursor_position()
  {
    return g_cursor_position;
  }

  inline FGUI::POINT get_cursor_position_delta()
  {
    return g_cursor_position_delta;
  }

  inline int get_cursor_wheel_delta()
  {
    return g_cursor_wheel_delta;
  }

  inline bool is_cursor_in_area(FGUI::AREA area)
  {
    return (get_cursor_position().m_iX > area.m_iLeft && get_cursor_position().m_iY > area.m_iTop &&
            get_cursor_position().m_iX < area.m_iLeft + area.m_iRight && get_cursor_position().m_iY < area.m_iTop + area.m_iBottom);
  }

} // namespace input

struct input_t
{
  input_t()
  {
    // initialize input system
    FGUI::INPUT.PullInput = input::pull_input;
    FGUI::INPUT.IsKeyHeld = input::get_key_held;
    FGUI::INPUT.IsKeyReleased = input::get_key_release;
    FGUI::INPUT.IsKeyPressed = input::get_key_press;
    FGUI::INPUT.GetCursorPos = input::get_cursor_position;
    FGUI::INPUT.GetCursorPosDelta = input::get_cursor_position_delta;
    FGUI::INPUT.IsCursorInArea = input::is_cursor_in_area;

    FGUI::INPUT.SetInputType(FGUI::INPUT_TYPE::INPUT_SYSTEM);
  }
};
extern input_t input_system;
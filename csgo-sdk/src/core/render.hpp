//
// csgo sdk
//

#pragma once

#include "interfaces.hpp"

// fgui library
#define FGUI_IMPLEMENTATION
#include <FGUI/FGUI.hpp>

namespace fonts
{
  FGUI::FONT watermark;
  FGUI::FONT esp;
}

namespace render
{
  inline void create_font(FGUI::FONT &_font, std::string _family, int _size, int _flags, bool _bold)
  {
    _font = csgo::vgui_surface->CreateFont();
    csgo::vgui_surface->SetFontGlyphSet(_font, _family.c_str(), _size, _bold ? 800 : 0, 0, 0, _flags);
  }

  inline FGUI::DIMENSION get_screen_size()
  {
    static FGUI::DIMENSION temporary_size = {0, 0};

    csgo::vgui_surface->GetScreenSize(temporary_size.m_iWidth, temporary_size.m_iHeight);

    return temporary_size;
  }

  inline FGUI::DIMENSION get_text_size(FGUI::FONT _font, std::string _text)
  {
    static FGUI::DIMENSION temporary_size = {0, 0};

    csgo::vgui_surface->GetTextSize(_font, std::wstring(_text.begin(), _text.end()).c_str(), temporary_size.m_iWidth, temporary_size.m_iHeight);

    return temporary_size;
  }

  inline void limit_area(int x, int y, int width, int height)
  {
    FGUI::AREA areaViewport = { 0, 0, 0, 0 };

    areaViewport.m_iLeft = x;
    areaViewport.m_iTop = y;
    areaViewport.m_iRight = (x + width);
    areaViewport.m_iBottom = (y + height);

    csgo::vgui_surface->DisableClipping(false);
    csgo::vgui_surface->SetClipRect(areaViewport.m_iLeft, areaViewport.m_iTop, areaViewport.m_iRight, areaViewport.m_iBottom);
  }

  inline void reset_limit()
  {
    csgo::vgui_surface->DisableClipping(true);
  }

  inline void rectangle(int _x, int _y, int _width, int _height, FGUI::COLOR _color)
  {
    csgo::vgui_surface->DrawSetColor(_color.m_ucRed, _color.m_ucGreen, _color.m_ucBlue, _color.m_ucAlpha);
    csgo::vgui_surface->DrawFilledRect(_x, _y, _x + _width, _y + _height);
  }

  inline void outline(int _x, int _y, int _width, int _height, FGUI::COLOR _color)
  {
    csgo::vgui_surface->DrawSetColor(_color.m_ucRed, _color.m_ucGreen, _color.m_ucBlue, _color.m_ucAlpha);
    csgo::vgui_surface->DrawOutlinedRect(_x, _y, _x + _width, _y + _height);
  }

  inline void gradient(int _x, int _y, int _width, int _height, FGUI::COLOR _color1, FGUI::COLOR _color2, bool _horizontal)
  {
    csgo::vgui_surface->DrawSetColor(_color1.m_ucRed, _color1.m_ucGreen, _color1.m_ucBlue, _color1.m_ucAlpha);
    csgo::vgui_surface->DrawFilledRectFade(_x, _y, _x + _width, _y + _height, 255, 255, _horizontal);

    csgo::vgui_surface->DrawSetColor(_color2.m_ucRed, _color2.m_ucGreen, _color2.m_ucBlue, _color2.m_ucAlpha);
    csgo::vgui_surface->DrawFilledRectFade(_x, _y, _x + _width, _y + _height, 0, 255, _horizontal);
  }

  inline void line(int _from_x, int _from_y, int _to_x, int _to_y, FGUI::COLOR _color)
  {
    csgo::vgui_surface->DrawSetColor(_color.m_ucRed, _color.m_ucGreen, _color.m_ucBlue, _color.m_ucAlpha);
    csgo::vgui_surface->DrawLine(_from_x, _from_y, _to_x, _to_y);
  }

  inline void text(int _x, int _y, FGUI::FONT _font, FGUI::COLOR _color, std::string _text)
  {
    csgo::vgui_surface->DrawColoredText(_font, _x, _y, _color.m_ucRed, _color.m_ucGreen, _color.m_ucBlue, _color.m_ucAlpha, _text.c_str());
  }

  inline bool world_to_screen(vec3_t& _origin, vec3_t& _screen) 
  {
    return (csgo::debug_overlay->ScreenPosition(_origin, _screen) != 1);
  }

  inline void texture(unsigned char *_data, int _x, int _y, int _width, int _height, float _scale)
  {
    static unsigned int texture_id = 0;

    bool initialized = [&]() {
      texture_id = csgo::vgui_surface->CreateNewTextureID(true);

      // if somehow the texture id is invalid
      if (!texture_id)
      {
        return false;
      }

      csgo::vgui_surface->DrawSetTextureRGBA(texture_id, _data, _width, _height);

      return true;
    }();

    if (initialized)
    {
      static bool draw_once = [&]() 
      {
        if (!csgo::vgui_surface->IsTextureIDValid(texture_id))
        {
          return false;
        }

        csgo::vgui_surface->DrawSetColor(255, 255, 255, 255);
        csgo::vgui_surface->DrawSetTexture(texture_id);

        return true;
      }();

      if (draw_once)
      {
        csgo::vgui_surface->DrawTexturedRect(_x, _y, _x + _width * _scale, _y + _height * _scale);
      }
    }
  }

} // namespace render

struct render_t
{
  render_t()
  {
    FGUI::RENDER.CreateFont = render::create_font;
    FGUI::RENDER.GetScreenSize = render::get_screen_size;
    FGUI::RENDER.GetTextSize = render::get_text_size;
    FGUI::RENDER.Rectangle = render::rectangle;
    FGUI::RENDER.Outline = render::outline;
    FGUI::RENDER.Gradient = render::gradient;
    FGUI::RENDER.Line = render::line;
    FGUI::RENDER.Text = render::text;

    // initialize other fonts here
    render::create_font(fonts::watermark, "Tahoma Bold", 11, FONTFLAG_ANTIALIAS, true);
    render::create_font(fonts::esp, "fs Tahoma 8px", 16, FONTFLAG_DROPSHADOW, true);
  }
};
extern render_t render_manager;
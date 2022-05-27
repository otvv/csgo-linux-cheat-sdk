//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class IMaterial;

enum FontDrawType_t
{
  // Use the "additive" value from the scheme file
  FONT_DRAW_DEFAULT = 0,

  // Overrides
  FONT_DRAW_NONADDITIVE,
  FONT_DRAW_ADDITIVE,

  FONT_DRAW_TYPE_COUNT = 2,
};

enum EFontFlags
{
  FONTFLAG_NONE,
  FONTFLAG_ITALIC = 0x001,
  FONTFLAG_UNDERLINE = 0x002,
  FONTFLAG_STRIKEOUT = 0x004,
  FONTFLAG_SYMBOL = 0x008,
  FONTFLAG_ANTIALIAS = 0x010,
  FONTFLAG_GAUSSIANBLUR = 0x020,
  FONTFLAG_ROTARY = 0x040,
  FONTFLAG_DROPSHADOW = 0x080,
  FONTFLAG_ADDITIVE = 0x100,
  FONTFLAG_OUTLINE = 0x200,
  FONTFLAG_CUSTOM = 0x400, // custom generated font - never fall back to asian compatibility mode
  FONTFLAG_BITMAP = 0x800, // compiled bitmap font - no fallbacks
};

struct Vector2D // TODO: get rid of this shit
{
  Vector2D() = default;
  Vector2D(float _x, float _y) : m_flX(_x), m_flY(_y) {}

  float m_flX, m_flY;
};

struct vertex_t
{
  vertex_t() {};
  vertex_t(const Vector2D &pos, const Vector2D &coord = Vector2D(0.f, 0.f)) 
  {
    m_Position = pos;
    m_TexCoord = coord;
  }

  Vector2D m_Position;
  Vector2D m_TexCoord;
};

class ISurface
{
public:

  void DrawSetColor(int red, int green, int blue, int alpha)
  {
    return memory::vfunc<14, void>(this, red, green, blue, alpha);
  }

  void DrawFilledRect(int x, int y, int width, int height)
  {
    return memory::vfunc<16, void>(this, x, y, width, height);
  }

  void DrawOutlinedRect(int x, int y, int width, int height)
  {
    return memory::vfunc<18, void>(this, x, y, width, height);
  }

  void DrawLine(int x1, int y1, int x2, int y2)
  {
    return memory::vfunc<19, void>(this, x1, y1, x2, y2);
  }

  void DrawSetTextFont(unsigned long font)
  {
    return memory::vfunc<23, void>(this, font);
  }

  void DrawSetTextColor(int red, int green, int blue, int alpha)
  {
    return memory::vfunc<24, void>(this, red, green, blue, alpha);
  }

  void DrawSetTextPos(int x, int y)
  {
    return memory::vfunc<26, void>(this, x, y);
  }

  void DrawPrintText(const wchar_t *text, int length)
  {
    return memory::vfunc<28, void>(this, text, length);
  }

  void DrawSetTextureFile(int texture_id, const char *file_name, int hardware_filter, bool force_reload)
  {
    return memory::vfunc<36, void>(this, texture_id, file_name, hardware_filter, force_reload);
  }

  void DrawSetTextureRGBA(int texture_id, unsigned const char *rgba_data, int width, int height)
  {
    return memory::vfunc<37, void>(this, texture_id, rgba_data, width, height);
  }

  void DrawSetTexture(int texture_id)
  {
    return memory::vfunc<38, void>(this, texture_id);
  }

  void DrawTexturedRect(int x, int y, int width, int height)
  {
    return memory::vfunc<41, void>(this, x, y, width, height);
  }

  bool IsTextureIDValid(int texture_id)
  {
    return memory::vfunc<42, bool>(this, texture_id);
  }

  int CreateNewTextureID(bool is_procedural)
  {
    return memory::vfunc<43, int>(this, is_procedural);
  }

  void GetScreenSize(int &width, int &height)
  {
    return memory::vfunc<44, void>(this, &width, &height);
  }

  void UnlockCursor()
  {
    return memory::vfunc<66, void>(this);
  }

   void LockCursor()
  {
    return memory::vfunc<67, void>(this);
  }

  unsigned long CreateFont()
  {
    return memory::vfunc<71, unsigned long>(this);
  }

  bool SetFontGlyphSet(unsigned long font, const char *font_name, int tall, int weight, int blur, int scanlines, int flags, int min_range = 0, int max_range = 0)
  {
    return memory::vfunc<72, bool>(this, font, font_name, tall, weight, blur, scanlines, flags, min_range, max_range);
  }

  void GetTextSize(unsigned long font, const wchar_t *text, int &wide, int &tall)
  {
    return memory::vfunc<79, void>(this, font, text, &wide, &tall);
  }

  void DrawOutlinedCircle(int x, int y, int radius, int segments)
  {
    return memory::vfunc<103, void>(this, x, y, radius, segments);
  }

  void DrawTexturedPolygon(int vertex_count, vertex_t *vertex, bool clip_vertices = true)
  {
    return memory::vfunc<106, void>(this, vertex_count, vertex, clip_vertices);
  }

  void DrawFilledRectFade(int x, int y, int w, int h, unsigned int alpha1, unsigned int alpha2, bool is_horizontal)
  {
    return memory::vfunc<123, void>(this, x, y, w, h, alpha1, alpha2, is_horizontal);
  }

  void ResetFontCaches()
  {
    return memory::vfunc<141, void>(this);
  }

  void GetClipRect(int &x, int &y, int &w, int &h)
  {
    return memory::vfunc<146, void>(this, x, y, w, h);
  }

  void SetClipRect(int x, int y, int w, int h)
  {
    return memory::vfunc<147, void>(this, x, y, w, h);
  }

  void DisableClipping(bool disable)
  {
    m_bEnableClipping = !disable;
    
    // memory::vfunc<159, void>(this, disable);
  }

  void DrawColoredText(unsigned long font, int x, int y, int red, int green, int blue, int alpha, const char *text)
  {
    return memory::vfunc<163, void>(this, font, x, y, red, green, blue, alpha, text);
  }

  void DrawSetTextureMaterial(int id, IMaterial *p_material)
  {
    return memory::vfunc<168, void>(this, id, p_material);
  }

private:
  char pad0[0x3A8];
  bool m_bEnableClipping;
};
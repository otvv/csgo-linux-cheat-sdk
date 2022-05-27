//
// csgo sdk
//

#pragma once

#include "../helpers/memory.hpp"

class ITexture;
class IMaterial;
class IMatRenderContext;

using MaterialHandle_t = unsigned short;

#define CREATERENDERTARGETFLAGS_HDR				0x00000001
#define CREATERENDERTARGETFLAGS_AUTOMIPMAP		0x00000002
#define CREATERENDERTARGETFLAGS_UNFILTERABLE_OK 0x00000004

enum CompiledVtfFlags
{
  TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
  TEXTUREFLAGS_TRILINEAR = 0x00000002,
  TEXTUREFLAGS_CLAMPS = 0x00000004,
  TEXTUREFLAGS_CLAMPT = 0x00000008,
  TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
  TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
  TEXTUREFLAGS_PWL_CORRECTED = 0x00000040,
  TEXTUREFLAGS_NORMAL = 0x00000080,
  TEXTUREFLAGS_NOMIP = 0x00000100,
  TEXTUREFLAGS_NOLOD = 0x00000200,
  TEXTUREFLAGS_ALL_MIPS = 0x00000400,
  TEXTUREFLAGS_PROCEDURAL = 0x00000800,
  TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
  TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,
  TEXTUREFLAGS_ENVMAP = 0x00004000,
  TEXTUREFLAGS_RENDERTARGET = 0x00008000,
  TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
  TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
  TEXTUREFLAGS_SINGLECOPY = 0x00040000,
  TEXTUREFLAGS_PRE_SRGB = 0x00080000,
  TEXTUREFLAGS_UNUSED_00100000 = 0x00100000,
  TEXTUREFLAGS_UNUSED_00200000 = 0x00200000,
  TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,
  TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,
  TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,
  TEXTUREFLAGS_CLAMPU = 0x02000000,
  TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,
  TEXTUREFLAGS_SSBUMP = 0x08000000,
  TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,
  TEXTUREFLAGS_BORDER = 0x20000000,
  TEXTUREFLAGS_UNUSED_40000000 = 0x40000000,
  TEXTUREFLAGS_UNUSED_80000000 = 0x80000000
};

enum ImageFormat
{
  IMAGE_FORMAT_UNKNOWN = -1,
  IMAGE_FORMAT_RGBA8888 = 0,
  IMAGE_FORMAT_ABGR8888,
  IMAGE_FORMAT_RGB888,
  IMAGE_FORMAT_BGR888,
  IMAGE_FORMAT_RGB565,
  IMAGE_FORMAT_I8,
  IMAGE_FORMAT_IA88,
  IMAGE_FORMAT_P8,
  IMAGE_FORMAT_A8,
  IMAGE_FORMAT_RGB888_BLUESCREEN,
  IMAGE_FORMAT_BGR888_BLUESCREEN,
  IMAGE_FORMAT_ARGB8888,
  IMAGE_FORMAT_BGRA8888,
  IMAGE_FORMAT_DXT1,
  IMAGE_FORMAT_DXT3,
  IMAGE_FORMAT_DXT5,
  IMAGE_FORMAT_BGRX8888,
  IMAGE_FORMAT_BGR565,
  IMAGE_FORMAT_BGRX5551,
  IMAGE_FORMAT_BGRA4444,
  IMAGE_FORMAT_DXT1_ONEBITALPHA,
  IMAGE_FORMAT_BGRA5551,
  IMAGE_FORMAT_UV88,
  IMAGE_FORMAT_UVWQ8888,
  IMAGE_FORMAT_RGBA16161616F,
  IMAGE_FORMAT_RGBA16161616,
  IMAGE_FORMAT_UVLX8888,
  IMAGE_FORMAT_R32F,
  IMAGE_FORMAT_RGB323232F,
  IMAGE_FORMAT_RGBA32323232F,
  IMAGE_FORMAT_NV_DST16,
  IMAGE_FORMAT_NV_DST24,
  IMAGE_FORMAT_NV_INTZ,
  IMAGE_FORMAT_NV_RAWZ,
  IMAGE_FORMAT_ATI_DST16,
  IMAGE_FORMAT_ATI_DST24,
  IMAGE_FORMAT_NV_NULL,
  IMAGE_FORMAT_ATI2N,
  IMAGE_FORMAT_ATI1N,
  IMAGE_FORMAT_DXT1_RUNTIME,
  IMAGE_FORMAT_DXT5_RUNTIME,
  NUM_IMAGE_FORMATS
};

enum RenderTargetSizeMode_t
{
  RT_SIZE_NO_CHANGE = 0,
  RT_SIZE_DEFAULT = 1,
  RT_SIZE_PICMIP = 2,
  RT_SIZE_HDR = 3,
  RT_SIZE_FULL_FRAME_BUFFER = 4,
  RT_SIZE_OFFSCREEN = 5,
  RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6,
  RT_SIZE_REPLAY_SCREENSHOT = 7,
  RT_SIZE_LITERAL = 8
};

enum MaterialRenderTargetDepth_t
{
  MATERIAL_RT_DEPTH_SHARED = 0x0,
  MATERIAL_RT_DEPTH_SEPARATE = 0x1,
  MATERIAL_RT_DEPTH_NONE = 0x2,
  MATERIAL_RT_DEPTH_ONLY = 0x3,
};

class IMaterialSystem
{
public:
  void IsGameStarted(bool state) { m_bGameStarted = state; }

  ImageFormat GetBackBufferFormat()
  {
    return memory::vfunc<36, ImageFormat>(this);
  }

  IMaterial *CreateMaterial(const char *material_name, void *key_values)
  {
    return memory::vfunc<83, IMaterial *>(this, material_name, key_values);
  }

  IMaterial *FindMaterial(const char *material_name, const char *texture_group, bool complain = true, const char *complain_prefix = nullptr)
  {
    return memory::vfunc<84, IMaterial *>(this, material_name, texture_group, complain, complain_prefix);
  }

  IMaterial *GetMaterial(MaterialHandle_t handle)
  {
    return memory::vfunc<89, IMaterial *>(this, handle);
  }

  ITexture *FindTexture(const char *texture, const char *texture_group, bool complain = true, int additional_creation_flags = 0x0)
  {
    return memory::vfunc<91, ITexture *>(this, texture, texture_group, complain, additional_creation_flags);
  }

  void BeginRenderTargetAllocation()
  {
    return memory::vfunc<94, void>(this);
  }

  void EndRenderTargetAllocation()
  {
    return memory::vfunc<95, void>(this);
  }

  ITexture *CreateNamedRenderTargetTextureEx(const char *name, int w, int h, int size_mode, int format, int depth, unsigned int texture_flags, unsigned int render_target_flags)
  {
    return memory::vfunc<97, ITexture *>(this, name, w, h, size_mode, format, depth, texture_flags, render_target_flags);
  }

  IMatRenderContext *GetRenderContext()
  {
    return memory::vfunc<115, IMatRenderContext *>(this);
  }

  ITexture *CreateFullFrameRenderTarget(const char *name)
  {
    return CreateNamedRenderTargetTextureEx(name, 1, 1, RT_SIZE_FULL_FRAME_BUFFER, GetBackBufferFormat(), MATERIAL_RT_DEPTH_SHARED, TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT, CREATERENDERTARGETFLAGS_HDR);
  }

  void ForceBeginRenderTargetAllocation()
  {
    bool old_state = m_bGameStarted;
    m_bGameStarted = false;
    BeginRenderTargetAllocation();
    m_bGameStarted = old_state;
  }

  void ForceEndRenderTargetAllocation()
  {
    bool old_state = m_bGameStarted;
    m_bGameStarted = false;
    EndRenderTargetAllocation();
    m_bGameStarted = old_state;
  }

private:
  char pad0[0x32A4];
  bool m_bGameStarted;
};
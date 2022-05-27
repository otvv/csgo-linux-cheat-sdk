//
// csgo sdk
//

#pragma once

#include "../helpers/matrix.hpp"
#include "../helpers/memory.hpp"
#include "../helpers/vector.hpp"

class CGameTrace;

using trace_t = CGameTrace;

#define CONTENTS_EMPTY 0
#define CONTENTS_SOLID 0x1
#define CONTENTS_WINDOW 0x2
#define CONTENTS_GRATE 0x8
#define CONTENTS_OPAQUE 0x80
#define CONTENTS_IGNORE_NODRAW_OPAQUE 0x2000
#define CONTENTS_MOVEABLE 0x4000
#define CONTENTS_DEBRIS 0x4000000
#define CONTENTS_MONSTER 0x2000000
#define CONTENTS_HITBOX 0x40000000

#define MASK_ALL 0xFFFFFFFF
#define MASK_SHOT_BRUSHONLY (CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_DEBRIS)
#define MASK_SHOT (CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTER | CONTENTS_WINDOW | CONTENTS_DEBRIS | CONTENTS_HITBOX)
#define MASK_SOLID (CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_MONSTER | CONTENTS_GRATE)
#define MASK_SHOT_HULL (CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTER | CONTENTS_WINDOW | CONTENTS_DEBRIS | CONTENTS_GRATE)
#define MASK_NPC_WORLD_STATIC (CONTENTS_SOLID | CONTENTS_WINDOW | CONTENTS_MONSTER | CONTENTS_GRATE)
#define MASK_OPAQUE (CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_OPAQUE)
#define MASK_OPAQUE_AND_NPCS (MASK_OPAQUE | CONTENTS_MONSTER)
#define MASK_VISIBLE_AND_NPCS (MASK_OPAQUE_AND_NPCS | CONTENTS_IGNORE_NODRAW_OPAQUE)

enum TraceType_t
{
  TRACE_EVERYTHING = 0,
  TRACE_WORLD_ONLY,
  TRACE_ENTITIES_ONLY,
  TRACE_EVERYTHING_FILTER_PROPS,
};

struct cplane_t
{
  vec3_t normal;
  float dist;
  unsigned char type;
  unsigned char signbits;
  unsigned char pad[2];
};

struct csurface_t
{
  const char *name;
  short surface_props;
  unsigned short flags;
};

struct Ray_t
{
  vec3_aligned_t start;
  vec3_aligned_t delta;
  vec3_aligned_t start_offset;
  vec3_aligned_t extents;

  const matrix_t<float, 3, 4> *world_axis_transform;

  bool is_ray;
  bool is_swept;

  Ray_t() : world_axis_transform(nullptr) {}

  void Init(const vec3_t &_start, const vec3_t &_end)
  {
    delta = vec3_aligned_t(_end - _start);
    is_swept = (delta.length_3d() != 0);
    extents.m_x = extents.m_y = extents.m_z = 0.0f;
    world_axis_transform = nullptr;
    is_ray = true;
    start_offset.m_x = start_offset.m_y = start_offset.m_z = 0.0f;
    start = _start;
  }
};

class CGameTrace
{
public:
  vec3_t start_position;
  vec3_t end_position;
  cplane_t plane;
  float fraction;
  int contents;
  unsigned int displacement_flags;
  bool all_solid;
  bool start_solid;
  float fraction_left_solid;
  csurface_t surface;
  int hit_group;
  short physicsbone;
  unsigned short world_surface_index;
  void *entity;
  int hitbox;
};

class ITraceFilter
{
public:
  virtual bool ShouldHitEntity(void *entity) = 0;
  virtual TraceType_t GetTraceType() const = 0;
};

class CTraceFilterWorldOnly : public ITraceFilter
{
public:
  bool ShouldHitEntity(void *entity) override
  {
    return !(entity == p_skip);
  }

  TraceType_t GetTraceType() const override
  {
    return TraceType_t::TRACE_EVERYTHING;
  }

  void *p_skip;
};

class IEngineTrace
{
public:
  int GetPointContents(const vec3_t &vector_abs_position, int contents_mask = MASK_ALL, void **ppentity = nullptr)
  {
    return memory::vfunc<0, int>(this, &vector_abs_position, contents_mask, ppentity); // 1
  }

  void ClipRayToEntity(const Ray_t &ray, unsigned int mask, void *entity, trace_t *trace)
  {
    return memory::vfunc<3, void>(this, &ray, mask, entity, trace);
  }

  void TraceRay(const Ray_t &ray, unsigned int mask, ITraceFilter *filter, trace_t *trace)
  {
    return memory::vfunc<5, void>(this, &ray, mask, filter, trace);
  }
};
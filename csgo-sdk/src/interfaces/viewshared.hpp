//
// csgo sdk
//

#pragma once

#include "../helpers/vector.hpp"

enum ClearFlags_t
{
  VIEW_CLEAR_COLOR = 0x1,
  VIEW_CLEAR_DEPTH = 0x2,
  VIEW_CLEAR_FULL_TARGET = 0x4,
  VIEW_NO_DRAW = 0x8,
  VIEW_CLEAR_OBEY_STENCIL = 0x10,
  VIEW_CLEAR_STENCIL = 0x20,
};

enum RenderViewInfo_t
{
  VIEW_UNSPECIFIED = 0,
  VIEW_DRAW_VIEWMODEL = (1 << 0),
  VIEW_DRAWHUD = (1 << 1),
  VIEW_SUPPRESS_MONITOR_RENDERING = (1 << 2),
};

enum MotionBlurMode_t
{
  MOTION_BLUR_DISABLE = 1,
  MOTION_BLUR_GAME = 2,
  MOTION_BLUR_SFM = 3
};

class CViewSetup
{
public:
  int x;
  int unscaled_x;
  int y;
  int unscaled_y;
  int width;
  int unscaled_width;
  int height;
  int unscaled_height;
  char pad0[0x98];
  float fov;
  float fov_viewmodel;
  vec3_t origin;
  vec3_t angles;
  float z_near;
  float z_far;
  float z_near_viewmodel;
  float z_far_viewmodel;
  float aspect_ratio;
  float near_blur_depth;
  float near_focus_depth;
  float far_focus_depth;
  float far_blur_depth;
  float near_blur_radius;
  float far_blur_radius;
  float dof_quality;
  MotionBlurMode_t motion_blur_mode;
  float shutter_time;
  vec3_t shutter_open_position;
  angl_t shutter_open_angles;
  vec3_t shutter_close_position;
  angl_t shutter_close_angles;
  float off_center_top;
  float off_center_bottom;
  float off_center_left;
  float off_center_right;
  bool off_center : 1;
  bool render_to_subrect_of_larger_screen : 1;
  bool do_bloom_and_tone_mapping : 1;
  bool do_depth_of_field : 1;
  bool hdr_target : 1;
  bool draw_world_normal : 1;
  bool cull_front_faces : 1;
  bool cache_full_scene_state : 1;
  bool csm_view : 1;
};
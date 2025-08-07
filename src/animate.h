#pragma once

#ifdef _WIN32
#ifdef ANIM_EXPORTS
#define ANIM_API __declspec(dllexport)
#else
#define ANIM_API __declspec(dllimport)
#endif
#else
#define ANIM_API
#endif

ANIM_API void animate_lerp(double* value, double start, double end, float d);
ANIM_API void animate_sin(double* value, double amplitude, double frequency,
                          float delta_time);

ANIM_API void animate_easein(double* value, double d);

ANIM_API void animate_cubic_bezier(double* value, double x0, double y0,
                                   double x1, double y1, double d);

ANIM_API void animate_back(double* value, double strength, double speed,
                           double d);

ANIM_API void animate_2d_circle(double* x, double* y, double radius,
                                double frequency, double t);

ANIM_API void animate_rect_squish(float* top_left_x, float* top_left_y,
                                  float* width, float* height, double amount,
                                  double t);

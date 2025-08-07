#include <math.h>

#include "animate.h"

#define M_PI 3.14159265358979323846

static double clamp_double(double value, double min_val, double max_val) {
  if (value < min_val) {
    return min_val;
  } else if (value > max_val) {
    return max_val;
  } else {
    return value;
  }
}

void animate_lerp(double* value, double start, double end, float d) {
  d = clamp_double(d, 0, 1);

  *value = start + (end - start) * d;
}

void animate_sin(double* value, double amplitude, double frequency,
                 float time) {
  double phase_shift = 0.0;
  *value = amplitude * sin(2 * M_PI * frequency * time + phase_shift);
}

void animate_cos(double* value, double amplitude, double frequency,
                 float time) {
  double phase_shift = 0.0;
  *value = amplitude * cos(2 * M_PI * frequency * time + phase_shift);
}

void animate_sin_d(double* value, double amplitude, double frequency,
                   float delta_time) {
  static double time = 0;

  animate_sin(value, amplitude, frequency, time);

  time += delta_time;
}

void animate_easein(double* value, double d) {
  d = clamp_double(d, 0, 1);
  *value = (*value) + (d * d);
}

void animate_cubic_bezier(double* value, double x0, double y0, double x1,
                          double y1, double d) {
  d = clamp_double(d, 0, 1);
  x0 = clamp_double(x0, 0, 1);
  y0 = clamp_double(y0, 0, 1);
  x1 = clamp_double(x1, 0, 1);
  y1 = clamp_double(y1, 0, 1);

  double px0;
  animate_lerp(&px0, 0, x0, d);
  double py0;
  animate_lerp(&py0, 0, y0, d);

  double px1;
  animate_lerp(&px1, x0, x1, d);
  double py1;
  animate_lerp(&py1, x0, x1, d);

  double px2;
  animate_lerp(&px2, x1, 1, d);
  double py2;
  animate_lerp(&py2, y1, 1, d);

  double ppx0;
  animate_lerp(&ppx0, px0, px1, d);
  double ppy0;
  animate_lerp(&ppy0, py0, py1, d);

  double ppx1;
  animate_lerp(&ppx1, px1, px2, d);
  double ppy1;
  animate_lerp(&ppy1, py1, py2, d);

  double pppx1;
  animate_lerp(&pppx1, ppx0, ppx1, d);
  double pppy1;
  animate_lerp(&pppy1, ppy0, ppy1, d);

  *value = pppy1;
}

void animate_back(double* value, double strength, double speed, double d) {
  *value = (((d * d) / speed) - d) * strength;
}

void animate_2d_circle(double* x, double* y, double radius, double frequency,
                       double t) {
  animate_sin(x, radius, frequency, t);
  animate_cos(y, radius, frequency, t);
}

void animate_rect_squish(float* top_left_x, float* top_left_y, float* width,
                         float* height, double amount, double t) {
  t = clamp_double(t, 0, 1);

  double percent_width = (*width) * (amount * t);
  double percent_height = (*height) * (amount * t);

  *top_left_x = (*top_left_x) + percent_width;
  *top_left_y = (*top_left_y) + percent_height;

  *width = (*width) - percent_width;
  *height = (*height) - percent_height;
}

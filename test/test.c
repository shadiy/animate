#include <math.h>
#include <stdio.h>

#include "../libs/raylib-5.5_win64_msvc16/include/raylib.h"
#include "../src/animate.h"

int main() {
  InitWindow(1024, 764, "test");

  double lerp = 0;
  double sin_value = 0;

  double time = 0;

  double easein = 0;
  double cubic = 0;
  double back = 0;

  double circle_x = 0;
  double circle_y = 0;

  Rectangle rect;
  rect.x = 280;
  rect.y = 100;
  rect.width = 70;
  rect.height = 70;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    double delta_time = GetFrameTime();
    time += delta_time;

    animate_lerp(&lerp, 0, 100, time);
    // printf("Lerp %f\n", lerp);
    DrawRectangle(0, lerp, 30, 30, WHITE);

    animate_sin(&sin_value, 100, 1, time);
    // printf("Sin %f\n", sin_value);
    DrawRectangle(40, sin_value + 50, 30, 30, WHITE);

    animate_easein(&easein, time);
    // printf("Easein %f\n", sin_value);
    DrawRectangle(80, easein, 30, 30, WHITE);

    animate_cubic_bezier(&cubic, 0.1, 0.1, 1, 1, time);
    // printf("Cubic %f\n", sin_value);
    DrawRectangle(130, cubic * 300, 30, 30, WHITE);

    animate_back(&back, 10, 2, time);
    // printf("Back %f\n", sin_value);
    DrawRectangle(170, (back * 100) + 300, 30, 30, WHITE);

    animate_2d_circle(&circle_x, &circle_y, 40, 2, time);
    // printf("Circle %f %f\n", circle_x, circle_y);
    DrawRectangle(circle_x + 240, circle_y + 100, 30, 30, WHITE);

    animate_rect_squish(&rect.x, &rect.y, &rect.width, &rect.height, 0.4, time);
    // printf("Circle %f %f\n", circle_x, circle_y);
    DrawRectangleRec(rect, WHITE);

    if (3 - 1 % (int)(time + 1) == 0) {
      rect.x = 280;
      rect.y = 100;
      rect.width = 70;
      rect.height = 70;
    }

    EndDrawing();

    if (time > 10) {
      time = 0;
    }
  }
}

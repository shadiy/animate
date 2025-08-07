@echo off

md build 2>nul

clang -g -DANIM_EXPORTS -shared src/animate.c -o animate.dll -Wl,/implib:animate.lib

clang -g test/test.c -o test.exe -Llibs/raylib-5.5_win64_msvc16/lib -lraylib.lib -lgdi32 -lwinmm -luser32 -lshell32 -lmsvcrt -lanimate.lib -Wl,/ENTRY:mainCRTStartup

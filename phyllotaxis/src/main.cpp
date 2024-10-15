#include "include/raylib.h"
#include "include/raymath.h"

const int screenWidth = 800;
const int screenHeight = 800;

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Phyllotaxis");
    SetTargetFPS(60);

    int n = 0;
    int c = 8;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        float angle = n * 137.1;
        float radius = c * sqrt(n);

        float x = radius * cos(angle) + screenWidth / 2;
        float y = radius * sin(angle) + screenHeight / 2;

        Color color = {
            static_cast<unsigned char>(fmod(angle - radius, 256)),
            static_cast<unsigned char>(fmod(angle * RAD2DEG, 256)),
            static_cast<unsigned char>(fmod(angle + RAD2DEG, 256)),
            255};

        DrawEllipse(x, y, 4, 4, color);
        n++;

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

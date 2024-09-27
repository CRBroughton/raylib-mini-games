#include "include/raylib.h"
#include "include/boundary.cpp"
#include "include/ray.cpp"
#include "include/particle.cpp"

int main(void)
{
    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Raycasting Demo");

    SetTargetFPS(60);

    Vector2 startPoint = {100, 100};
    Vector2 endPoint = {200, 300};
    Boundary boundary(startPoint, endPoint);
    Particle particle({screenWidth / 2, screenHeight / 2});

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        boundary.Draw();
        particle.show();
        particle.look(boundary);
        Vector2 mousePosition = GetMousePosition();

        particle.update(mousePosition);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

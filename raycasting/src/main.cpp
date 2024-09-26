#include "include/raylib.h"
#include "include/boundary.cpp"
#include "include/ray.cpp"

int main(void)
{
    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Raycasting Demo");

    SetTargetFPS(60);

    Vector2 startPoint = {300, 100};
    Vector2 endPoint = {300, 300};
    Boundary boundary(startPoint, endPoint);
    CustomRay ray({100, 200});

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Vector2 point = ray.Cast(boundary);

        boundary.Draw();
        ray.Draw();
        Vector2 mousePosition = GetMousePosition();
        ray.SetDirection(mousePosition.x, mousePosition.y);

        if (point.x != 0 && point.y != 0)
        {
            DrawEllipse(point.x, point.y, 8, 8, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

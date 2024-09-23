#include "include/raylib.h"
#include "include/boundary.cpp"
#include "include/ray.cpp"

int main(void) {
    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Raycasting Demo");

    SetTargetFPS(60);

    Vector2 startPoint = { 300, 100 };
    Vector2 endPoint = { 300, 300 };
    Boundary boundary(startPoint, endPoint);
    CustomRay ray({100, 200});
    bool point = ray.cast(boundary);

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        boundary.Draw();
        ray.Draw();

        // if (point) {
        //     DrawEllipse(point.x, point.y, 8, 8, BLACK);
        // }

        TraceLog(LOG_INFO, "The value of myBool is: %s", point ? "true" : "false");
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

#include "include/raylib.h"
#include "include/boundary.cpp"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raycasting Demo");

    SetTargetFPS(60);

    Vector2 startPoint = { 100, 100 };
    Vector2 endPoint = { 700, 350 };
    Boundary boundary(startPoint, endPoint);

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        boundary.Draw();
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

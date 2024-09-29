#include "include/raylib.h"
#include <cmath>

const int screenWidth = 400;
const int screenHeight = 400;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Menger Sponge Fractal");
    SetTargetFPS(60);

    Camera camera = {0};
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float cameraRotationSpeed = 0.01f;
    float radius = 10.0f;
    float angle = 0.0f;

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    DisableCursor();
    while (!WindowShouldClose())
    {

        angle += cameraRotationSpeed;
        if (angle > 2 * PI)
        {
            angle = 0.0f; // Reset the angle after a full rotation
        }

        camera.position.x = radius * cos(angle);
        camera.position.z = radius * sin(angle);
        camera.position.y = 5.0f;
        // UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

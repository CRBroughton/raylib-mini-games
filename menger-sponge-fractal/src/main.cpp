#include "include/raylib.h"
#include "include/box.cpp"
#include <cmath>
#include <vector>

const int screenWidth = 400;
const int screenHeight = 400;

template <typename T>
void addAll(std::vector<T> &destination, const std::vector<T> &source)
{
    destination.insert(destination.end(), source.begin(), source.end());
}

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

    DisableCursor();

    std::vector<Box> sponge;
    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    Box initialBox(cubePosition, 4.0f);
    sponge.push_back(initialBox);

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

        for (Box b : sponge)
        {
            b.show();
        };
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {

            std::vector<Box> nextGeneration;
            for (Box box : sponge)
            {
                std::vector<Box> newBoxes = box.generate();
                addAll(nextGeneration, newBoxes);
            }
            sponge = nextGeneration;
        }

        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

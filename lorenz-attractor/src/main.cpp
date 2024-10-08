#include "include/raylib.h"
#include "include/utils.h"
#include <vector>
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 800;

float x = 0.1f;
float y = 0;
float z = 0;

const float a = 10.0f;
const float b = 28.0f;
const float c = 8.0f / 3.0f;
const float scale = 1.0f;

std::vector<Vector3> points;
std::vector<Color> colors;

float timeElapsed = 0.0f;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Lorenz Attractor");
    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 0.0f, 150.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    float cameraAngle = 0.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        timeElapsed += dt;

        float dx = (a * (y - x)) * dt;
        float dy = (x * (b - z) - y) * dt;
        float dz = (x * y - c * z) * dt;

        x = x + dx;
        y = y + dy;
        z = z + dz;

        points.push_back({x, y, z});

        float hue = fmod(timeElapsed * 200.0f, 360.0f);
        Color colour = ColorFromHSV(hue, 1.0f, 1.0f);
        colors.push_back(colour);

        Vector3 center = {0.0f, 0.0f, 0.0f};
        for (const Vector3 &point : points)
        {
            center.x += point.x;
            center.y += point.y;
            center.z += point.z;
        }

        center.x /= points.size();
        center.y /= points.size();
        center.z /= points.size();
        camera.target = center;
        cameraAngle += dt * 0.5f;

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        const float cameraRadius = 150.0f;
        const float rotationSpeed = 0.5f;
        UpdateCameraRelativeToCenter(&camera, center, cameraRadius, rotationSpeed);

        // protect OOB
        int pointCount = points.size();
        const float lineThickness = 0.2f;
        if (pointCount > 1)
        {
            for (int i = 1; i < pointCount; i++)
            {

                DrawThickLine3D(points[i - 1], points[i], lineThickness, colors[i - 1]);
            }
        }

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

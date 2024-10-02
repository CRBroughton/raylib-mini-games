#include "include/raylib.h"
#include "include/box.cpp"
#include <cmath>
#include <vector>

const int screenWidth = 1000;
const int screenHeight = 1000;

template <typename T>
void addAll(std::vector<T> &destination, const std::vector<T> &source)
{
    destination.insert(destination.end(), source.begin(), source.end());
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Menger Sponge Fractal");
    SetTargetFPS(60);

    Shader shader = LoadShader("src/shaders/vs.glsl", "src/shaders/fs.glsl");

    Camera camera = {0};
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float cameraRotationSpeed = 0.01f;
    float radius = 10.0f;
    float angleX = 0.0f;
    // Slight diff on the Y angle, should help avoid singularity at the poles
    float angleY = 0.345f;

    Model cubeModel = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    cubeModel.materials[0].shader = shader;

    // Set ambient color for the shader
    int ambientColorLoc = GetShaderLocation(shader, "ambientColor");
    Vector3 ambientColor = {5.0f, 2.0f, 10.0f};
    SetShaderValue(shader, ambientColorLoc, &ambientColor, SHADER_UNIFORM_VEC3);

    // DisableCursor();

    std::vector<Box> sponge;
    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    Box initialBox(cubePosition, 4.0f);
    sponge.push_back(initialBox);

    while (!WindowShouldClose())
    {

        angleX += cameraRotationSpeed;
        angleY += cameraRotationSpeed * 0.5f; // Rotate slower on the Y axis
        if (angleX > 2 * PI)
        {
            angleX = 0.0f;
        }
        if (angleY > 2 * PI)
        {
            angleY = 0.0f;
        }

        camera.position.x = radius * cos(angleY) * sin(angleX);
        camera.position.z = radius * cos(angleY) * cos(angleX);
        camera.position.y = radius * sin(angleY);
        // UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        // Pass the current camera position to the shader
        int cameraPosLoc = GetShaderLocation(shader, "cameraPosition");
        SetShaderValue(shader, cameraPosLoc, &camera.position, SHADER_UNIFORM_VEC3);

        for (Box b : sponge)
        {
            b.show(cubeModel);
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

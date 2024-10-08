#include "include/raylib.h"
#include "include/boundary.cpp"
#include "include/ray.cpp"
#include "include/particle.cpp"
#include <vector>

const int screenWidth = 400;
const int screenHeight = 400;

Vector2 GetRandomCoord()
{
    float x = static_cast<float>(GetRandomValue(0, screenWidth));
    float y = static_cast<float>(GetRandomValue(0, screenHeight));
    return {x, y};
};

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Raycasting Demo");
    SetTargetFPS(60);

    std::vector<Boundary> boundaries;

    for (size_t i = 0; i < 5; i++)
    {
        float randomWidth = static_cast<float>(GetRandomValue(5, 20));
        float randomHeight = static_cast<float>(GetRandomValue(5, 20));
        Boundary boundary({GetRandomCoord(), GetRandomCoord()});
        boundaries.push_back(boundary);
    }

    Particle particle({screenWidth / 2, screenHeight / 2});

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        for (Boundary &boundary : boundaries)
        {
            boundary.Draw();
        };
        particle.show();
        particle.look(boundaries);
        Vector2 mousePosition = GetMousePosition();
        particle.update(mousePosition);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

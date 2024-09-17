#include <raylib.h>
#include <iostream>
#include <cmath>
#include <rlgl.h>

void branch(
    int branchLength,
    float angle) {
    DrawLine(0, 0, 0, - branchLength, {255, 255, 255, 255});
    rlTranslatef(0, - branchLength, 0);

    if (branchLength > 4) {
        // Reposition the origin hack via push matrix
        // & translate func
        rlPushMatrix();
        rlRotatef(angle, 0, 0, 1);
        // Recursive draw
        branch(branchLength * 0.67, angle);
        rlPopMatrix();
        rlPushMatrix();
        rlRotatef(-angle, 0, 0, 1);
        branch(branchLength * 0.67, angle);
        rlPopMatrix();
    }
}

int main(void) {
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Fractal Trees");

    int FPS = 15;
    int branchLength = 100;
    float angle = 45.0f;
    SetTargetFPS(FPS);


    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);


        // Move initial origin
        rlPushMatrix();
        rlTranslatef(WINDOW_WIDTH / 2, WINDOW_HEIGHT, 0);
        
        branch(branchLength, angle);

        rlPopMatrix();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

#include <raylib.h>
#include <iostream>
#include <cmath>
#include <rlgl.h>

void branch(
    int branchLength) {
    DrawLine(0, 0, 0, - branchLength, {255, 255, 255, 255});
    rlTranslatef(0, - branchLength, 0);

    if (branchLength > 4) {
        // Reposition the origin hack via push matrix
        // & translate func
        rlPushMatrix();
        rlRotatef(45, 0, 0, 1);
        // Recursive draw
        branch(branchLength * 0.67);
        rlPopMatrix();
        rlPushMatrix();
        rlRotatef(-45, 0, 0, 1);
        branch(branchLength * 0.67);
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
    SetTargetFPS(FPS);


    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);


        // Move initial origin
        rlPushMatrix();
        rlTranslatef(WINDOW_WIDTH / 2, WINDOW_HEIGHT, 0);
        
        branch(branchLength);

        rlPopMatrix();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

#include <raylib.h>
#include <iostream>
#include <rlgl.h>

void branch(
    int WINDOW_WIDTH,
    int WINDOW_HEIGHT,
    int branchLength) {
    DrawLine(0, 0, 0, - branchLength, {255, 255, 255, 255});
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

        // Reposition the origin hack via push matrix
        // & translate func
        rlPushMatrix();
        rlTranslatef(WINDOW_WIDTH / 2, WINDOW_HEIGHT, 0);

        branch(WINDOW_WIDTH, WINDOW_HEIGHT, branchLength);
        
        rlPopMatrix();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

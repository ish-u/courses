#include <iostream>
#include <graphics.h>
using namespace std;

void DDA(int x1, int y1, int x2, int y2)
{
    // finding the slope, dx and dy
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    float m = (float)dy / dx;

    // calculating the steps - number of pixels that our algorithm need to write
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    /*
        increment can be calulated by
            =>  inc_x = dx/abs(steps)
            =>  inc_y = dy/abs(steps)
    */
    float inc_x = (float)dx / steps;
    float inc_y = (float)dy / steps;

    // drawing the pixel for steps time
    float x = x1;
    float y = y1;
    putpixel((int)x, (int)y, 2);

    for (int i = 0; i < steps; i++)
    {
        // cout << x << "\t" << y << "\n";
        x += inc_x;
        y += inc_y;
        putpixel((int)x, (int)y, 1);
    }
    x += inc_x;
    y += inc_y;
    putpixel((int)x, (int)y, 2);

    return;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Drawing a Rectangle with Diagonals using DDA function
    // horizontal line
    DDA(50, 50, 50, 400);
    DDA(50, 400, 400, 400);

    // vertical line
    DDA(50, 50, 400, 50);
    DDA(400, 50, 400, 400);

    // positive slope
    DDA(50, 50, 400, 400);

    // negative slope
    DDA(400, 50, 50, 400);

    getch();
    closegraph();
    return 0;
}
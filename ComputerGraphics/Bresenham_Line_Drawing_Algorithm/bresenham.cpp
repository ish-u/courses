#include <iostream>
#include <graphics.h>
using namespace std;

// Bresenham's Line Drawing Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
void bresenham(int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    float slope = (float)dy / (float)dx;

    if (slope > 1 || slope < 0)
    {
        cout << "Slope should be b/w 0 and 1 : "
             << slope
             << "\n";
        return;
    }
    else
    {
        cout << "Slope : " << slope;
    }
    cout << "\n";

    int d = 2 * dy - dx;        // Initial Value of d
    int incrE = 2 * dy;         // Increment used for move to E
    int incrNE = 2 * (dy - dx); // Increment used for move to NE
    int x = x0;
    int y = y0;

    // writing the first pixel
    putpixel(x, y, color);

    // chosing the next pixel based on Bresenham's algorithm and writing it on the Screen
    while (x <= x1)
    {
        // cout << x << "\t" << y << "\n";
        // If d <= 0 we choose the E pixel and set 'd_new = d_old + a' (a = 2*dy)
        // If d > 0 we choose the NE pixel and set 'd_new = d_old + a + b' (a = 2*dy - 2*dx)
        // We increment 'x' in both cases (assuming the slope is b/w 0 and 1) and increment 'y' only for NE case
        if (d <= 0)
        {
            d += incrE;
        }
        else
        {
            d += incrNE;
            y++;
        }
        x++;
        putpixel(x, y, color);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Drawing line with Slopes - 0 , 0.25, 0.5, 0.75, 1
    bresenham(5, 8, 200, 700, 1);
    bresenham(90, 8, 5, 110, 2);
    bresenham(50, 50, 450, 450, 3);
    bresenham(50, 50, 450, 350, 4);
    bresenham(50, 50, 450, 250, 5);
    bresenham(50, 50, 450, 150, 6);
    bresenham(50, 50, 450, 50, 7);
    bresenham(50, 50, 50, 450, 8);

    getch();
    closegraph();
    return 0;
}
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

// Bresenham's Circle Drawing Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
// We utilise the 8-way symmetry of the Circle to plot the points using the points of Second Octant - (x,y)
void plotPoints(int x, int y, int h, int k, int color)
{
    // We transalte the circle to center (h,k) while plotting
    putpixel(x + h, y + k, color);
    putpixel(y + h, x + k, color);
    putpixel(y + h, -x + k, color);
    putpixel(x + h, -y + k, color);
    putpixel(-x + h, -y + k, color);
    putpixel(-y + h, -x + k, color);
    putpixel(-y + h, x + k, color);
    putpixel(-x + h, y + k, color);
}

// finding all the points of the 2nd Octant using the Bresenham's Midpoint Circle Drawing Algorithm
// (h,k) is the center of the circle
void bresenhamCircle(int h, int k, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    // Ploting all the 8 symmetric points for (x,y) in 8 octants
    plotPoints(x, y, h, k, color);

    while (y > x)
    {
        // cout << x << "\t" << y << "\n";
        // If d < 0  we select the E pixel and d_new = d + 2*x + 3
        // If d >= 0  we select the SE pixel and d_new = d + 2*x - 2*y + 5
        // We increment 'x' in both the cases and decremet 'y' when we select the SE pixel
        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plotPoints(x, y, h, k, color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Drawing Concentric Circle from 0 to 200 in increment of 10
    int i = 0;
    while (i < 200)
    {
        bresenhamCircle(320, 240, i, rand() % 16 + 1);
        i += 10;
    }

    getch();
    closegraph();
    return 0;
}
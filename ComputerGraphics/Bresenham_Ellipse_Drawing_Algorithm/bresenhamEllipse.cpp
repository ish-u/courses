#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

// Bresenham's Ellipse Drawing Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
// We utilise the 4-way symmetry of the Ellipse to plot the points using the points of Second Octant - (x,y)
void plotPoints(int x, int y, int h, int k, int color)
{
    // We transalte the circle to center (h,k) while plotting
    putpixel(x + h, y + k, color);
    putpixel(x + h, -y + k, color);
    putpixel(-x + h, -y + k, color);
    putpixel(-x + h, y + k, color);
    // putpixel(y + h, x + k, color);
    // putpixel(y + h, -x + k, color);
    // putpixel(-y + h, -x + k, color);
    // putpixel(-y + h, x + k, color);
}

// finding all the points of the 2nd Octant using the Bresenham's Midpoint Ellipse Drawing Algorithm
// (h,k) is the center of the Ellipse
void bresenhamEllipse(int h, int k, int a, int b, int color)
{
    int x = 0;
    int y = b;
    double d1 = b * b - (a * a * b) + (0.25 * a * a);

    // Ploting all the 4 symmetric points for (x,y) in 4 quadrant
    plotPoints(x, y, h, k, color);

    // Plotting points for Region 1
    while ((a * a * (y - 0.5)) > b * b * (x + 1))
    {
        if (d1 < 0)
        {
            d1 += b * b * (2 * x + 3); // Select E
        }
        else
        {
            d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2); // Select SE
            y--;
        }
        x++;
        cout << x << "\t" << y << "\t" << d1 << "\n";
        plotPoints(x, y, h, k, color);
    }

    // Plotting points for Region 2
    double d2 = b * b * (x + 0.5) * (x + 0.5) + (a * a) * (y - 1) * (y - 1) - a * a * b * b;
    while (y > 0)
    {
        if (d2 < 0)
        {
            d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3); // Select SE
            x++;
        }
        else
        {
            d2 += a * a * (-2 * y + 3); // Select S
        }
        y--;
        cout << x << "\t" << y << "\t" << d1 << "\n";
        plotPoints(x, y, h, k, color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Axis
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());

    // Drawing Concentric Circle from 0 to 200 in increment of 10
    int i = 0;
    // while (i < 200)
    // {
    //     // Axis
    //     bresenhamEllipse(getmaxx() / 2, getmaxy() / 2, 50 + i, 5 + i, rand() % 16 + 1);
    //     i += 10;
    // }

    bresenhamEllipse(getmaxx() / 2, getmaxy() / 2, 8, 6, rand() % 16 + 1);

    getch();
    closegraph();
    return 0;
}
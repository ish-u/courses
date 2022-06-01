#include <iostream>
#include <graphics.h>
using namespace std;

// Bresenham's Line Drawing Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
void bresenham(int x0, int y0, int x1, int y1, int color)
{
    // swapping P0(x0,y0) and P1(x1,y1) if P0 > P1
    // We are always drawing lines from LEFT to RIGHT
    if (x0 > x1)
    {
        int X = x0;
        int Y = y0;
        x0 = x1;
        y0 = y1;
        x1 = X;
        y1 = Y;
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    float slope = (float)dy / (float)dx;

    // Gradual Positive
    if (slope <= 1 && slope >= 0)
    {
        int d = 2 * dy - dx;        // Initial Value of d
        int incrE = 2 * dy;         // Increment used for move to E
        int incrNE = 2 * (dy - dx); // Increment used for move to NE
        int x = x0;
        int y = y0;

        // writing the first pixel
        putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);

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
            putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);
            // cout << x << "\t" << y << "\t" << d << "\n";
        }
        cout << "Slope : " << slope;
    }

    // Gradual Negative
    else if (slope >= -1 && slope <= 0)
    {
        int d = 2 * dy + dx;        // Initial Value of d
        int incrE = 2 * dy;         // Increment used for move to E
        int incrSE = 2 * (dy + dx); // Increment used for move to SE
        int x = x0;
        int y = y0;

        // writing the first pixel
        putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);

        // chosing the next pixel based on Bresenham's algorithm and writing it on the Screen
        while (x <= x1)
        {
            // cout << x << "\t" << y << "\n";
            // If d > 0 we choose the E pixel and set 'd_new = d_old + a' (a = 2*dy)
            // If d <= 0 we choose the SE pixel and set 'd_new = d_old + a + b' (a = 2*dy + 2*dx)
            // We increment 'x' in both cases (assuming the slope is b/w 0 and -1) and decrement 'y' only for SE case
            if (d <= 0)
            {
                d += incrSE;
                y--;
            }
            else
            {
                d += incrE;
            }
            x++;
            putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);
            // cout << x << "\t" << y << "\t" << d << "\n";
        }
        cout << "Slope : " << slope;
    }

    // Steep Negative
    else if (slope < -1)
    {
        int d = dy + 2 * dx;        // Initial Value of d
        int incrS = 2 * dx;         // Increment used for move to S
        int incrSE = 2 * (dy + dx); // Increment used for move to SE
        int x = x0;
        int y = y0;
        // writing the first pixel
        putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);

        // chosing the next pixel based on Bresenham's algorithm and writing it on the Screen
        while (x <= x1 && y >= y1)
        {
            // If d <= 0 we choose the S pixel and set 'd_new = d_old + a' (a = 2*dx)
            // If d > 0 we choose the SE pixel and set 'd_new = d_old + a + b' (a = 2*dy + 2*dx)
            // We decrement 'y' in both cases and increment 'x' only for S`E case
            if (d <= 0)
            {
                d += incrS;
            }
            else
            {
                d += incrSE;
                x++;
            }
            y--;
            putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);
            // cout << x << "\t" << y << "\t" << d << "\n";
        }
        cout << "Slope : " << slope;
    }

    // Steep Positive
    else if (slope > 1)
    {
        int d = dy - 2 * dx;        // Initial Value of d
        int incrN = -2 * dx;        // Increment used for move to E
        int incrNE = 2 * (dy - dx); // Increment used for move to SE
        int x = x0;
        int y = y0;
        // writing the first pixel
        putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);

        // chosing the next pixel based on Bresenham's algorithm and writing it on the Screen
        while (x <= x1 && y <= y1)
        {
            // cout << d << "\n";
            // If d > 0 we choose the E pixel and set 'd_new = d_old + a' (a = 2*dx)
            // If d <= 0 we choose the NE pixel and set 'd_new = d_old + a + b' (a = 2*dy - 2*dx)
            // We increment 'y' in both cases and increment 'x' only for NE case
            if (d <= 0)
            {
                d += incrNE;
                x++;
            }
            else
            {
                d += incrN;
            }
            y++;
            putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);
            // cout << x << "\t" << y << "\t" << d << "\n";
        }
        cout << "Slope : " << slope;
    }
    cout << "\n";
}
int main()
{
    int gd = DETECT, gm;
    initwindow(800, 600);

    // Drawing the Co-Ordinate Axis
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());

    // Drawing Lines in 4 Quadrants
    // Quadrant 1
    bresenham(50, 50, 450, 650, 1);
    bresenham(50, 50, 450, 550, 2);
    bresenham(50, 50, 450, 450, 3);
    bresenham(50, 50, 450, 350, 4);
    bresenham(50, 50, 450, 250, 5);
    bresenham(50, 50, 450, 150, 6);
    bresenham(50, 50, 450, 50, 7);
    bresenham(50, 50, 50, 450, 8);

    // Quadrant 2
    bresenham(-50, 50, -450, 650, 1);
    bresenham(-50, 50, -450, 550, 2);
    bresenham(-50, 50, -450, 450, 3);
    bresenham(-50, 50, -450, 350, 4);
    bresenham(-50, 50, -450, 250, 5);
    bresenham(-50, 50, -450, 150, 6);
    bresenham(-50, 50, -450, 50, 7);
    bresenham(-50, 50, -50, 450, 8);

    // Quadrant 3
    bresenham(-50, -50, -450, -650, 1);
    bresenham(-50, -50, -450, -550, 2);
    bresenham(-50, -50, -450, -450, 3);
    bresenham(-50, -50, -450, -350, 4);
    bresenham(-50, -50, -450, -250, 5);
    bresenham(-50, -50, -450, -150, 6);
    bresenham(-50, -50, -450, -50, 7);
    bresenham(-50, -50, -50, -450, 8);

    // Quadrant 4
    bresenham(50, -50, 450, -650, 1);
    bresenham(50, -50, 450, -550, 2);
    bresenham(50, -50, 450, -450, 3);
    bresenham(50, -50, 450, -350, 4);
    bresenham(50, -50, 450, -250, 5);
    bresenham(50, -50, 450, -150, 6);
    bresenham(50, -50, 450, -50, 7);
    bresenham(50, -50, 50, -450, 8);

    // Lines parallel to Co-Ordinate Axis
    bresenham(-450, 30, 450, 30, 9);
    bresenham(-450, -30, 450, -30, 9);
    bresenham(30, 450, 30, -450, 9);
    bresenham(-30, 450, -30, -450, 9);

    getch();
    closegraph();
    return 0;
}
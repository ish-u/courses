#include <iostream>
#include <graphics.h>
using namespace std;

const double xmin = 40;
const double xmax = 600;
const double ymin = 50;
const double ymax = 430;

typedef unsigned int outcode;
enum
{
    TOP = 1,
    BOTTOM = 2,
    RIGHT = 4,
    LEFT = 8
};
// Cohen-Sutherland Line Clipping Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
// Compute the Outcode given the co-ordinates of the points (x,y)
outcode CompOutCode(double x, double y)
{
    outcode code = 0;
    if (y > ymax)
    {
        code |= TOP;
    }
    else if (y < ymin)
    {
        code |= BOTTOM;
    }

    if (x > xmax)
    {
        code |= RIGHT;
    }
    else if (x < xmin)
    {
        code |= LEFT;
    }

    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{

    // Compute the Outcode of P0(x0,y0) and P1(x1,y1)
    outcode outcode0 = CompOutCode(x0, y0);
    outcode outcode1 = CompOutCode(x1, y1);
    outcode outcodeOut;

    boolean accept = FALSE;
    boolean done = FALSE;

    do
    {
        // Case 1 - Trivially Accept
        if (!(outcode0 | outcode1))
        {
            accept = TRUE;
            done = TRUE;
        }
        // Case 2 - Trivially Reject
        else if (outcode0 & outcode1)
        {
            done = TRUE;
        }
        // Case 3 - Partially Accept/Reject
        else
        {
            // new point
            double x, y;
            // Pick one of the Point which is outside the clip rectangle
            outcodeOut = outcode0 ? outcode0 : outcode1;
            // Calculating the intersecting point as both the test failed
            // Using - y = y0 + slope*(x - x0), x = x0 + (1/slope)*(y - y0)
            // TOP
            if (outcodeOut & TOP)
            {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            // BOTTOM
            else if (outcodeOut & BOTTOM)
            {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            // LEFT
            else if (outcodeOut & LEFT)
            {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }
            // RIGHT
            else
            {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }

            // Move/Change the Outdside Point to the Intersecting Point
            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = CompOutCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = CompOutCode(x1, y1);
            }
        }

        // cout << x0 << ", " << y0 << "\t" << x1 << ", " << y1 << "\t" << outcode0 << "\t" << outcode1 << "\t" << outcodeOut << "\n";

    } while (done == FALSE);

    // Draw the Clipped Line
    if (accept == TRUE)
    {
        line(x0, -1 * y0 + getmaxy(), x1, -1 * y1 + getmaxy());
    }

    // cout << x0 << ", " << y0 << "\t" << x1 << ", " << y1 << "\n";
}

// Draw the Clip Rectangle
void drawClipRectangle()
{
    line(xmin, -1 * ymin + getmaxy(), xmin, -1 * ymax + getmaxy());
    line(xmin, -1 * ymax + getmaxy(), xmax, -1 * ymax + getmaxy());
    line(xmax, -1 * ymax + getmaxy(), xmax, -1 * ymin + getmaxy());
    line(xmax, -1 * ymin + getmaxy(), xmin, -1 * ymin + getmaxy());
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Drawing the Unlcliped Lines
    char textBefore[50] = "Before Clipping";
    outtextxy(getmaxx() / 2 - 75, 5, textBefore);
    drawClipRectangle();
    line(0, -1 * 0 + getmaxy(), 100, -1 * 100 + getmaxy());
    line(-300, -1 * -10 + getmaxy(), 700, -1 * 350 + getmaxy());
    line(30, -1 * 50 + getmaxy(), 100, -1 * 451 + getmaxy());
    line(150, -1 * 80 + getmaxy(), 342, -1 * 243 + getmaxy());
    line(450, -1 * -80 + getmaxy(), 450, -1 * 700 + getmaxy());
    line(620, -1 * -80 + getmaxy(), 630, -1 * 700 + getmaxy());

    system("pause");
    cleardevice();

    // Drawing the Clipped Lines
    char textAfter[50] = "After Clipping";
    outtextxy(getmaxx() / 2 - 75, 5, textAfter);
    drawClipRectangle();
    CohenSutherlandLineClipAndDraw(0, 0, 100, 100);
    CohenSutherlandLineClipAndDraw(-300, -10, 700, 350);
    CohenSutherlandLineClipAndDraw(30, 50, 100, 451);
    CohenSutherlandLineClipAndDraw(150, 80, 342, 243);
    CohenSutherlandLineClipAndDraw(450, -80, 450, 700);
    CohenSutherlandLineClipAndDraw(650, -80, 650, 700);

    getch();
    closegraph();
    return 0;
}
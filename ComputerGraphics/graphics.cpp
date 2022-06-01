#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;
const float PI = 4 * atanf(1);

void breshn(int x1, int y1, int x2, int y2, int color)
{
    if (x2 > x1)
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        // Decision Variable
        int d = 2 * dy - dx;
        // Increment Condition in East and North East Direction
        int incE = 2 * dy;
        int incNE = 2 * (dy - dx);
        // Initial Points
        int x = x1;
        int y = y1;
        // Test Condition -> while x1 < x2
        while (x <= x2)
        {
            // Choose E
            if (d <= 0)
            {
                d += incE;
            }
            // Choose NE
            else
            {
                d += incNE;
                y++;
            }
            x++;
            putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, color);
            cout << x << "\t" << y << "\n";
        }
    }
}

void drawCirclePoints(int x, int y)
{
    // plotting the Circle Point using 8 way symmetry
    putpixel(x + getmaxx() / 2, -1 * y + getmaxy() / 2, 15);
    putpixel(-x + getmaxx() / 2, -1 * y + getmaxy() / 2, 15);
    putpixel(x + getmaxx() / 2, -1 * -y + getmaxy() / 2, 15);
    putpixel(-x + getmaxx() / 2, -1 * -y + getmaxy() / 2, 15);
    putpixel(y + getmaxx() / 2, -1 * x + getmaxy() / 2, 15);
    putpixel(-y + getmaxx() / 2, -1 * x + getmaxy() / 2, 15);
    putpixel(y + getmaxx() / 2, -1 * -x + getmaxy() / 2, 15);
    putpixel(-y + getmaxx() / 2, -1 * -x + getmaxy() / 2, 15);
}

void drawCircle(int radius)
{
    // Decision Variable
    int d = 1 - radius;
    // Starting Points
    int x = 0;
    int y = radius;
    // plotting the Ciricle
    while (y > x)
    {
        // if d < 0 -> point inside Circle -> Choose E
        if (d < 0)
        {
            d += 2 * x + 3;
        }
        // if d > 0 -> point outside Circle -> Choose SE
        else
        {
            d += (2 * x - 2 * y) + 5;
            y--;
        }
        x++;
        // drawCirclePoints(x, y);
        drawCirclePoints(x, y);
    }
}

// Line Clipping Cohen Sutherland

int xmin = 40;
int ymin = 40;
int xmax = 440;
int ymax = 440;

// outcode
typedef unsigned int outcode;
enum
{
    TOP = 1,
    BOTTOM = 2,
    RIGHT = 4,
    LEFT = 8
};

outcode computeOutCode(int x0, int y0)
{
    outcode out = 0;
    if (y0 > ymax)
    {
        out |= TOP;
    }
    else if (y0 < ymin)
    {
        out |= BOTTOM;
    }
    if (x0 > xmax)
    {
        out |= RIGHT;
    }
    else if (x0 < xmin)
    {
        out |= LEFT;
    }
    return out;
}

void clipLine(int x0, int y0, int x1, int y1)
{

    // Calculating Outcode P0 and P1
    boolean ACCEPT = FALSE;
    boolean DONE = FALSE;
    outcode P0 = computeOutCode(x0, y0);
    outcode P1 = computeOutCode(x1, y1);

    // iteratively cutting the line till we find the clipped line
    do
    {

        // Case 1 - Trivial Acceptance
        if (!(P0 | P1))
        {
            DONE = TRUE;
            ACCEPT = TRUE;
        }
        // Case 2 - Trivial Rejection
        else if (P0 & P1)
        {
            DONE = TRUE;
        }
        // Case 3 - Partial Acceptance
        else
        {
            outcode out = P0 ? P0 : P1;
            int x;
            int y;
            // Clip Top
            if (out & TOP)
            {
                x = x0 + (x1 - x0) * ((ymax - y0) / (y1 - y0));
                y = ymax;
            }
            // Clip Bottom
            else if (out & BOTTOM)
            {
                x = x0 + (x1 - x0) * ((ymin - y0) / (y1 - y0));
                y = ymin;
            }
            // Clip Right
            else if (out & RIGHT)
            {
                x = xmax;
                y = y0 + (y1 - y0) * ((xmax - x0) / (x1 - x0));
            }
            // Clip Left
            else if (out & LEFT)
            {
                x = xmin;
                y = y0 + (y1 - y0) * ((xmin - x0) / (x1 - x0));
            }

            // setting the clipped point to P0 or P1
            if (out == P0)
            {
                x0 = x;
                y0 = y;
                P0 = computeOutCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                P1 = computeOutCode(x1, y1);
            }
        }
    } while (DONE == FALSE);

    // Drawing the Line
    if (ACCEPT == TRUE)
    {
        line(x0, -1 * y0 + getmaxy(), x1, -1 * y1 + getmaxy());
    }
}

void drawClipRectangle()
{
    line(xmin, -1 * ymin + getmaxy(), xmax, -1 * ymin + getmaxy());
    line(xmax, -1 * ymin + getmaxy(), xmax, -1 * ymax + getmaxy());
    line(xmax, -1 * ymax + getmaxy(), xmin, -1 * ymax + getmaxy());
    line(xmin, -1 * ymax + getmaxy(), xmin, -1 * ymin + getmaxy());
}

// Matrix Class
class Matrix
{
public:
    int r;
    int c;
    float **m;
    // constructor
    Matrix(int r, int c)
    {
        this->r = r;
        this->c = c;
        // initializing row vectors
        m = new float *[r];
        // filling column vectors
        for (int i = 0; i < r; i++)
        {
            m[i] = new float[c];
        }
        // filling with zeros
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                m[i][j] = 0;
            }
        }
    }
    // Copy constructor
    Matrix(const Matrix &matrix)
    {
        this->r = matrix.r;
        this->c = matrix.c;

        // filling with old matrix
        this->m = new float *[r];
        for (int i = 0; i < r; i++)
        {
            m[i] = new float[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                m[i][j] = matrix.m[i][j];
            }
        }
    }
    // Display
    void display()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << m[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    // Multiply
    Matrix operator*(Matrix &B)
    {
        if (this->c != B.r)
        {
            cout << "BAD\n";
            return Matrix(0, 0);
        }
        // multiply
        Matrix toReturn(this->r, B.c);
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < B.c; j++)
            {
                for (int k = 0; k < this->c; k++)
                {
                    toReturn.m[i][j] += this->m[i][k] * B.m[k][j];
                }
            }
        }

        return toReturn;
    }

    void draw(Matrix object)
    {
        // Drawing the Shape
        for (int i = 0; i < object.r - 1; i++)
        {
            line(object.m[i][0] + getmaxx() / 2, -1 * object.m[i][1] + getmaxy() / 2, object.m[i + 1][0] + getmaxx() / 2, -1 * object.m[i + 1][1] + getmaxy() / 2);
        }
        line(object.m[object.r - 1][0] + getmaxx() / 2, -1 * object.m[object.r - 1][1] + getmaxy() / 2, object.m[0][0] + getmaxx() / 2, -1 * object.m[0][1] + getmaxy() / 2);
    }
};

int main()
{
    int gd = DETECT, gm;
    initwindow(800, 600);

    breshn(1, 1, 8, 5, 1);
    // Matrix A(3, 4);
    // for (int i = 0; i < A.r; i++)
    // {
    //     A.m[i][i] = 10;
    // }
    // A.display();
    // Matrix B(4, 3);
    // for (int i = 0; i < A.r; i++)
    // {
    //     B.m[i][i] = 20;
    // }
    // B.display();

    // Matrix C = A * B;
    // C.display();
    // Drawing the Co-Ordinate Axis
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    // int x0 = 20;
    // int y0 = 20;
    // int x1 = 400;
    // int y1 = 400;
    // line(x0, -1 * y0 + getmaxy(), x1, -1 * y1 + getmaxy());
    // drawClipRectangle();
    // system("pause");
    // cleardevice();
    // drawClipRectangle();
    // clipLine(x0, y0, x1, y1);

    // int x1, x2, y1, y2;
    // cout << "Enter x1:";
    // cin >> x1;
    // cout << "Enter x2:";
    // cin >> x2;
    // cout << "Enter y1:";
    // cin >> y1;
    // cout << "Enter y2:";
    // cin >> y2;

    // breshn(x1, x2, y1, y2, 15);

    // drawCircle(100);

    // 2-D
    Matrix object(4, 3);
    object.m[0][0] = 0;
    object.m[0][1] = 0;
    object.m[0][2] = 1;

    object.m[1][0] = 100;
    object.m[1][1] = 0;
    object.m[1][2] = 1;

    object.m[2][0] = 100;
    object.m[2][1] = 100;
    object.m[2][2] = 1;

    object.m[3][0] = 0;
    object.m[3][1] = 100;
    object.m[3][2] = 1;

    // displaying the co-ordinate matrix
    object.display();
    // object.draw(object);

    // Scale by 2

    // Matrix requiredObject = object * scaleMatrix;
    // requiredObject.display();
    // object.draw(requiredObject);

    // // rotate by 45
    // for (int i = 0; i < 720; i++)
    // {
    //     // line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    //     // line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    //     Matrix rotateMatrix(3, 3);
    //     rotateMatrix.m[0][0] = cos(i * PI / 180);
    //     rotateMatrix.m[0][1] = sin(i * PI / 180);
    //     rotateMatrix.m[1][0] = -1 * sin(i * PI / 180);
    //     rotateMatrix.m[1][1] = cos(i * PI / 180);
    //     rotateMatrix.m[2][2] = 1;

    //     Matrix translateMatrix(3, 3);
    //     translateMatrix.m[0][0] = 1;
    //     translateMatrix.m[1][1] = 1;

    //     translateMatrix.m[2][0] = i / 10;
    //     translateMatrix.m[2][1] = i / 10;
    //     translateMatrix.m[2][2] = 1;

    //     Matrix requiredObject = object * translateMatrix * rotateMatrix;
    //     object.draw(requiredObject);
    //     delay(10);
    //     // cleardevice();
    // }

    // Drawing Hermite Curve
    Matrix hermiteBasis(4, 4);
    hermiteBasis.m[0][0] = 2;
    hermiteBasis.m[0][1] = -2;
    hermiteBasis.m[0][2] = 1;
    hermiteBasis.m[0][3] = 1;

    hermiteBasis.m[1][0] = -3;
    hermiteBasis.m[1][1] = 3;
    hermiteBasis.m[1][2] = -2;
    hermiteBasis.m[1][3] = -1;

    hermiteBasis.m[2][0] = 0;
    hermiteBasis.m[2][1] = 0;
    hermiteBasis.m[2][2] = 1;
    hermiteBasis.m[2][3] = 0;

    hermiteBasis.m[3][0] = 1;
    hermiteBasis.m[3][1] = 0;
    hermiteBasis.m[3][2] = 0;
    hermiteBasis.m[3][3] = 0;

    // Points and Tangents
    Matrix geometricMatrix(4, 4);
    geometricMatrix.m[0][0] = 100;
    geometricMatrix.m[0][1] = 100;
    geometricMatrix.m[0][2] = 0;
    geometricMatrix.m[0][3] = 1;

    geometricMatrix.m[1][0] = 300;
    geometricMatrix.m[1][1] = 200;
    geometricMatrix.m[1][2] = 0;
    geometricMatrix.m[1][3] = 1;

    geometricMatrix.m[2][0] = 200;
    geometricMatrix.m[2][1] = 0;
    geometricMatrix.m[2][2] = 0;
    geometricMatrix.m[2][3] = 1;

    geometricMatrix.m[3][0] = 0;
    geometricMatrix.m[3][1] = -200;
    geometricMatrix.m[3][2] = 0;
    geometricMatrix.m[3][3] = 1;

    // setting t and selecting number of points
    double t = 0;
    int n = 10;
    double d = 1.0 / n;

    Matrix coOrdinates(n + 1, 3);
    Matrix T(1, 4);
    Matrix MH = hermiteBasis * geometricMatrix;
    for (int i = 0; i < n + 1; i++)
    {
        T.m[0][0] = t * t * t;
        T.m[0][1] = t * t;
        T.m[0][2] = t;
        T.m[0][3] = 1;

        Matrix coOrdinate = T * MH;
        coOrdinates.m[i][0] = coOrdinate.m[0][0];
        coOrdinates.m[i][1] = coOrdinate.m[0][1];
        coOrdinates.m[i][2] = coOrdinate.m[0][2];
        coOrdinates.m[i][3] = 1;

        t += d;
    }
    coOrdinates.display();
    for (int i = 0; i < n - 1; i++)
    {
        line(coOrdinates.m[i][0] + getmaxx() / 2, -1 * coOrdinates.m[i][1] + getmaxy() / 2, coOrdinates.m[i + 1][0] + getmaxx() / 2, -1 * coOrdinates.m[i + 1][1] + getmaxy() / 2);
    }

    // Drawing Bezier Curve
    Matrix bezierBasis(4, 4);
    bezierBasis.m[0][0] = 2;
    bezierBasis.m[0][1] = -2;
    bezierBasis.m[0][2] = 1;
    bezierBasis.m[0][3] = 1;

    bezierBasis.m[1][0] = -3;
    bezierBasis.m[1][1] = 3;
    bezierBasis.m[1][2] = -2;
    bezierBasis.m[1][3] = -1;

    bezierBasis.m[2][0] = 0;
    bezierBasis.m[2][1] = 0;
    bezierBasis.m[2][2] = 1;
    bezierBasis.m[2][3] = 0;

    bezierBasis.m[3][0] = 1;
    bezierBasis.m[3][1] = 0;
    bezierBasis.m[3][2] = 0;
    bezierBasis.m[3][3] = 0;

    // Geometric Matrix
    geometricMatrix.m[0][0] = -100;
    geometricMatrix.m[0][1] = -100;
    geometricMatrix.m[0][2] = 0;
    geometricMatrix.m[0][3] = 1;

    geometricMatrix.m[1][0] = 300;
    geometricMatrix.m[1][1] = 200;
    geometricMatrix.m[1][2] = 0;
    geometricMatrix.m[1][3] = 1;

    geometricMatrix.m[2][0] = 200;
    geometricMatrix.m[2][1] = 100;
    geometricMatrix.m[2][2] = 0;
    geometricMatrix.m[2][3] = 1;

    geometricMatrix.m[3][0] = 2000;
    geometricMatrix.m[3][1] = -200;
    geometricMatrix.m[3][2] = 0;
    geometricMatrix.m[3][3] = 1;

    t = 0;
    MH = bezierBasis * geometricMatrix;
    MH.display();
    for (int i = 0; i < n + 1; i++)
    {
        T.m[0][0] = t * t * t;
        T.m[0][1] = t * t;
        T.m[0][2] = t;
        T.m[0][3] = 1;

        Matrix coOrdinate = T * MH;
        coOrdinates.m[i][0] = coOrdinate.m[0][0];
        coOrdinates.m[i][1] = coOrdinate.m[0][1];
        coOrdinates.m[i][2] = coOrdinate.m[0][2];
        coOrdinates.m[i][3] = 1;

        t += d;
    }
    coOrdinates.display();
    for (int i = 0; i < n - 1; i++)
    {
        line(coOrdinates.m[i][0] + getmaxx() / 2, -1 * coOrdinates.m[i][1] + getmaxy() / 2, coOrdinates.m[i + 1][0] + getmaxx() / 2, -1 * coOrdinates.m[i + 1][1] + getmaxy() / 2);
    }
    getch();
    closegraph();
    return 0;
}
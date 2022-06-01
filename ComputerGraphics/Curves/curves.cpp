#include <graphics.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
#include "matrix.h"

char fileName[100] = "";
// CONSTANTS
const double PI = 4 * atanf(1);
const float THETA = 15 * (PI / 180);
const float PHI = 30 * (PI / 180);

void sortCoOrdinates(int *poly, int numberOfCoOrdinates)
{
    float centroidX = 0;
    float centroidY = 0;

    double thetaPoly[numberOfCoOrdinates];

    for (int i = 0; i < (numberOfCoOrdinates * 2); i++)
    {
        if (i % 2 == 0)
        {
            centroidX += poly[i];
        }
        else if (i % 2 != 0)
        {
            centroidY += poly[i];
        }
    }

    centroidX /= numberOfCoOrdinates;
    centroidY /= numberOfCoOrdinates;

    // cout << "( " << centroidX << " ," << centroidY << " )" << endl;

    for (int i = 0; i < (numberOfCoOrdinates * 2); i = i + 2)
    {
        thetaPoly[i / 2] = atan2((poly[i + 1] - centroidY), (poly[i] - centroidX));
    }

    // sorting the co-ordinates
    int i, j;
    float key;
    for (i = 1; i < numberOfCoOrdinates; i++)
    {
        key = thetaPoly[i];
        float x = poly[2 * i];
        float y = poly[(2 * i) + 1];
        j = i - 1;

        while (j >= 0 && thetaPoly[j] > key)
        {
            thetaPoly[j + 1] = thetaPoly[j];
            poly[2 * (j + 1)] = poly[2 * j];
            poly[(2 * (j + 1)) + 1] = poly[(2 * j) + 1];
            j = j - 1;
        }
        thetaPoly[j + 1] = key;
        poly[2 * (j + 1)] = x;
        poly[(2 * (j + 1)) + 1] = y;
    }
}

void drawAxis(float theta = THETA, float phi = PHI)
{
    Matrix *Lines = new Matrix(6, 4);
    Lines->m[0][0] = 2000;
    Lines->m[0][1] = 0;
    Lines->m[0][2] = 0;

    Lines->m[1][0] = -2000,
    Lines->m[1][1] = 0;
    Lines->m[1][2] = 0;

    Lines->m[2][0] = 0;
    Lines->m[2][1] = 2000;
    Lines->m[2][2] = 0;

    Lines->m[3][0] = 0;
    Lines->m[3][1] = -2000;
    Lines->m[3][2] = 0;

    Lines->m[4][0] = 0;
    Lines->m[4][1] = 0;
    Lines->m[4][2] = 2000;

    Lines->m[5][0] = 0,
    Lines->m[5][1] = 0;
    Lines->m[5][2] = -2000;

    Matrix pZ = getProjectionZ();

    Matrix rotateX = getRotationMatrixCounterClockwiseX(theta);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(phi);
    Matrix requiredMatrix = (*(Lines)) * rotateY * rotateX * pZ;
    // requiredMatrix.display();
    int c = 1;
    for (int i = 0; i < Lines->r; i++)
    {
        switch (i)
        {
        case 0:
            setcolor(4);
            break;
        case 2:
            setcolor(2);
            break;
        case 4:
            setcolor(1);
            break;
        default:
            break;
        }
        line(getmaxx() / 2, getmaxy() / 2, requiredMatrix.m[i][0] + (getmaxx() / 2), -1 * requiredMatrix.m[i][1] + (getmaxy() / 2));
    }
    setcolor(15);

    delete Lines;
}

// HERMITE CURVE
// =========================================
class HermiteCurve
{
private:
    Matrix *geometricMatrix;
    int n; // Number of Co-Ordinates to Find

public:
    // Constructor
    HermiteCurve(int n = 4)
    {
        this->n = n;
        this->geometricMatrix = new Matrix(4, 4, 0);
        this->geometricMatrix->m[0][3] = 1;
        this->geometricMatrix->m[1][3] = 1;
        this->geometricMatrix->m[2][3] = 1;
        this->geometricMatrix->m[3][3] = 1;
    }
    // Destructor
    ~HermiteCurve()
    {
        delete this->geometricMatrix;
    }
    // take input
    void input();
    // display
    void display();
};

void HermiteCurve ::input()
{
    cout << "Enter the Hermite Geometric Matrix rowise : \n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Row " << i << " : ";
        for (int j = 0; j < 3; j++)
        {
            cin >> this->geometricMatrix->m[i][j];
        }
    }
}

void HermiteCurve::display()
{
    cleardevice();

    // Hermite Basis and Coefficient Matrix
    Matrix hermiteBasis = getBasisHermiteCurve();
    Matrix coefficientMatrix = hermiteBasis * (*(this->geometricMatrix));

    // Calculating the Co-Ordinates
    Matrix coOrdinates(this->n + 1, 4);
    double d = 1.0 / this->n;
    double t = 0;
    Matrix T(1, 4, 0);
    for (int i = 0; i < this->n + 1; i++)
    {
        T.m[0][0] = t * t * t;
        T.m[0][1] = t * t;
        T.m[0][2] = t;
        T.m[0][3] = 1;

        // T.display();

        Matrix coOrdinate = T * coefficientMatrix;
        coOrdinates.m[i][0] = coOrdinate.m[0][0];
        coOrdinates.m[i][1] = coOrdinate.m[0][1];
        coOrdinates.m[i][2] = coOrdinate.m[0][2];
        coOrdinates.m[i][3] = 1;

        t += d;
    }

    // Axonometric Projection with THETA and PHI
    Matrix pZ = getProjectionZ();
    char text[50 + sizeof(char)] = "";
    // Displaying Angle Information
    outtextxy(20, 20, text);
    sprintf(text, "theta : %d \t", (int)(THETA * 180 / PI));
    outtextxy(20, 40, text);
    sprintf(text, "phi : %d", (int)(PHI * 180 / PI));
    outtextxy(20, 60, text);
    // Axonometric Projection
    Matrix rotateX = getRotationMatrixCounterClockwiseX(THETA);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(PHI);
    Matrix requiredMatrix = coOrdinates * rotateY * rotateX * pZ;

    // display the Axis
    drawAxis();

    // Draw the Curve
    for (int i = 1; i <= this->n; i++)
    {
        // reflect about x-axis
        // transtale to center of window
        line((requiredMatrix.m[i - 1][0]) + getmaxx() / 2, -1 * requiredMatrix.m[i - 1][1] + getmaxy() / 2, (requiredMatrix.m[i][0]) + getmaxx() / 2, -1 * requiredMatrix.m[i][1] + getmaxy() / 2);
    }
    setcolor(3);
    // Save Image
    sprintf(fileName, "Hermite_Curve_%d.bmp", (int)(rand() % 1000) + 1);
    writeimagefile(fileName);
}
// =========================================

// BEZIER CURVE
// =========================================
class BezierCurve
{
private:
    Matrix *geometricMatrix;
    int n; // Number of Co-Ordinates to Find

public:
    // Constructor
    BezierCurve(int n = 4)
    {
        this->n = n;
        this->geometricMatrix = new Matrix(4, 4, 0);
        this->geometricMatrix->m[0][3] = 1;
        this->geometricMatrix->m[1][3] = 1;
        this->geometricMatrix->m[2][3] = 1;
        this->geometricMatrix->m[3][3] = 1;
    }
    // Destructor
    ~BezierCurve()
    {
        delete this->geometricMatrix;
    }
    // take input of Geometric Matrix
    void input();
    // display
    void display();
};

void BezierCurve ::input()
{
    cout << "Enter the Bezier Geometric Matrix rowise : \n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Row " << i << " : ";
        for (int j = 0; j < 3; j++)
        {
            cin >> this->geometricMatrix->m[i][j];
        }
    }
}

void BezierCurve::display()
{
    cleardevice();
    // Bezier Basis and Coefficient Matrix
    Matrix hermiteBasis = getBasisBezierCurve();
    Matrix coefficientMatrix = hermiteBasis * (*(this->geometricMatrix));

    // Calculating the Co-Ordinates
    Matrix coOrdinates(this->n + 1, 4);
    double d = 1.0 / this->n;
    double t = 0;
    Matrix T(1, 4, 0);
    for (int i = 0; i < this->n + 1; i++)
    {
        T.m[0][0] = t * t * t;
        T.m[0][1] = t * t;
        T.m[0][2] = t;
        T.m[0][3] = 1;

        // T.display();

        Matrix coOrdinate = T * coefficientMatrix;
        coOrdinates.m[i][0] = coOrdinate.m[0][0];
        coOrdinates.m[i][1] = coOrdinate.m[0][1];
        coOrdinates.m[i][2] = coOrdinate.m[0][2];
        coOrdinates.m[i][3] = 1;

        t += d;
    }

    // Axonometric Projection with THETA and PHI
    Matrix pZ = getProjectionZ();
    char text[50 + sizeof(char)] = "";
    // Displaying Angle Information
    outtextxy(20, 20, text);
    sprintf(text, "theta : %d \t", (int)(THETA * 180 / PI));
    outtextxy(20, 40, text);
    sprintf(text, "phi : %d", (int)(PHI * 180 / PI));
    outtextxy(20, 60, text);
    // Axonometric Projection
    Matrix rotateX = getRotationMatrixCounterClockwiseX(THETA);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(PHI);
    Matrix requiredMatrix = coOrdinates * rotateY * rotateX * pZ;

    // display the Axis
    drawAxis();

    // Draw the Curve
    for (int i = 1; i <= this->n; i++)
    {
        // reflect about x-axis
        // transtale to center of window
        line((requiredMatrix.m[i - 1][0]) + getmaxx() / 2, -1 * requiredMatrix.m[i - 1][1] + getmaxy() / 2, (requiredMatrix.m[i][0]) + getmaxx() / 2, -1 * requiredMatrix.m[i][1] + getmaxy() / 2);
    }
    setcolor(3);

    // Drawing the Connvex Hull
    Matrix convexHull = *(this->geometricMatrix) * rotateY * rotateX;
    Matrix *convexHullPtr = &convexHull;
    int *poly = new int[(convexHull.r + 1) * 2];
    int k = 0;
    for (int i = 0; i < convexHull.r; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            poly[k++] = convexHull.m[i][j];
        }
    }
    sortCoOrdinates(poly, convexHull.r);
    poly[k++] = poly[0];
    poly[k++] = poly[1];

    for (int i = 0; i < ((convexHull.r + 1) * 2); i++)
    {
        // reflect about x-axis
        poly[i] *= (((i + 1) % 2 == 0) ? -1 : 1);
        // transtale to center of window
        poly[i] += (((i + 1) % 2 != 0) ? getmaxx() / 2 : getmaxy() / 2);
        // cout << poly[i] << "\t";
    }
    // drawing the Convex Hull
    drawpoly(convexHull.r + 1, poly);
    delete[] poly;
    setcolor(15);
    // Save Image
    sprintf(fileName, "Bezier_Curve_%d.bmp", (int)(rand() % 1000) + 1);
    writeimagefile(fileName);
}

// =========================================

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, NULL);
    initwindow(1080, 720);

    HermiteCurve *hCurve = new HermiteCurve(100);
    BezierCurve *bCurve = new BezierCurve(100);

    // Menu
    int flag = 1;
    int option = 0;
    do
    {
        cleardevice();

        cout << "Choose Option\n"
             << "1. Hermite Curve\n"
             << "2. Bezier Curve\n"
             << "3. Exit\n"
             << " : ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 1:
            hCurve->input();
            hCurve->display();
            break;
        case 2:
            bCurve->input();
            bCurve->display();
            break;
        case 3:
            flag = 0;
            cout << "EXITING\n";
            break;
        default:
            cout << "INVALID\n";
            break;
        }

        system("pause");
        system("cls");
    } while (flag);

    closegraph();

    // delete curve objects;
    delete hCurve;
    delete bCurve;
    cout << Matrix::created << "\t" << Matrix::deleted << "\n";

    return 0;
}
#include <iostream>
#include <math.h>
#include <graphics.h>
#include "matrix.h"
using namespace std;
char fileName[100] = "";

const float THETA = 15 * (3.14159265359 / 180);
const float PHI = 30 * (3.14159265359 / 180);
const float PI = 4 * atanf(1);

// Helper Functions for the ThreeDimObject Class
// Draw a Line with Axonometric Projection
void drawLine(Matrix Line, int color = 15, float theta = THETA, float phi = PHI)
{
    Matrix pZ = getProjectionZ();
    Matrix rotateX = getRotationMatrixCounterClockwiseX(theta);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(phi);
    Matrix requiredMatrix = Line * rotateY * rotateX * pZ;
    setcolor(color);
    line(requiredMatrix.m[0][0] + getmaxx() / 2, -1 * requiredMatrix.m[0][1] + getmaxy() / 2, requiredMatrix.m[1][0] + (getmaxx() / 2), -1 * requiredMatrix.m[1][1] + (getmaxy() / 2));
    setcolor(15);
}

// Drawing Co-Ordinate Axis with Oblique Projection
void drawAxisOblique(float alpha, float beta)
{
    // To Draw the Co-Ordinate Axis
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

    // Obtaining the Axis with the necessary transformation
    Matrix pZ = getProjectionZ();
    float f = 1 / tan(beta);
    Matrix oblique = getObliqueProjMatrix(alpha, f);
    Matrix requiredMatrix = (*(Lines)) * oblique * pZ;
    Matrix *requiredMatrixPtr = &requiredMatrix;

    // Drawing the Co-Ordinate Axis
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

// Drawing Co-Ordinate Axis with Perspective Projection
void drawAxisPrespective(float p, float q, float r)
{
    // To Draw the Co-Ordinate Axis
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

    // Obtaining the Axis with the necessary rotations
    Matrix pZ = getProjectionZ();
    Matrix perspective = getPerspectiveProjMatrix(p, q, r);
    Matrix requiredMatrix = (*(Lines)) * perspective * pZ;
    Matrix *requiredMatrixPtr = &requiredMatrix;

    // requiredMatrix.display();
    // Drawing the Co-Ordinate Axis
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

// Drawing Co-Ordinate Axis with Axonometric Projection
void drawAxis(float theta = THETA, float phi = PHI)
{
    // To Draw the Co-Ordinate Axis
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

    // Obtaining the Axis with the necessary rotations
    Matrix pZ = getProjectionZ();
    Matrix rotateX = getRotationMatrixCounterClockwiseX(theta);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(phi);
    Matrix requiredMatrix = (*(Lines)) * rotateY * rotateX * pZ;

    // requiredMatrix.display();
    // Drawing the Co-Ordinate Axis
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

// ThreeDimObject Class
class ThreeDimObject
{

public:
    // Default Constructor
    ThreeDimObject()
    {
        // A CUBE WITH A CORNER CUT
        this->numberOfCoOrdinates = 10;
        this->coOrdinates = new Matrix(10, 4);
        // A
        this->coOrdinates->m[0][0] = 200;
        this->coOrdinates->m[0][1] = 100;
        this->coOrdinates->m[0][2] = 200;
        // B
        this->coOrdinates->m[1][0] = 300;
        this->coOrdinates->m[1][1] = 100;
        this->coOrdinates->m[1][2] = 200;
        // C
        this->coOrdinates->m[2][0] = 300;
        this->coOrdinates->m[2][1] = 150;
        this->coOrdinates->m[2][2] = 200;
        // D
        this->coOrdinates->m[3][0] = 250;
        this->coOrdinates->m[3][1] = 200;
        this->coOrdinates->m[3][2] = 200;
        // E
        this->coOrdinates->m[4][0] = 200;
        this->coOrdinates->m[4][1] = 200;
        this->coOrdinates->m[4][2] = 200;
        // F
        this->coOrdinates->m[5][0] = 200;
        this->coOrdinates->m[5][1] = 100;
        this->coOrdinates->m[5][2] = 100;
        // G
        this->coOrdinates->m[6][0] = 300;
        this->coOrdinates->m[6][1] = 100;
        this->coOrdinates->m[6][2] = 100;
        // H
        this->coOrdinates->m[7][0] = 300;
        this->coOrdinates->m[7][1] = 200;
        this->coOrdinates->m[7][2] = 100;
        // I
        this->coOrdinates->m[8][0] = 200;
        this->coOrdinates->m[8][1] = 200;
        this->coOrdinates->m[8][2] = 100;
        // J
        this->coOrdinates->m[9][0] = 300;
        this->coOrdinates->m[9][1] = 200;
        this->coOrdinates->m[9][2] = 150;

        // filling last row as 1 for Homogenous Co-Ordinates
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            this->coOrdinates->m[i][3] = 1;
        }
        // this->coOrdinates->display();

        // WE WILL USE A ADJACENCY MATRIX TO REPRESENT WHETHER ANY TWO VERTICES (CO-ORDNIATES) ARE CONNECTED OR NOT
        // A,B,C, ... ,J --MAPS TO--> 0,1,2, ... ,9
        this->numberOfFaces = 7;
        this->edges = new Matrix(this->numberOfCoOrdinates, this->numberOfCoOrdinates, 0);
        // A
        this->edges->m[0][1] = 1;
        this->edges->m[0][4] = 1;
        this->edges->m[0][5] = 1;
        // B
        this->edges->m[1][0] = 1;
        this->edges->m[1][2] = 1;
        this->edges->m[1][6] = 1;
        // C
        this->edges->m[2][3] = 1;
        this->edges->m[2][1] = 1;
        this->edges->m[2][9] = 1;
        // D
        this->edges->m[3][2] = 1;
        this->edges->m[3][4] = 1;
        this->edges->m[3][9] = 1;
        // E
        this->edges->m[4][0] = 1;
        this->edges->m[4][3] = 1;
        this->edges->m[4][8] = 1;
        // F
        this->edges->m[5][0] = 1;
        this->edges->m[5][6] = 1;
        this->edges->m[5][8] = 1;
        // G
        this->edges->m[6][1] = 1;
        this->edges->m[6][5] = 1;
        this->edges->m[6][7] = 1;
        // H
        this->edges->m[7][8] = 1;
        this->edges->m[7][9] = 1;
        this->edges->m[7][6] = 1;
        // I
        this->edges->m[8][4] = 1;
        this->edges->m[8][5] = 1;
        this->edges->m[8][7] = 1;
        // J
        this->edges->m[9][2] = 1;
        this->edges->m[9][3] = 1;
        this->edges->m[9][7] = 1;

        char heading[50] = "";
        drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
    }
    // Overloaded Constructor - to use when want to take input of Co-Ordinates of Object/ThreeDimObject
    ThreeDimObject(int numberOfCoOrdinates)
    {
        this->numberOfCoOrdinates = numberOfCoOrdinates;
        if (this->numberOfCoOrdinates <= 0)
        {
            cout << "INVALID\n\n";
            return;
        }

        // taking Co-Ordinate Input
        this->coOrdinates = new Matrix(numberOfCoOrdinates, 4);
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            cout << "Co-Ordinate - " << i + 1 << " -> ";
            for (int j = 0; j < 2; j++)
            {
                cin >> this->coOrdinates->m[i][j];
            }
        }
        // filling last row as 1 for Homogeneous Co-Ordinates
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            this->coOrdinates->m[i][3] = 1;
        }

        // taking edges matrix input
        this->edges = new Matrix(numberOfCoOrdinates, numberOfCoOrdinates, 0);

        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            for (int j = 0; j < numberOfCoOrdinates; j++)
            {
                if (i != j)
                {
                    cout << "Connected - " << i + 1 << " <-> " << j + 1 << " : ";
                    cin >> this->edges->m[i][j];
                }
            }
        }

        // this->coOrdinates->display();
        // this->edges->display();
    }

    // Desctructor
    ~ThreeDimObject()
    {
        delete this->coOrdinates;
        delete this->edges;
    }
    // member function
    void scaling();
    void shearing();
    void reflection();
    void rotation();
    void translation();
    void transformationMatrix();
    void animation();
    void orthographicProjectionDemo();
    void axonometricProjectionDemo();
    void obliqueProjectionDemo();
    void perspectiveProjectionDemo();

private:
    // Data Members
    int numberOfCoOrdinates = 0;
    int numberOfFaces = 0;
    Matrix *coOrdinates;
    Matrix *edges;
    // Member Functions
    void drawShape(Matrix *coOrdinates);
    void convertToHomogenous(Matrix *coOrdinates);
    float *getCentroid(Matrix *coOrdinates);
    void drawOrthographicProjection(Matrix *coOrdinates, float theta, float phi, float ita, char *heading);
    void drawAxonometricProjection(Matrix *coOrdinates, float theta, float phi, char *heading);
    void drawObliqueProjection(Matrix *coOrdinates, float alpha, float beta);
    void drawPerspectiveProjection(Matrix *coOrdinates, float p, float q, float r, char *heading);
};

// To Draw the ThreeDimObject whose Co-Ordinate are in Homogenous Matrix as a "matrix" object
void ThreeDimObject::drawShape(Matrix *matrix)
{
    float **coOrdinates = matrix->m;
    int numberOfCoOrdinates = matrix->r;

    if (numberOfCoOrdinates != this->numberOfCoOrdinates)
    {
        cout << "BAD \n";
        return;
    }

    // cout << "\nDRAWN FIGURE HOMOGENOUS CO_ORDINATES\n";
    // cout << "===================================";
    // matrix->display();
    // cout << "===================================\n\n";

    // DRAWING THE 3-D OBJECT
    for (int i = 0; i < numberOfCoOrdinates; i++)
    {
        for (int j = 0; j < numberOfCoOrdinates; j++)
        {
            if (this->edges->m[i][j] == 1)
            {
                // reflect about x-axis
                // translate to center of window
                line((coOrdinates[i][0]) + getmaxx() / 2, -1 * coOrdinates[i][1] + getmaxy() / 2, (coOrdinates[j][0]) + getmaxx() / 2, -1 * coOrdinates[j][1] + getmaxy() / 2);
            }
        }
    }
}

// Convert the Co-Ordinates to Homogeneous Co-Ordinates of a Matrix Object with h = 1
void ThreeDimObject::convertToHomogenous(Matrix *matrix)
{
    for (int i = 0; i < matrix->r; i++)
    {
        matrix->m[i][0] /= matrix->m[i][3];
        matrix->m[i][1] /= matrix->m[i][3];
        matrix->m[i][3] = 1;
    }
}

// Get Centroid of an Object/ThreeDimObject
float *ThreeDimObject ::getCentroid(Matrix *coOrdinates)
{
    float centroidX = 0;
    float centroidY = 0;
    float centroidZ = 0;

    double thetaPoly[numberOfCoOrdinates];

    for (int i = 0; i < numberOfCoOrdinates; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (j == 0)
            {
                centroidX += coOrdinates->m[i][j];
            }
            else if (j == 1)
            {
                centroidY += coOrdinates->m[i][j];
            }
            else if (j == 2)
            {
                centroidZ += coOrdinates->m[i][j];
            }
        }
    }

    centroidX /= numberOfCoOrdinates;
    centroidY /= numberOfCoOrdinates;
    centroidZ /= numberOfCoOrdinates;
    // cout << centroidX << "\t" << centroidY << "\t" << centroidZ << "\n";
    static float centroid[3];
    centroid[0] = centroidX;
    centroid[1] = centroidY;
    centroid[2] = centroidZ;

    return centroid;
}

// PROJECTIONS

// ORTHOGRAPHIC PROJECTION
// =============================================================
void ThreeDimObject ::drawOrthographicProjection(Matrix *m, float theta, float phi, float ita, char *heading)
{
    float *centroid = getCentroid(m);
    // Creating the Required Transformation Matrices
    Matrix T = getTranslationMatrix(centroid[0], centroid[1], centroid[2]);
    Matrix T_inv = getTranslationMatrix(-1 * centroid[0], -1 * centroid[1], -1 * centroid[2]);
    Matrix pZ = getProjectionZ();
    Matrix rotateX = getRotationMatrixCounterClockwiseX(theta);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(phi);
    Matrix rotateZ = getRotationMatrixCounterClockwiseZ(ita);
    Matrix scaleMatrix = getScaleMatrix(3, 3, 3);
    outtextxy(20, 20, heading);

    // Finding the Transformed Object/ThreeDimObject Co-Ordinates
    Matrix face = (*(m)) * T * rotateX * rotateY * rotateZ * scaleMatrix * pZ;
    Matrix *requiredMatrixPtr = &face;
    this->drawShape(requiredMatrixPtr);
}

void ThreeDimObject::orthographicProjectionDemo()
{
    cleardevice();
    char text[50 + sizeof(char)];
    float theta = 0;
    float phi = 0;
    float ita = 0;

    // FRONT
    sprintf(text, "Orthographic -> FRONT");
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_FRONT.bmp");
    // writeimagefile(fileName);
    cleardevice();

    // RIGHT
    theta = phi = ita = 0;
    sprintf(text, "Orthographic -> RIGHT");
    phi = -90 * (PI / 180);
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_RIGHT.bmp");
    // writeimagefile(fileName);
    cleardevice();

    // TOP
    theta = phi = ita = 0;
    sprintf(text, "Orthographic -> TOP");
    theta = 90 * (PI / 180);
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_TOP.bmp");
    // writeimagefile(fileName);
    cleardevice();

    // BOTTOM
    theta = phi = ita = 0;
    sprintf(text, "Orthographic -> BOTTOM");
    theta = -90 * (PI / 180);
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_BOTTOM.bmp");
    // writeimagefile(fileName);
    cleardevice();

    // REAR
    theta = phi = ita = 0;
    sprintf(text, "Orthographic -> REAR");
    phi = 180 * (PI / 180);
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_REAR.bmp");
    // writeimagefile(fileName);
    cleardevice();

    // LEFT
    theta = phi = ita = 0;
    sprintf(text, "Orthographic -> LEFT");
    phi = 90 * (PI / 180);
    drawOrthographicProjection(this->coOrdinates, theta, phi, ita, text);
    delay(1000);
    // sprintf(fileName, "Orthographics_LEFT.bmp");
    // writeimagefile(fileName);
    cleardevice();
}
// =============================================================

// AXONOMETRIC PROJECTION
// =============================================================
void ThreeDimObject::drawAxonometricProjection(Matrix *m, float theta, float phi, char *heading)
{
    float *centroid = getCentroid(m);
    char text[50 + sizeof(char)];

    outtextxy(20, 20, heading);
    sprintf(text, "theta : %d \t", (int)(theta * 180 / PI));
    outtextxy(20, 40, text);
    sprintf(text, "phi : %d", (int)(phi * 180 / PI));
    outtextxy(20, 60, text);

    Matrix pZ = getProjectionZ();
    Matrix rotateX = getRotationMatrixCounterClockwiseX(theta);
    Matrix rotateY = getRotationMatrixCounterClockwiseY(phi);
    Matrix requiredMatrix = (*(m)) * rotateY * rotateX * pZ;
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawShape(requiredMatrixPtr);
    drawAxis(theta, phi);

    // calculating foreshortening  ratios
    Matrix U(3, 4, 1);
    for (int i = 0; i < 3; i++)
    {
        U.m[i][3] = 1;
    }
    Matrix F = U * rotateY * rotateX * pZ;
    float fx = sqrt(F.m[0][0] * F.m[0][0] + F.m[0][1] * F.m[0][1]);
    float fy = sqrt(F.m[1][0] * F.m[1][0] + F.m[1][1] * F.m[1][1]);
    float fz = sqrt(F.m[2][0] * F.m[2][0] + F.m[2][1] * F.m[2][1]);
    sprintf(text, "fx : %f", fx);
    outtextxy(20, 80, text);
    sprintf(text, "fy : %f", fy);
    outtextxy(20, 100, text);
    sprintf(text, "fz : %f", fz);
    outtextxy(20, 120, text);
}

void ThreeDimObject::axonometricProjectionDemo()
{
    char text[50 + sizeof(char)];
    float theta = 0;
    float phi = 0;

    cleardevice();

    // TRIMETRIC
    // TAKING THE EXAMPLE OF ROTAION IN y-axis FOLLOWED BY x-axis
    sprintf(text, "Axonometric Projection -> Trimetric");
    for (int i = 0; i <= 90; i += 15)
    {
        for (int j = 15; j <= 45; j += 15)
        {
            // Grid Lines
            theta = i * (PI / 180);
            phi = j * (PI / 180);
            drawAxonometricProjection(this->coOrdinates, theta, phi, text);
            delay(1000);
            // sprintf(fileName, "Axonometric_Trimetric_%d_%d.bmp", i, j);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }
    }

    // DIMETRIC
    {
        float fz = 0;
        for (int i = 0; i < 9; i++)
        {
            sprintf(text, "Axonometric Projection -> Dimetric");
            fz = 0.125 * i;
            theta = asin(fz / sqrt(2));
            phi = asin(fz / sqrt(2 - powf(fz, 2)));
            drawAxonometricProjection(this->coOrdinates, theta, phi, text);
            delay(1000);
            // sprintf(fileName, "Axonometric_Dimetric_%d_%d.bmp", i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }
    }
    // ISOMETRIC
    {
        sprintf(text, "Axonometric Projection -> Isometric");

        // (35.26, -45)
        theta = 35.26 * (PI / 180);
        phi = -45 * (PI / 180);
        drawAxonometricProjection(this->coOrdinates, theta, phi, text);
        delay(1000);
        // system("pause");
        // sprintf(fileName, "Axonometric_Isometric_%d_%d.bmp", (int)(theta * (180 / PI)), (int)(phi * (180 / PI)));
        // writeimagefile(fileName);
        cleardevice();

        // (-35.26, -45)
        theta = -35.26 * (PI / 180);
        phi = -45 * (PI / 180);
        drawAxonometricProjection(this->coOrdinates, theta, phi, text);
        delay(1000);
        // sprintf(fileName, "Axonometric_Isometric_%d_%d.bmp", (int)(theta * (180 / PI)), (int)(phi * (180 / PI)));
        // writeimagefile(fileName);
        // system("pause");
        cleardevice();

        // (35.26, 45)
        theta = 35.26 * (PI / 180);
        phi = 45 * (PI / 180);
        drawAxonometricProjection(this->coOrdinates, theta, phi, text);
        delay(1000);
        // sprintf(fileName, "Axonometric_Isometric_%d_%d.bmp", (int)(theta * (180 / PI)), (int)(phi * (180 / PI)));
        // writeimagefile(fileName);
        // system("pause");
        cleardevice();

        // (-35.26, 45)
        theta = -35.26 * (PI / 180);
        phi = 45 * (PI / 180);
        drawAxonometricProjection(this->coOrdinates, theta, phi, text);
        delay(1000);
        // sprintf(fileName, "Axonometric_Isometric_%d_%d.bmp", (int)(theta * (180 / PI)), (int)(phi * (180 / PI)));
        // writeimagefile(fileName);
        // system("pause");
        cleardevice();
    }
}
// =============================================================

// OBLIQUE PROJECTION
// =============================================================
void ThreeDimObject ::obliqueProjectionDemo()
{
    cleardevice();
    // Cabinet Projection
    float alpha = -45;
    float beta = 45;
    for (int i = alpha; i <= 45; i += 15)
    {
        drawObliqueProjection(this->coOrdinates, i * PI / 180, beta * PI / 180);
        delay(1000);
        // sprintf(fileName, "Oblique_Cabinet_%d.bmp", i);
        // writeimagefile(fileName);
        // system("pause");
        cleardevice();
    }

    // Cavalier Projection
    alpha = -45;
    beta = 63.435;
    for (int i = alpha; i <= 45; i += 15)
    {
        drawObliqueProjection(this->coOrdinates, i * PI / 180, beta * PI / 180);
        delay(1000);
        sprintf(fileName, "Oblique_Cavalier_%d.bmp", i);
        writeimagefile(fileName);
        // system("pause");
        cleardevice();
    }
}

void ThreeDimObject ::drawObliqueProjection(Matrix *coOrdinates, float alpha, float beta)
{
    Matrix pZ = getProjectionZ();
    char text[50 + sizeof(char)];
    float f = 1 / tan(beta);

    sprintf(text, "Oblique Projection");
    outtextxy(20, 20, text);
    sprintf(text, "alpha : %f \t", alpha * 180 / PI);
    outtextxy(20, 40, text);
    sprintf(text, "beta : %f", beta * 180 / PI);
    outtextxy(20, 60, text);
    sprintf(text, "f : %f", f);
    outtextxy(20, 80, text);

    Matrix oblique = getObliqueProjMatrix(alpha, f);
    Matrix requiredMatrix = (*(coOrdinates)) * oblique * pZ;
    Matrix *requiredMatrixPtr = &requiredMatrix;
    drawAxisOblique(alpha, beta);
    this->drawShape(requiredMatrixPtr);
}
// =============================================================

// PERSPECTIVE PROJECTION
// =============================================================
void ThreeDimObject::drawPerspectiveProjection(Matrix *m, float p, float q, float r, char *heading)
{
    cleardevice();
    char text[50 + sizeof(char)];
    outtextxy(20, 20, heading);
    sprintf(text, "p : %f \t", p);
    outtextxy(20, 40, text);
    sprintf(text, "q : %f", q);
    outtextxy(20, 60, text);
    sprintf(text, "r : %f", r);
    outtextxy(20, 80, text);

    Matrix pZ = getProjectionZ();
    Matrix perspective = getPerspectiveProjMatrix(p, q, r);
    Matrix requiredMatrix = (*(m)) * perspective * pZ;
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->convertToHomogenous(requiredMatrixPtr);
    this->drawShape(requiredMatrixPtr);
    drawAxisPrespective(p, q, r);
}

void ThreeDimObject ::perspectiveProjectionDemo()
{
    char text[50 + sizeof(char)];
    float p = 0;
    float q = 0;
    float r = 0;

    // SINGLE POINT
    sprintf(text, "Perspective -> Single Point");
    {
        // z
        for (int i = 5; i <= 10; i++)
        {
            r = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Single_Point_Z_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }

        // y
        p = q = r = 0;
        for (int i = 5; i <= 10; i++)
        {
            q = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Single_Point_Y_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }

        // x
        p = q = r = 0;
        for (int i = 5; i <= 10; i++)
        {
            p = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Single_Point_X_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }
    }

    // TWO POINT
    sprintf(text, "Perspective -> Two Point");
    {
        // xy
        p = q = r = 0;
        for (int i = 5; i <= 10; i++)
        {
            p = 1 / (100 * (float)i);
            q = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Two_Point_XY_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }

        // xz
        p = q = r = 0;
        for (int i = 5; i <= 10; i++)
        {
            p = 1 / (100 * (float)i);
            r = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Two_Point_XZ_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }

        // yz
        p = q = r = 0;
        for (int i = 5; i <= 10; i++)
        {
            q = 1 / (100 * (float)i);
            r = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Two_Point_YZ_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }
    }

    // THREE POINT
    sprintf(text, "Perspective -> Three Point");
    {
        p = q = r = 0;

        for (int i = 5; i <= 10; i++)
        {
            p = 1 / (100 * (float)i);
            q = 1 / (100 * (float)i);
            r = 1 / (100 * (float)i);
            this->drawPerspectiveProjection(this->coOrdinates, p, q, r, text);
            delay(1000);
            // sprintf(fileName, "Three_Point_XYZ_%d.bmp", 10 - i);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
        }
    }
}
// =============================================================
// =============================================================

// OBJECT ANIMATION
// =============================================================
void ThreeDimObject ::animation()
{
    double pi = 4 * atan(1);
    float *centroid = this->getCentroid(this->coOrdinates);
    Matrix T = getTranslationMatrix(centroid[0], centroid[1], centroid[2]);
    Matrix T_inv = getTranslationMatrix(-1 * centroid[0], -1 * centroid[1], -1 * centroid[2]);
    Matrix pZ = getProjectionZ();
    char text[50 + sizeof(char)];
    cout << "Rotating Object Translated to Origin uniformly Scaled by a factor of 2.5\n";

    int i = 0;
    while (i != 720)
    {
        float theta = i * (pi / 180);
        float phi = -0.25 * i * (pi / 180);
        float ita = 0.25 * i * (pi / 180);
        float threeSixty = 360;

        sprintf(text, "Rotation Angles");
        outtextxy(20, 20, text);
        // drawAxis(theta, phi);
        sprintf(text, "theta : %f \t", fmod((theta * 180 / pi), threeSixty));
        outtextxy(20, 40, text);
        sprintf(text, "phi : %f", fmod((phi * 180 / pi), threeSixty));
        outtextxy(20, 60, text);
        sprintf(text, "ita : %f", fmod((ita * 180 / pi), threeSixty));
        outtextxy(20, 80, text);

        Matrix rotateY = getRotationMatrixCounterClockwiseY(theta);
        Matrix rotateX = getRotationMatrixCounterClockwiseX(phi);
        Matrix rotateZ = getRotationMatrixCounterClockwiseX(ita);
        Matrix scaleMatrix = getScaleMatrix(2.5, 2.5, 2.5);
        Matrix requiredMatrix = (*(this->coOrdinates)) * T * rotateX * rotateY * rotateZ * scaleMatrix * pZ;
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawShape(requiredMatrixPtr);
        delay(10);
        cleardevice();
        i++;
    }
}
// =============================================================

// TRANSFORMATION DEMONSTRATION

// To show Scaling Demonstration
void ThreeDimObject::scaling()
{
    char heading[200] = "";
    drawAxis();
    cout << "SCALING\n"
         << "1. Uniform Scaling \n"
         << "2. Non-Uniform Scaling \n"
         << "Enter Option : ";
    int option;
    cin >> option;
    float scaleFactorX = 1;
    float scaleFactorY = 1;
    float scaleFactorZ = 1;
    switch (option)
    {
    case 1:
    {
        cout << "Enter Scale : ";
        cin >> scaleFactorX;
        scaleFactorY = scaleFactorX;
        scaleFactorZ = scaleFactorX;
    }
    break;
    case 2:
    {
        cout << "Enter Scale Factor in x-direction : ";
        cin >> scaleFactorX;
        cout << "Enter Scale Factor in y-direction : ";
        cin >> scaleFactorY;
        cout << "Enter Scale Factor in z-direction : ";
        cin >> scaleFactorZ;
    }
    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }
    Matrix scaleMatrix = getScaleMatrix(scaleFactorX, scaleFactorY, scaleFactorZ);
    Matrix requiredMatrix = (*(this->coOrdinates)) * (scaleMatrix);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    // original figure
    this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
    // scaled figure
    sprintf(heading, "SCALING BY x: %f, y: %f, z: %f", scaleFactorX, scaleFactorY, scaleFactorZ);
    this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
    requiredMatrixPtr = NULL;
}

// To show Shearing Demonstration
void ThreeDimObject ::shearing()
{
    float theta = 15 * (PI / 180);
    float phi = 30 * (PI / 180);
    char heading[50] = "SHEARING DEMONSTRATION";

    cout << "SHEARING \n"
         << "1. about x-direction \n"
         << "2. about y-direction \n"
         << "3. about z-direction \n"
         << "4. general shearing matrix \n"
         << "Enter Option : ";
    float shearingX1 = 0;
    float shearingX2 = 0;
    float shearingY1 = 0;
    float shearingY2 = 0;
    float shearingZ1 = 0;
    float shearingZ2 = 0;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        cout << "Enter Shearing Factor : \n";
        cout << "X1 : ";
        cin >> shearingX1;
        cout << "X2 : ";
        cin >> shearingX2;
    }
    break;
    case 2:
    {
        cout << "Enter Shearing Factor : \n";
        cout << "Y1 : ";
        cin >> shearingY1;
        cout << "Y2 : ";
        cin >> shearingY2;
    }
    break;
    case 3:
    {
        cout << "Enter Shearing Factor : \n";
        cout << "Z1 : ";
        cin >> shearingZ1;
        cout << "Z2 : ";
        cin >> shearingZ2;
    }
    break;
    case 4:
    {
        cout << "Enter Shearing Factor : \n";

        cout << "X1 : ";
        cin >> shearingX1;
        cout << "X2 : ";
        cin >> shearingX2;

        cout << "Y1 : ";
        cin >> shearingY1;
        cout << "Y2 : ";
        cin >> shearingY2;

        cout << "Z1 : ";
        cin >> shearingZ1;
        cout << "Z2 : ";
        cin >> shearingZ2;
    }

    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }

    // Drawing the Figure
    for (int i = 15; i <= 60; i += 15)
    {
        for (int j = 30; j <= 45; j += 15)
        {
            // Grid Lines
            theta = i * (PI / 180);
            phi = j * (PI / 180);
            Matrix shearingMatrix = getShearingMatrix(shearingX1, shearingX2, shearingY1, shearingY2, shearingZ1, shearingZ2);
            Matrix requiredMatrix = (*(this->coOrdinates)) * (shearingMatrix);
            Matrix *requiredMatrixPtr = &requiredMatrix;
            this->drawAxonometricProjection(this->coOrdinates, theta, phi, heading);
            this->drawAxonometricProjection(requiredMatrixPtr, theta, phi, heading);
            // sprintf(fileName, "Shearing_%d_%d.bmp", i, j);
            // writeimagefile(fileName);
            // system("pause");
            cleardevice();
            requiredMatrixPtr = NULL;
        }
    }
}

// To show Reflection Demonstration
void ThreeDimObject ::reflection()
{
    Matrix pZ = getProjectionZ();
    float theta = 15 * (PI / 180);
    float phi = 30 * (PI / 180);
    char heading[50] = "";

    cout << "REFLECTION \n"
         << "1. about xy-plane \n"
         << "2. about yz-plane \n"
         << "3. about xz-plane \n"
         << "4. about arbitrary plane \n"
         << "Enter Option : ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        // XY PLANE
        sprintf(heading, "XY PLANE");
        for (int i = 15; i <= 90; i += 15)
        {
            for (int j = 30; j <= 45; j += 15)
            {
                // Grid Lines
                theta = i * (PI / 180);
                phi = j * (PI / 180);
                drawAxis(theta, phi);
                Matrix reflectionMatrix = getReflectionMatrixAboutXYPlane();
                Matrix requiredMatrix = (*(this->coOrdinates)) * reflectionMatrix;
                Matrix *requiredMatrixPtr = &requiredMatrix;
                this->drawAxonometricProjection(this->coOrdinates, theta, phi, heading);
                this->drawAxonometricProjection(requiredMatrixPtr, theta, phi, heading);
                // sprintf(fileName, "Reflection_XY_%d_%d.bmp", i, j);
                // writeimagefile(fileName);
                // system("pause");
                cleardevice();
                requiredMatrixPtr = NULL;
            }
        }
    }
    break;
    case 2:
    {
        // YZ PLANE
        sprintf(heading, "YZ PLANE");
        for (int i = 15; i <= 90; i += 15)
        {
            for (int j = 30; j <= 45; j += 15)
            {
                // Grid Lines
                theta = i * (PI / 180);
                phi = j * (PI / 180);
                drawAxis(theta, phi);
                Matrix reflectionMatrix = getReflectionMatrixAboutYZPlane();
                Matrix requiredMatrix = (*(this->coOrdinates)) * reflectionMatrix;
                Matrix *requiredMatrixPtr = &requiredMatrix;
                this->drawAxonometricProjection(this->coOrdinates, theta, phi, heading);
                this->drawAxonometricProjection(requiredMatrixPtr, theta, phi, heading);
                // sprintf(fileName, "Reflection_YZ_%d_%d.bmp", i, j);
                // writeimagefile(fileName);
                // system("pause");
                cleardevice();
                requiredMatrixPtr = NULL;
            }
        }
    }
    break;
    case 3:
    {
        // XZ PLANE
        sprintf(heading, "XZ PLANE");
        for (int i = 15; i <= 90; i += 15)
        {
            for (int j = 30; j <= 45; j += 15)
            {
                // Grid Lines
                theta = i * (PI / 180);
                phi = j * (PI / 180);
                drawAxis(theta, phi);
                Matrix reflectionMatrix = getReflectionMatrixAboutXZPlane();
                Matrix requiredMatrix = (*(this->coOrdinates)) * reflectionMatrix;
                Matrix *requiredMatrixPtr = &requiredMatrix;
                this->drawAxonometricProjection(this->coOrdinates, theta, phi, heading);
                this->drawAxonometricProjection(requiredMatrixPtr, theta, phi, heading);
                // sprintf(fileName, "Reflection_XZ_%d_%d.bmp", i, j);
                // writeimagefile(fileName);
                // system("pause");
                cleardevice();
                requiredMatrixPtr = NULL;
            }
        }
    }
    break;
    case 4:
    {
        // ARBITARY PLANE
        sprintf(heading, "ARBITARY PLANE");
        cout << "Enter the Three Co-Ordinate of the Arbitary Plane : \n";
        Matrix arbitaryPlane(3, 4);
        for (int i = 0; i < 3; i++)
        {
            cout << "Co-Ordinate - " << i + 1 << " -> ";
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    arbitaryPlane.m[i][j] = 1;
                }
                else
                {
                    cin >> arbitaryPlane.m[i][j];
                }
            }
        }
        cout << "\n";

        // Finding the DCs
        // Finding the Normal to Plane using Cross Product using three vectors A,B,C
        // n = (B-A)x(C-A)
        // B-A
        arbitaryPlane.m[1][0] -= arbitaryPlane.m[0][0];
        arbitaryPlane.m[1][1] -= arbitaryPlane.m[0][1];
        arbitaryPlane.m[1][2] -= arbitaryPlane.m[0][2];
        // C-A
        arbitaryPlane.m[2][0] -= arbitaryPlane.m[0][0];
        arbitaryPlane.m[2][1] -= arbitaryPlane.m[0][1];
        arbitaryPlane.m[2][2] -= arbitaryPlane.m[0][2];

        // normal vector
        float nX = arbitaryPlane.m[1][2] * arbitaryPlane.m[2][1] - arbitaryPlane.m[1][1] * arbitaryPlane.m[2][2];
        float nY = -1 * (arbitaryPlane.m[1][2] * arbitaryPlane.m[2][2] - arbitaryPlane.m[1][0] * arbitaryPlane.m[2][2]);
        float nZ = arbitaryPlane.m[1][1] * arbitaryPlane.m[2][0] - arbitaryPlane.m[1][0] * arbitaryPlane.m[2][1];
        float distance = sqrt((nX * nX) + (nY * nY) + (nZ * nZ));

        // calculating direction cosines
        float cx = nX / distance;
        float cy = nY / distance;
        float cz = nZ / distance;

        // calculating alpha and beta
        float d = sqrt((cy * cy) + (cz * cz));
        float alpha = acos(cx / d);
        float beta = acos(d);
        cout << "Normal Vector : " << nX << "\t" << nY << "\t" << nZ << "\n";
        cout << "Direction Cosines : " << cx << "\t" << cy << "\t" << cz << "\n";
        cout << "Angle of Rotation : \n"
             << "\tx-axis - " << alpha * (180 / PI) << "\n"
             << "\ty-axis - " << -1 * beta * (180 / PI) << "\n";

        // Finding the required transformation Matrix and applying it to the Object
        Matrix translate = getTranslationMatrix(arbitaryPlane.m[0][0], arbitaryPlane.m[0][1], arbitaryPlane.m[0][2]);
        Matrix rotateX = getRotationMatrixCounterClockwiseX(alpha);
        Matrix rotateY = getRotationMatrixCounterClockwiseY(-1 * beta);
        Matrix reflect = getReflectionMatrixAboutXYPlane();
        Matrix rotateY_inv = getRotationMatrixCounterClockwiseY(beta);
        Matrix rotateX_inv = getRotationMatrixCounterClockwiseX(-1 * alpha);
        Matrix translate_inv = getTranslationMatrix(-1 * arbitaryPlane.m[0][0], -1 * arbitaryPlane.m[0][1], -1 * arbitaryPlane.m[0][2]);
        Matrix requiredMatrix = (*(this->coOrdinates)) * translate * rotateX * rotateY * reflect * rotateY_inv * rotateX_inv * translate_inv;
        Matrix *requiredMatrixPtr = &requiredMatrix;

        //  Drawing the Original and Transformed Object
        this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
        this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
        // sprintf(fileName, "Reflection_Arbitary.bmp");
        // writeimagefile(fileName);
        requiredMatrixPtr = NULL;
    }
    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }
}

// To show Rotation Demonstration
void ThreeDimObject ::rotation()
{
    Matrix pZ = getProjectionZ();
    char heading[50] = "";

    cout << "ROTATION \n"
         << "1. Counter Clockwise about x-axis \n"
         << "2. Counter Clockwise about y-axis \n"
         << "3. Counter Clockwise about z-axis \n"
         << "4. Counter Clockwise about an arbitary axis\n"
         << "Enter Option : ";
    int option;
    cin >> option;
    float ita = 0;
    switch (option)
    {
    case 1:
    {
        // X-AXIS
        cout << "Enter Angle : ";
        cin >> ita;
        ita *= (PI / 180);
        Matrix rotationMatrix = getRotationMatrixCounterClockwiseX(ita);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (rotationMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
        sprintf(heading, "X-Axis by : %d", (int)(ita * 180 / PI));
        this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
        // sprintf(fileName, "Rotation_X_%d_.bmp", (int)(ita * 180 / PI));
        // writeimagefile(fileName);
        requiredMatrixPtr = NULL;
    }
    break;
    case 2:
    {
        // Y-AXIS
        cout << "Enter Angle : ";
        cin >> ita;
        ita *= (PI / 180);
        Matrix rotationMatrix = getRotationMatrixCounterClockwiseY(ita);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (rotationMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
        sprintf(heading, "Y-Axis by : %d", (int)(ita * 180 / PI));
        this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
        // sprintf(fileName, "Rotation_Y_%d_.bmp", (int)(ita * 180 / PI));
        // writeimagefile(fileName);
        requiredMatrixPtr = NULL;
    }
    break;
    case 3:
    {
        // Z-AXIS
        cout << "Enter Angle : ";
        cin >> ita;
        ita *= (PI / 180);
        Matrix rotationMatrix = getRotationMatrixCounterClockwiseZ(ita);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (rotationMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
        sprintf(heading, "Z-Axis by : %d", (int)(ita * 180 / PI));
        this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
        // sprintf(fileName, "Rotation_Z_%d_.bmp", (int)(ita * 180 / PI));
        // writeimagefile(fileName);
        requiredMatrixPtr = NULL;
    }
    break;
    case 4:
    {
        // ARBITARY AXIS
        cout << "Enter the Two Co-Ordinate of the Arbitrary Axis : \n";
        Matrix arbitaryAxis(2, 4);
        for (int i = 0; i < 2; i++)
        {
            cout << "Co-Ordinate - " << i + 1 << " -> ";
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    arbitaryAxis.m[i][j] = 1;
                }
                else
                {
                    cin >> arbitaryAxis.m[i][j];
                }
            }
        }

        // Drawing the Arbitary Axis Line and Original Object
        drawLine(arbitaryAxis, 2);
        this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
        // sprintf(fileName, "Rotation_Arbritary_Before%d_.bmp", ita * 180 / PI);
        // writeimagefile(fileName);

        // Finding the DCs
        arbitaryAxis.m[1][0] -= arbitaryAxis.m[0][0];
        arbitaryAxis.m[1][1] -= arbitaryAxis.m[0][1];
        arbitaryAxis.m[1][2] -= arbitaryAxis.m[0][2];

        // finding the distance between points
        float distance = sqrt((arbitaryAxis.m[1][0] * arbitaryAxis.m[1][0]) + (arbitaryAxis.m[1][1] * arbitaryAxis.m[1][1]) + (arbitaryAxis.m[1][2] * arbitaryAxis.m[1][2]));

        // calculating the direction cosines
        float cx = +arbitaryAxis.m[1][0] / distance;
        float cy = +arbitaryAxis.m[1][1] / distance;
        float cz = +arbitaryAxis.m[1][2] / distance;
        float d = sqrt((cy * cy) + (cz * cz));

        // calculating alpha and beta
        float alpha = acos(cx / d);
        float beta = acos(d);
        cout << "Direction Cosines : " << cx << "\t" << cy << "\t" << cz << "\n";
        // cout << "Angle of Rotation to Coincide Arbitrary Axis with z-axis : " << alpha << "\t" << beta << "\n";
        cout << "Angle of Rotation to Coincide Arbitrary Axis with z-axis : " << alpha * (180 / PI) << "\t" << beta * (180 / PI) << "\n";

        // Angle of Rotation by the Arbitrary  Axis
        float delta = 1;
        cout << "Enter the angle of Rotation : ";
        cin >> delta;
        delta *= PI / 180;
        // Finding the required transformation Matrix
        Matrix translate = getTranslationMatrix(arbitaryAxis.m[0][0], arbitaryAxis.m[0][1], arbitaryAxis.m[0][2]);
        Matrix rotateX = getRotationMatrixCounterClockwiseX(alpha);
        Matrix rotateY = getRotationMatrixCounterClockwiseY(-1 * beta);
        Matrix rotateZ = getRotationMatrixCounterClockwiseZ(delta);
        Matrix rotateY_inv = getRotationMatrixCounterClockwiseY(beta);
        Matrix rotateX_inv = getRotationMatrixCounterClockwiseX(-1 * alpha);
        Matrix translate_inv = getTranslationMatrix(-1 * arbitaryAxis.m[0][0], -1 * arbitaryAxis.m[0][1], -1 * arbitaryAxis.m[0][2]);
        Matrix requiredMatrix = (*(this->coOrdinates)) * translate * rotateX * rotateY * rotateZ * rotateY_inv * rotateX_inv * translate_inv;
        Matrix *requiredMatrixPtr = &requiredMatrix;

        // Drawing the Transformed Object
        cleardevice();
        arbitaryAxis.m[1][0] += arbitaryAxis.m[0][0];
        arbitaryAxis.m[1][1] += arbitaryAxis.m[0][1];
        arbitaryAxis.m[1][2] += arbitaryAxis.m[0][2];
        drawLine(arbitaryAxis, 2);
        sprintf(heading, "Rotation about Arbitary Axis by : %d", (int)(delta * 180 / PI));
        this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
        // sprintf(fileName, "Rotation_Arbritary_After%d_.bmp", ita * 180 / PI);
        // writeimagefile(fileName);
        requiredMatrixPtr = NULL;
        delay(100);
    }
    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }
}

// To show Translation Demonstration
void ThreeDimObject::translation()
{
    Matrix pZ = getProjectionZ();
    char heading[100] = "TRANSLATION ";

    cout << "TRANSLATION \n";
    float xFactor = 0;
    float yFactor = 0;
    float zFactor = 0;
    cout << "Translate x co-ordinate by : ";
    cin >> xFactor;
    cout << "Translate y co-ordinate by : ";
    cin >> yFactor;
    cout << "Translate z co-ordinate by : ";
    cin >> zFactor;
    Matrix translationMatrix = getTranslationMatrix(xFactor, yFactor, zFactor);
    Matrix requiredMatrix = (*(this->coOrdinates)) * (translationMatrix);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
    sprintf(heading, "TRANSLATION BY x: %f, y: %f, z: %f", -1 * xFactor, -1 * yFactor, -1 * zFactor);
    this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
    // sprintf(fileName, "Translation_%d_%d_%d.bmp", (int)xFactor, (int)yFactor, (int)zFactor);
    // writeimagefile(fileName);
    requiredMatrixPtr = NULL;
}
#include <stdlib.h>
// To show General Transformation Demonstration
void ThreeDimObject ::transformationMatrix()
{
    Matrix transformationMat(4, 4);
    Matrix pZ = getProjectionZ();
    char heading[50] = "GENERAL TRANSFORMATION";
    cout << "Enter General 4x4 Transformation Matrix Co-Ordinates\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Row" << i + 1 << " : ";
        for (int j = 0; j < 4; j++)
        {
            cin >> transformationMat.m[i][j];
        }
    }
    cout << "\n";
    Matrix requiredMatrix = (*(this->coOrdinates)) * (transformationMat);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawAxonometricProjection(this->coOrdinates, THETA, PHI, heading);
    this->drawAxonometricProjection(requiredMatrixPtr, THETA, PHI, heading);
    // sprintf(fileName, "General_Transformation_%d.bmp", (rand() % 1000 + 1) * 10);
    // writeimagefile(fileName);
    requiredMatrixPtr = NULL;
}

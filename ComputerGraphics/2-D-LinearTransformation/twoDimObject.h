#include <iostream>
#include <math.h>
#include <graphics.h>
#include <vector>
using namespace std;

// Matrix Class
class Matrix
{

public:
    // Data Members
    int r;
    int c;
    float **m;
    // Static Variables
    static vector<Matrix *> tempMatrices;
    // Constructor
    Matrix(int r, int c, int identity = 1)
    {
        this->r = r;
        this->c = c;
        m = new float *[r];
        for (int i = 0; i < r; i++)
        {
            m[i] = new float[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (identity == 1)
                {
                    if (i == j)
                    {
                        m[i][j] = 1;
                    }
                    else
                    {
                        m[i][j] = 0;
                    }
                }
                else
                {
                    m[i][j] = 0;
                }
            }
        }
    }
    // Copy Constructor
    Matrix(const Matrix &matrix)
    {
        r = matrix.r;
        c = matrix.c;
        m = new float *[r];
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
    // Destructor
    ~Matrix()
    {
        try
        {
            for (int i = 0; i < r; i++)
            {
                delete[] m[i];
                m[i] = NULL;
            }
            delete m;
            m = NULL;
        }
        catch (exception &e)
        {
            cout << "ERROR : \t " << e.what() << "\n";
        }
    }
    // Member Functions
    void display();
    Matrix operator*(Matrix &B);
    Matrix transpose();
};

// Initialzing the Static Varibale to store Pointers to Temporary Matrices
vector<Matrix *> Matrix::tempMatrices = {};

// To Display the Matrix
void Matrix ::display()
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

// To Multiply Two Matrix Objects A*bB
Matrix Matrix::operator*(Matrix &B)
{
    if (this->c != B.r)
    {
        cout << "BAD";
        return *(new Matrix(0, 0));
    }
    Matrix *C = new Matrix(this->r, B.c, 0);
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < B.c; j++)
        {
            for (int k = 0; k < this->c; k++)
            {
                C->m[i][j] += (this->m[i][k] * B.m[k][j]);
            }
        }
    }
    // Saving the pointer to the Craeted Matrix Object
    Matrix::tempMatrices.push_back(C);
    // cout << C << "\n";
    return *C;
}

// To Find the Transpose of the Matrix
Matrix Matrix ::transpose()
{
    Matrix T(this->c, this->r);
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < this->c; j++)
        {
            T.m[i][j] = this->m[j][i];
        }
    }
    return T;
}

// TRANSFORMATION MATRICES
// SCALE MATRIX
Matrix getScaleMatrix(float scaleFacorX, float scaleFacorY)
{
    Matrix scaleMatrix(3, 3);
    scaleMatrix.m[2][2] = 1;
    scaleMatrix.m[0][0] = scaleFacorX;
    scaleMatrix.m[1][1] = scaleFacorY;
    return scaleMatrix;
}
// SHEARING MATRIX
Matrix getShearingMatrix(float shearingFactorX, float shearingFactorY)
{
    Matrix shearingMatrix(3, 3);
    shearingMatrix.m[1][0] = shearingFactorX;
    shearingMatrix.m[0][1] = shearingFactorY;
    shearingMatrix.display();
    return shearingMatrix;
}
// REFLECTION MATRICES
Matrix getReflectionMatrixAboutX()
{
    Matrix reflectionMatrix(3, 3);
    reflectionMatrix.m[0][0] = 1;
    reflectionMatrix.m[1][1] = -1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutY()
{
    Matrix reflectionMatrix(3, 3);
    reflectionMatrix.m[0][0] = -1;
    reflectionMatrix.m[1][1] = 1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutXY()
{
    Matrix reflectionMatrix(3, 3, 0);
    reflectionMatrix.m[0][1] = 1;
    reflectionMatrix.m[1][0] = 1;
    reflectionMatrix.m[2][2] = 1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutX_Y()
{
    Matrix reflectionMatrix(3, 3, 0);
    reflectionMatrix.m[0][1] = -1;
    reflectionMatrix.m[1][0] = -1;
    reflectionMatrix.m[2][2] = 1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutOrigin()
{
    Matrix reflectionMatrix(3, 3);
    reflectionMatrix.m[0][0] = -1;
    reflectionMatrix.m[1][1] = -1;
    reflectionMatrix.m[2][2] = 1;
    return reflectionMatrix;
}
// ROTATION MATRICES
Matrix getRotationMatrixCounterClockwise(float theta)
{
    Matrix rotationMatrix(3, 3);
    const double multiplier = pow(10.0, 5);
    rotationMatrix.m[0][0] = cos(theta);
    rotationMatrix.m[0][1] = sin(theta);
    rotationMatrix.m[1][0] = (-1) * sin(theta);
    rotationMatrix.m[1][1] = cos(theta);

    return rotationMatrix;
}
Matrix getRotationMatrixClockwise(float theta)
{
    Matrix rotationMatrix(3, 3);
    rotationMatrix.m[0][0] = cos(theta);
    rotationMatrix.m[0][1] = (-1) * sin(theta);
    rotationMatrix.m[1][0] = sin(theta);
    rotationMatrix.m[1][1] = cos(theta);

    return rotationMatrix;
}
// TRANSLATION MATRICES
Matrix getTranslationMatrix(float xFactor, float yFactor)
{
    Matrix translationMatrix(3, 3);
    translationMatrix.m[2][0] = (-1) * xFactor;
    translationMatrix.m[2][1] = (-1) * yFactor;
    return translationMatrix;
}

// TwoDimObject Class
class TwoDimObject
{

public:
    // Data Memebers
    Matrix *coOrdinates;
    int numberOfCoOrdinates = 0;
    // Constructor
    TwoDimObject()
    {
        this->numberOfCoOrdinates = 4;
        this->coOrdinates = new Matrix(4, 3);
        this->coOrdinates->m[0][0] = 50;
        this->coOrdinates->m[0][1] = 50;
        this->coOrdinates->m[1][0] = 50;
        this->coOrdinates->m[1][1] = 135;
        this->coOrdinates->m[2][0] = 170;
        this->coOrdinates->m[2][1] = 150;
        this->coOrdinates->m[3][0] = 150;
        this->coOrdinates->m[3][1] = 70;

        // filling last row as 1 for Homogenous Co-Ordinates
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            this->coOrdinates->m[i][2] = 1;
        }
        // this->coOrdinates->display();
    }
    // Overloaded Constructor - to use when want to take input of Co-Ordinates
    TwoDimObject(int numberOfCoOrdinates)
    {
        this->numberOfCoOrdinates = numberOfCoOrdinates;
        this->coOrdinates = new Matrix(numberOfCoOrdinates, 3);
        // taking Co-Ordinate Input
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            cout << "Co-Ordinate - " << i + 1 << " -> ";
            for (int j = 0; j < 2; j++)
            {
                cin >> this->coOrdinates->m[i][j];
            }
        }
        // filling last row as 1 for Homogenous Co-Ordinates
        for (int i = 0; i < numberOfCoOrdinates; i++)
        {
            this->coOrdinates->m[i][2] = 1;
        }
        // this->coOrdinates->display();
    }

    // Desctructor
    ~TwoDimObject()
    {
        delete this->coOrdinates;
    }
    // member function
    void drawObject(Matrix *matrix);
    void scaling();
    void reflection();
    void shearing();
    void rotation();
    void translation();
    void transformationMatrix();
};

// To Draw the 2D Object whose Co-Ordinate are passes as in Homogenous Matrix as a "matrix" object
void TwoDimObject::drawObject(Matrix *matrix)
{
    float **coOrdinates = matrix->m;
    int numberOfCoOrdinates = matrix->r;

    cout << "\nDRAWN FIGURE HOMOGENOUS CO_ORDINATES\n";
    cout << "===================================";
    matrix->display();
    cout << "===================================\n\n";

    // creating the poly array that will be the input to the "drawpoly()" function of the winbgim library
    int *poly = new int[(numberOfCoOrdinates + 1) * 2];
    int k = 0;
    for (int i = 0; i < numberOfCoOrdinates; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            poly[k++] = coOrdinates[i][j];
        }
    }
    poly[k++] = coOrdinates[0][0];
    poly[k++] = coOrdinates[0][1];
    for (int i = 0; i < ((numberOfCoOrdinates + 1) * 2); i++)
    {
        // reflect about x-axis
        poly[i] *= (((i + 1) % 2 == 0) ? -1 : 1);
        // transtale to center of window
        poly[i] += (((i + 1) % 2 != 0) ? getmaxx() / 2 : getmaxy() / 2);
        // cout << poly[i] << "\t";
    }
    // drawing the polygon
    drawpoly(numberOfCoOrdinates + 1, poly);
    delete[] poly;
}

// To show Scaling Demonstration
void TwoDimObject::scaling()
{
    cout << "SCALING\n"
         << "1. Uniform Scaling \n"
         << "2. Non-Uniform Scaling \n"
         << "Enter Option : ";
    int option;
    cin >> option;
    float scaleFactorX = 1;
    float scaleFactorY = 1;
    switch (option)
    {
    case 1:
    {
        cout << "Enter Scale : ";
        cin >> scaleFactorX;
        scaleFactorY = scaleFactorX;
    }
    break;
    case 2:
    {
        cout << "Enter Scale Factor in x-direction : ";
        cin >> scaleFactorX;
        cout << "Enter Scale Factor in y-direction : ";
        cin >> scaleFactorY;
    }
    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }
    Matrix scaleMatrix = getScaleMatrix(scaleFactorX, scaleFactorY);
    Matrix requiredMatrix = (*(this->coOrdinates)) * (scaleMatrix);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawObject(requiredMatrixPtr);
    requiredMatrixPtr = NULL;
}

// To show Reflection Demonstration
void TwoDimObject ::reflection()
{
    cout << "REFLECTION \n"
         << "1. about x-axis \n"
         << "2. about y-axis \n"
         << "3. about origin \n"
         << "4. about x = y \n"
         << "5. about x = -y \n"
         << "6. about an arbitary line\n"
         << "Enter Option : ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        Matrix reflectionMatrix = getReflectionMatrixAboutX();
        Matrix requiredMatrix = (*(this->coOrdinates)) * (reflectionMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 2:
    {
        Matrix reflectionMatrix = getReflectionMatrixAboutY();
        Matrix requiredMatrix = (*(this->coOrdinates)) * (reflectionMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 3:
    {
        Matrix reflectionMatrix = getReflectionMatrixAboutOrigin();
        Matrix requiredMatrix = (*(this->coOrdinates)) * (reflectionMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 4:
    {
        Matrix reflectionMatrix = getReflectionMatrixAboutXY();
        Matrix requiredMatrix = (*(this->coOrdinates)) * (reflectionMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 5:
    {
        Matrix reflectionMatrix = getReflectionMatrixAboutX_Y();
        Matrix requiredMatrix = (*(this->coOrdinates)) * (reflectionMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 6:
    {
        cout << "Enter Equation of Line in this form : F(x,y) = Ax + By + C = 0 \n";
        float A = 0;
        float B = 0;
        float C = 0;
        cout << "A : ";
        cin >> A;
        cout << "B : ";
        cin >> B;
        cout << "C : ";
        cin >> C;

        // About x-axis with some translation
        if ((A != 0) && (B == 0) && (C != 0))
        {
            // Line about which the reflection will be performed
            Matrix *reflectionLine = new Matrix(2, 3);
            reflectionLine->m[0][0] = 0;
            reflectionLine->m[0][1] = getmaxy();
            reflectionLine->m[0][2] = 1;
            reflectionLine->m[1][0] = 0;
            reflectionLine->m[1][1] = -getmaxy();
            reflectionLine->m[1][2] = 1;

            // Drawing the Reflection Line
            Matrix translationMatrix = getTranslationMatrix(C, 0);
            Matrix requiredLineMatrix = (*reflectionLine) * translationMatrix;
            Matrix *requiredLineMatrixPtr = &requiredLineMatrix;
            this->drawObject(requiredLineMatrixPtr);
            requiredLineMatrixPtr = NULL;
            delete reflectionLine;

            // Drawing the Reflected Figure
            Matrix reflectionMatrix = getReflectionMatrixAboutY();
            Matrix requiredMatrix = (*(this->coOrdinates)) * reflectionMatrix * translationMatrix;
            Matrix *requiredMatrixPtr = &requiredMatrix;
            this->drawObject(requiredMatrixPtr);
            requiredMatrixPtr = NULL;
        }
        // About y-axis with some translation
        else if ((A == 0) && (B != 0) && (C != 0))
        {
            // Line about which the reflection will be performed
            Matrix *reflectionLine = new Matrix(2, 3);
            reflectionLine->m[0][0] = getmaxx();
            reflectionLine->m[0][1] = 0;
            reflectionLine->m[0][2] = 1;
            reflectionLine->m[1][0] = -getmaxx();
            reflectionLine->m[1][1] = 0;
            reflectionLine->m[1][2] = 1;

            // Drawing the Reflection Line
            Matrix translationMatrix = getTranslationMatrix(0, C);
            Matrix requiredLineMatrix = (*reflectionLine) * translationMatrix;
            requiredLineMatrix.display();
            Matrix *requiredLineMatrixPtr = &requiredLineMatrix;
            this->drawObject(requiredLineMatrixPtr);
            requiredLineMatrixPtr = NULL;
            delete reflectionLine;

            // Drawing the Reflected Figure
            Matrix reflectionMatrix = getReflectionMatrixAboutX();
            Matrix requiredMatrix = (*(this->coOrdinates)) * reflectionMatrix * translationMatrix;
            Matrix *requiredMatrixPtr = &requiredMatrix;
            this->drawObject(requiredMatrixPtr);
            requiredMatrixPtr = NULL;
        }
        else
        {
            // Arbitary Line Parameters
            float slope = (-A) / (B);
            float y_intercept = (-C) / (B);
            float x_intercept = (-C) / (A);
            float theta = atan(slope);
            cout << "Slope : " << slope << "\n";
            cout << "x_intercept : " << x_intercept << "\n";
            cout << "y_intercept : " << y_intercept << "\n";
            cout << "theta : " << theta << "\n";

            // Drawing the Reflection Line
            float x1 = getmaxx();
            float y1 = slope * x1 + y_intercept;
            float y2 = getmaxy();
            float x2 = (y2 - y_intercept) / slope;
            float x3 = -1 * getmaxx();
            float y3 = slope * x3 + y_intercept;
            float y4 = -1 * getmaxy();
            float x4 = (y4 - y_intercept) / slope;
            Matrix *reflectionLine = new Matrix(4, 3);
            reflectionLine->m[0][0] = x1;
            reflectionLine->m[0][1] = y1;
            reflectionLine->m[1][0] = x2;
            reflectionLine->m[1][1] = y2;
            reflectionLine->m[2][0] = x3;
            reflectionLine->m[2][1] = y3;
            reflectionLine->m[3][0] = x4;
            reflectionLine->m[3][1] = y4;
            this->drawObject(reflectionLine);
            delete reflectionLine;

            // Translate the line to Origin
            Matrix translateMat = getTranslationMatrix(0, y_intercept);
            // Rotate the line to coincide with x-axis
            Matrix rotationMatrix = getRotationMatrixClockwise(theta);
            // Reflection about x-axis
            Matrix reflectionMatrix = getReflectionMatrixAboutX();
            // Rotate the line to coincide with x-axis
            Matrix rotationMatrixInverse = rotationMatrix.transpose();
            // Re-translate to original point
            Matrix translateMatInverse = getTranslationMatrix(0, -y_intercept);
            // Composition Matrix
            Matrix compositionMatrix = translateMat * rotationMatrix * reflectionMatrix * rotationMatrixInverse * translateMatInverse;
            Matrix requiredMatrix = (*(this->coOrdinates)) * (compositionMatrix);
            Matrix *requiredMatrixPtr = &requiredMatrix;
            this->drawObject(requiredMatrixPtr);
            requiredMatrixPtr = NULL;
        }
    }
    break;
    default:
    {
        cout << "INVALID\n";
    }
        return;
    }
}

// To show Shearing Demonstration
void TwoDimObject ::shearing()
{
    cout << "SHEARING \n"
         << "1. about x-component \n"
         << "2. about y-component \n"
         << "3. about both x-component and y-component \n"
         << "Enter Option : ";
    float shearingX = 1;
    float shearingY = 1;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        cout << "Enter Shearing Factor : ";
        cin >> shearingX;
        Matrix shearingMatrix = getShearingMatrix(shearingX, 0);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (shearingMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 2:
    {
        cout << "Enter Shearing Factor : ";
        cin >> shearingY;
        Matrix shearingMatrix = getShearingMatrix(0, shearingY);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (shearingMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 3:
    {
        cout << "Enter Shearing Factor x-component : ";
        cin >> shearingX;
        cout << "Enter Shearing Factor y-component : ";
        cin >> shearingY;
        Matrix shearingMatrix = getShearingMatrix(shearingX, shearingY);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (shearingMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
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
void TwoDimObject ::rotation()
{
    cout << "ROTATION \n"
         << "1. Counter Clockwise about Origin \n"
         << "2. Clockwise about Origin \n"
         << "3. Counter Clockwise about an arbitary point\n"
         << "4. Clockwise about an arbitary point\n"
         << "Enter Option : ";
    int option;
    cin >> option;
    double pi = 4 * atan(1);
    float theta = 0;
    switch (option)
    {
    case 1:
    {
        cout << "Enter Angle : ";
        cin >> theta;
        theta *= (pi / 180);
        Matrix rotationMatrix = getRotationMatrixCounterClockwise(theta);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (rotationMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 2:
    {
        cout << "Enter Angle : ";
        cin >> theta;
        theta *= (pi / 180);
        Matrix rotationMatrix = getRotationMatrixClockwise(theta);
        Matrix requiredMatrix = (*(this->coOrdinates)) * (rotationMatrix);
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 3:
    {
        cout << "Enter Angle : ";
        cin >> theta;
        theta *= (pi / 180);
        float x, y;
        cout << "Enter Co-Ordinates of the Points \n";
        cout << "x : ";
        cin >> x;
        cout << "y : ";
        cin >> y;
        // Plotting the arbitary Co-Ordinate
        putpixel((x + (getmaxx() / 2)), ((-1 * y) + (getmaxy() / 2)), 3);
        Matrix T = getTranslationMatrix(x, y);
        Matrix R = getRotationMatrixCounterClockwise(theta);
        Matrix T_inverse = getTranslationMatrix(-x, -y);
        Matrix requiredMatrix = (*(this->coOrdinates)) * T * R * T_inverse;
        Matrix *requiredMatrixPtr = &requiredMatrix;
        this->drawObject(requiredMatrixPtr);
        requiredMatrixPtr = NULL;
    }
    break;
    case 4:
    {
        cout << "Enter Angle : ";
        cin >> theta;
        theta *= (pi / 180);
        int x, y;
        cout << "Enter Co-Ordinates of the Points \n";
        cout << "x : ";
        cin >> x;
        cout << "y : ";
        cin >> y;
        // Plotting the arbitary Co-Ordinate
        putpixel((x + (getmaxx() / 2)), ((-1 * y) + (getmaxy() / 2)), 3);
        Matrix T = getTranslationMatrix(x, y);
        Matrix R = getRotationMatrixClockwise(theta);
        Matrix T_inverse = getTranslationMatrix(-x, -y);
        Matrix requiredMatrix = (*(this->coOrdinates)) * T * R * T_inverse;
        Matrix *requiredMatrixPtr = &requiredMatrix;
        cout << requiredMatrixPtr << "\n";
        this->drawObject(requiredMatrixPtr);
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

// To show Translation Demonstration
void TwoDimObject::translation()
{
    cout << "TRANSLATION \n";
    float xFactor = 0;
    float yFactor = 0;
    cout << "Translate x co-ordinate by : ";
    cin >> xFactor;
    cout << "Translate y co-ordinate by : ";
    cin >> yFactor;
    Matrix translationMatrix = getTranslationMatrix(xFactor, yFactor);
    Matrix requiredMatrix = (*(this->coOrdinates)) * (translationMatrix);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawObject(requiredMatrixPtr);
    requiredMatrixPtr = NULL;
}

// To show Translation Demonstration
void TwoDimObject ::transformationMatrix()
{
    Matrix transformationMat(3, 3);
    int option = 0;
    cout << "Choose Option\n"
         << "1. 2x2 Matrix\n"
         << "2. 3x3 Matrix\n"
         << " : ";
    cin >> option;
    switch (option)
    {
    case 1:
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "(" << (i + 1) << " , " << (j + 1) << ") : ";
                cin >> transformationMat.m[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "(" << (i + 1) << " , " << (j + 1) << ") : ";
                cin >> transformationMat.m[i][j];
            }
        }

        break;
    default:
        cout << "INVALID\n";
        return;
    }
    cout << "Transformation Matrix : \n";
    transformationMat.display();
    cout << "\n";
    Matrix requiredMatrix = (*(this->coOrdinates)) * (transformationMat);
    Matrix *requiredMatrixPtr = &requiredMatrix;
    this->drawObject(requiredMatrixPtr);
    requiredMatrixPtr = NULL;
}

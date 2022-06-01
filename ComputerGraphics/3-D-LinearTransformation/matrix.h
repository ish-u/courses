#include <iostream>
#include <math.h>
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
    static int created;
    static int deleted;
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
        this->created++;
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
        this->created++;
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
            this->deleted++;
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

// Initializing  the Static Variable to store Pointers to Temporary Matrices
int Matrix::created = 0;
int Matrix::deleted = 0;

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
    Matrix C(this->r, B.c, 0);
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < B.c; j++)
        {
            for (int k = 0; k < this->c; k++)
            {
                C.m[i][j] += (this->m[i][k] * B.m[k][j]);
            }
        }
    }
    // Saving the pointer to the Craeted Matrix Object
    // Matrix::tempMatrices.push_back(C);
    // cout << C << "\n";
    return C;
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
Matrix getScaleMatrix(float scaleFactorX, float scaleFactorY, float scaleFactorZ)
{
    Matrix scaleMatrix(4, 4);
    scaleMatrix.m[2][2] = 1;
    scaleMatrix.m[0][0] = scaleFactorX;
    scaleMatrix.m[1][1] = scaleFactorY;
    scaleMatrix.m[2][2] = scaleFactorZ;
    return scaleMatrix;
}
// SHEARING MATRIX
Matrix getShearingMatrix(float X1, float X2, float Y1, float Y2, float Z1, float Z2)
{
    Matrix shearingMatrix(4, 4);
    shearingMatrix.m[1][0] = X1;
    shearingMatrix.m[2][0] = X2;

    shearingMatrix.m[0][1] = Y1;
    shearingMatrix.m[2][1] = Y2;

    shearingMatrix.m[0][2] = Z1;
    shearingMatrix.m[1][2] = Z2;

    return shearingMatrix;
}
// REFLECTION MATRICES
Matrix getReflectionMatrixAboutXYPlane()
{
    Matrix reflectionMatrix(4, 4);
    reflectionMatrix.m[2][2] = -1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutYZPlane()
{
    Matrix reflectionMatrix(4, 4);
    reflectionMatrix.m[0][0] = -1;
    return reflectionMatrix;
}
Matrix getReflectionMatrixAboutXZPlane()
{
    Matrix reflectionMatrix(4, 4);
    reflectionMatrix.m[1][1] = -1;
    return reflectionMatrix;
}
// ROTATION MATRICES
// COUNTER-CLOCKWISE
Matrix getRotationMatrixCounterClockwiseX(float theta)
{
    Matrix rotationMatrix(4, 4);
    rotationMatrix.m[1][1] = cos(theta);
    rotationMatrix.m[1][2] = sin(theta);
    rotationMatrix.m[2][1] = (-1) * sin(theta);
    rotationMatrix.m[2][2] = cos(theta);
    return rotationMatrix;
}

Matrix getRotationMatrixCounterClockwiseY(float theta)
{
    Matrix rotationMatrix(4, 4);
    rotationMatrix.m[0][0] = cos(theta);
    rotationMatrix.m[0][2] = (-1) * sin(theta);
    rotationMatrix.m[2][0] = sin(theta);
    rotationMatrix.m[2][2] = cos(theta);
    return rotationMatrix;
}

Matrix getRotationMatrixCounterClockwiseZ(float theta)
{
    Matrix rotationMatrix(4, 4);
    rotationMatrix.m[0][0] = cos(theta);
    rotationMatrix.m[0][1] = sin(theta);
    rotationMatrix.m[1][0] = (-1) * sin(theta);
    rotationMatrix.m[1][1] = cos(theta);
    return rotationMatrix;
}

// TRANSLATION MATRICES
Matrix getTranslationMatrix(float xFactor, float yFactor, float zFactor)
{
    Matrix translationMatrix(4, 4);
    translationMatrix.m[3][0] = (-1) * xFactor;
    translationMatrix.m[3][1] = (-1) * yFactor;
    translationMatrix.m[3][2] = (-1) * zFactor;
    return translationMatrix;
}

// PROJECTION MATRICES
Matrix getProjectionZ()
{
    Matrix projectionZ(4, 4);
    projectionZ.m[2][2] = 0;
    return projectionZ;
}

// PERSPECTIVE  PROJECTION
Matrix getPerspectiveProjMatrix(float p, float q, float r)
{
    Matrix prespectiveMatrix(4, 4);
    prespectiveMatrix.m[0][3] = p;
    prespectiveMatrix.m[1][3] = q;
    prespectiveMatrix.m[2][3] = r;
    return prespectiveMatrix;
}

// OBLIQUE PROJECTION
Matrix getObliqueProjMatrix(float alpha, float f)
{
    Matrix obliqueMatrix(4, 4);
    obliqueMatrix.m[2][0] = -f * cos(alpha);
    obliqueMatrix.m[2][1] = -f * sin(alpha);
    obliqueMatrix.m[2][2] = 0;
    return obliqueMatrix;
}
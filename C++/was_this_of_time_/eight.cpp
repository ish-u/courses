#include <iostream>
#include <stdlib.h>
#include <cstring>


using namespace std;
class Matrix
{
    int rows;
    int col;
    int a[3][3];
public:
    Matrix(int p = 3, int q = 3)
    {
        rows = p; col = q;
        a[p][q];
        for(int i = 0; i < p; i++)
        {
            for(int j = 0; j < q; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void get();
    void put();
    void add(Matrix &x);
    void mul(Matrix &x);
    void transpose();
};

void Matrix::get()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<"Enter "<<(i+1)<<(j+1)<<":"; cin>>a[i][j];
        }
    }
}

void Matrix::put()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void Matrix::add(Matrix &x)
{
    if(col != x.rows)
    {
        cout<<"Operation can't be performed\n";
        exit(1);
    }
    Matrix temp(rows,x.col);

    for(int i = 0; i < temp.rows; i++)
    {
        for(int j = 0; j < temp.col; j++)
        {
            temp.a[i][j] = a[i][j] + x.a[i][j];
        }
    }
    temp.put();

}

void Matrix::mul(Matrix &x)
{
    if(col != x.rows)
    {
        cout<<"Operation can't be performed\n";
        exit(1);
    }
    Matrix temp(rows,x.col);

    for(int i = 0; i < temp.rows; i++)
    {
        for(int j = 0; j < temp.col; j++)
        {
            for(int k = 0; k < col; k++)
            {
                temp.a[i][j] += a[k][j] *x.a[i][k];
            }
        }
    }
    temp.put();

}

void Matrix::transpose()
{
    Matrix temp(rows,col);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            temp.a[i][j] = a[j][i];
        }
    }
    temp.put();
}

int main(int argc, char *argv[])
{
    int r1,c1,r2,c2;
    int choice = 1;
    cout<<"\t\t\!!MATRIX!!\n";
    cout<<"Enter the dimensions of Matrix A:"; cin>>r1>>c1;
    cout<<"Enter the dimensions of Matrix B:"; cin>>r2>>c2;
    cout<<"\n";
    Matrix A(r1,c1);
    cout<<"Matrix A:\n"; A.get();
    Matrix B(r2,c2);
    cout<<"\nMatrix B:\n"; B.get();
    char z;
    do
    {
        cout<<"You can do:\n";
        cout<<"a. Add A+B\n";
        cout<<"b. Multiply A*B\n";
        cout<<"c. Transpose A and B\n";
        cout<<"\nEnter Choice:"; cin>>z;

        switch(z)
        {
        case 'a':
        case 'A':
            A.add(B);
            break;
        case 'b':
        case 'B':
            A.mul(B);
            break;
        case 'c':
        case 'C':
            A.transpose();
            B.transpose();
            break;
        default:
            cout<<"Invalid Input\n Aborting;;;;;';';'";
            choice = 0;
        }

    }
    while(choice);
    return 0;

}




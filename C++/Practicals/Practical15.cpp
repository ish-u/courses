#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Matrix
{
    private:
        int row,col;
        int mat[100][100];
    public:
        Matrix(int a = 3, int b = 3)
        {
            row = a; col = b;
            mat[a][b];
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    mat[i][j] = 0;
                }
            }
        }
        void read();
        void show();
        void add(Matrix &);
        void sub(Matrix &);
        void mul(Matrix &);
        void transpose();

};

void  Matrix :: show()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout<<mat[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl;

}

void Matrix :: read()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cout<<"Element"<<i+1<<j+1<<": ";
            cin>>mat[i][j];
        }
        cout<<endl;
}

void Matrix :: add(Matrix &a)
{
    if (row != a.row && col != a.col)
    {
        cout<<"\nNOT POSSIBLE\n";
        return;
    }
    else
    {
        Matrix temp(row,col);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                temp.mat[i][j] = mat[i][j] + a.mat[i][j];
            }
        }
        temp.show();
    }
}

void Matrix :: sub(Matrix &a)
{
    if (row != a.row && col != a.col)
    {
        cout<<"\nNOT POSSIBLE\n";
        return;
    }
    else
    {
        Matrix temp(row,col);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                temp.mat[i][j] = mat[i][j] - a.mat[i][j];
            }
        }
        temp.show();
    }
}

void Matrix :: transpose()
{
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            cout<<mat[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


}

void Matrix :: mul(Matrix &a)
{
   if (col != a.row)
   {
       cout<<"\nNOT POSSIBLE\n";
   }
   else
   {
       Matrix z(row,a.col);

       for (int i = 0; i < row; i++)
       {
           for (int j = 0; j < a.col ; j++)
           {
               for (int k = 0; k < col; k++)
               {
                   z.mat[i][j] += mat[i][k]*a.mat[k][j];
               }
           }
       }
        z.show();
    }

}



int main()
{

    int r1,c1,r2,c2;
    cout<<"__MATRIX OPERATIONS USING CLASSES __\n\n";
    cout<<"Enter the Dimensions of Matrix A :"; cin>>r1>>c1;
    cout<<"Enter the Dimensions of Matrix A :"; cin>>r2>>c2;

    Matrix A(r1,c1);
    Matrix B(r2,c2);
    cout<<"\nEnter the Elements of Matrix A:"<<endl;
    A.read();
    cout<<"Enter the Elements of Matrix B:"<<endl;
    B.read();
    cout<<"MATRIX A:"<<endl;
    A.show();
    cout<<"MATRIX B:"<<endl;
    B.show();

    int choice;

    do
    {

        cout<<"\n____OPERATIONS____\n";
        cout<<"1.Add\n"<<"2.Subtract\n"<<"3.Multiply\n"<<"4.Transpose\n"<<"5.Exit\n";
        cout<<"Enter Operation: "; cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
                cout<<"Matrices after Addition"<<endl;
                A.add(B);
                break;
            case 2:
                cout<<"Matrices after Subtraction"<<endl;
                A.sub(B);
                break;
            case 3:
                cout<<"Matrices after Multiplication"<<endl;
                A.mul(B);
                break;
            case 4:
                cout<<"MATRIX A:"<<endl;
                A.transpose();
                cout<<"MATRIX B:"<<endl;
                B.transpose();
                break;
            case 5:
                cout<<"EXITING>>>>...\n";
                break;
            default:
                cout<<"Invalid\n";
                return 1;
        }
    }
    while(choice != 5);
    return 0;

}


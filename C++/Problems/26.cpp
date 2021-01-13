
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Matrix{
    int arr[3][3];
    public:
        Matrix(){
            for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                            arr[i][j] =0;
                            }
                    }
        }
        void read();
        Matrix operator +(Matrix &a);
        Matrix operator -(Matrix &a);
        void transpose();
        Matrix operator *(Matrix &a);
        void  show();


};
void Matrix :: read(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"Element"<<i+1<<j+1<<" :";
            cin>>arr[i][j];
        }
    }
}

Matrix Matrix :: operator +(Matrix &a)
{
    Matrix c;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c.arr[i][j] = arr[i][j] + a.arr[i][j];
        }
    }
    return c;
}

Matrix Matrix :: operator -(Matrix &a)
{
    Matrix c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c.arr[i][j] = arr[i][j] - a.arr[i][j];
        }
    }
    return c;
}

Matrix Matrix :: operator *(Matrix &a)
{
    Matrix c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c.arr[i][j] += (a.arr[i][k]*arr[k][j]);
            }
        }
    }
    return c;

}

void Matrix :: transpose()
{
    Matrix z;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            z.arr[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = z.arr[i][j];
        }
    }

}

void Matrix :: show()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}




int main(){
    Matrix A;
    Matrix B;
    A.show();
    B.show();
    A.read();
    B.read();

    Matrix C;

    C = A * B;
    C.show();


}


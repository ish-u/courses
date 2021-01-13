//FIND THE SQUARE OF ALL THE ELEMENTS IN THE DIAGONALS OF A MATRIX (p x q)

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;


int main()
{
    int p,q;
    cout<<"Rows :";
    cin>>p;
    cout<<"Columns :";
    cin>>q;
    int matrix_1[p][q];

    for(int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout<<"Element Matrix"<<(i+1)<<(j+1)<<" : ";
            cin>>matrix_1[i][j];
        }
    }

    int sum_1 = 0;

    for (int i = 0, j = 0;i < p, j < q; i++,j++)
    {
        cout<<matrix_1[i][j]*matrix_1[i][j]<<" ";
        sum_1 += matrix_1[i][j]*matrix_1[i][j];
    }

    cout<<endl;

    int sum_2 = 0;
    for (int i = 0, j = q - 1;i < p, j >=0 ; i++,j--)
    {
        cout<<matrix_1[i][j]*matrix_1[i][j]<<" ";
        sum_2 += matrix_1[i][j]*matrix_1[i][j];
    }

    cout<<endl;

    cout<<"Diagonal 1 Sum: "<<sum_1<<endl;
    cout<<"Diagonal 2 Sum: "<<sum_2;

    cout<<endl;
    return 0;
}



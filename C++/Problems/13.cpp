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

    cout<<"The square of the diagonal-element of the matrix are: ";
    for (int i = 0, j = 0;i < p, j < q; i++,j++)
    {
        cout<<matrix_1[i][j]*matrix_1[i][j]<<" ";
    }

    cout<<endl;
    return 0;
}



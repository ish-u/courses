//FIND THE SQUARE OF ALL THE ELEMENTS IN THE DIAGONALS OF A MATRIX (p x q)

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the size of Square Matrix :";
    cin>>n;
    int matrix[n][n];


    //INPUT THE MATRIX
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Element "<<(i+1)<<(j+1)<<" : ";
            cin>>matrix[i][j];
        }
    }

    //UPPER HALF SUM
    int sumUp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)  //ROW'S INDEX IS SMALLER THAN COLUMN'S INDEX IN UPPERHALF;
            {
                sumUp += matrix[i][j];
            }
        }
    }

    //LOWER HALF SUM
    int sumDown = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)  //ROW'S INDEX IS LARGER THAN COLUMN'S INDEX IN UPPERHALF;
            {
                sumDown += matrix[i][j];
            }
        }
    }

    cout<<endl;
    cout<<"The Sum of Upper-Half of the Matrix  is : "<<sumUp<<endl;
    cout<<"The Sum of Lower-Half of the Matrix is :  "<<sumDown<<endl;




    return 0;
}



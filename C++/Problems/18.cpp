//subtract two matrix

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;



int main(){

    //Matrix 1
    int p,q;
    cout<<":Matrix 1:"<<endl;
    cout<<"Enter The Rows      :";
    cin>>p;
    cout<<"Enter The Columns   :";
    cin>>q;
    int matrix_1[p][q];

    //Matrix 2
    int a,b;
    cout<<endl<<":Matrix 2:"<<endl;
    cout<<"Enter The Rows      :";
    cin>>a;
    cout<<"Enter The Columns   :";
    cin>>b;
    int matrix_2[a][b];

    if (a != p && b != q)
    {
        cout<<"Can't ADD, matrices have different dimensions."<<endl;
        exit(1);
    }
    cout<<endl;

    //INPUT MATRIX_1
    cout<<"ENTER MATRIX 1 ELEMENTS"<<endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout<<"Element "<<(i+1)<<(j+1)<<" : ";
            cin>>matrix_1[i][j];
            }
    }

    //INPUT MATRIX_2
    cout<<endl;
    cout<<"ENTER MATRIX 2 ELEMENTS"<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout<<"Element "<<(i+1)<<(j+1)<<" : ";
            cin>>matrix_2[i][j];
        }
    }

    //ADD MATRIX_1 AND MATRIX_2 AND STORE THEM IN MATRIX_3
    int matrix_3[a][b];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j< b; j++)
        {
            matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
    }

    //PRINT THE ADDED MATRIX
    cout<<'\n'<<"MATRIX_3 "<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout<<matrix_3[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}




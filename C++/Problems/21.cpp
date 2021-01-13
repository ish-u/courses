//FIND THE TRANSPOSE OF THE MATRIX

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;



int main(){
    int p,q;
    cout<<"Enter The Rows      :";
    cin>>p;
    cout<<"Enter The Columns   :";
    cin>>q;
    int matrix[p][q];

    cout<<endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout<<"Element "<<(i+1)<<(j+1)<<" : ";
            cin>>matrix[i][j];
            }
    }


	//A NEW MATRIX TO STORE THE TRANSPOSE OF MATRIX FROM THE USER
	int matrix_transpose[p][q];

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			matrix_transpose[i][j] = matrix[j][i];
		}
	}

	//PRINT OUT THE TRANSPOSE MATRIX

	cout<<"Transpose of the Matrix :"<<endl;

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout<<matrix_transpose[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

	}

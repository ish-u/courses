//Lower_half display of array.

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;


int main(){
    int p;
    cout<<"Enter The Size of Square Matrix :";
    cin>>p;
    int matrix[p][p];

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout<<"Element "<<(i+1)<<(j+1)<<" : ";
            cin>>matrix[i][j];
            }
    }
    cout<<"LowerHalf"<<endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }



    return 0;
}





//sum of each row and column of an matrix

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
    int sum = 0;

    //ROW SUM
    cout<<'\n'<<"ROW SUM -> "<<endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0;j < q; j++)
        {
            sum = sum + matrix[i][j];
        }
        cout<<"Row"<<i+1<<" Sum :"<<setw(8)<<sum<<endl;
        sum = 0;
    }

    sum = 0;
        //COLUMN SUM
    cout<<'\n'<<"COLUMN SUM -> "<<endl;
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {
            sum = sum + matrix[j][i];
        }
        cout<<"Column"<<i+1<<" Sum :"<<setw(5)<<sum<<endl;
        sum = 0;
    }

    return 0;
}




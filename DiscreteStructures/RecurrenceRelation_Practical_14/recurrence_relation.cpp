#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
14. Write a program to accept an input n from the user and graphically represent the values of
T(n) where n varies from 0 to n for the recurrence relations. For e.g. T(n) = T(n-1) + n,
T(0) = 1, T(n) = T(n-1) + n^2, T(0) =1, T(n) = 2*T(n)/2 + n, T(1)=1.
*/
//T(n) = T(n-1) + n, T(0) = 1;
int relation_1(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n + relation_1(n-1); 
    }
}

//T(n) = T(n-1) + n^2, T(0) = 1;
int relation_2(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return pow(n,2) + relation_2(n-1);
    }
}

//T(n) = 2*T(n)/2 + n, T(1)=1;
int relation_3(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return 2*relation_3(n/2) + n;
    }
    
}
int main(void)
{
    int choice,n;
    int flag = 1;
    cout<<"RECURRENCE RELATION\n";
    do
    {
        cout<<setfill('-')<<setw(30)<<"\n"; 
        cout<<"Which relation you want to find : \n\n"
            <<"1. T(n) = T(n-1) + n, T(0) = 1 \n"
            <<"2. T(n) = T(n-1) + n^2, T(0) = 1 \n"
            <<"3. T(n) = 2*T(n)/2 + n, T(1)=1\n\n";
        cout<<"Choice : ";
        cin>>choice;
        if(choice < 1 || choice > 3)
        {
            flag = 0;
            cout<<"Exitng...";
            break;
        }
        cout<<"Enter n : ";
        cin>>n;
        if(n < 0)
        {
            flag = 0;
            cout<<"Arithemetic Error";
            break;
        }
        switch (choice)
        {
        case 1:
            cout<<"T("<<n<<") : "<<relation_1(n);
            break;
        case 2:
            cout<<"T("<<n<<") : "<<relation_2(n);
            break;
        case 3:
            cout<<"T("<<n<<") : "<<relation_3(n);
            break;
        }
        cout<<"\n";
    }
    while(flag);
    return 0;
}
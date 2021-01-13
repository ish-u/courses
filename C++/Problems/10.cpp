//Linear SEARCH 

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    //LINEAR SEARCH
    cout<<"Enter The number of Elements you want in your array : ";
    int n;
    cin>>n;
    if (n == 0)
    {
        cout<<"Terminating ...";
        return 1;
    }

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter The Element you want to search in your array : ";
    int ele;
    cin>>ele;
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            cout<<"The element "<<ele<<" is at the :"<<endl;
            cout<<"Index :"<<(i)<<endl;
            cout<<"Position : "<<(i+1)<<endl;
            flag = 1;
        }

    }
    if(flag == 0){
        cout<<"The element is not found";
    }
    return 0;
}


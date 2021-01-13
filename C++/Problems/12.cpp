//FIND THE LARGEST AND THE SMALLEST ELEMENT IN AN ARRAY;

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;


int main()
{
    cout<<"How may elements you want in your array: ";
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int largest = arr[0];
    int smallest = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }

        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }


    cout<<"The largest element of the array is :"<<largest<<endl;
    cout<<"The smallest element of the array is :"<<smallest<<endl;

    return 0;
}



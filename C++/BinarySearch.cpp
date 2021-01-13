// Binary Search {Ascending and Descending}
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

void selAsc(int *a,int n);
void selDsc(int *a,int n);
void show(int a[],int n);
int binarySearchAsc(int a[],int n,int b);
int binarySearchDsc(int a[],int n,int b);


int main(){

    int arr[10] = {0,5,2,55,66,1,9,7,6,3};
    selDsc(arr,10);
    show(arr,10);
    binarySearchDsc(arr,10,55);


}

int binarySearch(int a[],int n,int b)
{
    int first, mid, last;
    first = 0;
    last = n -1;
    while(first <= last)
    {
        mid  = (first + last)/2;
        if (a[mid] == b )
        {
            cout<<"Found You !"<<endl;
            return b;
                    }
        else if ( b > a[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    return 1;

}

int binarySearchDsc(int a[],int n,int b)
{
    int first, mid, last;
    first = 0;
    last = n -1;
    while(first <= last)
    {
        mid  = (first + last)/2;
        if (a[mid] == b )
        {
            cout<<"Found You !"<<endl;
            return b;
                    }
        else if ( b < a[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    return 1;

}


void show(int arr[],int n)
{
    for (int x = 0; x < n; x++)
    {
        cout<<arr[x]<<" ";
    }
    cout<<endl;

}



void selAsc(int *arr,int n)
{
    int temp;
    int *ptr,*ptr_2;
    for (ptr = arr; ptr < &arr[n]; ptr++)
    {
        for (ptr_2 = arr; ptr_2 <  &arr[n]; ptr_2++)
        {
            if (*ptr_2 > *ptr)
            {
                temp = *ptr_2;
                *ptr_2 = *ptr;
                *ptr = temp;
            }

        }
    }
}

void selDsc(int *arr,int n)
{
    int temp;
    int *ptr,*ptr_2;
    for (ptr = arr; ptr < &arr[n]; ptr++)
    {
        for (ptr_2 = arr; ptr_2 <  &arr[n]; ptr_2++)
        {
            if (*ptr_2 < *ptr)
            {
                temp = *ptr_2;
                *ptr_2 = *ptr;
                *ptr = temp;
            }

        }
    }
}





// SELECTION SORT {Ascending and Descending}
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

void selAsc(int *a,int n);
void selDsc(int *a,int n);

int main(){

    int arr[10] = {2,10,3,55,5,6,1,77,38,0};
    selAsc(arr,10);
    for (int x = 0; x < 10; x++)
    {
        cout<<arr[x]<<" ";
    }

    selDsc(arr,10);
    for (int x = 0; x < 10; x++)
    {
        cout<<arr[x]<<" ";
    }

    return 0;

}

void selAsc(int *arr,int n)
{
    int temp;
    int *ptr,*ptr_2;
    for (ptr = arr; ptr < &arr[n-1]; ptr++)
    {
        for (ptr_2 = arr; ptr_2 <  &arr[n-1]; ptr_2++)
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
    for (ptr = arr; ptr < &arr[n-1]; ptr++)
    {
        for (ptr_2 = arr; ptr_2 <  &arr[n-1]; ptr_2++)
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





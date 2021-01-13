#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
void b_search(int *,int , int );
void s_sort(int *,int n);

int main(int argc, char *argv[])
{
    int a[10] = {1,5,3,4,2,22,5,555,865,223};
    int b[10] = {2,55,6,4,9,8,8,999,6,5};
    s_sort(a,10);
    b_search(a,10,865);

    return 0;
}

void s_sort(int *arr, int n)
{
    int *ptr_1;
    int *ptr_2;
    int temp;
    for(ptr_1 = arr; ptr_1 <= &arr[n-1]; ptr_1++)
    {
        for(ptr_2 = arr; ptr_2 <=&arr[n-1]; ptr_2++)
        {
            if(*ptr_1 > *ptr_2)
            {
                temp = *ptr_1;
                *ptr_1 = *ptr_2;
                *ptr_2 = temp;
            }
        }
    }
}

void b_search(int *a, int n,int c)
{
    int first = 0;
    int last = n-1;
    int mid;
    while(first <= last )
{
        mid = (first+last)/2;
        if(c > a[mid])
        {
                last = mid - 1;
        }
        else if(c < a[mid])
        {
            first = mid + 1;
        }
        else if(c == a[mid])
        {
            cout<<"Found\nIndex :"<<(mid+1);
            break;
        }
        else
        {
            cout<<"Not found";
        }
    }

}


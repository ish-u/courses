#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
void s_sort(int *, int );

int main(int argc, char *argv[])
{
    int a[10] = {1,5,3,4,2,22,5,555,865,223};
    int b[10] = {2,55,6,4,9,8,8,999,6,5};
    int s1 = sizeof(a)/sizeof(a[0]);
    int s2 = sizeof(b)/sizeof(b[0]);
    int s = s1+s2;
    int c[s];
    for(int i = 0; i < s1 ; i++)
    {
        c[i] = a[i];
    }

    for (int j = 0; j < s2; j++)
    {
        c[s1+j] = b[j];
    }
    s_sort(c,s);
    for(int i = 0; i < s; i++)
    {
        cout<<c[i]<<" ";
    }

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

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n;  //var for elements of array
    cout<<"Enter the number of elements you want in your array:\t";
    cin>>n;

    int arr[n]; //array of size n

    cout<<"Enter the number of elements in an array:\n";

    //loop to take input of 'n' elements of array
    for(int i = 0; i < n; ++i)
    {
        cout<<(i+1)<<":";
        cin>>arr[i];
    }
    cout<<"Array without duplicate elements  : ";

    //loop to delete duplicate elements of array
    for(int i = 0 ; i < n; i++)
    {
        for(int j = i+1; j < n; )
        {
            //condition to compare kth element with (n-k) elements of array
            //starting from (k+1)th element
            if(arr[i] == arr[j])
            {
                //loop to shift all the elements from where a duplicate is found
                for (int k = j; k < n; k++)
                {
                    arr[k] = arr[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
            //every time  a duplicate is found the total number of elements of array are
            //decremented by 1

            //every time a duplicate is not found the index of array is incremented by 1
            //it
        }
    }

    for (int a = 0; a < n; a++)
    {
        cout<<arr[a]<<"  ";
    }
    return 0;
}

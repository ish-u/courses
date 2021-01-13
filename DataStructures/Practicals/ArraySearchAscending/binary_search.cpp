#include <iostream>
using namespace std;

int main()
{
    int size = 10;
    int search = 0;
    cout<<"Array Search \n";
    cout<<"Enter the Numer of Elements in the Array : "; cin>>size;
    int *A = new int[size];
    for(int i = 0; i < size; i++)
    {
        A[i] = 0;
    }
    cout<<"Enter the Elements in the Array : ";
    for(int i = 0; i < size; i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the element you want to search : "; cin>>search;
    //sorting the array in asceding order using Insertion Sort
    for(int i = 1; i < size; i++)
    {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    cout<<"Sorted Array :";
    for(int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    //using Binary Search to find the Element
    int start = 0;
    int end = size - 1;
    int middle = 0;
    while(start <= end)
    {
        middle = (start+end)/2;
        if(search == A[middle])
        {
            cout<<"Element Found; Index : "<<middle;
            return 0;
        }
        else if(search > A[middle])
        {
            start = middle + 1;
        }
        else if(search < A[middle])
        {
            end = middle - 1;
        }
    }
    cout<<"Element Not Found\n";
    return -1;
}
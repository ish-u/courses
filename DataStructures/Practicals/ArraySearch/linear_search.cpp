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
    //searching
    for(int i = 0; i < size; i++)
    {
        if(A[i] == search)
        {
            cout<<"Element Found; Index : "<<i;
            return 0;
        }
    }
    cout<<"Element Not Found\n";
    return -1;
}
#include <iostream>
#include <iomanip>
using namespace std;

//using Heap's Algorithm - https://en.wikipedia.org/wiki/Heap%27s_algorithm
//to generate permutation(without repetition)
int permutation(int* a, int size,int n);

//to generate permutation(with repetition)
int permutationR(int* a, int size,int n,int* temp);

//to console output array
int print(int *a,int n);

//to swap two elements
void swap(int *a,int x,int y);

int main(void)
{
    int n, choice;
    cout<<setw(35)<<"| PERMUTATION GENERATOR |\n";
    cout<<setfill('-')<<setw(40)<<" "<<"\n";
    cout<<"How manny elements are there in your sequence : ";
    cin>>n;
    int* a = new int[n];
    int* temp = new int[n];
    //taking input 
    cout<<"Enter the elements : ";
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cout<<"1. Permutation with Repetition.\n"
        <<"2. Permutation without Repetition.\n"
        <<"What do you want to perform ? : ";
    cin>>choice;
    cout<<setfill('-')<<setw(40)<<" "<<"\n";
    switch (choice)
    {
    case 1:
        cout<<"Permutataions : \n";
        permutationR(a,n,0,temp);
        break;
    case 2:
        cout<<"Permutataions : \n";
        permutation(a,n,n);
        break;
    default:
        cout<<"Error...";
        break;
    }
    cout<<setfill('-')<<setw(40)<<" "<<"\n";
    delete[] temp;
    delete[] a;
    return 0;
}

//Permutation with Repetition
int permutation(int *a, int size,int n)
{
    //if size = 1 print the array
    if(size == 1)
    {
        print(a,n);
    }
    else
    {
        //permutation for kth element unaltered
        permutation(a,size-1,n);
        //permutation for kth element swapped with each of k-1 elements
        for(int i = 0; i < size-1; ++i)
        {
            //if k is even swap i-th and k-th element
            //else swap 0-th and k-th element
            if(size%2 == 0)
            {
                swap(a,i,size-1);
            }
            else
            {
                swap(a,0,size-1);
            }
            permutation(a,size-1,n);

            
        }
    }
    

}

//Permutation with Repetition
int permutationR(int* a, int size,int n,int *temp)
{
    if(n == size)
    {
        print(temp,n);
    }
    else
    {
        for(int i = 0; i < size; ++i)
        {
            temp[n] = a[i];
            permutationR(a,size,n+1,temp);
        }
    }
    
}

//print() function
int print(int *a,int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

//swap() function
void swap(int *a,int x,int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}


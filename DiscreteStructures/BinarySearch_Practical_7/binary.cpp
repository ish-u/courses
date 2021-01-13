#include <iostream>
using namespace std;

//binarySearch() function
void binarySearch(int *a, int start, int end, int b);
//bubbleSort()
void bubbleSort(int *a, int n);

int main(void)
{
    cout<<"| BINARY SEARCH |\n";
    int n;
    cout<<"How may elements you want in your array : "; cin>>n;
    if(n<=0)
    {
        cout<<"Exiting...";
        return -1;
    }
    int a[n];
    cout<<"Enter Array : ";
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);
    cout<<"Sorted Array : ";
    for(int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
    int f;
    cout<<"\nWhich Element You Want To Find : "; 
    cin>>f;
    binarySearch(a,0,n,f);
    
    return 0;
}

void bubbleSort(int *a, int n)
{
    int temp;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void binarySearch(int *a, int start, int end, int b)
{
    if(start <= end)
    {
        int middle = (start+end-1)/2; 
        if(b == a[middle])
        {
            cout<<"Found! \nLocated At "<<(middle+1);
        }
        
        if(b > a[middle])
        {
            binarySearch(a,middle+1,end,b);
        }

        binarySearch(a,0,middle-1,b);
        
    }
    else
    {
        cout<<"Not Found!!";
    }
    
}


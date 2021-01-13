#include <iostream>

using namespace std;

int fibonacci(int n);

int main(void)
{
    int n;
    cout<<"Enter the number of elements you want in your Fibonacci Sequence : "; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    return 0;
}

int fibonacci(int n)
{
    //fibonacci sq - 0 1 1 2 3 5 8 ...
    //{[a(n) = a(n-2) + a(n-1)] for 2<=n} and a(0) = 0 and a(1) = 1 
    //usiing recurrence
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-2)+fibonacci(n-1);
    }
    
   return 0;
}
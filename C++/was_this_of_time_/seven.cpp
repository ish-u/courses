#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
int gcd(int a, int b);

int main(int argc, char *argv[])
{
    cout<<"Enter the two numbers:\n";
    int a,b;
    cout<<"a:"; cin>>a;
    cout<<"b:"; cin>>b;
    gcd(a,b);

    return 0;
}

int gcd(int a, int b)
{
    int z;
    if(a > b)
    {
        z = b;
    }
    else
    {
        z = a;
    }
    for(int i = 1; i < z; i++)
    {
        if(a % z== 0 && b%z ==0)
        {
            cout<<"GCD is "<<z;
            return 0;
        }
    }
    cout<<"NO GCD ";
    return 1;
}


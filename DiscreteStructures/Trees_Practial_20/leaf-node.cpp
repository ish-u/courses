#include <iostream>
using namespace std;

int main(void)
{
    int m,i,l;
    cout<<"Enter the value of m : "; cin>>m;
    cout<<"Enter the value of i : "; cin>>i;
    l = i*(m-1) + 1;
    cout<<"The m-ary tree with m = "<<m<<" and i = "<<i<<" has "<<l<<" leaf nodes";
    return 0;
}
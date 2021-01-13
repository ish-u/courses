#include <iostream>

using namespace std;
int divide(int &x, int &y);

int main(int argc, char *argv[])
{
    int p,q;
    cout<<"Enter p:"; cin>>p;
    cout<<"Enter q:"; cin>>q;
    try
    {
        divide(p,q);
    }
    catch(int x)
    {
        cout<<"Exception can\'t  divide by zero";
    }

}

int divide(int &x ,int &y)
{
    if(y == 0)
    {
        throw 0;
    }
    else
    {
        cout<<x<<"/"<<y<<" is :"<<x/y;
    }

}




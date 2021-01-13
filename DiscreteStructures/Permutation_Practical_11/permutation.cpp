#include <iostream>
#include <iomanip>
using namespace std;

//factorial function
int factorial(int n)
{

    if(n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

//permutation function
int pertmutation(int n, int r)
{
    if(n < 0 || r < 0)
    {
        return 0;
    }
    return factorial(n)/factorial(n-r);
}

//combination function
int combination(int n,int r)
{
    if(n < 0 || r < 0)
    {
        return 0;
    }
    return pertmutation(n,r)/factorial(r);
}
int main(void)
{
    cout<<setw(15)<<"|P 'n C |"<<"\n";
    cout<<setfill('-')<<setw(20)<<"\n";
    int flag = 1;
    int choice = 0;
    int n,r;
    do
    {
        cout<<"1. Permutation.\n";
        cout<<"2. Combination.\n";
        cout<<"What do you want to do : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter n :";
                cin>>n;
                cout<<"Enter r :";
                cin>>r;
                cout<<"P("<<n<<","<<r<<") : "<<pertmutation(n,r)<<"\n";
                cout<<setfill('-')<<setw(20)<<"\n";
                break;
            case 2:
                cout<<"Enter n :";
                cin>>n;
                cout<<"Enter r :";
                cin>>r;
                cout<<"C("<<n<<","<<r<<") : "<<combination(n,r)<<"\n";
                cout<<setfill('-')<<setw(20)<<"\n";
                break;
            default:
                cout<<"Exiting...";
                flag = 0;
                break;
        }
        
    } while (flag);
    
    return 0;
}
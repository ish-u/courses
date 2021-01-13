#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Customer
{
    private:
        char name[10];
        int acc_number;
        int time_period;
        int amt;
    public:
        Customer()
        {
            cout<<"\nINITIALIZING CLASS CUSTOMERS\n";
        }
        void get_input();
        void show();
        void withdrawal();


};

void Customer :: get_input()
{
    cout<<"__________________\n";
    cout<<"Enter Name: "; cin>>name;
    cout<<"Enter Account Number: "; cin>>acc_number;
    cout<<"Enter Time Period :"; cin>>time_period;
    cout<<"Enter Amount : "; cin>>amt;
}

void Customer :: show()
{
    cout<<"====================\n";
    cout<<"Name: "<<name;
    cout<<"\nAccount Number: "<<acc_number;
    cout<<"\nTime Period :"<<time_period;
    cout<<"\nAmount : "<<amt;
    cout<<"\n====================\n";
}

void Customer :: withdrawal()
{
    if (time_period > 2)
    {
        show();
    }
}

int main()
{

    Customer Bank[2];
    for (int i = 0; i < 2; i++)
    {
        Bank[i].get_input();
    }
    for (int i = 0; i < 2; i++)
    {
        Bank[i].show();
    }
    return 0;


}


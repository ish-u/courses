#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    cout<<"\n::ENTER THE DETAILS OF THE EMPLOYEE::\n\n";
    float basic,hra,allowance,tax,subtotal,total,emp_no;
    char name[20];
    char post[10];

    cout<<"ENTER THE NAME OF EMPLOYEE"<<setw(20)<<":";
    cin>>name;
    cout<<"ENTER EMPLOYEE NUMBER"<<setw(25)<<":";
    cin>>emp_no;
    cout<<"ENTER THE POSITION OF EMPLOYEE IN COMPANY"<<setw(5)<<":";
    cin>>post;
    cout<<"ENTER THE BASIC PAY OF EMPLOYEE"<<setw(15)<<":";
    cin>>basic;

    hra = 0.1*basic;
    allowance = 0.12*basic;
    subtotal = hra+allowance+basic;
    tax = 0.07*subtotal;
    total = subtotal-tax;

    cout<<"\n\t\tPAY SLIP";
    cout<<"\n\n";
    cout<<"NAME"<<setw(24)<<name<<endl;
    cout<<"EMPLOYEE NUMBER"<<setw(10)<<emp_no<<endl;

    cout<<"\n\n";
    cout<<"BASIC"<<setw(19)<<":   "<<basic<<endl;
    cout<<"HRA"<<setw(21)<<":  +"<<hra<<endl;
    cout<<"ALLOWANCE"<<setw(15)<<":  +"<<allowance<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"SUBTOTAL"<<setw(16)<<":   "<<subtotal<<endl;
    cout<<"TAX"<<setw(21)<<":  -"<<tax<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"TOTAL"<<setw(19)<<":   "<<total<<endl;
	
	return 0;


}


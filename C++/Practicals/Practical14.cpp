#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;


void gcd();
void factorial();
void fibonacci();

int main(void)
{
	int choice;
    cout<<"1. Display fibonacci series.\n";
	cout<<"2. Calculate factorial of a number.\n";
	cout<<"3. Calculate GCD.\n\n";

	cout<<"Enter Choice: "; cin>>choice;
	switch(choice)
	{
		case 1:
			fibonacci();
			break;
		case 2:
			factorial();
			break;
		case 3:
			gcd();
			break;
		default:
			cout<<"Wrong Choice Exiting\n";
	}

    return 0;
}

void fibonacci()
{
	int n,temp;
	cout<<"\nHow many number do you want? :  "; cin>>n;
	int one = 1;
	int second = 1;

	cout<<"1 1 ";
	for (int i = 0; i < n - 2; ++i)
	{
		temp = second;
		second = second + one;
		one = temp;
		cout<<second<<" ";
	}
}
void factorial()
{
    int n;
    int fact = 1;
    cout<<"\nEnter the Number: "; cin >>n;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }

    cout<<"Factorial of "<<n<<" is: "<<fact<<endl;


}
void gcd()
{
    int a,b,large,small,g;
    cout<<"Enter Two Digits :\n";
    cout<<"a: "; cin>>a;
    cout<<"b: "; cin>>b;

    if (a > b)
    {
        large = a;
        small = b;
    }
    else
    {
        large = b;
        small = a;
    }


    for (int i = 1; i <= small ; ++i )
    {
        if (small % i == 0 && large % i == 0)
        {
            g = i;
        }
    }
    cout<<"GCD :"<<g;

}







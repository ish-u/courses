#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;


// FOR A NUMBER NOT BEING PRIME THE PROGRAM RETURNS WITH AN EXIT CODE 1
// FOR A NUMBER BEING PRIME THE PROGRAM RETURN WITH AN EXIT CODE 0
int prime(int n);
void hundred();

int main(void)
{
	int choice,n;
	cout<<"1. Find whether a number is prime or not.\n";
	cout<<"2. Find all the prim numbers b/w 0 and 100\n";
	cout<<"\nEnter Your Choice: ";
	cin>>choice;


	switch(choice)
	{
		case 1:
			cout<<"Enter The Digit: ";
			cin>>n;
			prime(n);
			cout<<"A PRIME NUMBER";
			break;
		case 2:
		    hundred();
		    break;
        default:
            cout<<"ENTER A VALID CHOICE"<<endl;
            exit(1);
	}


	return 0;

}

int prime(int n)
{
    if(n == 1)
    {
        cout<<"A PRIME NUMBER"<<endl;
    }
    else
    {
        for(int i = 2; i < n; i++){

            if(n % i == 0){
                cout<<"NOT A PRIME NUMBER "<<endl;
                exit(1);
            }
        }
    }
	return 0;
}

void hundred()
{
	int counter = 0;
	cout<<"\nAll Prime Numbers b/w 0 and 100: ";
	for(int i = 1; i < 100; i++)
	{
		for (int j = 1; j <= i;j++)
		{
			if(i % j == 0)
			{
				counter++;
			}
		}

		if (counter == 2)
		{
			cout<<i<<" ";
		}
		counter = 0;
	}
	cout<<endl;
}

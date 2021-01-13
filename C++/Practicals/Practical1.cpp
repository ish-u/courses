
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <ctype.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter The Number :";
	cin>>n;

	int sum = 0;
	int product = 1;
	int digit, temp = n;

	for (int i = 0; temp != 0; i++)
	{

		digit = temp%10;
		sum = sum + digit;
		temp = temp/10;
	}
	cout<<"The Sum Of All the Digit of the Number is  :"<<sum<<endl;
	temp = n;

	for (int i = 0; temp != 0; i++)
	{
		digit = temp%10;
		product = product * digit;
		temp = temp/10;
	}
	
	cout<<"The Products of All Digits of the Number is :"<<product;
    
    cout<<endl;
}

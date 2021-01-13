#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{

	int n;
	cout<<"Enter The Number : ";
	cin>>n;
    int digit;
    int temp = n;

    cout<<"The Number in reverse is  : ";
	for(int i = 0; temp != 0; i++)
	{
		digit = temp%10;
		cout<<digit;
		temp = temp / 10;
	}
	
		
}
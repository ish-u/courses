#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{

	int n;
	cout<<"Enter The Number of element you want in series: ";
	cin>>n;
	
	float sum = 0;
	
	for(float i = 1; i <= n; i++)
	{
		sum = sum + (1/i);
	}
	cout<<sum;
	return 0;
		
		
}
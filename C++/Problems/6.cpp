#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout<<"How many elements you want to sum of the following series : \n S = 1 + x + (x)^2 + ... + (x)^n : \n";
	cin>>n;
	cout<<" x = ";
	int z;
	cin>>z;
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += pow(z,i);
	}

	cout<<sum;


}


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <ctype.h>
using namespace std;

int main(int argc, char** argv)
{

	
	cout<<"1 - 2 + 3 - 4 + 5 - 6..."<<endl;
	cout<<"How many terms do you want to add in the above series: ";
	int n;
	cin>>n;

	int sum = 0,sumEven = 0,sumOdd = 0;
	
	for(int i = 0; i <= n; i++){
		if(i % 2 == 0)
		{
			sumEven = sumEven + i;
		}
		else if(i % 2 != 0)
		{
			sumOdd = sumOdd + i;
		}
	}
	
	sum = sumOdd - sumEven;
	
	cout<<"The Sum of "<<n<<" terms of the given series is: "<<sum<<endl;
	return 0;
		
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;


void factor();

int main(void)
{
	factor();	
	return 0;	
}


void factor()
{
	int n;
	cout<<"Enter The Digit: ";
	cin>>n;
	cout<<"The Factors of "<<n<<" are : ";
	for(int i = 1; i <= n; i++){
		
		if(n % i == 0){
			cout<<i<<" ";
		}
	}
	
}




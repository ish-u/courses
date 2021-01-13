#include <iostream>

using namespace std;

int main()
{

	float celciusTemp, faranTemp, result;

	cout<<"Enter The Temperture in Celcius";
	cin>>celciusTemp;

	result = (( 9/5)*celciusTemp) + 32;

	cout<<"Temperature in Faranhiet is: "<<setprecision(5)<<setw(10)<<result;

	return 0;


}

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"How many odd numbers you want to print: ";
	cin>>n;
	cout<<"The First "<<n<<" odd numbers in descending order are : ";

	for(int i = n -1; i >= 0; --i)
	{
		cout<<((2*i) + 1)<<" ";
	}


}

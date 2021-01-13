#include <iostream>

using namespace std;
void swapNum(int *a, int *b);

int main()
{
	int a,b;
	int *ptra,*ptrb;
	cout<<"Enter two numbers"<<endl;
	cout<<"a: "; cin>>a;
	cout<<"b: "; cin>>b;

	ptra = &a;
	ptrb = &b;

	cout<<"Numbers before Swapping: \n";
	cout<<"a: "<<a;
	cout<<"\nb: "<<b;
	swapNum(ptra,ptrb);

	cout<<"\nNumbers after Swapping: \n";
	cout<<"a: "<<a;
	cout<<"\nb: "<<b;

}

void swapNum(int *a, int *b)
{
     int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

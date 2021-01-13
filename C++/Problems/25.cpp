#include <iostream>
#include <stdio.h>

using namespace std;

class Fraction{
	private:
		int n;
		int d;
	public:
		Fraction()
		{
			n = 1;
			d = 1;
		}
		
		void input()
		{
			cout<<"Fraction ";
			cin>>n;
			cout<<"/";
			cin>>d;	
			
		}
		
		void add(Fraction a)
		{
			n = (n * a.d) + (a.n * d);
			d = d * a.d;  
		}
		
		void display()
		{
			cout<<"Fraction";
			cout<<n;
			cout<<d;
		} 
}


int main()
{

	Fraction a;
	Fraction b;
	
	a.input();
	b.input();
	return 0;	
}
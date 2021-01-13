#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.H>
#include <conio.h>



int main(){
	
	cout<<setfill(' ')<<setw(20)<<"WELCOME TO NUMBER PYRAMID";
	int n;
	
	cout<<"\nEnter A Number b/w (0 - 32767) : ";
	cin>>n;

	

		
	
	for(int i = 0; i<5;i++){
		int x =n;
		for(int j = 5; j>i;j--){
		int z = x%10;
		x = x/10;
		cout<<z<<"  ";
	}
		n = n/10;
		cout<<endl;
	}

}

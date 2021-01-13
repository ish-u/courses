#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.H>
#include <conio.h>



int main(){
	
float value;
char type;

cout<<setfill(' ')<<setw(30)<<"CONVERT TO INCHES"<<endl;
cout<<"\nEnter the type of measurement you want to convert to inches"<<endl;
cout<<"F - Foot"<<endl;
cout<<"C - Centimeter"<<endl;
cout<<"Y - Yard"<<endl;
cout<<"M - Meter"<<endl;
cin>>type;

cout<<"\nEnter The Value: ";

if(type == 'f' || type == 'F' || type == 'C' || type == 'c' || type == 'Y' || type == 'y' || type == 'M' || type == 'm'){

cin>>value;

switch(type){
	
	case 'f':
	case 'F':
		cout<<"The Value in inches is : "<<(value*12.0);
		break;
	case 'C':
	case 'c':
		cout<<"The Value in inches is : "<<(value*2.54);
		break;
	case 'Y':
	case 'y':
		cout<<"The Value in inches is : "<<(value*36.0);
		break;
	case 'M':
	case 'm':
		cout<<"The Value in inches is  : "<<(value*39.37);
		break;
	
		
	
	
	}
}else{
	cout<<"PLEASE ENTER A VALID TYPE";
}






}

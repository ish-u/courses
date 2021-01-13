#include <iostream>

int main(){
	int value1 = 0;   //change value1 and value2 to get different fabionacci sequence as per need
	int value2 = 1;
	int value;
	int n;
	cout<<"How mny numbers of the series you want : ";
	cin>>n;
	
	cout<<value1<<","<<value2;
	for(int i = 1; i < n; i++){
		value = value1 + value2;
		cout<<"The Required Series is : "
		cout<<","<<value;
		
		value1 = value2;
		value2 = value;
		
	}
}
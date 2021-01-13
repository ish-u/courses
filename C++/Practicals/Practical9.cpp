#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;



void getInput(int n,int a[]);
void avg(int n, int a[]);
void printEven(int a[],int n);
void printOdd(int a[],int n);
void max(int a[],int n);
void min(int a[],int n);
void rev(int a[],int n);
void dup(int a[],int n);

int main() {
	int again = 1;
	do{
		int choice;
		cout<<"1. "<<"Find the Average of all the numbers of an array."<<endl;
		cout<<"2. "<<"Find all the Even Numbers in an array."<<endl;
		cout<<"3. "<<"Find all the Odd Numbers in an array."<<endl;
		cout<<"4. "<<"Find the Largest Number of an array."<<endl;
		cout<<"5. Find the Smallest Number of an array."<<endl;
		cout<<"6. Print an array in reverse."<<endl;
		cout<<"7. Remove Duplicate Elements from the array."<<endl;
		cout<<endl;
		cout<<"What Do You Wanna Perform : ";
		cin>>choice;
		if (choice <= 0 || choice >= 8)
		{
			cout<<"Terminating .....";
			return 1;
		}
		cout<<"Enter the Number of Elements you want in your array: ";
		int n;
		cin>>n;
		cout<<"Enter The Elements: "<<endl;
		int a[n];
		getInput(n,a);
	
		
		switch(choice)
		{
			case 1:
				avg(n,a);
				break;
			case 2:
				printEven(a,n);
				break;
			case 3:
				printOdd(a,n);
				break;
			case 4:
				max(a,n);
				break;
			case 5:
				min(a,n);
				break;
			case 6:
				rev(a,n);
				break;
			case 7:
				dup(a,n);
				break;
				
				
		}
		cout<<endl;
		cout<<"DO YOU RESTART: "<<endl;
		cout<<"1 - restart"<<endl;
		cout<<"0 - terminate"<<endl;
		cin>>again;
		if(again == 0){
			cout<<"Terminating";
		}
		else{
			cout<<"restarting...."<<endl;
			again = 1;
		}
		/*
		printEven(a,n);
		printOdd(a,n);
		max(a,n);
		min(a,n);
		rev(a,n);
		dup(a,n);	
		*/
	}
	while(again);
	return 0;
}

void getInput(int n, int a[])
{
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
}

void avg(int n, int a[]){
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	cout<<"The Average : "<<(float)(sum)/(float)n;
}

void printEven(int a[],int n)
{
	cout<<"The even Elements Of the Array are : ";
	for(int i = 0; i < n; i++ )
	{
		if(a[i]%2 == 0){
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
}

void printOdd(int a[],int n)
{
	cout<<"The Odd Elemnents of the Array are : ";
	for (int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0)
		{
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
}

void max(int a[],int n)
{
	int largest = a[0];
	for (int i = 1; i < n; i++)
	{
		if(largest < a[i]){
			largest = a[i];
		}
	}
	cout<<"The Largest Element Of the Array is : "<<largest<<endl;
}

void min(int a[],int n)
{
	int smallest = a[0];
	for (int i = 0; i < n; i++)
	{
		if(smallest > a[i])
		{
			smallest = a[i];
		}
	}
	cout<<"The Smallest Element Of the Array is : "<<smallest<<endl;
}

void rev(int a[],int n)
{
	cout<<"REVERSE: "<<a[n-1];
	for(int i = n - 2; i >= 0; i--)
	{
		cout<<","<<a[i];
	}
	cout<<endl;
}

void dup(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n;)
		{
			if(a[j] == a[i]){
				for(int k = j  ; k < n ; k++)
				{
					a[k] = a[k+1];
					
				}
				n = n - 1;
			}
			else
			{
				j++;
			}
			
		}	
	}

	for(int z = 0; z < n; z++)
	{
		cout<<a[z]<<" ";
	}
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;


int stringlen(char a[]);
void strlenptr(char a[]);
void address(char a[]);
void concWO(char a[], char b[]);
void concW(char a[], char b[]);
void compareStr(char a[],char b[]);
void upper(char a[]);
void lower(char a[]);
void reverse(char a[]);
void vow(char a[]);




int main(int argc, char** argv){


	cout<<"      :DO STUFF WITH TWO STRINGS:    "<<endl;
	cout<<endl;
	cout<<setw(10)<<"1> Find The Memory Address of Two Strings. "<<endl;
	cout<<setw(10)<<"2> Concatenate Two Strings using 'strcat'. "<<endl;
	cout<<setw(10)<<"3> Concatenate Two Strings without using 'strcat'. "<<endl;
	cout<<setw(10)<<"4> Comapre The Length Of Two Strings. "<<endl;
	cout<<setw(10)<<"5> Uppercase all letters in Two Strings. "<<endl;
	cout<<setw(10)<<"6> Lowercase all letters in Two Strings. "<<endl;
	cout<<setw(10)<<"7> Reverse Strings."<<endl;
	cout<<setw(10)<<"8> Find the number of Vowels in each String"<<endl;
	cout<<setw(10)<<"9> Calculate the length of a string using pointers"<<endl;
	cout<<endl;
	int choice;

	int again = 1;

	do
	{
		cout<<"What function you wanna perform : ";
		cin>>choice;
		if(choice > 9)
		{
			cout<<"BAD CHOICE...EXITING";
			return 1;
		}
		char a[250];
		char b[250];
		cout<<"STRING A : ";
		cin>>a;
		cout<<"STRING B : ";
		cin>>b;


		switch(choice)
		{
			case 1:
				cout<<"String A: "<<endl;
				address(a);
				cout<<"String B: "<<endl;
				address(b);
				break;
			case 2:
				cout<<"Concatenate without the use of function 'strcat' :";
				concWO(a,b);
				break;
			case 3:
				cout<<"Concatenate with the use of function 'strcat' :";
				concW(a,b);
				break;
			case 4:
				cout<<"The Two Strings have the following relationship : ";
				compareStr(a,b);
				break;
			case 5:
				cout<<"String A: ";
				upper(a);
				cout<<"String B: ";
				upper(b);
				break;
			case 6:
				cout<<"String A: ";
				lower(a);
				cout<<"String B: ";
				lower(b);
				break;
			case 7:
				cout<<"String A ";
				reverse(a);
				cout<<"String B ";
				reverse(b);
				break;
			case 8:
				cout<<"The Number of Vowels in the String A : ";
				vow(a);
				cout<<"The Number of Vowels in the String B : ";
				vow(b);
				break;
			case 9:
				cout<<"The Length of Two Strings are: \n";
				cout<<"A: ";
				strlenptr(a);
				cout<<"\nB: ";
				strlenptr(b);

		}
		cout<<endl;
		char restart;
		cout<<"Type Y or N"<<endl;
		cout<<"Restart : ";
		cin>>restart;

		if(restart == 'Y' || restart == 'y')
		{
			cout<<"Restarting.........."<<endl;
		}
		else if(restart == 'N')
		{
			cout<<"Terminating";
			again = 0;

		}
		else{
			cout<<"Terminating";
			again = 0;

		}

		}


	while(again);

}








int stringlen(char a[]){

	int k = 0;
	for(int i = 0; a[i] != '\0'; i++)
	{
		k++;
	}
	return k;

}

void address(char a[]){
	for (int i = 0; i < stringlen(a); i++)
	{
		cout<<a[i]<<" "<<&a + sizeof(a[i])*i<<endl;
	}
	cout<<endl;


}

void concWO(char a[], char b[])
{
	int z = stringlen(a) + stringlen(b);
	char newStr[z];
	for(int i = 0; i < stringlen(a);i++)
	{
		newStr[i] = a[i];
	}
	for (int j = 0,k = stringlen(a); j < z; k++, j++)
	{
		newStr[k] = b[j];
	}
	cout<<newStr;

}

void concW(char a[], char b[])
{
	cout<<strcat(a,b);
}

void compareStr(char a[],char b[]){

	int x = stringlen(a);
	int y = stringlen(b);

	if(x == y)
	{
		cout<<"Equal";
	}
	else if(x > y)
	{
		cout<<"a > b";
	}
	else if(x < y)
	{
		cout<<"a < b";
	}
}

void upper(char a[])
{
	for (int i = 0; i < stringlen(a); i++)
	{
		if(a[i] >= 97 && a[i] < 123)
		{
			int cap = (int)a[i] - 32;
			cout<<(char)cap;
		}
		else if(a[i] >= 65 && a[i] < 91)
		{
			cout<<a[i];
		}
		else
		{
			cout<<a[i];
		}
	}
	cout<<endl;
}
void lower(char a[])
{
	for (int i = 0; i < stringlen(a); i++)
	{
		if(a[i] >= 65 && a[i] < 91)
		{
			int cap = (int)a[i] + 32;
			cout<<(char)cap;
		}
		else if(a[i] >= 97 && a[i] < 123)
		{
			cout<<a[i];
		}
		else
		{
			cout<<a[i];
		}
	}
	cout<<endl;


}

void reverse(char a[])
{
	cout<<"REVERSE : ";
	for(int i = stringlen(a) - 1; i >= 0; i--)
	{
		cout<<a[i];
	}
	cout<<endl;
}

void vow(char a[])
{
	int count = 0;
	for (int i = 0; i < stringlen(a); i++)
	{
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
		{
			count = count + 1;
		}
	}
	cout<<count<<endl;
}

void strlenptr(char a[])
{
	int length = 0;
	for (; *a != '\0'; a++)
	{
		length++;
	}
	cout<<length;

}

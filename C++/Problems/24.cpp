//VOTERS Example

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

struct Voter
{
	int id;
	char name[20];
	char addr[80];
	int age;
};

Voter voter[20];



int main(){

        for (int j = 0; j < 20; j++)
        {
            cout<<"VOTER : "<<(j+1)<<endl;
            cout<<"Name : ";
            gets(voter[j].name);
            cout<<"ID : ";
            cin>>voter[j].id;
            cout<<"Address :";
            gets(voter[j].addr);
            cout<<"Age :";
            cin>>voter[j].age;
            cout<<endl;
        }

        cout<<"All the voters above the age of 60 are :";
        for (int i = 0; i < 20; i++)
        {

            if (voter[i].age >= 60)
            {
                cout<<"Name: "<<voter[i]. name<<endl;
                cout<<"ID :"<<voter[i].id<<endl;
                cout<<"Address :"<<voter[i].addr<<endl;
            }
            cout<<"=============================="<<endl;
        }



	return 0;
}


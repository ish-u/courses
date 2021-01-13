//PROGRAM THAT REVERSES THE AN ENTERED LINE 

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char s[50];
    cout<<"Enter A String (Max Length - 50)"<<endl;
    cin.getline(s,50);          //INPUTS THE LINE
    int l = strlen(s);            //COUNTS THE LENGTH OF THE ENTERED LINE
    int counter = 0;
    cout<<"The reverse of the entered string is : \'";
    for(int i = l - 1; i >= 0; i--)
    {
       cout<<s[i];

    }
    cout<<"\'"<<endl;
    return 0;


}



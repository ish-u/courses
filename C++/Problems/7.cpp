//Program that converts all the spaces present in the string to hypen


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char s[50];
    cout<<"Enter A String (Max Length - 50)"<<endl;
    cin.getline(s,50);
    int l = strlen(s);
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            s[i] = '_';
        }

    }
    cout.write(s,l);
    return 0;


}



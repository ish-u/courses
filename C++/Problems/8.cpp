//PROGRAM THAT COUNTS THE NUMBER OF VOWELS IN  AN ENTERED LINE.


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
    for(int i = 0; s[i] != '\0'; i++)
    {
        switch(s[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            counter++;

        }

    }
    cout<<"The Following String \" ";
    cout.write(s,l);
    cout<<" \" has : "<<counter<<" vowels."<<endl;
    return 0;


}



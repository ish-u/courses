//NEEDS IMPROVEMENT


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;


int main(){


    char a[80];
    cout<<"Enter a line  (max word limit 80) :";
    cin.getline(a,80);
    int len = strlen(a);

    if (strlen(a) > 80)
    {
        cout<<"Not in Word Limit.";
        exit(0);
    }

    int counter = 0;    // Counts the number of words in a line

    for (int i = 0; i < len; i++)
    {
        if (a[i] == ' ')
        {
            counter++;
        }
    }

    cout<<"The number of words present in the entered line are : "<<counter + 1 ;

	return 0;

	}

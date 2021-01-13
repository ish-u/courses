#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void addr(char *);
void compare(char *, char *);
int length(char *);
void upper(char*);
void revrs(char *);

int main(int argc, char *argv[])
{
    char a[256];
    char b[256];
    cout<<"Enter String A:\t"; cin>>a;
    cout<<"Enter String B:\t"; cin>>b;

    int choice = 1;
    do
    {
        cout<<"\n\t\tDo stuff with strings:\n";
        char sel;
        cout<<"a. Find the address of each character of the strings\n";
        cout<<"b. Compare the two strings\n";
        cout<<"c. Find the length of the two strings\n";
        cout<<"d. Uppercase all the characters of the strings\n";
        cout<<"e. Reverse both the Strings\n";
        cout<<"\n\n";
        cout<<"Enter the Choice: "; cin>>sel;
        switch(sel)
        {
            case 'a':
            case 'A':
                cout<<"String A:"; addr(a);
                cout<<"String B:";addr(b);
                break;
            case 'b':
            case 'B':
                compare(a,b);
                break;
            case 'c':
            case 'C':
                cout<<"Length String A :"<<length(a);
                cout<<"\n";
                cout<<"Length String B :"<<length(b);
                break;
            case 'd':
            case 'D':
                cout<<"Uppercasing A and B:\n";
                upper(a); upper(b);
                cout<<a<<"\n"<<b;
                break;
            case 'e':
            case 'E':
                cout<<"Reversing Both the strings:\n";
                revrs(a);
                cout<<"\n";
                revrs(b);
                break;
            default:
                cout<<"Invalid Input";
                choice  = 0;
        }

    }
    while(choice);

    return 0;
}

void addr(char *a)
{
    cout<<"\n";
    for(int i = 0; a[i] != '\0'; i++)
    {
        cout<<a[i]<<"\t:"<<(void *)&a[i]<<"\n";
    }
}

int length(char *a)
{
    int length = 0;
    for(;*a != 0; a++)
    {
        length++;
    }
    return length;
}

void compare(char *a,char *b)
{
    int x = length(a);
    int y = length(b);
    if(x > y)
    {
        cout<<"String A is greater than String B\n";
    }
    else if (y < x)
    {
        cout<<"String B is greater than String A\n";
    }
    else if(x== y)
    {
        cout<<"Both Strings are Equal\n";
    }
}

void upper(char *a)
{
    for (int i = 0; a[i] != 0; i ++)
    {
        if(a[i] >= 'a')
        {
            a[i] = a[i] - 32;
        }
    }
}

void revrs(char *a)
{
    for(int i = length(a) - 1; i >= 0;i--)
    {
        cout<<a[i];
    }
}

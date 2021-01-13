#include <iostream>
#include <string.h>

using namespace std;

int palindrome(char a[]);

int main()
{
    //A STRING OF SIZE 256
    char str[256];

    cout<<"Enter String:";
    cin.getline(str,256);
    palindrome(str);

    return 0;
}


int palindrome(char a[])
{
     //START OF THE STRING
    int i = 0;
    //END OF THE STRING
    int j = strlen(a)-1;

    while(i < j)
    {
        if(a[i] != a[j])
        {
            cout<<"The given String is not a Palindrome\n";
            return 1;
        }
        i++;
        j--;
    }

    cout<<"The given String is a Palindrome\n";
    return 0;
}

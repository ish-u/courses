#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout<<"No string entered :/\n";
        cout<<"use - practicce.exe string";
        exit(1);
    }

    //temporary char
    char z = '\0';
    //a array of size 26
    int alpha[26];
    //initializing array
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 0;
    }
    //loop that runs through all the elements of agrv
    for (int i = 1; i < argc; i++)
    {
        //loop that runs through all the elements of argv[i]
        for (int j = 0; j < strlen(argv[i]); j++)
        {
            //storing argv[i][j] after converting it to lowercase
            z = tolower(argv[i][j]);
            //getting the value of z b/w 0-26
            z = z - 'a';
            //incrementing alpha array
            alpha[z]++;
        }
    }

    for(int i = 0; i < 26; i ++)
    {
        cout<<(char)('a'+i)<<"\t"<<alpha[i]<<"\n";
    }

    return 0;
}

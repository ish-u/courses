#include <iostream>
#include <ctype.h>
#include <string.h>
#include <iomanip>

using namespace std;

int main(int argc,char *argv[])
{
    if(argc == 1)
    {
        cout<<"NO SENTENCE ENTERED .."<<endl;
        exit(1);
    }

	char temp = 'a';
	int pos;

	//ARRAY TO KEEP COUNT OF ALPHABETS
	int alphabet[26];


	//INITAILIZING THE ARRAY WITH ALL ZEROS
	for (int i = 0; i < 26; i ++)
    {
		alphabet[i] = 0;

    }

	//LOOP TO CALCULATE THE OCCURENCE OF LETTERS
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < strlen(argv[i]); j++)
        {
            temp = tolower(argv[i][j]);
            pos = (int)temp - 97;
            alphabet[pos]++;

        }
	}
	//DISPLAY THE ARRAY
	cout<<setw(12)<<"LETTER"<<setw(13)<<"FREQUENCY"<<endl;
	for (int i = 0; i < 26; i++)
    {
        cout<<setw(10)<<char(97+i)<<setw(10)<<alphabet[i]<<endl;
    }


	return 0;
}

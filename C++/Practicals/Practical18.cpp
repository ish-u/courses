#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream src;
    fstream dest;
    char temp;

    src.open("src.txt",ios::in);
    dest.open("dest.txt",ios::out);
    if (!src)
    {
        cout<<"FILE DOESN'T EXIST"<<endl;
        exit(1);
    }

    else
    {
        cout<<"EDITING......."<<endl;
        while(src>>temp)
        {
            dest<<temp;
        }
        cout<<"EDITED>>.";
    }

    src.close();
    dest.close();

	return 0;
}

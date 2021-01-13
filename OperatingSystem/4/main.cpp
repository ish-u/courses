#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argv, char* argc[])
{
	if(argv == 2)
	{
		char cmd[] = "stat ";
		strcat(cmd,argc[1]);
		system(cmd);
		return 0;
	}
	else
	{
		cout<<"Incorrect Input\n";
		return -1;
	}
}

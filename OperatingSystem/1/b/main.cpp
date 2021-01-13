#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int pid  = fork();
	if(pid == 0)
	{
		cout<<"\nChild : "<<getpid()<<" \n";
	}
	else
	{
		cout<<"\nParent : "<<getpid()<<" \n";
	}
	return 0;
}

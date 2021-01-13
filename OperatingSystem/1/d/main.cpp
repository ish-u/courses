#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	int pid  = fork();
	if(pid == 0)
	{
		cout<<"\nChild : "<<getpid()<<"\n";
	}
	else
	{
		wait(NULL);
		cout<<"\nParent : "<<getpid()<<"\n";
	}
	return 0;
}

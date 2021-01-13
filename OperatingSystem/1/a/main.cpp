#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int pid  = fork();
	cout<<"\nPID : "<<getpid()<<"\n";
	cout<<"Same Code\n";
	return 0;
}

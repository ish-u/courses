#include <pthread.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int sumN = 0;
void *sum(void *n);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"Error : Use \"./a.out N \" \n";
		exit(-1);
	}
	if(atoi(argv[1]) <= 0)
	{
		cout<<"Error : Negative and Zero not allowed\n";
		exit(-2);
	}
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,sum,argv[1]);
	pthread_join(tid,0);
	cout<<sumN<<"\n";
	
	return 0;
}

void *sum(void *n)
{

	int i = 0;
	int limit = atoi((char*)n);
	sumN = 0;
	for(int i = 1; i <= limit; i++)
	{
		sumN += i;
	}
	pthread_exit(0);
}

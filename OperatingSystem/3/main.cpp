#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"* Memeory Information * \n";
	system(" awk 'NR==1, NR==3 {print NR,$0}' /proc/meminfo");	
	return 0;
}

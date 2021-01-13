#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"* CPU and Kernel Information\n";
	system(" awk '/processor/ {print}' /proc/cpuinfo");
	system("awk '/model/ {print}' /proc/cpuinfo");
	system("awk '/vendor_id/ {print}' /proc/cpuinfo");
	system("cat /proc/version");
	return 0;
}

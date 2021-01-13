#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{

	int numberOfProcess = 0;
	cout<<"Enter the Number of Processes : "; cin>>numberOfProcess;
	/*Creating the a 2-D array with Rows = numberOfProcess and Column = 5 and taking input from the user
		{For the i-ht Processes}
		processes[i][0] = Arrival Time
		processes[i][1] = Burst Time
		processes[i][2] = Completion Time
		processes[i][3] = Turnaround Time
		processes[i][4] = Waiting Time
		processes[i][5] = PID
	*/
	float processes[numberOfProcess][6];
	for(int i = 0; i < numberOfProcess; i++)
	{
		processes[i][0] = processes[i][1] = processes[i][2] = processes[i][3] = processes[i][4] = processes[i][5] =  0;
	}
	cout<<"\n";
	//taking input from user
	for(int i = 0; i < numberOfProcess; i++)
	{
		//system("clear");
		cout<<"Process "<<i+1<<"\n";
		cout<<left<<setw(15)<<"Arrival Time  "<<": "; cin>>processes[i][0];
		cout<<left<<setw(15)<<"Burst Time  "<<": "; cin>>processes[i][1];
		processes[i][5] = i+1;
		cout<<"\n";
	}
	//sort the processes according to their arrival time using insertion sort
	for(int j = 1; j < numberOfProcess; j++)
	{
		float key_1 = processes[j][0];
		float key_2 = processes[j][1];
		int key_3 = processes[j][5];
		int k = j-1;
		while(k >= 0 && processes[k][0] > key_1)
		{
			processes[k+1][0] = processes[k][0];
			processes[k+1][1] = processes[k][1];
			processes[k+1][5] = processes[k][5];
			k = k - 1;
		}
		processes[k+1][0] = key_1;
		processes[k+1][1] = key_2;
		processes[k+1][5] = key_3;
	}
	//computer the Completion, Waiting and Trunaround Time
	float  completionTime = 0;
	float avgWaitingTime = 0;
	float avgTurnaroundTime = 0;
	for(int i = 0; i < numberOfProcess; i++)
	{
		completionTime += processes[i][1];
		processes[i][2] = completionTime;
		processes[i][3] = abs(processes[i][2] - processes[i][0]);
		processes[i][4] = abs(processes[i][3] - processes[i][1]);
		avgWaitingTime += processes[i][4];
		avgTurnaroundTime += processes[i][3];
	}
	//system("clear");
	cout<<"\n"<<right;
	cout<<setw(10)<<"Process"<<setw(20)<<"Arrival Time"<<setw(20)<<"Burst Time"<<setw(20)<<"Completion Time"
	    <<setw(20)<<"Turnaround Time"<<setw(20)<<"Waiting Time\n";
	cout<<setfill('=')<<setw(120)<<"\n";
	for(int i = 0; i < numberOfProcess; i++)
	{
		cout<<setfill(' ');
		cout<<setw(5)<<processes[i][5]<<setw(18)<<processes[i][0]<<"ms"<<setw(18)<<processes[i][1]<<"ms"
		    <<setw(18)<<processes[i][2]<<"ms"<<setw(18)<<processes[i][3]<<"ms"<<setw(18)<<processes[i][4]<<"ms\n";
	}
	cout<<setfill('=')<<setw(120)<<"\n";
	cout<<setfill(' ');
	cout<<"\n Avergae Waiting Time : "<<avgWaitingTime/numberOfProcess<<"ms";
	cout<<"\n Average Turnaround Time : "<<avgTurnaroundTime/numberOfProcess<<"ms\n";
	return 0;
}

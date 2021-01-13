#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	cout<<"Shortest Job First (Non Preemptive)\n";
	int numberOfProcess = 0;
	cout<<"Enter the Number of Processes : "; cin>>numberOfProcess;
	/*
		Creating a 2-D Array with rows = numberOfProcess and col = 6
		and initialising each value with 0
			{for i-th process}
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
		processes[i][0] = processes[i][1] = processes[i][2] = processes[i][3] = processes[i][4] = processes[i][5] = 0;
	}
	//taking input for the Arrival Time from the user
	cout<<"\n";
	for(int i = 0; i < numberOfProcess; i++)
	{
		cout<<"Processes "<<i+1<<"\n";
		cout<<left<<setw(15)<<"Arrival Time"<<": "; cin>>processes[i][0];
		cout<<setw(15)<<"Burst Time"<<": "; cin>>processes[i][1];
		processes[i][5] = i+1;
		cout<<"\n";
	}
	cout<<right;
	//sorting the processes according to Arrival Time
	for(int i = 1; i < numberOfProcess; i++)
	{
		float key_1 = processes[i][0];
		float key_2 = processes[i][1];
		float key_3 = processes[i][5];
		int j = i-1;
		while(j >= 0 && processes[j][0] > key_1)
		{
			processes[j+1][0] = processes[j][0];
			processes[j+1][1] = processes[j][1];
			processes[j+1][5] = processes[j][5];
			j = j - 1;
		}
		processes[j+1][0] = key_1;
		processes[j+1][1] = key_2;
		processes[j+1][5] = key_3;
	}
	float ct = 0;
	//selecting the process that has the minimum burst time and that has arrived
	//NOTE -> can be improved by using a swap function
	for(int i = 1; i < numberOfProcess; i++)
	{
		ct += processes[i-1][1];
		float key_1 = processes[i][0];
		float key_2 = processes[i][1];
		float key_3 = processes[i][5];
		int replace = i;
		for(int k = i; k < numberOfProcess; k++)
		{
			if(processes[k][0] < ct && (processes[k][1] < processes[replace][1]))
			{
				replace = k;
			}
		}
		processes[i][0] = processes[replace][0];
		processes[i][1] = processes[replace][1];
		processes[i][5] = processes[replace][5];
		processes[replace][0] = key_1;
		processes[replace][1] = key_2;
		processes[replace][5] = key_3;
	}
	//calculating the Waiting Time , Completion Time and Turnaround Time
	float completionTime = 0;
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
	//printing the Processes Chart
	cout<<"\n";
	cout<<setw(10)<<"Processes"<<setw(20)<<"ArrivalTime"<<setw(20)<<"Burst Time"<<setw(20)<<"Completion TIme"
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


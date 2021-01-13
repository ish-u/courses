#include <iostream>
#include <iomanip>
using namespace std;
#include "queue.h"

//process class
class Process{

	public:
		int name;
        int is_in_ready_queue;
		float arrival_time;
		float burst_time;
		float temp_burst_time;
		float completion_time;
		float turnaround_time;
		float waiting_time;
		//constructor
		Process()
		{
			arrival_time = burst_time = temp_burst_time = completion_time = turnaround_time = waiting_time = 0;
		}
};

int main()
{
	float timeQuantum = 2;
	//taking input from the User
	int numberOfProcess;
	cout<<"Round Robin Scheduling\n";
	cout<<"\nHow many Proocess you want? : "; cin>>numberOfProcess;
	cout<<"Enter Time Quantum : "; cin>>timeQuantum;
    if(numberOfProcess <= 0)
    {
        return -1;
    }
	Process *processQueue[numberOfProcess];
    cout<<"\n";
	for(int i = 0; i < numberOfProcess; i++)
	{
		processQueue[i] = new Process();
		processQueue[i]->name = i+1;
        processQueue[i]->is_in_ready_queue = 0;
		cout<<"Process "<<i+1<<" : \n";
		cout<<"Arrival Time : "; cin>>processQueue[i]->arrival_time;
		cout<<"Burst Time : "; cin>>processQueue[i]->burst_time;
		processQueue[i]->temp_burst_time = processQueue[i]->burst_time;
        cout<<"\n";
	}
	//arrangin the process according to their arrival time using Bubble Sort
	for(int i = 0; i < numberOfProcess-1; i++)
	{	Process* temp = 0;
		for(int j = 0; j < numberOfProcess-1; j++ )
		{
			if(processQueue[j]->arrival_time > processQueue[j+1]->arrival_time)
			{
				temp = processQueue[j];
				processQueue[j] = processQueue[j+1];
				processQueue[j+1] = temp;
			}
			temp = 0;
		}
	}
	//algorithm
	//findind the completion time 
	int flag = true;
	float current_time = processQueue[0]->arrival_time;
    queueLL<Process*> *ready_queue = new queueLL<Process*>();
    Process *p = 0;
    ready_queue->enqueue(processQueue[0]);
    processQueue[0]->is_in_ready_queue = 1;
    while(!ready_queue->isEmpty())
    {
        p = ready_queue->firstEle();
        if(p->arrival_time <= current_time && (p->temp_burst_time > 0))
		{
            if(p->temp_burst_time <= timeQuantum)
            {
                current_time += p->temp_burst_time;
                p->completion_time = current_time;
                p->temp_burst_time = 0;
            }
            else
            {
                current_time += timeQuantum;
                p->temp_burst_time -= timeQuantum;					
            }
		}
        ready_queue->dequeue();
        for(int i = 0; i < numberOfProcess; i++)
        {
            if((processQueue[i]->arrival_time <= current_time) && (processQueue[i]->temp_burst_time > 0) && (processQueue[i] != p) && (processQueue[i]->is_in_ready_queue == 0))
            {
                ready_queue->enqueue(processQueue[i]);
                processQueue[i]->is_in_ready_queue = 1;
            }
        }
        if(p->temp_burst_time > 0)
        {
            ready_queue->enqueue(p);
        }
        p = 0;
    }
	//finding the waiting time and turnaround time of each process and avg waiting and turnaround time for all processes
    float avg_waitingTime = 0;
    float avg_turnaroundTime = 0;
	for(int i = 0; i < numberOfProcess; i++)
	{
		processQueue[i]->turnaround_time = processQueue[i]->completion_time - processQueue[i]->arrival_time;
		processQueue[i]->waiting_time = processQueue[i]->turnaround_time - processQueue[i]->burst_time;	
        avg_turnaroundTime += processQueue[i]->turnaround_time;
        avg_waitingTime += processQueue[i]->waiting_time;
	}
    //displaying the Process Chart
    cout<<"\n";
    cout<<setw(10)<<"Process"<<setw(20)<<"ArrivalTime"<<setw(20)<<"Burst Time"<<setw(20)<<"Completion TIme"
	    <<setw(20)<<"Turnaround Time"<<setw(20)<<"Waiting Time\n";
	cout<<setfill('=')<<setw(120)<<"\n";
	for(int i = 0; i < numberOfProcess; i++)
	{
		cout<<setfill(' ');
		cout<<setw(5)<<processQueue[i]->name<<setw(18)<<processQueue[i]->arrival_time<<"ms"<<setw(18)<<processQueue[i]->burst_time<<"ms"
                    <<setw(18)<<processQueue[i]->completion_time<<"ms"<<setw(18)<<processQueue[i]->turnaround_time<<"ms"<<setw(18)<<processQueue[i]->waiting_time<<"ms\n";
	}
    cout<<setfill('=')<<setw(120)<<"\n";
    cout<<"Average Waiting Time : "<<avg_waitingTime/numberOfProcess<<"\n";
    cout<<"Average Turnaround Time : "<<avg_turnaroundTime/numberOfProcess<<"\n";
	return 0;
}

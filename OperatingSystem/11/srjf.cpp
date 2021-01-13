#include <iostream>
#include <iomanip>
using namespace std;

class Process
{
    public:
        int name;
        float arrival_time;
        float burst_time;
        float temp_burst_time;
        float completion_time;
        float waiting_time;
        float turnaround_time;
        //constructor
        Process()
        {
            arrival_time = burst_time = temp_burst_time = completion_time = waiting_time = turnaround_time = 0;
            name = 0;
        }
};

int main()
{
    //taking input from user
    int numberOfProcess;
    cout<<"SRJF Scheduling\n";
    cout<<"Number of Process : "; cin>>numberOfProcess;
    if(numberOfProcess <= 0)
    {
        return -1;
    }
    cout<<"\n";
    //initializing the process queue
    Process *processQueue[numberOfProcess];
    for(int i = 0; i < numberOfProcess; i++)
    {
        processQueue[i] = new Process();
        processQueue[i]->name = i+1; 
        cout<<"Process "<<i+1;
        cout<<left;
        cout<<"\n";
        cout<<setw(20)<<"Arrival Time"<<" :"; cin>>processQueue[i]->arrival_time;
        cout<<setw(20)<<"Burst Time"<<" :"; cin>>processQueue[i]->burst_time;
        processQueue[i]->temp_burst_time = processQueue[i]->burst_time;
        cout<<"\n";
    }
    cout<<right;
    //arranging the Process according to their arrival time
    for(int i = 0; i < numberOfProcess - 1; i++)
    {
        for(int j = 0; j < numberOfProcess - 1; j++)
        {
            if(processQueue[j]->arrival_time > processQueue[j+1]->arrival_time)
            {
                Process *temp = processQueue[j];
                processQueue[j] = processQueue[j+1];
                processQueue[j+1] = temp;
            }
        }
    }
    //algorithm
    Process *temp = processQueue[0];
    int flag = true;
    float current_time = processQueue[0]->arrival_time;
    while(flag)
    {
        if(temp->arrival_time <= current_time && temp->temp_burst_time > 0)
        {
            if(temp->temp_burst_time <= 1)
            {
                current_time += temp->temp_burst_time;
                temp->temp_burst_time = 0;
                temp->completion_time = current_time;
            }
            else
            {
                temp->temp_burst_time -= 1;
                current_time += 1;
            }
        }
        else
        {
            current_time += 1;
        }
        //checking flag
        flag = false;
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(processQueue[i]->temp_burst_time > 0)
            {
                flag = true;
                temp = processQueue[i];
                break;
            }
        }
        //selecting the next smallest process after every 1 unit time
        for(int i = 0; i < numberOfProcess; i++)
        {
            if(processQueue[i] != temp)
            {
                if(processQueue[i]->arrival_time <= current_time && processQueue[i]->temp_burst_time > 0 && processQueue[i]->temp_burst_time < temp->temp_burst_time)
                {
                    temp = processQueue[i];
                }
            }
        }
        
    }
    //finding the Completion Time, Waiting Time and Trunaround Time
    float avg_waitingTime = 0;
    float avg_turnaroundTime = 0;
    for(int i = 0; i < numberOfProcess; i++)
    {
        processQueue[i]->turnaround_time = processQueue[i]->completion_time - processQueue[i]->arrival_time;
        processQueue[i]->waiting_time = processQueue[i]->turnaround_time - processQueue[i]->burst_time;
        avg_turnaroundTime += processQueue[i]->turnaround_time;
        avg_waitingTime +=  processQueue[i]->waiting_time;
    }
    //rearranging the Process according to their arrival time
    for(int i = 0; i < numberOfProcess - 1; i++)
    {
        for(int j = 0; j < numberOfProcess - 1; j++)
        {
            if(processQueue[j]->arrival_time > processQueue[j+1]->arrival_time)
            {
                Process* temp = processQueue[j];
                processQueue[j] = processQueue[j+1];
                processQueue[j+1] = temp;
            }
        }
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
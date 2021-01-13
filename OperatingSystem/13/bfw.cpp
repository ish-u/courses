#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Block
{
    public:
        int size;
        string firstProcesses,worstProcesses,bestProcesses;
        //constructor
        Block()
        {
            size = 0;
            bestProcesses = "";
            worstProcesses = "";
            firstProcesses = "";
        }
};

int main()
{
    cout<<"Dynamic Storage Allocation Problem \n";
    int numberOfBlocks, numberOfProcess;
    cout<<setw(25)<<"Enter the Number of Blocks"<<" : "; cin>>numberOfBlocks;
    cout<<setw(25)<<"Enter the Number of Processes"<<" : "; cin>>numberOfProcess;
    if(numberOfBlocks <= 0|| numberOfProcess <= 0)
    {
        return -1;
    }
    cout<<"\nEnter the Size of Blocks and Processes in kB\nProcesses will be allocated in the entered order\n";
    //creating arrays for Blocks and Process and taking input of their size from user
    Block *blocks[numberOfBlocks];
    int processes[numberOfProcess] = {0};
    int tempBlocks[numberOfBlocks];
    for(int i = 0; i < numberOfBlocks; i++)
    {
        blocks[i] = new Block();
        cout<<"Block "<<i+1<<" :"; cin>>blocks[i]->size;
        tempBlocks[i] = blocks[i]->size;
    }
    cout<<"\n";
    for(int i = 0; i < numberOfProcess; i++)
    {
        cout<<"Proess "<<i+1<<" :"; cin>>processes[i];
    }

    //first fit
    cout<<"\nFirst Fit\n==============\n";
    for(int i = 0; i < numberOfProcess; i++)
    {
        for(int j = 0; j < numberOfBlocks; j++)
        {
            if(tempBlocks[j] >= processes[i])
            {
                tempBlocks[j] -= processes[i];
                blocks[j]->firstProcesses += to_string(i+1) + " ";
                cout<<char(i+1);
                break;
            }
        }
    }
    cout<<left;
    cout<<setw(10)<<"Block"<<setw(10)<<"Size"<<setw(10)<<"Process"<<setw(15)<<"Left Memory";
    cout<<"\n";
    for(int i = 0; i < numberOfBlocks; i++)
    {
        cout<<setw(10)<<(i+1)<<setw(10)<<blocks[i]->size<<setw(10)<<blocks[i]->firstProcesses<<setw(15)<<tempBlocks[i];
        cout<<"\n";
    }
    
    //best first
    cout<<"\nBest Fit\n==============\n";
    for(int i = 0; i < numberOfBlocks; i++)
    {
        tempBlocks[i] = blocks[i]->size;
    }
    for(int i = 0; i < numberOfProcess; i++)
    {
        int smallest = -1;
        for(int j = 0; j < numberOfBlocks; j++)
        {
            if(tempBlocks[j] >= processes[i])
            {
                smallest = j;
                break;
            }
        }
        if(smallest != -1)
        {
            for(int k = 0; k < numberOfBlocks; k++)
            {
                if(tempBlocks[smallest] > tempBlocks[k]  && tempBlocks[k] >= processes[i])
                {
                    smallest = k;
                }
            }
            tempBlocks[smallest] -= processes[i];
            blocks[smallest]->bestProcesses += to_string(i+1) + " ";
        }
    }

    cout<<left;
    cout<<setw(10)<<"Block"<<setw(10)<<"Size"<<setw(10)<<"Process"<<setw(15)<<"Left Memory";
    cout<<"\n";
    for(int i = 0; i < numberOfBlocks; i++)
    {
        cout<<setw(10)<<(i+1)<<setw(10)<<blocks[i]->size<<setw(10)<<blocks[i]->bestProcesses<<setw(15)<<tempBlocks[i];
        cout<<"\n";
    }

    //worst fit
    cout<<"\nWorst Fit\n==============\n";
    for(int i = 0; i < numberOfBlocks; i++)
    {
        tempBlocks[i] = blocks[i]->size;
    }
    for(int i = 0; i < numberOfProcess; i++)
    {
        int largest = -1;
        for(int j = 0; j < numberOfBlocks; j++)
        {
            if(tempBlocks[j] >= processes[i])
            {
                largest = j;
                break;
            }
        }
        if(largest != -1)
        {
            for(int k = 0; k < numberOfBlocks; k++)
            {
                if(tempBlocks[largest] < tempBlocks[k]  && tempBlocks[k] >= processes[i])
                {
                    largest = k;
                }
            }
            tempBlocks[largest] -= processes[i];
            blocks[largest]->worstProcesses += to_string(i+1) + " ";
        }
    }
    cout<<left;
    cout<<setw(10)<<"Block"<<setw(10)<<"Size"<<setw(10)<<"Process"<<setw(15)<<"Left Memory";
    cout<<"\n";
    for(int i = 0; i < numberOfBlocks; i++)
    {
        cout<<setw(10)<<(i+1)<<setw(10)<<blocks[i]->size<<setw(10)<<blocks[i]->worstProcesses<<setw(15)<<tempBlocks[i];
        cout<<"\n";
    }

    return 0;
}

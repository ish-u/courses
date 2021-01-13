#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<"DISTANCE VECTOR PROTOCOL SIMULATION\n";
    int vertices = 5;
    cout<<"Enter the Number of Routers : "; cin>>vertices;
    int distanceTable[vertices][vertices] = {0};

    int hopTable[vertices][vertices] = {0};

    //Input
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout<<"("<<i<<","<<j<<") : "; cin>>distanceTable[i][j];
            hopTable[i][j] = j;
            if(i!=j && distanceTable[i][j] == 0)
            {
                distanceTable[i][j] = 1000;
            }
        }
        cout<<"\n";
    }

    //Sharing the Routing Table and Recalculating the Cost 
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            for(int k = 0; k < vertices; k++)
            {
                if(distanceTable[i][j] > (distanceTable[i][k] + distanceTable[k][j]))
                {
                    distanceTable[i][j] = distanceTable[i][k] + distanceTable[k][j];
                    if(hopTable[i][j] == j)
                    {
                        hopTable[i][j] = k;
                    }
                    else
                    {
                        hopTable[i][j] = hopTable[i][j]*10 + k;
                    }
                }
            }
        }
    }
    cout<<"Routing Tables\n";
    for(int i = 0; i < vertices; i++)
    {
        cout<<"Router : "<<i<<"\n";  
        cout<<left;
        cout<<setw(12)<<"Destiantion"<<setw(10)<<"Distance"<<setw(10)<<"Next Hop"<<"\n";
        for(int j = 0; j < vertices; j++)
        {
            cout<<"     "<<setw(10)<<j<<setw(10)<<distanceTable[i][j]<<setw(10)<<hopTable[i][j]<<"\n";
        }
        cout<<right;
        cout<<"\n";
    }

    return 0;
}
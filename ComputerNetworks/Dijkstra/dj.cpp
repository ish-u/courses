#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int vertices = 5;
    int source = 2;
    cout<<"DIJKSTRA SIMULATION FOR A SOURCE ROUTER IN A NETWORK\n";
    cout<<"Enter the Number of Router : "; cin>>vertices;
    int adjMatrix[vertices][vertices] = {
        {0, 3, 1, 0, 0},
        {3, 0, 7, 5, 1},
        {1, 7, 0, 2, 0},
        {0, 5, 2, 0, 7},
        {0, 1, 0, 7, 0}
    };
    
    // //Input
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout<<"("<<i<<","<<j<<") : "; cin>>adjMatrix[i][j];
        }
        cout<<"\n";
    }

    //Output
    cout<<"Adjacency Matrix\n";
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";
    cout<<"Enter the Source Vertex : "; cin>>source;

    int visited[vertices] = {0};             //to keep track of visited nodes
    int shortestDistance[vertices] = {0};    //to store the Shortest Distance of Each Node from the Source Node
    int hops[vertices] = {0};
    int flag = 1;
    int traverse = source;
    for(int i = 0; i < vertices; i++)
    {
        shortestDistance[i] = INT_MAX; 
    }
    shortestDistance[traverse] = 0;
    visited[traverse] = 1;
    while(flag)
    {
        //finding the node with the shortest path that is not visited
        for(int i = 0; i < vertices; i++)
        {
            if(!visited[i])
            {
                if(shortestDistance[i] < shortestDistance[traverse])
                {
                    traverse = i;
                }
            }
        }
        //update the shortestDistance Array
        for(int i = 0; i < vertices; i++)
        {
            if(!visited[i] && adjMatrix[traverse][i])
            {
                if(shortestDistance[traverse] + adjMatrix[traverse][i] < shortestDistance[i])
                {
                    shortestDistance[i] = shortestDistance[traverse] + adjMatrix[traverse][i];
                    hops[i] = traverse;
                }
            }
        }

        //set the Node to be visited
        visited[traverse] = 1;

        //checking flag
        for(int i = 0; i < vertices; i++)
        {
            flag = 0;
            if(!visited[i])
            {
                traverse = i;
                flag = 1;
                break;
            }
        }
    }

    //displaying the result
    cout<<"Routing Table for Source\n";
    cout<<left<<setw(10)<<"Vertex"<<setw(10)<<"Distance"<<setw(10)<<"Closest Node";
    cout<<"\n";
    for(int i = 0; i < vertices; i++)
    {
        cout<<"     "<<setw(10)<<i<<setw(10)<<shortestDistance[i]<<setw(10)<<hops[i];
        cout<<"\n";
    }
    return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<setw(40)<<"| Euler Path and Circuit |\n";
    //in case of Directed Graphs the value 1 in the position matrix[i][j] represent an edge from i-th edge to j-th edge
    cout<<setfill('-')<<setw(50)<<"\n";

    int n;      //Number of Vertices
    cout<<"Enter the Number of Vertices in the Graph : ";
    cin>>n;
    cout<<setfill('-')<<setw(50)<<"\n";
    //check whether the input is valid or not
    if(n <= 0)
    {
        cout<<"Not Valid\n";
        return -1;
    }

    //initializing the AdjacencyMatrix with vertex 'n'
    int matrix[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            matrix[i][j] = 0;

    //taking the input from user of the Graph in form of AdjacencyMatrix
    for(int i = 0; i < n; i++)
    {
        int a;      //number of vertices adjacent to a particular vertex
        cout<<"Enter the Number of Vertices Adjacent to Vertex "<<(i+1)<<" : ";
        cin>>a;
        //check whether the input is valid
        if(a < 0)
        {
            cout<<"Not Valid";
            return 1;
        }
        int adj[a];     //initializing an array that will hold all the adjacent vertices to the vertex 'i'
        // taking input of array adj
        cout<<"Vertices : ";
        for(int j = 0; j < a; j++)
        {
            cin>>adj[j];
        }
        for(int k = 0; k < a; k++)
        {
            matrix[i][adj[k]-1] += 1;
        }

    }

    cout<<setfill('-')<<setw(50)<<"\n";
    cout<<"\tADJANCENCY MATRIX\n\n";
     //printing the AdjacencyMatrix
     cout<<"\t";
     for(int i = 0; i <n; i++)
     {
         cout<<(i+1)<<"\t";
     }
     cout<<"\n";
    for(int i = 0; i < n; ++i)
    {
        cout<<(i+1)<<"\t";
        for(int j = 0; j < n; ++j)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<setfill('-')<<setw(50)<<"\n\n";

    int degree[n];      //initializing an array that will contain the degree of 'n' vertices of the graph
    for(int i = 0; i < n; i++)
        degree[i] = 0;

    int sum = 0;        //temporary variable to store the degree of an individual vertex
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            sum += matrix[i][j];
        }
        degree[i] = sum;
        sum = 0;
    }


    //check whether the Graph has a Euler Path or Euler Circuit
    int odd = 0;
    for(int i = 0; i < n; i++)
    {
        if(degree[i] % 2 != 0)
        {
            odd++;
        }
    }

    if(odd > 2)
    {
        cout<<"Neither Euler Path Nor Euler Circuit.\n";
    }
    else if(odd == 2)
    {
        cout<<"Euler Path.\n";
    }
    else
    {
        cout<<"Euler Circuit.\n";
    }
    return 0;
}

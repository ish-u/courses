#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<setw(30)<<"| ADJACENCY MATRIX |\n";
    int n;      //Number of Vertices
    cout<<"Enter the Number of Vertices in the Graph : ";
    cin>>n;

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
            matrix[i][adj[k]-1] = 1;
        }

    }

     //printing the AdjacencyMatrix
    cout<<setfill('-')<<setw(40)<<" ";
    cout<<"\nThe Adjacency Matrix : \n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<setfill('-')<<setw(40)<<" ";
    //check whether the graph is complete or not
    cout<<"\n";
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            sum += matrix[i][j];
        }
    }

    if(sum == (n*(n-1)))
    {
        cout<<"The Graph is a Complete Graph";
    }
    else
    {
        cout<<"The Graph is not a Complete Graph";
    }

    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //in case of Directed Graphs the value 1 in the position matrix[i][j] represent an edge from i-th edge to j-th edge
    cout<<setw(30)<<"| InDegree-OutDegree |\n";
    cout<<setfill('-')<<setw(50)<<" \n";
    int n;      //Number of Vertices
    cout<<"Enter the Number of Vertices in the Graph : ";
    cin>>n;
    cout<<setfill('-')<<setw(50)<<" \n";
    //check whether the input is valid or not
    if(n <=0)
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
        //initializing an array that will hold all the adjacent vertices to the vertex 'i'
        int adj[a];         
        if(a > 0)
        {
            // taking input of array adj
            cout<<"Vertices : ";
        }
        for(int j = 0; j < a; j++)
        {
            cin>>adj[j];
        }
        for(int k = 0; k < a; k++)
        {
            matrix[i][adj[k]-1] = 1;
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


    int deg[n][2];      //an array that will contain the in-degree and out-degree of the respective vertices
    int sum = 0;

    //calculating in-degree of the vertices
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <  n; ++j)
        {
            sum += matrix[i][j];
        }
        deg[i][0] = sum;
        sum = 0;
    }

    sum = 0;
    //calculating out-degree of the vertices
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <  n; ++j)
        {
            sum += matrix[j][i];
        }
        deg[i][1] = sum;
        sum = 0;
    }

    cout<<setfill('_')<<setw(30)<<"\n";
    //displaying the in-degree and out-degree of the inputted Graph
    cout<<"V"<<"\t"<<"Out"<<"\t"<<"In"<<"\n";
    for(int i = 0; i < n; i++)
    {
        cout<<(i+1)<<"\t";
        for(int j = 0; j < 2; j++)
        {
            cout<<deg[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<setfill('-')<<setw(30)<<"\n";
    return 0;
}

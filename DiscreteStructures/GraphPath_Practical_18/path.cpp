#include <iostream>
#include <iomanip>
using namespace std;

//using the Theorem : For a Graph 'G' with Adjacency Matrix 'A' with respect to ordering 1,2,3...,n(with directed
//or undirected, with multiple edges and loops allowed). The number of different paths of length 'r' from 'i' to 'j'
//,where r > 0, equals (i,j)th entry of matrix 'A^r'

//path() funciton
int path(int* result,int* graph,int* temp,int vertex,int path_length)
{
    for (int n = 0; n < path_length-1; ++n)
    {
        
        for (int i = 0; i < vertex; ++i)
        {
            for (int j = 0; j < vertex; ++j)
            {
                for (int k = 0; k < vertex; ++k)
                {
                    temp[(i * vertex) + j]  += result[(i * vertex) + k] * graph[(k * vertex) + j];
                }
            }
        }
        //updating result
        for (int i = 0; i < vertex; ++i)
        {
            for (int j = 0; j < vertex; ++j)
            {
                result[(i * vertex) + j] = temp[(i * vertex) + j];
            }
        }
        //restting temp
        for (int i = 0; i < vertex; ++i)
        {
            for (int j = 0; j < vertex; ++j)
            {
                temp[(i * vertex) + j] = 0;
            }
        }
    }

}

int main(void)
{
    cout<<setw(33)<<"| PATH COUNTER |\n";
    cout<<setfill('-')<<setw(50)<<"\n";
    int *graph;
    int vertex, src, dest, path_length;
    cout << "Enter the number of vertices in the graph : ";
    cin >> vertex;
    if (vertex < 0)
    {
        return -1;
    }
    //creating a 2-D array to represent Adjacency Matrix
    graph = new int[vertex * vertex];
    //taking input for adjaceny matrix from user
    cout<<setfill('-')<<setw(50)<<"\n";
    cout << "Enter the Adjacency Matrix : \n";
    for (int i = 0; i < vertex; ++i)
    {
        for (int j = 0; j < vertex; ++j)
        {
            cout << "(" << (i + 1) << "," << (j + 1) << ") : ";
            cin >> graph[(i * vertex) + j];
        }
    }
    //printing the adjacency matrix of the graph
    cout<<"\nAdjacency Matrix :\n";
    for (int i = 0; i < vertex; ++i)
    {
        for (int j = 0; j < vertex; ++j)
        {
            cout << graph[(i * vertex) + j] << " ";
        }
        cout << "\n";
    }
    cout<<setfill('-')<<setw(50)<<"\n";
    cout << "Enter the Source vertex : ";
    cin >> src;
    cout << "Enter the Destination vertex : ";
    cin >> dest;
    cout << "Enter the Path Length : ";
    cin >> path_length;
    if (src > vertex || dest > vertex)
    {
        cout << "No such vertex exists";
        return -2;
    }
    int *temp = new int[vertex * vertex];
    int *result = new int[vertex*vertex]; 
    for (int i = 0; i < vertex; ++i)
    {
        for (int j = 0; j < vertex; ++j)
        {
            temp[(i * vertex) + j] = 0;
            result[(i * vertex) + j] = graph[(i * vertex) + j];
        }
    }
    //counting the number of paths between src and destination
    path(result,graph,temp,vertex,path_length);
    cout<<"Total Number of Paths b/w "<<src<<" and "<<dest<<" : "<<result[((src-1)*vertex) + (dest-1)];
    cout<<"\n"<<setfill('-')<<setw(50)<<" ";
    delete[] graph;
    delete[] temp;
    delete[] result;
    return 0;
}
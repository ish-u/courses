#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //declaring the size of array and taking input from the user
    int n = 0;
    cout<<"Enter the Number of elements you want in the Array : ";
    cin>>n;
    //checking the user input
    if(n <= 0)
    {
        cout<<"Not Possible\n";
        return 1;
    }

    //declaring array of size 'n' and taking input from user
    int list[n];
    cout<<"Enter the Elements of the array of size "<<n<<" : ";
    for(int i = 0; i < n; i++)
        cin>>list[i];
    
    //Insertion Sort
    int comp = 0;   //number of comparision
    int swap = 0;   //number of swaps
    int key = 0;    //key
    int j;
    cout<<setfill('-')<<setw(40)<<" \n";
    for(int i = 1; i < n; i++)
    {
        key = list[i];
        j = i - 1;
        while(j >= 0)
        {
            if(list[j] > key)
            {
                comp++;
                swap++;
                list[j+1] = list[j]; 
                j--; 
            }
            else
            { 
                comp++;
                break;
            }
            
            
        }
        list[j+1] = key;
        //printing the iteration
        cout<<"Iteration  "<<(i)<<" : ";
        for(int k = 0; k < n; k++)
            cout<<list[k]<<" ";
        cout<<"\n";
    }
    cout<<setfill('-')<<setw(40)<<" \n";
    cout<<"Comparision : "<<comp<<"\n";
    cout<<"Swap : "<<swap<<"\n";
    cout<<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<list[i]<<" ";
    }
    
 

    return 0;
}
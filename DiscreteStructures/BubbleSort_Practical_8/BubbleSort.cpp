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
    
    //Bubble Sort
    int swap = 0;   //number of swaps
    int comp = 0;   //number of comparision
    int temp;       //temporary variable 
    cout<<setfill('-')<<setw(40)<<" \n";
    for(int i =0; i < n-1; i++)
    {
        cout<<"Iteration  "<<(i+1)<<" : ";
        for(int j = 0; j < n-i-1; j++)
        {
            if(list[j] > list[j+1])
            {
                //swapping
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                swap++;

            }
            comp++;
        }
        for(int k = 0; k < n; k++)
                cout<<list[k]<<" ";
            cout<<"\n";
    }
    cout<<setfill('-')<<setw(40)<<" \n";
    cout<<"Swap : "<<swap<<"\n";
    cout<<"Comparision : "<<comp<<"\n";
    cout<<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<list[i]<<" ";
    }
    
    return 0;
}
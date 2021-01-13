
#include <iostream>
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
    
    //Selection Sort
    int swap = 0;   //number of swaps
    int comp = 0;   //number of comparision
    int temp;       //temporary variable 
    int min = 0;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(list[min] > list[j])
            {
                min = j;

            }
            comp++;
            
        }

        if(min != i)
        {
            //swapping
            temp = list[i];
            list[i] = list[min];
            list[min] = temp;
            swap++;

        }

        //printing the iteration
        cout<<"Iteration  "<<(i+1)<<" : ";
        for(int k = 0; k < n; k++)
            cout<<list[k]<<" ";
        

        cout<<"\n";
    }

    cout<<"Swap : "<<swap<<"\n";
    cout<<"Comparision : "<<comp<<"\n";
    cout<<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<list[i]<<" ";
    }
    
 

    return 0;
}
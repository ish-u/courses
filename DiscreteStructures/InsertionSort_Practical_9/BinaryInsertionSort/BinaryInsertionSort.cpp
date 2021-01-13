#include <iostream>

using namespace std;

int main(void){
    
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
    int arr[n];
    cout<<"Enter the Elements of the array of size "<<n<<" : ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int i;
    int m;
    int mid;
    //binary insertion sort
    for(int j = 1; j < n; j++)
    {
        i = 0;
        int left = i;
        int right = j-1;
        //finding the correct place of arr[j] => 'i'
        //--------------------------
        while(left < right){
            mid = (left+right)/2;
            if(arr[j] > arr[mid]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if(arr[left] > arr[j]){
                i = left;
            }
        else{
            i = left + 1;
        }
        //---------------------------
        
        //shifiting the array and inserting arr[j] at it's cprrect postion i.e. arr[i]
        //---------------------------
        m = arr[j];
        for(int k = 0; k < j-i; k++)
        {
            arr[j-k] = arr[j-k-1];
        }
        arr[i] = m;
        //printing the iteration
        cout<<"Iteration  "<<(j)<<" : ";
        for(int l = 0; l < n; l++)
            cout<<arr[l]<<" ";
        cout<<"\n";
        //--------------------------
    }   

    cout<<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    } 
    return 0;
}
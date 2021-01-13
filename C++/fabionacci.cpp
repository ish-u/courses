#include <iostream>

using namespace std;

int main()
{
    int num0 = 0;
    int num1 = 1;
    int num;
    int z;
    cout<<"Enter the number of terms you want in your sequence: ";
    cin>>z;
    
    cout<<"\nThe Sequence is as follows : ";
    cout<<num0<<","<<num1;
    
    for(int i = 1;i<=z;i++){
        num = num1 + num0;
        cout<<","<<num;
        num0 = num1;
        num1 = num;
        
    }
    cout<<".";
 
}
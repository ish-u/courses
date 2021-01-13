#include <iostream>
#include <iomanip>
using namespace std;

//counter variable
int counter;

//to find the solution to - x1 + x2 + x3 + ... + xn = c
//we have to find all the permutation that n-unique-integers that add up to c

//check() function
bool check(int *a,int n,int c)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
    }

    if(sum == c)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//print() function
void print(int* a, int n,int c)
{
    counter++;
    for(int i = 0; i < n-1; ++i)
    {
        cout<<a[i]<<" + ";
    }
    cout<<a[n-1]<<" = "<<c<<"\n";
}

//permutation function
void permutation(int* a, int size,int n,int *temp,int constant)
{
    if(n == size)
    {
        if(check(temp,n,constant))
        {
            print(temp,n,constant);
        }
        
    }
    else
    {
        for(int i = 0; i < size; ++i)
        {
            temp[n] = a[i];
            permutation(a,size,n+1,temp,constant);
        }
    }
    
}

//solution() function
void solution(int *a,int n,int c)
{
    //generating permutation and checking if they are correct or not
    int *temp = new int[n];
    permutation(a,n,0,temp,c);
    delete[] temp;
}


int main(void)
{
    int n,c;
    cout<<setfill(' ')<<setw(30)<<"| SOLUTION FINDER |\n";
    cout<<setfill('-')<<setw(40)<<" "<<endl;
    cout<<"Enter the last element of set : ";
    cin>>n;
    n = n+1;
    int* sequence = new int[n];
    cout<<"Enter Constant :";
    cin>>c;
    if(c>10)
    {
        cout<<"Bound Error";
        return -1;
    }
    if((n-1) > c)
    {
        cout<<"NO SOLUTION EXISTS";
        return 1;
    }
    for(int i = 0; i < n; i++)
    {
        sequence[i] = i;
    }
    cout<<setfill('-')<<setw(40)<<" ";
    cout<<"\nThe Sequence has the following form :- ";
    for(int i = 0; i < n-1; ++i)
    {
        cout<<"x"<<i+1<<" + ";
    }
    cout<<"x"<<n<<" = "<<c<<"\n";
    cout<<"Here are the possible solution : \n";
    solution(sequence,n,c);
    cout<<"There are total : "<<counter<<" possible solutions\n";
    cout<<setfill('-')<<setw(40)<<" "<<endl;
    delete[] sequence;
    return 0;
}

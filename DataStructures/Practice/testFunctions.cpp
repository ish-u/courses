#include <iostream>
#include <iomanip>
#include <deque>
#include <conio.h>
#include <queue>
#include <stack> 
#include <exception>
#include <string>
#include <math.h>
using namespace std;

#include "lowertTriangle.h"
#include "sll.h"
#include "queue.h"
// int recursiveLinearSearch(int *S, int start, int end, int value)
// {
//     if(start > end)
//     {
//         return -1;
//     }
//     if(S[start] == value)
//     {
//         return start;
//     }
//     recursiveLinearSearch(S,start+1,end,value);
// }

void reverseArray(int *a,int i,int j)
{
    if(i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        reverseArray(a,i+1,j-1);
    }
    return;
}


void printOdd(int n)
{
    if(n == 1)
    {
        cout<<"1 ";
        return;
    }
    if(n % 2 != 0)
    {
        cout<<n<<" ";
    }
    printOdd(n-1);
}

string putCommas(string s, int n)
{
    if(n < 1000)
    {
        s =  to_string(n) +  s ;
        // cout<<s;
        return s;
    }
    s = "," + to_string(n%1000) +  s ;
    n = n/1000;
    putCommas(s,n);
}

int multiply(int a, int b)
{
    if(b == 0)
    {
        return 0;
    }
    return a + multiply(a,b-1);
}

// float sum(int n)
// {
//     if(n == 1)
//     {
//         return 1;
//     }

//     return  pow(-1,n)*float(1/n) + sum(n-1);
   
    
// }

void cubes(int n)
{
    if(n == 0)
    {
        return;
    }
    cubes(n-1);
    cout<<n*n*n<<" ";
}

// int gcd(int n, int m)
// {
//     if(m <= n && n%m == 0)
//     {
//         return m;
//     }
//     else if(m < n)
//     {
//         gcd(m,n);
//     }
//     else
//     {
//         gcd(m,n%m);
//     }
// }


bool pa(string s,int i, int j)
{
    if(i > j)
    {
        cout<<"Pallindrome";
        return true;
    }
    if(s[i] != s[j])
    {
        cout<<"Sorry";
        return false;
    }
    pa(s,i+1,j-1);
}

int main()
{
    string s = "tenet";
    cout<<pa(s,0,s.length()-1);
    // cout<<gcd(5,25);
    // string x = ""
    // string s = putCommas(x,1234567);
    // cout<<s;

    // cout<<multiply(50,50);

    // cout<<sum(3);

    // printOdd(10);
    // queueLL<int> *a = new queueLL<int>();
    // try
    // {
    //     a->dequeue();
    // }
    // catch(QueueError Q)
    // {
    //     cout<<Q.s<<"\n";
    // }

        // int a[] = {1,2,3,4,5,6};
    // reverseArray(a,0,5);
    // for(int i = 0; i < 6; i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    // int A[6] = {1,2,3,4,5,6};
    // cout<<recursiveLinearSearch(A,0,5,10);
    // deque<int> *D = new deque<int>();
    // queue<int> *Q = new queue<int>();
    // stack<int> *S = new stack<int>();
    // for(int i = 1; i < 9; i++)
    // {
    //     D->push_back(i);
    // }


    //Stack
    // for(int i = 0; i < 3; i++)
    // {
    //     S->push(D->front());
    //     D->pop_front();
    // }
    // D->push_back(D->front());
    // D->pop_front();
    // S->push(D->front());
    // D->pop_front();
    // S->push(D->back());
    // D->pop_back();    
    // while (!D->empty())
    // {
    //     S->push(D->front());
    //     D->pop_front();
    // }
    // while (!S->empty())
    // {
    //     D->push_front(S->top());
    //     S->pop();
    // }

    // while (!D->empty())
    // {
    //     cout<<D->front();
    //     D->pop_front();
    // }



    //Queue
    // for(int i = 0; i < 3; i++)
    // {
    //     Q->push(D->front());
    //     D->pop_front();
    // }
    // D->push_back(D->front());
    // D->pop_front();
    // Q->push(D->front());
    // D->pop_front();
    // Q->push(D->back());
    // D->pop_back();
    // while (!D->empty())
    // {
    //     Q->push(D->front());
    //     D->pop_front();
    // }
    // while (!Q->empty())
    // {
    //     D->push_back(Q->front());
    //     Q->pop();
    // }

    // while (!D->empty())
    // {
    //     cout<<D->front();
    //     D->pop_front();
    // }
    
    // lowerTriangle<int> *l = new lowerTriangle<int>(3);
    // lowerTriangle<int> *m = new lowerTriangle<int>(3);
    // for(int i = 1; i < 4; i++)
    // {
    //     l->store(i,i);
    //     m->store(i,i);
    // }
    // l->multiply(l,m);
    

    return 0;
}


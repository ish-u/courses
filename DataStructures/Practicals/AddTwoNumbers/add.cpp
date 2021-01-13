#include <iostream>
#include "stack.h"
#include <iomanip>
#include <string>
#include <ctype.h>
using namespace std;

void add(string x, string y)
{
    //creating two int stacks
    Stack<int>* A = new Stack<int>();
    Stack<int>* B = new Stack<int>();
    //inserting the  
    int i  = 0;
    while(i != x.length())
    {
        string temp = "";
        temp += x[i];
        A->push(stoi(temp));
        i++;
    }
    i = 0;
    while(i != y.length())
    {
        string temp = "";
        temp += y[i];
        B->push(stoi(temp));
        i++;
    }
    //adding the two numbers
    int carry , sum;
    carry = sum = 0;
    Stack<int> *AplusB = new Stack<int>();
    while (A->returnTop() != -1 || B->returnTop() != -1)
    {
        sum = carry + A->pop() + B->pop();
        carry = sum/10;
        sum = sum % 10;
        AplusB->push(sum);
        sum = 0;
    }
    if(carry != 0)
    {
        AplusB->push(carry);
    }
    //displaying the sum
    while(AplusB->returnTop() != -1)
    {
        cout<<AplusB->pop();
    }
    
    delete A;
    delete B;
    delete AplusB;
}


int main()
{
    cout<<"Add Two Numbers using Stack\n";
    cout<<"*Enter '~' in either A or B to Exit*\n\n";
    string a;
    string b;
    while(true)
    {
        cout<<"A : "; getline(cin,a);
        cout<<"B : "; getline(cin,b);
        if(a == "~" || b == "~")
            break;
        cout<<"A+B = "; add(a,b);
        cout<<"\n\n";
    }
    return 0;

}
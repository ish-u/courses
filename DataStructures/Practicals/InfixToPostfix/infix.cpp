#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include "stack.h"
#include <iomanip>
using namespace std;

int p(char x)
{
    switch(x)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}



void toPostfix(string exp)
{
    //stack to store operands
    Stack<char>* stk = new Stack<char>();
    string output = "";
    char temp;
    for(int i = 0; i < exp.length(); ++i)
    {
        temp = exp[i];
        if(isdigit(temp))
        {
            output += temp;
        }
        else if(temp == '(' || (p(temp) > p(stk->topElement())) || stk->returnTop() == -1)
        {
            stk->push(temp);
        }
        else if(temp == ' ')
        {
            if(output.back() != ' ')
                output += ' ';   
        }
        else if(temp != ' ')
        {
            if(temp == ')')
            {
                while(stk->topElement() != '(')
                {
                    if(output.back() != ' ')
                        output += ' ';
                    output += stk->pop();
                }
                stk->pop();                
            }
            else
            {   
                if(p(temp) == -1)
                {
                    cout<<"Syntax Error";
                    return;
                }
                while(p(temp) <= p(stk->topElement()))
                {
                    if(output.back() != ' ')
                        output += ' ';
                    output += stk->pop();
                }
                stk->push(temp);
            }
        }
    }
    while(stk->returnTop() != -1)
    {
        if(output.back() != ' ')
            output += ' ';
        output += stk->pop();
    }
    cout<<": "<<output;
}

int main()
{
    cout<<setw(30)<<"INFIX TO POSTFIX/PREFIX\n\n";
    cout<<"* Add Spaces;\n"
        <<"* Valid -> 12 + 3 - 5 * (7 / 3) \n"
        <<"* Invlaid -> 12+3 -5 *(7/3)\n\n";
    cout<<"Enter ~ to Exit\n";
    while(true)
    {
        string s;
        cout<<"\n=>";
        getline(cin,s);
        if(s == "~")
            return 0;
        toPostfix(s);
    }
    return 0;
}
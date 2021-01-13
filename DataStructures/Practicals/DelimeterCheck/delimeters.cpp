#include <iostream>
#include "stack.h"
#include <string>
#include <iomanip>
using namespace std;

void checkDelimeters(string exp)
{
    //creating a Stack of char type
    Stack<char> *stack = new Stack<char>();
    for(int i = 0; i < exp.length(); i++)
    {
        //Brackets -> (), {}, []
        char temp = exp[i];
        if(temp == '(' || temp == '{' || temp == '[')
        {
            stack->push(exp[i]);
        }
        else if(temp == ')' || temp == '}' || temp == ']')
        {
            if(stack->returnTop() == -1)
            {
                cout<<"Invalid Expression\n";
                return;
            }
            else
            {
                char check = stack->pop();
                switch(check)
                {
                    case '(':
                        if(temp != ')')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;
                    case '{':
                        if(temp != '}')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;
                    case '[':
                        if(temp != ']')
                        {
                            cout<<"Invalid Expression\n";
                            return;
                        }
                        break;                    
                    default:
                        break;
                }
            }
            
        }
    }
    if(stack->returnTop() == -1)
    {
        cout<<"Expression is Correct\n";
        delete stack;
        return;
    }
    cout<<"Invalid Expression\n";
    delete stack;
    return;

}


int main()
{
    cout<<setw(30)<<"* Delimiter Checking *\n\n";
    cout<<"Enter ~ to Exit\n";
    string s;
    while(true)
    {
        cout<<"\n=>"; getline(cin,s);
        if(s == "~")
            break;
        checkDelimeters(s);
    }
    return 0;
}
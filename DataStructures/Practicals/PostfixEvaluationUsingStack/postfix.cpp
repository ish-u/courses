#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//Stack
class Stack
{
    private:
        int *S;
        int size;
        int top;
    public:
        //constructor
        Stack()
        {
            size = 10;
            top = -1;
            S = new int[size];
            for(int i = 0; i < size; i++)
            {
                S[i] = i;
            }
        }
        //Destructor
        ~Stack()
        {
            delete[] S;
        }
        //member functions
        int isEmpty();
        void clear();
        void display();
        void push(int x);
        int pop();
        void topElement();
};

//to check whether the Stack is Empty or Not
int Stack :: isEmpty()
{
    if(top == -1)
    {
        return 0;
    }
    return top;
}

//to clear the Stack and set top=-1
void Stack :: clear()
{
    top = -1;
}

//to display the stack
void Stack :: display()
{
    if(top != -1)
    {
        for(int i = 0; i <= top; ++i)
        {
            cout<<S[i]<<" ";
        }
    }
    else
    {
        cout<<"EMPTY";
    }
    cout<<"\n";
}

//to push an element on the Stack
void Stack :: push(int x)
{
    //check whether the Stack is full or not and move forward accordingly
    if(top == (size-1))
    {
        size = size * 2;
        int* tempArray = new int[size];
        for(int i = 0; i <=top; ++i)
        {
            tempArray[i] = S[i];
        }
        //deleting the original array and replacing it with the new one
        delete[] S;
        S = tempArray;
    }
    S[++top] = x;
}

//to pop an element from the array
int Stack :: pop()
{
    if(top != -1)
    {
        return S[top--];
    }
}

//evaluate the Postfix Expression
void postfix(string exp)
{
    Stack *A = new Stack();
    for(int i = 0; i < exp.length(); ++i)
    {
        if(isdigit(exp[i]))
        {
            A->push((int)exp[i]-48);
        }
        else if(exp[i] == '_')
        {
            i++;
            string temp;
            while (exp[i] != '_')
            {
                char c = exp[i];
                temp += c;
                i++;
            }
            A->push(stoi(temp));
        }
        else
        {
            int num_1 = A->pop();
            int num_2 = A->pop();
            switch(exp[i])
            {
                case '+':
                    A->push(num_2 + num_1);
                    break;
                case '-':
                    A->push(num_2 - num_1);
                    break;
                case '*':
                    A->push(num_2 * num_1);
                    break;
                case '/':
                    A->push(num_2 / num_1);
                    break;
            }
        }
    }
    if(A->isEmpty() == 0)
    {
        cout<<":"<<A->pop();
    }
    else
    {
        cout<<"Error in Parsing";
    }    
    delete A;
}

//evaluate the Postfix Expression
void prefix(string exp)
{
    Stack *A = new Stack();
    for(int i = (exp.length()-1); i >= 0 ; --i)
    {
        if(isdigit(exp[i]))
        {
            A->push((int)exp[i]-48);
        }
        else if(exp[i] == '_')
        {
            i--;
            string temp;
            while (exp[i] != '_')
            {
                char c = exp[i];
                temp += c;
                i--;
            }
            string t = "";
            for(int j = (temp.length() -1); j >= 0; j--)
            {
                t += temp[j];
            }
            A->push(stoi(t));
        }
        else
        {
            int num_2 = A->pop();
            int num_1 = A->pop();
            switch(exp[i])
            {
                case '+':
                    A->push(num_2 + num_1);
                    break;
                case '-':
                    A->push(num_2 - num_1);
                    break;
                case '*':
                    A->push(num_2 * num_1);
                    break;
                case '/':
                    A->push(num_2 / num_1);
                    break;
            }
        }
    }
    if(A->isEmpty() == 0)
    {
        cout<<":"<<A->pop();
    }
    else
    {
        cout<<"Error in Parsing";
    }    
    delete A;
}




int main()
{
    cout<<"EVALUATE POSTFIX/PREFIX EXPRESSION\n";
    cout<<"\n * Append ! in start for Prefix Expression"
        <<"\n * Use _(underscore) to enter numbers with more than one digit (ex-> _12_3+ => 15)"
        <<"\n * For Consecutive Numbers with digits more than 2 use as following : _number1__number2_ "
        <<"\n * Enter ~ to Exit\n";
    string s;
    while(true)
    {
        cout<<"\n=>"; getline(cin,s);
        if(s == "~")
            break;
        if(s[0] == '!')
        {
            prefix(s.substr(1));
        }
        else
        {
            postfix(s);
        }
        
    }
    return 0;
}
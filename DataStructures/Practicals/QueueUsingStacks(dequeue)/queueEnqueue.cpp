#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "stack.h"

//class queue
class queue
{
    public:
        int *q;
        int size,front,rear;
        Stack<int> *S1;
        Stack<int> *S2;
        //constructor
        queue(int size = 10)
        {
            front = rear = -1;
            this->size = size;
            S1 = new Stack<int>();
            S2 = new Stack<int>();
        }
        //destructor
        ~queue()
        {
            delete S1;
            delete S2;
        }
        //member function
        int isEmpty();
        int isFull();
        void enqueue(int x);
        void dequeue();
        void clear();
        void display();
};


//isEmmpty() function
int queue :: isEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

//isFull() function
int queue :: isFull()
{
    if(rear == (size-1))
        return 1;
    return 0;
}

//clear() function
void queue :: clear()
{
    if(!isEmpty())
    {
        front = rear = -1;
        S1->clear();
        S2->clear();
        cout<<"Cleared\n";
        getch();
    }
}

//display() function
void queue :: display()
{
    cout<<"QUEUE -> ";
    S1->display();
}

//enqueue() function
void queue :: enqueue(int x)
{
    if(isFull())
    {
        cout<<"Queue is Full\n Dequeue or Clear to Use\n";
        getch();
    }
    else if(isEmpty())
    {
        S1->push(x);
        front++;
        rear++;
    }
    else
    {
        S1->push(x);
        rear++;
    }   
}

//dequeue() function
void queue :: dequeue()
{
    if(isEmpty())
    {
        cout<<"Empty Queue\n";
        getch();
        return;
    }
    else if(front == rear)
    {
        front = rear = -1;
        cout<<S1->pop();
    }
    else
    {
        front++;
        while(S1->returnTop() != -1)
        {
            S2->push(S1->pop());
        }
        cout<<S2->pop();
        while(S2->returnTop() != -1)
        {
            S1->push(S2->pop());
        }
    }
}

//main() function
int main()
{
    queue *Q = new queue();
    int choice;
    int flag = 1;
    do
    {
        Q->display();
        cout<<"--------------------\n"
            <<"Operations :\n"
            <<"1. enqueue(x)\n"
            <<"2. dequeue()\n"
            <<"3. clear()\n"
            <<"4. Exit\n"
            <<"--------------------\n"
            <<"What do you want to do : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int temp;
            cout<<"Element : ";  cin>>temp;
            Q->enqueue(temp);
            break;
        case 2:
            Q->dequeue();
            break;
        case 3:
            Q->clear();
            break;
        case 4:
        default:
            flag = 0;
            break;
        }
        system("CLS");
    } while (flag);
    delete Q;
    return 0;

}
// Perform linear queues using Array implementation.
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Queue Class
class queue
{
    int size,front,rear;
    int* q;
    public:
        //constructor
        queue(int size = 10)
        {
            front = rear = -1;
            this->size = size;
            q = new int[size];
            for(int i = 0; i < size ; ++i)
                q[i] = 0;
        }
        //destructor
        ~queue()
        {
            delete[] q;
        } 
        //member function
        int isEmpty();
        int isFull();
        void enqueue(int x);
        void dequeue();
        void clear();
        void display();
};

int queue :: isEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

int queue :: isFull()
{
    if((rear + 1) % size == front)
        return 1;
    return 0;
}

void queue :: clear()
{
    front = rear = -1;
}

void queue :: enqueue(int x)
{
    if(isEmpty())
    {
        front++;
        rear++;
        q[front] = x;
    }
    else if(isFull())
    {
        cout<<"Queue is full\n";
        cout<<"Dequeue or Clear to use again\n";
        getch();
    }
    else
    {
        if(isFull() == 0)
        {
            rear = (rear + 1) % size;
            q[rear] = x;
        }
    }
}

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
    }
    else
    {   
        front = (front + 1) % size;
        return;
    }

}

void queue :: display()
{
    cout<<"QUEUE-> ";
    if(!isEmpty())
    {
        // taken from ->  http://www.cprogrammingnotes.com/question/static-circular-queue.html
        if(front <= rear)
        {
            for(int i = front; i <= rear; i++)
            {
                cout<<q[i]<<" ";
            }
        }
        else
        {
            for(int i = front; i < size; i++)
            {
                cout<<q[i]<<" ";
            }
            for(int i = 0; i <= rear; i++ )
            {
                cout<<q[i]<<" ";
            }
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Empty\n";
    }
    
}


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
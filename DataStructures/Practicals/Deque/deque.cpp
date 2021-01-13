#include <iostream>
using namespace std;
#include "DLL.h"


template <typename T>
class deque
{
    int size,front,rear;
    DoublyLinkedList<T> *DLL = 0;
    public:
        //constructor
        deque()
        {
            DLL = new DoublyLinkedList<T>();
        }
        //destructor
        ~deque()
        {
            delete DLL;
        } 
        //member function
        int isEmpty();
        int isFull();
        void insertAtFront();
        void insertAtEnd();
        void deleteAtFront();
        void deleteAtEnd();
        T getFront();
        T getRear();
        void clear();
        void display();
};

template <typename T>
int deque<T> :: isEmpty()
{
    if(DLL->isEmpty())
    {
        return 1;
    }
    return 0;
}

template <typename T>
void deque<T> :: insertAtFront()
{
    DLL->insertAtBegin();
}

template <typename T>
void deque<T> :: insertAtEnd()
{
    DLL->insertAtEnd();
}

template <typename T>
void deque<T> :: deleteAtFront()
{
    if(this->isEmpty())
    {
        DLL->deleteAtBegin();
    }
    else
    {
        cout<<"deque is Empty\n";
    }
    
}

template <typename T>
void deque<T> :: deleteAtEnd()
{
    if(this->isEmpty())
    {
        DLL->deleteAtEnd();
    }
    else
    {
        cout<<"deque is Empty\n";
    }
}

template <typename T>
T deque<T> :: getFront()
{
    if(this->isEmpty())
    {
        return DLL->head->data;
    }
    else
    {
        cout<<"Empty\n";
        return INT_MAX;
    }
}

template <typename T>
T deque<T> :: getRear()
{
    if(this->isEmpty())
    {
        return DLL->tail->data;
    }
    else
    {
        cout<<"Empty\n";
        return INT_MAX;
    }
}

template <typename T>
void deque<T> :: display()
{
    if(this->isEmpty())
    {
        DLL->traverse();
    }
    else
    {
        cout<<"Empty\n";
    }
    
}



using namespace std;

int main()
{
    deque<int> *Q = new deque<int>();
    int choice;
    int flag = 1;
    do
    {
        cout<<"--------------------\n";
        cout<<"deque -> ";
        Q->display();
        cout<<"--------------------\n"
            <<"Operations :\n"
            <<"1. insertAtFront()\n"
            <<"2. insertAtEnd()\n"
            <<"3. deleteAtFront()\n"
            <<"4. deleteAtEnd*()\n"
            <<"5. Display Front\n"
            <<"6. Display Rear\n"
            <<"8. Exit\n"
            <<"What do you want to do : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            Q->insertAtFront();
            break;
        case 2:
            Q->insertAtEnd();
            break;
        case 3:
            Q->deleteAtFront();
            break;
        case 4:
            Q->deleteAtEnd();
            break;
        case 5:
            cout<<Q->getFront()<<"\n";
            break;
        case 6:
            cout<<Q->getRear()<<"\n";
            break;
        default:
            flag = 0;
            break;
        }
    cout<<"\n";
    }while (flag);
    delete Q;
    return 0;
}
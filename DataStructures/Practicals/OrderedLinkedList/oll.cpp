#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Node Class
template <typename T>
class Node
{
public:
    T data;
    Node* nextNode;
    //constructor
    Node(T data = 0, Node* nextNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node; DATA = <<"<<this->data<<"\n";
    }
};

template <typename T>
class OrderedLinkedList
{
private:
    //data members
    int totalNodes;
    Node<T> *head,*tail,*temp;
public:
    //constructor
    OrderedLinkedList()
    {
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~OrderedLinkedList()
    {
        temp = head;
        Node<T>* nextNodeptr = 0;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextNodeptr = temp->nextNode;
            delete temp;
            temp = nextNodeptr;
        }
        cout<<"Done.\n";
    }

    //member functions 
    //insert function
    void insertNode()
    {
        temp = new Node<T>();
        cout<<"Enter the Data : ";cin>>temp->data;
        if(head == 0)
        {
            head = tail = temp;
            totalNodes++; 
        }
        else if(head->data == temp->data || tail->data == temp->data)
        {
            return;
        }
        else if(head->data > temp->data)
        {
            temp->nextNode = head;
            head = temp;
            totalNodes++;
        }
        else if(tail->data < temp->data)
        {
            tail->nextNode = temp;
            tail = temp;
            totalNodes++;
        }
        else
        {
            Node<T>* requiredNode = head;
            while(requiredNode->nextNode->data < temp->data)
            {
                requiredNode = requiredNode->nextNode;
            }
            if(requiredNode->nextNode->data == temp->data)
            {
                //beacuse the Node Already Exists
                return;
            }
            else
            {
                temp->nextNode = requiredNode->nextNode;
                requiredNode->nextNode = temp;
                totalNodes++;
            }
            
        }
        temp = 0;
        
    }

    //delete function
    void deleteNode()
    {
        int loc;
        cout<<"Enter the Location : "; cin>>loc;
        if(totalNodes > 0)
        {
            if(loc < 0 || loc > totalNodes)
            {
                cout<<"INVALID\n";
                cout<<"Press Enter to Continue ";
                getch();
            }
            else if(loc == 1)
            {
                temp = head;
                if(totalNodes == 1)
                {
                    head = tail = 0;
                }
                else
                {
                    head = head->nextNode;                    
                }
                delete temp;
                temp = 0;
                totalNodes--;
            }
            else
            {
                int counter = 1;
                temp = head;
                while(counter != (loc-1))
                {
                    temp = temp->nextNode;
                    counter++;
                }
                Node<T>* requiredNode = temp->nextNode;
                temp->nextNode = requiredNode->nextNode;
                if(requiredNode == tail)
                {
                    temp->nextNode = 0;
                    tail = temp;
                }
                delete requiredNode;
                temp = requiredNode = 0;
                totalNodes--;
            }
            
        }
    }
    //merge function
    void merge(OrderedLinkedList<T> &A,OrderedLinkedList<T> &B)
    {
        //temporary list
        OrderedLinkedList<T> *tempList = new OrderedLinkedList<T>();
        if(A.totalNodes > 0 && B.totalNodes > 0)
        {
            A.temp = A.head;
            B.temp = B.head;
            //setting the head of the temporary list
            tempList->temp = new Node<T>();
            tempList->totalNodes++;
            if(A.temp->data > B.temp->data)
            {
                tempList->temp->data = B.head->data;
                B.temp = B.temp->nextNode;
            }
            else if (B.temp->data > A.temp->data)
            {
                tempList->temp->data = A.head->data;
                A.temp = A.temp->nextNode;
            }
            else if(A.temp->data == B.temp->data)
            {
                tempList->temp->data = A.head->data;
                A.temp = A.temp->nextNode;
                B.temp = B.temp->nextNode;
            }
            //adding the head of the temporary list
            tempList->head = tempList->tail =  tempList->temp;
            while(A.temp != 0 && B.temp != 0)
            {
                tempList->temp->nextNode = new Node<T>();
                tempList->temp = tempList->temp->nextNode;
                if(A.temp->data > B.temp->data)
                {
                    tempList->temp->data = B.temp->data;
                    B.temp = B.temp->nextNode;
                }
                else if(A.temp->data < B.temp->data)
                {
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->nextNode;
                }
                else if(A.temp->data == B.temp->data)
                {
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->nextNode;
                    B.temp = B.temp->nextNode;
                }
            }
            if(A.temp != 0)
            {
                while(A.temp != 0)
                {
                    tempList->temp->nextNode = new Node<T>();
                    tempList->temp = tempList->temp->nextNode;
                    tempList->temp->data = A.temp->data;
                    A.temp = A.temp->nextNode;                   
                }
            }
            else if(B.temp != 0)
            {
                while(B.temp != 0)
                {
                    tempList->temp->nextNode = new Node<T>();
                    tempList->temp = tempList->temp->nextNode;
                    tempList->temp->data = B.temp->data;
                    B.temp = B.temp->nextNode;   
                }
            }
            tempList->traverse();
            getch();
        }
    }
    //traverse function
    void traverse()
    {
        if(totalNodes > 0)
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->nextNode;
            }
            cout<<"\n";
            temp = 0;
        }
        else
        {
            cout<<"EMPTY\n";
        }
        
    }
};


int main()
{
    OrderedLinkedList<int>* list_1 = new OrderedLinkedList<int>();
    OrderedLinkedList<int>* list_2 = new OrderedLinkedList<int>();
    OrderedLinkedList<int>* list = list_1;
    int currentList = 1;
    int choice;
    char flag = 'y';
    do
    {
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"ORDERED LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"LIST  1: "; list_1->traverse();
        cout<<"LIST  2: "; list_2->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"CURRENTLY SELECTED - > "<<currentList<<"\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Insert \n"
            <<"2. Delete \n"
            <<"3. Merge \n"
            <<"4. Switch \n"
            <<"5. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                list->insertNode();
                break;
            case 2:
                list->deleteNode();
                break;
            case 3:
                list->merge(*list_1,*list_2);
                break;
            case 4:
                currentList = (currentList == 1) ? 2 : 1;
                list = (list == list_1) ? list_2 : list_1;
                break; 
            case 5:
                flag = 'n';
                break;
            default:
                break;
        }
        system("CLS");

    }while(flag != 'n');


}
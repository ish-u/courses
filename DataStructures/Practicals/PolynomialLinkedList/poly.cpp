// 13.	WAP to add two polynomials using linked list representation.
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;


//Polynomial Node Class
template <typename T>
class PolynomialNode
{
public:
    PolynomialNode *nextNode; 
    int power;
    T cofficient;
    //constructor
    PolynomialNode(T power = 0, T cofficient = 0, PolynomialNode *nextNode = 0)
    {   
        this->power = power;
        this->cofficient = cofficient;
        this->nextNode = nextNode;
    }
    
};

template <typename T>
class PolynomialLinkedList
{
private:
    //data members
    PolynomialNode<T> *head,*tail,*temp;
    int totalNodes;
public:
    //constructor
    PolynomialLinkedList()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~PolynomialLinkedList()
    {
        temp = head;
        PolynomialNode<T>* nextNodePtr;
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        } 
        cout<<"Done.\n";
    }
    //member functions

    //traverse function
    void print()
    {
        if(head == 0)
        {
            cout<<"EMPTY.\n";
        }
        else
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->cofficient<<"x^"<<temp->power;
                temp = temp->nextNode;
                if(temp != 0)
                    cout<<" + ";
            }
            cout<<"\n";
            temp = 0;
        }
    }

    //insert function
    void insertTerm()
    {   
        temp = new PolynomialNode<T>();
        cout<<"Enter the Power of term : "; cin>>temp->power;
        cout<<"Enter the Cofficient of term : "; cin>>temp->cofficient;
        if(head == 0)
        {
            head = tail = temp;
        }
        else if (temp->power == head->power)
        {
            head->cofficient += temp->cofficient;
        }
        else if(temp->power > tail->power)
        {
            tail->nextNode = temp;
            tail = temp;
        }
        else if(temp->power < head->power)
        {
            temp->nextNode = head;
            head = temp;
        }
        else
        {
            PolynomialNode<T>* requiredNode = head;
            while(requiredNode != 0)
            {
                if(requiredNode->nextNode->power > temp->power)
                {
                    temp->nextNode = requiredNode->nextNode;
                    requiredNode->nextNode = temp;
                    break;
                }
                else if(requiredNode->nextNode->power == temp->power)
                {
                    requiredNode->nextNode->cofficient += temp->cofficient;
                    break;
                }
                requiredNode = requiredNode->nextNode;
            }
            requiredNode = 0;
        }
        temp = 0;
        totalNodes++;

    }
    //delete a term in the selected polynomial
    void deleteTerm()
    {
        int loc;
        cout<<"Enter the location you want to remove : "; cin>>loc;
        if(loc < 0 || loc > totalNodes)
        {
            cout<<"Invalid Location\n";
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
            PolynomialNode<T> *requiredNode = head;
            while(counter != (loc-1))
            {
                requiredNode= requiredNode->nextNode;
                counter++;
            }
            temp = requiredNode->nextNode;
            requiredNode->nextNode = temp->nextNode;
            //checking if the entered location is a tail
            if(temp == tail)
            {
                tail = requiredNode;
                requiredNode->nextNode = 0;
            }
            delete temp;
            temp = 0;
            totalNodes--;
            
        }
        
    }
    //add two polynomial
    void operator +(PolynomialLinkedList<T>& l)
    {
        if(totalNodes > 0 && l.totalNodes > 0)
        {
            temp = head;
            l.temp = l.head;
            PolynomialLinkedList<T>* tempPoly = new PolynomialLinkedList<T>();
            tempPoly->temp = new PolynomialNode<T>();
            if(temp->power > l.temp->power)
            {
                tempPoly->temp->power = l.temp->power;
                tempPoly->temp->cofficient = l.temp->cofficient;
                tempPoly->head = tempPoly->temp;
                l.temp = l.temp->nextNode;
                
            }
            else if(temp->power < l.temp->power)
            {
                tempPoly->temp->power = temp->power;
                tempPoly->temp->cofficient = temp->cofficient;
                tempPoly->head = tempPoly->temp;
                temp = temp->nextNode;
            }
            else if (temp->power == l.temp->power)
            {
                tempPoly->temp->power = temp->power + l.temp->power;
                tempPoly->temp->cofficient = temp->cofficient + l.temp->cofficient;
                tempPoly->head = tempPoly->temp;
                temp = temp->nextNode;
                l.temp = l.temp->nextNode;
            }
            tempPoly->temp = tempPoly->head;
            while(temp != 0 && l.temp != 0)
            {
                tempPoly->temp->nextNode = new PolynomialNode<T>();
                tempPoly->temp = tempPoly->temp->nextNode;
                if(temp->power == l.temp->power)
                {
                    tempPoly->temp->power = temp->power + l.temp->power;
                    tempPoly->temp->cofficient = temp->cofficient + l.temp->cofficient;
                    temp = temp->nextNode;
                    l.temp = l.temp->nextNode;
                }
                else if(temp->power < l.temp->power)
                {
                    tempPoly->temp->power = temp->power;
                    tempPoly->temp->cofficient = temp->cofficient;
                    temp = temp->nextNode;
                }
                else if(temp->power > l.temp->power)
                {
                    tempPoly->temp->power = l.temp->power;
                    tempPoly->temp->cofficient = l.temp->cofficient;
                    l.temp = l.temp->nextNode;
                }
            }
            if(temp != 0)
            {
                while(temp != 0)
                {
                    tempPoly->temp->nextNode = new PolynomialNode<T>();
                    tempPoly->temp = tempPoly->temp->nextNode;
                    tempPoly->temp->power = temp->power;
                    tempPoly->temp->cofficient = temp->cofficient;
                    temp = temp->nextNode;                
                }
            }
            else if(l.temp != 0)
            {
                while(l.temp != 0)
                {
                    tempPoly->temp->nextNode = new PolynomialNode<T>();
                    tempPoly->temp = tempPoly->temp->nextNode;
                    tempPoly->temp->power = l.temp->power;
                    tempPoly->temp->cofficient = l.temp->cofficient;
                    l.temp = l.temp->nextNode;
                }
            }

            //printing the node
            tempPoly->print();
        }
        
    }
};


int main()
{

    PolynomialLinkedList<int> *poly;
    PolynomialLinkedList<int> *poly_1 = new PolynomialLinkedList<int>();
    PolynomialLinkedList<int> *poly_2 = new PolynomialLinkedList<int>();
    int currentPolynomial = 1;
    poly = poly_1;
    char flag = 'y';
    int choice;
    //menu
    do{
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"POLYNOMIAL LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"Polynomial 1 : "; poly_1->print();
        cout<<"Polynomial 2 : "; poly_2->print();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"CURRENTLY SELECT : "<<currentPolynomial<<"\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Switch \n"
            <<"2. Insert \n"
            <<"3. Delete \n"
            <<"4. Add\n"
            <<"5. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                currentPolynomial = (currentPolynomial == 1) ? 2 : 1;
                poly = (poly == poly_1) ? poly_2 : poly_1;
                break;
            case 2:
                poly->insertTerm();
                break;
            case 3:
                poly->deleteTerm();
                break;
            case 4:
                cout<<setw(30)<<setfill('-')<<"\n";
                cout<<"ADDITION : "; *poly_1 + *poly_2;
                cout<<setw(30)<<setfill('-')<<"\n";
                cout<<"Press Enter to Continue ";
                getch();
                break;
            case 5:
                flag = 'n';
                break;
            default:
                break;
        }
        system("CLS");

    }
    while(flag == 'y');
    cout<<"\n";
    system("CLS");
    delete poly_1;
    delete poly_2;
    return 0;
}
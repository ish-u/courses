
template <typename T>
class Node
{
public:
    //data members
    T data;
    Node *nextNode;
    Node *prevNode;
    //constructor
    Node(T data = 0, Node *nextNode = 0, Node *prevNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
        this->prevNode = prevNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node ; Data = "<<this->data<<"\n";
    }
};


//Doubly Linked List Class
template <typename T>
class DoublyLinkedList
{
public:
    //data members
    Node<T> *head,*tail,*temp;
    int totalNodes;
    //constructor
    DoublyLinkedList()
    {
        tail = head = temp = 0;
        totalNodes = 0;
    }
    //desctructor
    ~DoublyLinkedList()
    {
        system("CLS");
        temp = head;
        Node<T> *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        cout<<"\nDone.\n";
    }
    
    //member functions
    //isEmpty() function
    int isEmpty()
    {
        if(totalNodes)
        {
            return totalNodes;
        }
        return 0;
    }

    //insert at the begin
    void  insertAtBegin()
    {
        //taking input from User
        temp = new Node<T>();
        cout<<"Enter the Data : ";
        cin>>temp->data;
        //checking if the list is Empty or not and Adding a Node Object accordingly
        if(head != 0)
        {
            head->prevNode = temp;
            temp->nextNode = head;
            head = temp;
        }
        else
        {
            head = tail = temp;
        }   
        totalNodes++;
        temp = 0;
    }

    //insert at the end
    void insertAtEnd()
    {
        //taking input from User
        temp = new Node<T>();
        cout<<"Enter the Data : ";
        cin>>temp->data;
        //checking if the list is Empty or not and Adding a Node Object accordingly
        if(head != 0)
        {
            tail->nextNode = temp;
            temp->prevNode = tail;
            tail = temp;
        }
        else
        {
            head = tail = temp;
        }
        totalNodes++;
        temp = 0;

    }

    //insert at n-th location
    void  insertAtLoc()
    {
        //taking input from User
        temp = new Node<T>();
        cout<<"Enter the Data : ";
        cin>>temp->data;
        //asking user for Loaction or Index they want to insert Node
        int loc;
        cout<<"Enter Location : "; cin>>loc;
        if(loc < 0 || loc > totalNodes)
        {
            cout<<"Invalid Location\n";
        }
        else if(loc == 1)
        {
            head->prevNode = temp;
            temp->nextNode = head;
            head = temp;
            totalNodes++;
        }
        else
        {
            int counter = 1;
            Node<T> *requiredNode = head;
            //traversing to the Node of given location
            while(counter != (loc-1))
            {
                requiredNode = requiredNode->nextNode;
                counter++;
            }
            //linking the "temp" Node in the linked list at the asked "loc"
            temp->nextNode = requiredNode->nextNode;
            temp->prevNode = requiredNode;
            requiredNode->nextNode->prevNode = temp;
            requiredNode->nextNode = temp;
            totalNodes++;
        }
        temp = 0;
    }

    //delete at the beginning
    void  deleteAtBegin()
    {
        if(isEmpty())
        {
            temp = head;
            head = head->nextNode;
            head->prevNode = 0;
            delete temp;
            temp = 0;
        }
        else
        {
            cout<<"Invalid\n";
        }
    }

    //delete at the end
    void  deleteAtEnd()
    {
        if(isEmpty())
        {
            if(head == tail)
            {
                delete head;
                head = tail = temp = 0;
            }
            else
            {
                temp = tail;
                tail = tail->prevNode;
                tail->nextNode = 0;
                delete temp;
                temp = 0;
            }
            totalNodes--;
        }
        else
        {
            cout<<"Invalid\n";
        }

    }

    //delete at n-th location
    void  deleteAtLoc()
    {
        //asking user for Loaction or Index they want to insert Node
        int loc;
        cout<<"Enter Location : "; cin>>loc;
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
                head->prevNode = 0;
            }
            delete temp;
            temp = 0;
            totalNodes--;
            
        }
        else
        {
            int counter = 1;
            temp = head;
            while (counter != loc)
            {
                temp = temp->nextNode;
                counter++;
            }
            //checking if the entered location is a tail
            if(temp == tail)
            {
                tail = temp->prevNode;
                tail->nextNode = 0;
            }
            else
            {
                temp->prevNode->nextNode = temp->nextNode;
                temp->nextNode->prevNode = temp->prevNode;
            }
            delete temp;
            temp = 0;
            totalNodes--;
            
        }
    }

    //traverse function
    void  traverse()
    {
        if(head != 0)
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->nextNode;
            }
            temp = 0;
            cout<<"\n";
        }
        else
        {
            cout<<"EMPTY\n";
        }   
    }

    //search function
    void   search()
    {
        if(isEmpty())
        {
            //query from user
            int query;
            cout<<"Enter the Element You want to Search"; cin>>query;
            temp = head;
            int counter = 1;
            while(temp != 0)
            {
                if(temp->data == query)
                {
                    cout<<"Found at Index : "<<counter<<"\n";
                    return; 
                }
                temp = temp->nextNode;
                counter++;
            }
            cout<<"Not Found\n";
        }
        else
        {
            cout<<"List Is Empty\n";
        }
    }
};


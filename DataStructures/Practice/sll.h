//Node Class
template <typename T>
class Node
{
public:
    //data members
    T data;
    Node *nextNode;
    //constructor
    Node(T data = 0, Node *nextNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node ; Data = "<<this->data<<"\n";
    }
};

//Singly Linked List
template <typename T>
class SinglyLinkedList
{
private:
    //data members
    Node<T> *head,*tail,*temp;
    int totalNodes;
public:
    //constructor
    SinglyLinkedList()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~SinglyLinkedList()
    {
        temp = head;
        Node<T> *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        cout<<"Done.\n";
    }
    //member functions
    Node<T>* returnHead(); 
    void insertAtEnd();
    void insertAtBegin();
    void insertAtLoc();
    void deleteAtEnd();
    void deleteAtBegin();
    void deleteAtLoc();
    void traverse();    //to display the list
    void search();
    int isEmpty();
    void reverse();
    void operator +(SinglyLinkedList &l); 
};


template <typename T>
Node<T>* SinglyLinkedList<T> :: returnHead()
{
    return head;
}

//isEmpty Function
template <typename T>
int SinglyLinkedList<T> :: isEmpty()
{
    if(totalNodes == 0)
    {
        return 0;
    }
    return totalNodes;
}

//search function
template <typename T>
void SinglyLinkedList<T> :: search()
{
    if(isEmpty())
    {
        //getting data value from User
        int query;
        int counter = 1;
        cout<<"Enter the data (*type - 'int') you want to Search : ";
        cin>>query;
        temp = head;
        while(temp != 0)
        {
            if(temp->data == query)
            {
                cout<<"Found @ Index - "<<counter<<"\n";
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


//insert at beginnig
template <typename T>
void SinglyLinkedList<T> :: insertAtBegin()
{
    //creating a new Node Object
    temp = new Node<T>();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    if(head != 0)
    {
        temp->nextNode = head;
        head = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    totalNodes++;
}

//insert at end
template <typename T>
void SinglyLinkedList<T> :: insertAtEnd()
{
    //creating a new Node Object
    temp = new Node<T>();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    if(head != 0)
    {
        tail->nextNode = temp;
        tail = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    totalNodes++;
}

//insert a node at n-th position
template <typename T>
void SinglyLinkedList<T> :: insertAtLoc()
{
    //creating a new Node Object
    temp = new Node<T>();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    //taking location input
    int loc;
    cout<<"Enter Location : ";
    cin>>loc;
    if(loc < 0 || loc > totalNodes)
    {
        cout<<"Invalid Location\n";
    }
    else if(loc == 1)
    {
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
        requiredNode->nextNode = temp;
        totalNodes++;
    }
    temp = 0;
    
}

//delete at beginning
template <typename T>
void SinglyLinkedList<T> :: deleteAtBegin()
{
    if(totalNodes > 0)
    {
        temp = head;
        head = head->nextNode;
        delete temp;
        temp = 0;
        totalNodes--;
    }
    else
    {
        cout<<"Invalid\n";
    }
    
}

//delete at end
template <typename T>
void SinglyLinkedList<T> :: deleteAtEnd()
{
    if(totalNodes > 0)
    {
        if(head == tail)
        {
            delete head;
            head = tail = temp = 0;
            totalNodes--;
        }
        else
        {       
            temp = head;
            while (temp->nextNode != tail)
            {
                temp = temp->nextNode;
            }
            delete tail;
            temp->nextNode = 0;
            tail = temp;
            temp = 0;
            totalNodes--;
        }
    }
    else
    {
        cout<<"Invalid\n";
    }
    
}

//delete at location
template <typename T>
void SinglyLinkedList<T> :: deleteAtLoc()
{
    //taking location input
    int loc;
    cout<<"Enter the location you want to enter the Node : ";
    cin>>loc;
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
        Node<T> *requiredNode = head;
        //traversing to the Node of given location
        while(counter != (loc-1))
        {
            requiredNode = requiredNode->nextNode;
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
//traverse function
template <typename T>
void SinglyLinkedList<T> :: traverse()
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
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        cout<<"\n";
        temp = 0;
    }
    
}

//reverse the linked list
template <typename T>
void SinglyLinkedList<T> :: reverse()
{
    if (isEmpty())
    {
        temp = head;
        Node<T> *previous = 0;
        Node<T> *next = 0;
        while(temp != 0)
        {
            next = temp->nextNode;
            temp->nextNode = previous;
            previous = temp;
            temp = next;  
        }
        tail = head;
        head = previous;
        temp = 0;
    }
    else
    {
        cout<<"The List is EMPTY\n";
    }
    
}

//concatenate function
template <typename T>
void SinglyLinkedList<T> :: operator +(SinglyLinkedList<T> &l)
{
    if(this->totalNodes > 0 && l.totalNodes > 0)
    {
        this->temp = tail;
        Node<T> *newNode = 0;
        l.temp = l.head;
        while(l.temp != 0)
        {
            newNode = new Node<T>(l.temp->data,0);
            this->totalNodes++;
            this->temp->nextNode = newNode;
            this->temp = this->temp->nextNode;
            l.temp = l.temp->nextNode; 
        }
        this->tail = newNode;
        this->temp = l.temp = newNode = 0;
    }
}



//class Node
template <typename T>
class Node
{
    public:
        T data;
        Node *nextNode;
        //constructor
        Node(T data, Node<T>* nextNode)
        {
            this->data = data;
            this->nextNode = nextNode;
        }
        //destructor
        ~Node()
        {
            // cout<<"Destroyed "<<this->data<<"\n";
        }
};

template <typename T>
class queueLL
{
    private:
        Node<T> *head, *tail, *temp;
        int totalNodes;
    public:
        //constructor
        queueLL()
        {
           head = tail = temp = 0;
           totalNodes = 0; 
        }
        //destructor
        ~queueLL()
        {
            temp = head;
            Node<T>* nextPtr = 0;
            while(temp->nextNode != head)
            {
                nextPtr = temp->nextNode;
                delete temp;
                temp = nextPtr;
            }
            temp = nextPtr = 0;
            cout<<"Done\n";          
        }

        int isEmpty()
        {
            if(totalNodes == 0)
                return 1;
            return 0;
        }

        void enqueue(T x)
        {
            temp = new Node<T>(x,0);
            if(tail == 0)
            {
                head = tail = temp;
                tail->nextNode = head;
            }
            else
            {
                tail->nextNode = temp;
                tail = temp;
                temp->nextNode = head;
            }
            temp = 0;
            totalNodes++;
            
        }

        void dequeue()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty\n";
            }
            else
            {
                if(head == tail)
                {
                    temp = head;
                    head = tail = 0;
                }
                else
                {
                    temp = head;
                    head = head->nextNode;
                    tail->nextNode = head;
                }
                // cout<<temp->data;
                delete temp;
                temp = 0;
                totalNodes--;
            }
        }

        void clear()
        {
            if(!isEmpty())
            {
                temp = head;
                Node<T>* nextPtr = 0;
                while(temp != head)
                {
                    nextPtr = temp->nextNode;
                    delete temp;
                    temp = nextPtr;
                }
                temp = nextPtr = head = tail = 0; 
                totalNodes = 0;
                cout<<"Queue Cleared\n";
            }
        }

        T firstEle()
        {
            if(!isEmpty())
            {
                return head->data;
            }
            return 0;
        }

        void display()
        {
            if(!isEmpty())
            {
                temp = head;
                do
                {
                    cout<<temp->data<<" ";
                    temp = temp->nextNode;
                }
                while(temp != head);
                cout<<"\n";
                temp = 0;
            }
            else
            {
                cout<<"EMPTY\n";
            }
            
        }

};


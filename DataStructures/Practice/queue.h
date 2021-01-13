//class NodeQ
template <typename T>
class NodeQ
{
    public:
        T data;
        NodeQ *nextNode;
        //constructor
        NodeQ(T data, NodeQ* nextNode)
        {
            this->data = data;
            this->nextNode = nextNode;
        }
        //destructor
        ~NodeQ(){}
};


class QueueError : public exception
{
    public:
        string s;
        QueueError(string s)
        {
            this->s = s; 
        }
};


template <typename T>
class queueLL 
{
    private:
        NodeQ<T> *head, *tail, *temp;
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
            NodeQ<T>* nextPtr = 0;
            while (temp != 0) 
            {
                nextPtr = temp->nextNode;
                delete temp;
                temp = nextPtr;
            }
            temp = nextPtr = 0;
            // cout<<"Done\n";          
        }

        int isEmpty()
        {
            if(totalNodes == 0)
                return 1;
            return 0;
        }

        void enqueue(T x)
        {
            temp = new NodeQ<T>(x,0);
            if(tail == 0)
            {
                head = tail = temp;
            }
            else
            {
                tail->nextNode = temp;
                tail = temp;
            }
            temp = 0;
            totalNodes++;
            
        }

        void dequeue()
        {
            if(isEmpty())
            {
                throw QueueError("Queue is Empty\n");
                cout<<"Queue is Empty\n";
                getch();
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
                }
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
                NodeQ<T>* nextPtr = 0;
                while(temp != 0)
                {
                    nextPtr = temp->nextNode;
                    delete temp;
                    temp = nextPtr;
                }
                temp = nextPtr = head = tail = 0; 
                totalNodes = 0;
                cout<<"Queue Cleared\n";
                getch();
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
                while (temp != 0)
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
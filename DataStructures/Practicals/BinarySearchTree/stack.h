//NodeLL Class
template <typename T>
class NodeLL
{
    public:
        T data;
        NodeLL* nextNode;
        //constructor
        NodeLL(T data = 0, NodeLL* nextNode = 0)
        {
            this->data = data;
            this->nextNode = nextNode;
        }
        //destructor
        ~NodeLL()
        {
            // cout<<"DESTROYING : "<<this->data<<"\n";
        }
};

//Stack Linked List Class
template <typename T>
class StackLL
{
    private:
        NodeLL<T> *top,*temp;
        int totalNodes;
    public:
        //constructor
        StackLL()
        {
            top = temp = 0;
            totalNodes = 0;
        }
        //destructor
        ~StackLL()
        {
            temp = top;
            NodeLL<T> *nextNodePtr;
            while(temp != 0)
            {
                nextNodePtr = temp->nextNode;
                delete temp;
                temp = nextNodePtr;
            }
            // cout<<"Done.\n";
        }
        //member functions

        //return the number of elements in the stack
        int isEmpty()
        {
            if(totalNodes)
            {
                return totalNodes;
            }
            return 0;
        }

        //clear the stack
        void clear()
        {
            cout<<"Clearing The Stack\n";
            temp = top;
            NodeLL<T> *nextNodePtr;
            while(temp != 0)
            {
                nextNodePtr = temp->nextNode;
                delete temp;
                temp = nextNodePtr;
            }
            top = temp = 0;
            totalNodes = 0;
            // cout<<"Done.\n";
        }

        //display the stack
        void display()
        {
            if(isEmpty())
            {    
                temp = top;
                while(temp != 0)
                {
                    cout<<temp->data<<" ";
                    temp = temp->nextNode;
                }
                cout<<"\n";
            }
            else
            {
                cout<<"EMPTY\n";
            }
        }

        //push an element to the stack
        void push(T x)
        {
            temp = new NodeLL<T>(x,0);
            if(top == 0)
            {
                top = temp;
            }
            else
            {
                temp->nextNode = top;
                top = temp;
            }
            temp = 0;
            totalNodes++;
        }

        //pop and element from the Stack
        void pop()
        {
            if(top != 0)
            {
                temp = top;
                top = top->nextNode;
                delete temp;
                temp = 0;
                totalNodes--;
            }
        }

        //prints the top element of the Stack
        T topElement()
        {
            if(top != 0)
            {
                return top->data;
            }
            return 0;
        }

};

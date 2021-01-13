//Stack
template <typename T>
class Stack
{
    private:
        T *S;
        int size;
        int top;
    public:
        //constructor
        Stack()
        {
            size = 10;
            top = -1;
            S = new T[size];
            for(int i = 0; i < size; i++)
            {
                S[i] = 0;
            }
        }
        //Destructor
        ~Stack()
        {
            delete[] S;
        }
        //member functions
        int returnTop();
        void push(T x);
        void display();
        void clear();
        T pop();
};

//to check whether the Stack is Empty or Not
template <typename T>
int Stack<T> :: returnTop()
{
    return top;
}

//to push an element on the Stack
template <typename T>
void Stack<T> :: push(T x)
{
    //check whether the Stack is full or not and move forward accordingly
    if(top == (size-1))
    {
        size = size * 2;
        T* tempArray = new T[size];
        for(int i = 0; i <=top; ++i)
        {
            tempArray[i] = S[i];
        }
        //deleting the original array and replacing it with the new one
        delete[] S;
        S = tempArray;
    }
    S[++top] = x;
}

//to pop an element from the array
template <typename T>
T Stack<T> :: pop()
{
    if(top != -1)
    {
        return S[top--];
    }
}

//to display the stack
template <typename T>
void Stack<T> :: display()
{
    if(top != -1)
    {
        for(int i = 0; i <= top; ++i)
        {
            cout<<S[i]<<" ";
        }
    }
    else
    {
        cout<<"EMPTY";
    }
    cout<<"\n";
}

//to clear the Stack and set top=-1
template <typename T>
void Stack<T> :: clear()
{
    top = -1;
}

template <typename T>
class lowerTriangle
{
    private:
        int size;
        int dimension;
        T *lower;
    public:
        lowerTriangle(int dimension);
        ~lowerTriangle();
        void store(int i, int j);
        void store(int i, int j,int data);
        T retrive(int i, int j);
        void display();
        void multiply(lowerTriangle<T> *A, lowerTriangle<T> *B);
};


template <typename T>
lowerTriangle<T> :: lowerTriangle(int dimension)
{
    this->dimension = dimension;
    if(dimension > 0)
    {
        size = ((dimension+1)*dimension)/2;
        lower = new T[size];
        for(int i = 0; i < size; i++)
        {
            lower[i] = 0;
        }
    }
    else
    {
        lower = 0;
    }
}

template <typename T>
lowerTriangle<T> :: ~lowerTriangle()
{
    delete[] lower;
}

template <typename T>
void lowerTriangle<T> :: display()
{
    for(int i = 1; i <= dimension; i++)
    {
        for(int j = 1; j <= dimension; j++)
        {
            if(i >= j)
            {
                int k = (i*(i-1))/2 + j;
                cout<<setw(3)<<lower[k-1]<<" ";
            }
            else
            {
                cout<<setw(3)<<0<<" ";
            }
        }
        cout<<"\n";
    }
}

template <typename T>
void lowerTriangle<T> :: store(int i, int j)
{
    if((i <= dimension) && (j <= dimension))
    {
        if(i >= j)
        {
            T temp = 0;
            cout<<"Data : "; cin>>temp;    
            int k = (i*(i-1))/2 + j;
            lower[k-1] = temp;
        }       
    }
    else
    {
        cout<<"Out of Bounds\n";
        return;
    }
}

//store overloaded
template <typename T>
void lowerTriangle<T> :: store(int i, int j,int data)
{
    if((i <= dimension) && (j <= dimension))
    {
        if(i >= j)
        {    
            int k = (i*(i-1))/2 + j;
            lower[k-1] = data;
        }       
    }
    else
    {
        cout<<"Out of Bounds\n";
        return;
    }
}

template <typename T>
T lowerTriangle<T> :: retrive(int i, int j)
{
    if(i <= dimension && j <= dimension)
    {
        if(i >= j)
        { 
            int k = (i*(i-1))/2 + j; 
            return lower[k-1];
        }
    }
    return 0;
}


template <typename T>
void lowerTriangle<T> :: multiply(lowerTriangle<T> *A, lowerTriangle<T> *B)
{
    lowerTriangle<T>* temp = new lowerTriangle<T>(A->dimension);
    //multiplying 
    for(int i = 1; i <= A->dimension; i++)
    {
        for(int j = 1; j <= A->dimension; j++)
        {
            for(int k = 1; k <= A->dimension; k++)
            {
                temp->store(i,j,temp->retrive(i,j) + (A->retrive(i,k))*(B->retrive(k,j)));
            }
        }
    }
    temp->display();
    delete temp;
    return ;
}

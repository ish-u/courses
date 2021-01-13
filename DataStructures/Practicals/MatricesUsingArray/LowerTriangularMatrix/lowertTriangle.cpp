#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

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
        T retrive(int i, int j);
        void display();
};

template <typename T>
lowerTriangle<T> :: lowerTriangle(int dimension)
{
    this->dimension = dimension;
    if(dimension > 0)
    {
        size = ((dimension+1)*dimension)/2;
        cout<<size;
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


int main()
{
    int flag = true;;
    int op = 0;
    int size;
    cout<<"Lower Triangular Matrix\n";
    cout<<"Enter Dimension :"; cin>>size;
    if(size < 0)
    {
        return -1;
    }
    lowerTriangle<int> *d = new lowerTriangle<int>(size);
    system("CLS");
    do
    {
        cout<<"[Indexing Start at (1,1)]\n";
        int i = 0;
        int j = 0;
        d->display();
        cout<<"1. Store\n"
            <<"2. Retrieve\n"
            <<"Enter Operation : "; cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Enter Index : "; cin>>i; cin>>j;
                d->store(i,j);
                break;
            case 2:
                cout<<"Enter Index : "; cin>>i; cin>>j;
                cout<<d->retrive(i,j)<<"\n";
                break;
            default:
                flag = false;
                break;
        }
        // getch();
        // system("CLS");
        cout<<"\n";
    }
    while(flag);
    return 0;
}
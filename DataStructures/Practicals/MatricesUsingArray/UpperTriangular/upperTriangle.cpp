#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

template <typename T>
class upperTriangle
{
    private:
        int size;
        int dimension;
        T *upper;
    public:
        upperTriangle(int dimension);
        ~upperTriangle();
        void store(int i, int j);
        T retrive(int i, int j);
        void display();
};

template <typename T>
upperTriangle<T> :: upperTriangle(int dimension)
{
    this->dimension = dimension;
    if(dimension > 0)
    {
        size = ((dimension+1)*dimension)/2;
        cout<<size;
        upper = new T[size];
        for(int i = 0; i < size; i++)
        {
            upper[i] = 0;
        }
    }
    else
    {
        upper = 0;
    }
}

template <typename T>
upperTriangle<T> :: ~upperTriangle()
{
    delete[] upper;
}

template <typename T>
void upperTriangle<T> :: display()
{
    for(int i = 1; i <= dimension; i++)
    {
        for(int j = 1; j <= dimension; j++)
        {
            if(i <= j)
            {
                int k = size - (j*(j-1)/2) + (i-j);
                cout<<setw(3)<<upper[k-1]<<" ";
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
void upperTriangle<T> :: store(int i, int j)
{
    if((i <= dimension) && (j <= dimension))
    {
        if(i <= j)
        {
            T temp = 0;
            cout<<"Data : "; cin>>temp;    
            int k = size - (j*(j-1)/2) + (i-j);
            upper[k-1] = temp;
        }       
    }
    else
    {
        cout<<"Out of Bounds\n";
        return;
    }
}

template <typename T>
T upperTriangle<T> :: retrive(int i, int j)
{
    if(i <= dimension && j <= dimension)
    {
        if(i <= j)
        { 
            int k = size - (j*(j-1)/2) + (i-j); 
            return upper[k-1];
        }
    }
    return 0;
}


int main()
{
    int flag = true;;
    int op = 0;
    int size;
    cout<<"Upper Triangular Matrix\n";
    cout<<"Enter Dimension :"; cin>>size;
    if(size < 0)
    {
        return -1;
    }
    upperTriangle<int> *d = new upperTriangle<int>(size);
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
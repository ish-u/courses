#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;


template <typename T>
class symmetricMatrix
{
    private:
        int dimension;
        int size;
        T *S;
    public:
        symmetricMatrix(int size);
        ~symmetricMatrix();
        void display();
        void store(int i, int j);
        T retrive(int i, int j);
};

template <typename T>
symmetricMatrix<T> :: symmetricMatrix(int size)
{
    this->size = size;
    if(size > 0)
    {
        size = (size*(size+1))/2;
        S = new T[size];
        for(int i = 0; i < size; i++)
        {
            S[i] = 0;
        }
    }
    else
    {
        S = 0;
    }
}

template <typename T>
symmetricMatrix<T> :: ~symmetricMatrix()
{
    delete[] S;
}

template <typename T>
void symmetricMatrix<T> :: store(int i, int j)
{
    if(i <= size && j <=size)
    {
        T temp = 0;
        int k = 0;
        cout<<"Data : "; cin>>temp;    
        if(i >= j)
        {
            k = (i*(i-1))/2 + j;
        }
        else
        {
            k = (j*(j-1))/2 + i;
        }
        S[k-1] = temp;
    }   
    else
    {
        cout<<"Out of Bounds\n";
    }
}

template <typename T>
T symmetricMatrix<T> :: retrive(int i, int j)
{
    if(i <= size && j <=size)
    {    
        int k = 0;
        if(i >= j)
        {
            k = (i*(i-1))/2 + j;
        }
        else
        {
            k = (j*(j-1))/2 + i;
        }
        return S[k-1];
    }   
    else
    {
        cout<<"Out of Bounds\n";
    }
}

template <typename T>
void symmetricMatrix<T> :: display()
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            int k = 0;
            if(i >= j)
            {
                k = (i*(i-1))/2 + j;
            }
            else
            {
                k = (j*(j-1))/2 + i;
            }
            cout<<S[k-1]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int flag = true;
    int op = 0;
    int size;
    cout<<"Symmetric Triangular Matrix\n";
    cout<<"Enter Dimension :"; cin>>size;
    if(size < 0)
    {
        return -1;
    }
    symmetricMatrix<int> *d = new symmetricMatrix<int>(size);
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
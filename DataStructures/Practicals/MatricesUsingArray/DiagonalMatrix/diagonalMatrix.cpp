#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

template <typename T>
class diagonalMatrix
{
    private:
        int size;
        T* diagonal;
    public:
        diagonalMatrix(int size);
        ~diagonalMatrix();
        void store(int i, int j);
        T retrive(int i, int j);
        void display();
};

template <typename T>
diagonalMatrix<T> :: diagonalMatrix(int size)
{
    this->size = size;
    if(size > 0)
    {
        diagonal = new T[size];
        for(int i = 0; i < size; i++)
        {
            diagonal[i] = 0;
        }
    }
    else
    {
        diagonal = 0;
    }
}

template <typename T>
diagonalMatrix<T> :: ~diagonalMatrix()
{
    delete[] diagonal;
}

template <typename T>
void diagonalMatrix<T> :: store(int i, int j)
{
    if((i <= size) && (j <= size))
    {
        if(i == j)
        {
            T temp = 0;
            cout<<"Data : "; cin>>temp;    
            diagonal[i-1] = temp;
        }       
    }
    else
    {
        cout<<"Out of Bounds\n";
        return;
    }
}

template <typename T>
T diagonalMatrix<T> :: retrive(int i, int j)
{
    if(i <= size && j <= size)
    {
        if(i == j)
        { 
            return diagonal[i-1];
        }
    }
    return 0;
}

template <typename T>
void diagonalMatrix<T> :: display()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)
            {
                cout<<setw(3)<<diagonal[i]<<" ";
            }
            else
            {
                cout<<setw(3)<<0<<" ";
            }
        }
        cout<<"\n";
    }
}


int main()
{
    int flag = true;;
    int op = 0;
    int size;
    cout<<"Diagonal Matrix\n";
    cout<<"Enter Size :"; cin>>size;
    if(size < 0)
    {
        return -1;
    }
    diagonalMatrix<int> *d = new diagonalMatrix<int>(size);
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
        cout<<"Enter Index : "; cin>>i; cin>>j;
        switch(op)
        {
            case 1:
                d->store(i,j);
                break;
            case 2:
                cout<<d->retrive(i,j)<<"\n";
                break;
            default:
                flag = false;
                break;
        }
        getch();
        // system("CLS");
        cout<<"\n";
    }
    while(flag);
    
    return 0;

}
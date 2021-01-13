// 1. Write a program, using templates, to sort a list of n elements. Give user the option to perform sorting
// using Insertion sort, Bubble sort or Selection sort.
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

template <typename T>
class Sort
{
    private:
        int size = 10;
        T* list;
    public:
        //constructor
        Sort(int size = 10)
        {
            this->size = size;
            this->list = new T[size];
            //initailizing the list to 0 for all data types
            for(int i = 0; i < size; i++)
            {
                list[i] = 0;
            }
        }
        //member functions
        //to display the list
        void display()
        {
            for(int i = 0; i < size; i++)
            {
                cout<<list[i]<<" ";
            }
            cout<<"\n";
        }
        //to take input
        void input()
        {
            for(int i = 0; i < size; i++)
            {
                cin>>list[i];
            }
        }
        //selection sort
        void selectionSort()
        {
            for(int i = 0; i < size-1; i++)
            {
                int min = i;
                for(int j = i+1; j < size; j++)
                {
                    if(list[j] < list[min])
                    {
                        min = j;
                    }
                }
                if(min != i)
                {
                    T temp = list[i];
                    list[i] = list[min];
                    list[min] = temp;
                }
            }
        }
        //bubble sort
        void bubbleSort()
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size-i; j++)
                {
                    if (list[j] > list[j + 1])
                    {
                        T temp = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = temp;
                    }
                }
            }
        }
        //insertion sort
        void insertionSort()
        {
            for(int i = 1; i < size; i++)
            {
                int key = list[i];
                int j = i-1;
                while((j >= 0) && (key < list[j]))
                {
                    list[j+1] = list[j];
                    j--;
                }
                list[j+1] = key; 
            }
        }
        
};

int main()
{
    int s;
    int flag = 1;
    int op;
    system("CLS");
    do
    {
        cout<<setw(20)<<"SORTER\n"
            <<"1. Selection Sort\n"
            <<"2. Bubble Sort\n"
            <<"3. Insertion Sort\n"
            <<"Type Anything Else to Exit\n"
            <<"Which Sort you want to use: >"; cin>>op;
            if(op > 3)
            {
                return 0;
            }
            cout<<"Size of List : ";  cin>>s;
            Sort<int> *Sorter = new Sort<int>(s);
            cout<<"Enter List :"; Sorter->input();
        switch(op)
        {
            case 1:
                Sorter->selectionSort();
                break;
            case 2:
                Sorter->bubbleSort();
                break;
            case 3:
                Sorter->insertionSort();
                break;
            default:
                flag = 0;
                break;
        }
        Sorter->display();
        getch();
        system("CLS");
        delete Sorter;
    }
    while (flag);
    
    return 0;
}
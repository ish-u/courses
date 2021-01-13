#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
#include "heap.h"

class PriorityQueue{

    private:
        Heap* h;
    public:
        //constructor
        PriorityQueue()
        {
            h = new Heap();
        }
        //destructor
        ~PriorityQueue()
        {
            delete h;
        }
        //member function
        void display();
        void heap_increase_key(int i,int key);
        void heap_decrease_key(int i,int key);
        void max_heap_insert(int key);
        void min_heap_insert(int key);
        int heap_maximum();
        int heap_minimum();
        int heap_extract_max();
        int heap_extract_min();
};

void PriorityQueue :: display()
{
    h->display();
}

void PriorityQueue :: heap_increase_key(int i,int key)
{

    if(i < 0 || i > (h->heapsize - 1))
    {
        cout<<"Invalid Index\n";
        return;
    }
    if(key < h->heap[i])
    {
        cout<<"New Key is smaller than the Curent Key\n";
        return;
    }
    else
    {
        //setting the value of key at the i-th index of heap
        h->heap[i] = key;
        //re-establishing the Heapify Property
        while (i > 0 && (h->heap[h->parent(i)] < h->heap[i]))
        {
            //swapping the entered key with it's Parent
            int temp = h->heap[i];
            h->heap[i] = h->heap[h->parent(i)];
            h->heap[h->parent(i)] = temp;
            //setting i to the index of Parent of inserted key
            i = h->parent(i);
        }   
    }
}

void PriorityQueue :: max_heap_insert(int key)
{
    h->insert(h,key);
    h->buildMaxHeap(h);
}

int PriorityQueue :: heap_maximum()
{
    if(h->heapsize > 0)
    {
        return h->heap[0];
    }
    else
    {
        cout<<"Queue Empty\n";
    }
}

int PriorityQueue :: heap_extract_max()
{
    if(h->heapsize < 0)
    {
        cout<<"Heap Underflow\n";
    }
    else
    {
        int max = h->heap[0];
        h->heap[0] = h->heap[--(h->heapsize)];
        h->maxHeapify(h,0);
        return max;
    }
    
}

void PriorityQueue :: heap_decrease_key(int i, int key)
{
    if(i < 0 || i > (h->heapsize - 1))
    {
        cout<<"Invalid Index\n";
        return;
    }
    if(h->heap[i] < key)
    {   
        cout<<"New Key is larger than the Current Key\n";
        return;
    }
    else
    {
        //setting the value of key at the i-th index of heap
        h->heap[i] = key;
        //re-establishing the Heapify Property
        while (i > 0 && (h->heap[h->parent(i)] > h->heap[i]))
        {
            //swapping the entered key with it's Parent
            int temp = h->heap[i];
            h->heap[i] = h->heap[h->parent(i)];
            h->heap[h->parent(i)] = temp;
            //setting i to the index of Parent of inserted key
            i = h->parent(i);
        } 
    } 
}

void PriorityQueue :: min_heap_insert(int key)
{
    h->insert(h,key);
    h->buildMinHeap(h);
}

int PriorityQueue :: heap_minimum()
{
    if(h->heapsize > 0)
    {
        return h->heap[0];
    }
    else
    {
        cout<<"Queue Empty\n";
    }
}

int PriorityQueue :: heap_extract_min()
{
    if(h->heapsize < 0)
    {
        cout<<"Heap Underflow\n";
    }
    else
    {
        int min = h->heap[0];
        h->heap[0] = h->heap[--(h->heapsize)];
        h->minHeapify(h,0);
        return min;
    }
    
}

int main()
{
    int queueFlag = 1;
    cout<<"PRIORITY QUEUE\n"
        <<"1. Min Priority Queue\n"
        <<"2. Max Priority Queue\n"
        <<"What Priority Queue You Want? : "; cin>>queueFlag;
    queueFlag--;
    if(!(queueFlag == 0 || queueFlag == 1))
    {
        cout<<"Error\n";
        return -1;
    }
    int flag = 1;
    int op,temp;
    PriorityQueue *p = new PriorityQueue();
    system("CLS");
    cout<<"Indexing Start at Zero\n";
    //menu
    do
    {
        cout<<"================================================\n"
            <<"Queue - ";p->display();
        cout<<"================================================\n";
        cout<<"Operations :\n";
        if(queueFlag)
        {
            cout<<"1. Insert\n"
                <<"2. Increase Key\n"
                <<"3. Get Maximum\n"
                <<"4. Extract Maximum\n";
        }
        else
        {
            cout<<"1. Insert\n"
                <<"2. Decrease Key\n"
                <<"3. Get Minimum\n"
                <<"4. Extract Minimum\n";
        }
        cout<<"What do you want to perform : "; cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Enter Value : "; cin>>temp;
                if(queueFlag)
                {
                    p->max_heap_insert(temp); 
                }
                else
                {
                    p->min_heap_insert(temp);
                }
                break;
            case 2:
                int i;
                cout<<"Enter Index : "; cin>>i;
                cout<<"Enter Value : "; cin>>temp;
                if(queueFlag)
                {
                    p->heap_increase_key(i,temp);
                }
                else
                {
                    p->heap_decrease_key(i,temp);
                }
                break;
            case 3:
                if(queueFlag)
                {
                    cout<<p->heap_maximum();
                }
                else
                {
                    cout<<p->heap_minimum();
                }
                break;
            case 4:
                if(queueFlag)
                {
                    cout<<p->heap_extract_max();
                }
                else
                {
                    cout<<p->heap_extract_min();
                }
                break;
            default:
                flag = 0;
                break;
        }
        getch();
        system("CLS");
    } 
    while(flag);
    delete p;
    return 0;
}

class Heap
{
    public:
        int heapsize;
        int arraySize = 10;
        int *heap;
        Heap(int arraySize = 10)
        {
            heapsize = 0;
            heap = new int[arraySize];
            for(int i = 0; i < arraySize; i++)
            {
                heap[i] = 0;
            }
        }
        ~Heap()
        {
            delete[] heap;
        }
        int parent(int i){ return int((i-1)/2); }
        int left(int i){ return 2*i+1; }
        int right(int i){ return (2*i)+2; }
        void display();
        void insert(Heap* A,int a);
        void maxHeapify(Heap* A, int i);
        void minHeapify(Heap* A, int i);
        void buildMaxHeap(Heap *A);
        void buildMinHeap(Heap *A);
        void heapsort();
};

//display function
void Heap :: display()
{
    for(int i = 0; i < heapsize; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<"\n";
}

//maxheapify function
void Heap :: maxHeapify(Heap* A, int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);
    //finding the largest among Parent, Left and Right
    if(l < heapsize && A->heap[l] > A->heap[i])
    {
        largest = l;
    }
    
    if(r < heapsize && A->heap[r] > A->heap[largest])
    {
        largest = r;
    }

    //exchanging if the Parent(i) doesn't contains the largest element
    if(i != largest)
    {
        int temp = A->heap[i];
        A->heap[i] = A->heap[largest];
        A->heap[largest] = temp;
        //calling maxHeapify again with i = largest
        maxHeapify(A,largest);
    }
    
}

//minheapify function
void Heap :: minHeapify(Heap* A, int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    //finding the smallest among Parent, Left and Right
    if(l < heapsize && A->heap[l] < A->heap[i])
    {
        smallest = l;
    }
    
    if(r < heapsize && A->heap[r] < A->heap[smallest])
    {
        smallest = r;
    }

    //exchanging if the Parent(i) doesn't contains the largest element
    if(i != smallest)
    {
        int temp = A->heap[i];
        A->heap[i] = A->heap[smallest];
        A->heap[smallest] = temp;
        //calling maxHeapify again with i = largest
        minHeapify(A,smallest);
    }
    
}

//build heap
void Heap :: buildMaxHeap(Heap* A)
{
    for(int i = int((heapsize-1)/2); i >= 0; i--)
    {
        maxHeapify(A,i);
    }
}

//build heap
void Heap :: buildMinHeap(Heap* A)
{
    for(int i = int((heapsize-1)/2); i >= 0; i--)
    {
        minHeapify(A,i);
    }
}

//insert function
void Heap :: insert(Heap* A,int a)
{
    if(heapsize == arraySize)
    {
        int *temp = new int[2*arraySize];
        for(int i = 0; i < 2*arraySize; i++)
        {
            temp[i] = 0;
        }
        for(int i = 0; i < arraySize; i++)
        {
            temp[i] = heap[i];
        }
        delete heap;
        heap = temp;
        temp = 0;
    }
    heap[heapsize++] = a;
}

//heapsort
void Heap :: heapsort()
{
    buildMaxHeap(this);
    int heapsizeTemp = heapsize;
    int temp = 0;
    //lopping from last index to second index
    for(int i = (heapsize-1); i > 0; i--)
    {
        //exchanging the last and first element of the heap
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        //decreasing heapsize
        heapsize--;
        //calling heapify
        maxHeapify(this,0);
    }
    heapsize = heapsizeTemp;
    display();
    buildMaxHeap(this);
}
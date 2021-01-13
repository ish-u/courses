#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Set Class
class Set
{
    int *input_set;
    void show(int* a,int n);
    int remove_duplicate(int* a,int n);    
public:
    int total_elements;
    int *output_set;
    //default constructor
    Set()
    {
        cout << "Enter the Number of Element of the Set: ";
        cin >> total_elements;
        input_set = new int[total_elements];
        cout << "Enter the Elements of the Set: ";
        for (int i = 0; i < total_elements; i++)
        {
            cin >> input_set[i];
        }

        //removing duplicate elements from array
        total_elements = remove_duplicate(input_set,total_elements);

        //creating the set from the input_set array
        output_set = new int[total_elements];
        for (int i = 0; i < total_elements; ++i)
        {
            output_set[i] = input_set[i];
        }
    }
    //descructor
    ~Set()
    {
        delete[] input_set;
        delete[] output_set;
    }
};

//dup() function
int Set::remove_duplicate(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n;)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n-1; k++)
                {
                    a[k] = a[k + 1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    return n;
}

//Relation Class
class Relation 
{
    int *relation;
    int numberOfElements;
    public:
        Relation()
        {
            Set a;
            numberOfElements = a.total_elements;
            //creating a 2-D matrix to take input of the relation
            relation = new int[numberOfElements*numberOfElements];
            //taking input of the relation
            cout<<"\nEnter 1 if element belongs to relation and 0 if not : \n";
            for(int i = 0; i < numberOfElements; ++i)
            {
                for(int j = 0; j < numberOfElements; ++j)
                {
                    cout<<"("<<a.output_set[i]<<","<<a.output_set[j]<<"): ";
                    cin>>relation[i*a.total_elements+j];
                }
            }
            cout<<"\n";
            cout<<"Relation : \n";
            show();


        }
        ~Relation()
        {
            delete[] relation;
        }    
        void show();
        bool isReflexive();
        bool isSymmetric();
        bool isAntiSymmetric();
        bool isTransitive();
};

//show() function
void Relation::show()
{
    for(int i = 0; i < numberOfElements; ++i)
            {
                cout<<" ";
                for(int j = 0; j < numberOfElements; ++j)
                {

                    cout<<relation[i*numberOfElements+j]<<" ";
                }
                cout<<"\n";
            }
}

//isReflexive() function
bool Relation::isReflexive()
{
    int flag = 1;
    for(int i = 0; i < numberOfElements; ++i)
    {
        if(relation[(i*numberOfElements)+i] != 1)
        {
            flag = 0;
            break;
        }
    }

    if(flag && numberOfElements)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//isSymmetric() function
bool Relation::isSymmetric()
{
    int flag = 1;
    for(int i = 0; i < numberOfElements; ++i)
    {
        for(int j = 0; j < numberOfElements; ++j)
        {   
            //checking whether the relation = relation(transpose)
            if(relation[i*numberOfElements+j] != relation[j*numberOfElements+i])
            {
                flag = 0;
                break;
            }
        }
        if(!flag)
        {
            break;
        }
    }

    return flag;
}

//isAntiSymmetric() function
bool Relation::isAntiSymmetric()
{
    int flag = 1;
    for(int i = 0; i < numberOfElements; ++i)
    {
        for(int j = 0; j < numberOfElements; ++j)
        {
            if(i != j)
            {
                if (relation[i * numberOfElements + j] && relation[j * numberOfElements + i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }

    return flag;
    
}

//isTransitive() function
bool Relation::isTransitive()
{
    int* temp = new int[numberOfElements*numberOfElements];
    for(int i = 0; i < numberOfElements; ++i)
    {
        for(int j = 0; j < numberOfElements; ++j)
        {
            temp[(i*numberOfElements)+j] = 0;
        }
    }
    //https://math.stackexchange.com/questions/2164129/transitivity-of-a-relation-through-matrix
    //A Relation represented by a matrix A is transitive if A[i][j] = 0 then A^2[i][j] = 0 ;for i and j within the bounds of 2-D array

    //finding A^2
    for(int i = 0; i < numberOfElements; ++i)
    {
        for(int j = 0; j < numberOfElements; ++j)
        {
            for(int k = 0; k < numberOfElements; ++k)
            {
                temp[(i*numberOfElements)+j] += relation[(i*numberOfElements)+k]*relation[(k*numberOfElements)+j];
            }
        }
    }

    //checking whether the condition is true or not
    int flag = 1;
    for(int i = 0; i < numberOfElements; ++i)
    {
        for(int j = 0; j < numberOfElements; ++j)
        {
            if(relation[(i*numberOfElements)+j])
            {
                if(!temp[(i*numberOfElements)+j])
                {
                    flag = 0; 
                    break;
                }
            }
            else
            {
                if(temp[(i*numberOfElements)+j])
                {
                    flag = 0;
                    break;
                }
            }
            
        }
        if(!flag)
        {
            break;
        }
    }

    delete[] temp;
    return flag;
}

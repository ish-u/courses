#include <iomanip>
#include "Set.h"
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
        void isReflexive();
        void isSymmetric();
        void isAntiSymmetric();
        void isTransitive();
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
void Relation::isReflexive()
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
        cout<<"The Relation is Reflexive\n";
    }
    else
    {
        cout<<"The Relation is not Reflexive\n";
    }
}

//isSymmetric() function
void Relation::isSymmetric()
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
    if(flag)
    {
        cout<<"The Relation is Symmetric\n";
    }
    else
    {
        cout<<"The Relation is not Symmetric\n";
    }
}

//isAntiSymmetric() function
void Relation::isAntiSymmetric()
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

    if(flag)
    {
        cout<<"The Relation is Anti-Symmetric\n";
    }
    else
    {
        cout<<"The Relation is not Anti-Symmetric\n";
    }
    
}

//isTransitive() function
void Relation::isTransitive()
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

    if(flag)
    {
        cout<<"The Relation is Transitive\n";
    }
    else
    {
        cout<<"The Relation is not Transitive\n";
    }
    

    delete[] temp;
}


int main(void)
{
    int flag = 1;
    int choice;
    cout<<setw(20)<<"| RELATIONS |"<<endl;
    cout<<setfill('-')<<setw(33)<<" "<<"\n";
    Relation r;
    cout<<"\n";
    do
    {
        cout<<setfill('-')<<setw(33)<<" "<<endl;
        cout<<"Is the Relation - \n"
            <<"1. Reflexive ?\n"
            <<"2. Symmetric ?\n"
            <<"3. Anti-Symmetric ?\n"
            <<"4. Transitive ?\n"
            <<"----> Enter Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            r.isReflexive();
            break; 
        case 2:
            r.isSymmetric();
            break;
        case 3:
            r.isAntiSymmetric();
            break;
        case 4:
            r.isTransitive();
            break;
        default:
            cout<<"Exiting";
            flag = 0;
            break;
        }
        
    } while (flag);
    
    return 0; 
}
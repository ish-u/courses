#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Set
{
    int total_elements;
    int *input_set;
    int *output_set;
    int cardinality;
    int numberOfPowerSets;

public:
    //default constructor
    Set()
    {
        int temp = 0;
        cout << "Enter the Number of Element of the Set: ";
        cin >> total_elements;
        input_set = new int[total_elements];
        cout << "Enter the Elements of the Set: ";
        for (int i = 0; i < total_elements; i++)
        {
            cin >> input_set[i];
        }

        //removing duplicate elements from array
        for (int i = 0; i < total_elements; ++i)
        {
            for (int j = i+1; j < total_elements;)
            {
                if (input_set[i] == input_set[j])
                {
                    for(int k = j; k < total_elements;k++)
                    {
                        input_set[k] = input_set[k+1];
                    }
                    total_elements--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        //creating the set from the input_set array
        output_set = new int[total_elements];
        for(int i = 0; i < total_elements; ++i)
        {
            output_set[i] = input_set[i];
        }

        //cardinality of the Set
        cardinality = total_elements;

        //number of powersets of the input set
        numberOfPowerSets = pow(2,cardinality);

    }
    //memeber functions;
    bool isMemember(int b);
    void powerSet();
    void show();
    //descructor
    ~Set()
    {
        delete[] input_set;
    }
};

//isMember() function
bool Set::isMemember(int b)
{
    for (int i = 0; i < this->total_elements; i++)
    {
        if (this->input_set[i] == b)
        {
            return true;
        }
    }

    return false;
}

//powerSet() function
void Set::powerSet()
{
    cout<<"The given Set has : "<<this->numberOfPowerSets<<" subsets.\n";
    //"from geeksforgeeks"
    //we use bitwise & and left-shift operator for the problem
    //consider a set {a,b}
    //all the sets this can have can be represented as a sequence of binary digits
    /*
        00-{}
        01-{a}
        10-{b}
        11-{a,b}
        Thus, by genearting this sequence and printing the digit on the set that has a '1' we can generate
        all the sets of the Set i.e Powerset
    */

   for(int i = 0; i < this->numberOfPowerSets; ++i)
   {
       cout<<"{ ";
       for(int j = 0 ; j < this->total_elements;j++)
       {
           //condition for generating the sequence to be printed
           if(i & (1<<j))
           {
               cout<<this->output_set[j]<<" ";
           }
           
       }
       cout<<"}\n";
   }
}

//show() function
void Set::show()
{
    cout<<"The Cardinality of the Set is : "<<this->cardinality<<endl;
    cout<<"SET : ";
    for(int i = 0; i < this->total_elements; i++)
    {
        cout<<this->output_set[i]<<" ";
    }
}


int main()
{
    int flag = 1;
    int choice;
    cout<<setw(21)<<"| SET |"<<endl;
    cout<<setfill('-')<<setw(40)<<" "<<endl;
    Set a;
    cout<<setfill('-')<<setw(40)<<" "<<endl;
    a.show();
    cout<<"\n"<<setfill('-')<<setw(40)<<" "<<endl;
    do
    {
        cout<<"1. Find whether the element is member of SET\n"
            <<"2. Power Set of SET\n"
            <<"What do you want to find? : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                int z;
                cout<<"Enter the element you want to check : ";cin>>z;
                if(a.isMemember(z))
                {
                    cout<<"YES!";
                }
                else
                {
                    cout<<"NO!";
                }
                
                cout<<"\n"<<setfill('-')<<setw(40)<<" "<<endl;
                break;
            case 2:
                a.powerSet();
                cout<<setfill('-')<<setw(40)<<" "<<endl;
                break;
            default:
                flag = 0;
                cout<<"Exiting...";
                break;

        }
    }   
    while(flag);
    return 0;
}
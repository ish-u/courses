#include <iostream>
#include <cmath>
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

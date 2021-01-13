#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Set Class
class Set
{
    int total_elements;
    int *input_set;
    int *output_set;
    void show(int* a,int n);
    int remove_duplicate(int* a,int n);

public:
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
    //memeber functions;
    void show();
    void isSubset(Set &a);
    void doUnion(Set &a);
    void doIntersection(Set &a);
    void doComplement(Set &a);
    void symmDiff(Set &a);
    void setDiff(Set &a);
    void cartesianProduct(Set &a);
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

//show() function
void Set::show()
{
    for (int i = 0; i < this->total_elements; i++)
    {
        cout << this->output_set[i] << " ";
    }
}

//show(int*a)
void Set::show(int *a,int n)
{
    cout<<"{ ";
    for(int i = 0; i < n ; i++)
    {
        cout << a[i] << " ";
    }
    cout<<"}\n";
}

//isSubset() function
void Set::isSubset(Set &a)
{
    int this_set = 1;
    int a_set = 1;
    int flag;
    //checking if calling set is subset of a set 
    for(int i = 0; i < this->total_elements; ++i)
    {
        flag = 1;
        for(int j = 0; j < a.total_elements; ++j)
        {
            if(this->output_set[i] == a.output_set[j])
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            
        }
        if(flag == 0)
        {
            this_set = 0;
            break;
        }
    }
    //checking if Set a is subset of calling set 
    for(int i = 0; i < a.total_elements; ++i)
    {
        flag = 1;
        for(int j = 0; j < this->total_elements; ++j)
        {
            if(a.output_set[i] == this->output_set[j])
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            
        }
        if(flag == 0)
        {
            a_set = 0;
            break;
        }
    }
    if(this_set == 1  && a_set == 1)
    {
        cout<<"Equal Sets";
    }
    else if(this_set == 1)
    {
        cout<<"Set : ";
        this->show();
        cout<<" is the subset of ";
        cout<<"Set : ";
        a.show();
    }
    else if(a_set == 1)
    {
        cout<<"Set : ";
        a.show();
        cout<<" is the subset of ";
        cout<<"Set : ";
        this->show();
    }
    else
    {
        cout<<"Disjoint Sets";
    }
    
}

//doUnion() function
void Set::doUnion(Set &a)
{
    //creating an new array to store the union of the two set
    int union_total_elements = this->total_elements + a.total_elements;
    int* union_set = new int[union_total_elements];
    //copying elements from both the sets to the newly created array
    for(int i = 0; i < this->total_elements; ++i)
    {
        union_set[i] = this->output_set[i];
    }
    for(int i = this->total_elements; i < union_total_elements; ++i)
    {
        union_set[i] = a.output_set[i-this->total_elements];
    }
    //removing the duplicate elements
    union_total_elements = remove_duplicate(union_set,union_total_elements);
    //printing the union
    cout<<"Union : ";
    show(union_set,union_total_elements);
    //deleting the union_set array
    delete[] union_set;

}

//doIntersection() function
void Set::doIntersection(Set &a)
{
    //creating a new array for the intersection 
    int intersection_total_elements = (this->total_elements > a.total_elements) ? a.total_elements : this->total_elements;
    int* intersection_set = new int[intersection_total_elements];
    int count = 0;
    for(int i = 0; i < this->total_elements; ++i)
    {
        for(int j = 0; j < a.total_elements ; ++j)
        {
            if(this->output_set[i] == a.output_set[j])
            {
                intersection_set[count++] = this->output_set[i];
                break;
            }
        }
    }
    intersection_total_elements = count;
    //printing the intersection set
    cout<<"Intersection : ";
    show(intersection_set,intersection_total_elements);
    //deleting the intersection set array
    delete[] intersection_set;
}

//doComplement() function
void Set::doComplement(Set &a)
{
    //creating a Universal Set
    int universal_total_elements = this->total_elements + a.total_elements;
    int* universal_set = new int[universal_total_elements];
    //copying the elements in the universal set and removing duplicates
    for(int i = 0; i < this->total_elements; ++i)
    {
        universal_set[i] = this->output_set[i];
    }
    for(int i = this->total_elements; i < universal_total_elements; ++i)
    {
        universal_set[i] = a.output_set[i-this->total_elements];
    }
    universal_total_elements = remove_duplicate(universal_set,universal_total_elements);

    //creating the complement set
    int complement_total_elements = universal_total_elements - a.total_elements;
    int* complement_set = new int[complement_total_elements];
    int count = 0;
    int flag = 1;
    for(int i = 0; i < universal_total_elements; ++i)
    {
        flag = 1;
        for(int j = 0; j < this->total_elements; ++j )
        {
            if(universal_set[i] == this->output_set[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            complement_set[count++] = universal_set[i];
        }
    }
    complement_total_elements = count;
    //printitng the complement 
    cout<<"Complement : ";
    show(complement_set,complement_total_elements);
    //deleting the universal-set and complement-set array 
    delete[] universal_set;
    delete[] complement_set;

}

//setDiff() function
void Set::setDiff(Set &a)
{
    //creating a temp set
    int temp_total_elements = this->total_elements;
    int* temp_set = new int[temp_total_elements];
    int count = 0;
    int flag = 1;
    for(int i = 0; i < this->total_elements; ++i)
    {
        flag = 1;
        for(int j = 0; j < a.total_elements; ++j)
        {
            if(this->output_set[i] == a.output_set[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            temp_set[count++] = this->output_set[i];
        }
    }
    temp_total_elements = count;
    //printing the set difference
    cout<<"Set Difference : ";
    show(temp_set,temp_total_elements);
    //deleting the temporaray set array
    delete[] temp_set;
}

//symmDiff() function
void Set::symmDiff(Set &a)
{
    //we know that symmetric difference of A and B = (A Union B) - (A Intersection B)
    //finding the union set
    int union_total = this->total_elements + a.total_elements;
    int* union_set = new int[union_total];
    for(int i = 0; i < this->total_elements; ++i)
    {
        union_set[i] = this->output_set[i];
    }
    for(int i = this->total_elements; i < union_total; ++i)
    {
        union_set[i] = a.output_set[i-this->total_elements];
    }
    union_total = remove_duplicate(union_set,union_total);

    //finding the intersection set
    int intersection_total = (this->total_elements > a.total_elements) ? a.total_elements : this->total_elements;
    int* intersection_set = new int[intersection_total];
    int count = 0;
    for(int i = 0; i < this->total_elements; ++i)
    {
        for(int j = 0; j < a.total_elements ; ++j)
        {
            if(this->output_set[i] == a.output_set[j])
            {
                intersection_set[count++] = this->output_set[i];
                break;
            }
        }
    }
    intersection_total = count;

    //finding the difference : (A Union B) - (A Intersection B)
    int symm_total = union_total;
    int* symm_set = new int[symm_total];
    count = 0;
    int flag = 1;
    for(int i = 0; i < union_total; ++i)
    {
        flag = 1;
        for(int j = 0; j < intersection_total; ++j)
        {
            if(union_set[i] == intersection_set[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            symm_set[count++] = union_set[i];
        }
    }
    symm_total = count;

    //printing the symmetric set
    cout<<"Symmetric Difference : ";
    show(symm_set,symm_total);

    //deleting the union_set, intersection_set and symm_set array
    delete[] symm_set;
    delete[] intersection_set;
    delete[] union_set;
}

//cartesianProduct() function
void Set::cartesianProduct(Set &a)
{
    //Cartesian Product is all the unique pairs of elements between two sets
    int count = 1;
    cout<<"Cartesian Product : ";
    cout<<"{ ";
    for(int i = 0; i < this->total_elements; ++i)
    {
        for(int j = 0; j < a.total_elements; ++j)
        {
            cout<<"("<<this->output_set[i]<<","<<a.input_set[j]<<") ";
            if(count % 10 == 0){ cout<<endl<<"  "; }
            count++;
        }
    }
    cout<<"}\n";

}

int main(void)
{
    int flag = 1;
    int choice;
    cout<<setw(25)<<"| SET OPERATTION |"<<endl;
    cout<<setfill('-')<<setw(33)<<" "<<endl;
    cout << "* SET A * \n";
    Set a;
    cout << "\n* SET B *\n";
    Set b;
    do
    {
        cout<<setfill('-')<<setw(33)<<" "<<endl;
        cout<<"\n1. Union\n"
            <<"2. Intersection\n"
            <<"3. Complement (SET - A)\n"
            <<"4. Complement (SET - B)\n"
            <<"5. Set Difference (A-B)\n"
            <<"6. Set Difference (B-A)\n"
            <<"7. Symmetric Difference\n"
            <<"8. Cartesian Product (A*B)\n"
            <<"9. Carteian Product (B*A)\n";
        cout << "----> What Do You Want To Perform ? : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                a.doUnion(b);
                break;
            case 2:
                a.doIntersection(b);
                break;
            case 3:
                a.doComplement(b);
                break;
            case 4:
                b.doComplement(a);
                break;
            case 5:
                a.setDiff(b);
                break;
            case 6:
                b.setDiff(a);
                break;
            case 7:
                a.symmDiff(b);
                break;
            case 8:
                a.cartesianProduct(b);
                break;
            case 9:
                b.cartesianProduct(a);
                break;
            default:
            cout<<"Exiting ... ";
                flag = 0;
                break;
        }
        cout<<"\n";
    } while (flag);
    return 0;
}
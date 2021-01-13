#include "Relation.h"

int main()
{
    cout<<setw(20)<<"Checking whether the Relation is Equivalent, Partial Order Relation or None :"<<endl;
    cout<<setfill('-')<<setw(60)<<" "<<"\n";
    cout<<"Enter Relation : \n";
    Relation r;
    cout<<setfill('-')<<setw(33)<<" "<<"\n\n";
    if(r.isReflexive() && r.isSymmetric() && r.isTransitive() && !r.isAntiSymmetric())
    {
        cout<<"The Relation is a Equivalence Relation";
    }
    else if(r.isReflexive() && r.isAntiSymmetric() && r.isTransitive() && !r.isSymmetric())
    {
        cout<<"The Relation is a Partial Order Relation";
    }
    else if(r.isReflexive() && r.isSymmetric() && r.isAntiSymmetric() && r.isTransitive())
    {
        cout<<"The Relation is both a Equivalence and a Partial Order Relation";
    }
    else
    {
        cout<<"The Relation is neither a Equivalence nor a Partial Order Relation";
    }
    cout<<"\n";
    return 0;
}
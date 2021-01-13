#include <iostream>
#include <iomanip>
using namespace std;

//conjunction
bool OR(int x,int y)
{
    return (x||y);
}
//disjunction
bool AND(int x,int y)
{
    return (x&&y);
}
//negation
bool NOT(int x)
{
    return !x;
}

//NAND
bool NAND(int x, int y)
{
    return NOT(AND(x,y));
}

//NOR
bool NOR(int x, int y)
{
    return NOT(OR(x,y));
}

//exclusive OR
bool XOR(int x,int y)
{
    return OR(AND(NOT(x),y),AND(x,NOT(y)));
}

//conditional
bool implies(int x,int y)
{
    return OR(NOT(x),y);

}

//bicondiitonal
bool bicondtional(int x, int y)
{
    return AND(implies(x,y),implies(y,x));
}

//exclusive NOR
bool XNOR(int x,int y)
{
    return NOT(XOR(x,y));
}


int main()
{
    int x,y;
    cout<<"Enter the truth value of  \n";
    cout<<"x : "; cin>>x;
    cout<<"y : "; cin>>y;
    if((x > 1 || y > 1) || (x < 0 || y < 0))
    {
        cout<<"Bound";
        return -1;
    }
    cout<<"\n";
    cout<<" Truth Table :";
    cout<<"\n"<<setfill('-')<<setw(72);
    cout<<"\n"<<setfill(' ')<<setw(3)<<"x"<<setw(3)<<"y"<<setw(3)<<"!x"<<setw(3)<<"!y"<<setw(5)<<"OR"<<setw(7)<<"AND"<<setw(7)<<"NOR"<<setw(7)<<"NAND"<<setw(7)<<"XOR"<<setw(7)<<"x->y"<<setw(7)<<"x<->y"<<setw(7)<<"XNOR";
    cout<<"\n"<<setfill('-')<<setw(72)<<"\n";
    cout<<setfill(' ')<<setw(3)<<x<<setw(3)<<y<<setw(3)<<NOT(x)<<setw(3)<<NOT(y)<<setw(5)<<OR(x,y)<<setw(7)<<AND(x,y)<<setw(7)<<NOR(x,y)<<setw(7)<<NAND(x,y)<<setw(7)<<XOR(x,y)<<setw(7)<<implies(x,y)<<setw(7)<<bicondtional(x,y)<<setw(7)<<XNOR(x,y);
    cout<<"\n";
    return 0;
}
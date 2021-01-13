#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>
#include <cmath>

using namespace std;

class Box
{
    private:
        float l,b,h;
    public:
        Box(float x = 0,float y = 0, float z = 0)
        {
            l = x; b = y; h = z;
        }
        void show();
        void get();
        void volume();
        void tsarea();
        void operator =(Box &);
        void operator +(Box &);
        friend void operator ==(Box&,Box&);

};

void Box :: show()
{
    cout<<"\nThe Dimensions of the Box are: \n";
    cout<<"l :"<<l<<"\nb: "<<b<<"\nh: "<<h<<"\n";
}

void Box :: get()
{
    cout<<"\nEnter The Dimensions of The Box :\n";
    cout<<"l :"; cin>>l;
    cout<<"b: "; cin>>b;
    cout<<"h: "; cin>>h;
}

void Box :: volume()
{
    cout<<"The Volume of The Box is :"<<l*b*h<<endl;
}

void Box :: tsarea()
{
    cout<<"The Total Surface Area of The Box is :"<<2*(l*b + b*h + h*l)<<endl;
}
void Box :: operator =(Box &q)
{
    l = q.l; b = q.b; h = q.h;
}

void operator ==(Box &p, Box &q)
{
    if (p.l == q.l && p.b == q.b && p.h == q.h)
    {
        cout<<"\nTwo BOXES are EQUAL\n"<<endl;
    }
    else
    {
        cout<<"\nTwo BOXES are NOT EQUAL\n"<<endl;
    }
}

void Box :: operator +(Box &p)
{
    l = l + p.l; b = b + p.b; h = p.h;
}

int main()
{

    Box A,B;
    A.get();
    B.get();
    A.show();
    B.show();
    A.tsarea(); A.volume();
    B.tsarea(); B.volume();

    A == B;
    A = B;
    A.tsarea(); A.volume();
    B.tsarea(); B.volume();

    A + B;

    A.tsarea(); A.volume();
    B.tsarea(); B.volume();
    return 0;
}

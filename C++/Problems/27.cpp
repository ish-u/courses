
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box()
        {
            l = 0; b = 0; h = 0;
        }
        Box(int x, int y, int z)
        {
            l = x; b = y; h = z;
        }
        void total_surface_area();
        void volume();
        void input();
        Box operator ++();
        //Box operator ++(int x);
        Box operator --();
        //Box operator --(int x);
        void operator ==(Box &a);
        void operator =(Box &a);
};

void Box :: total_surface_area()
{
    cout<<"The Surface area of the box is : "<<2*((l*b)+(b*h)+(h*l))<<endl;
}

void Box :: volume()
{
    cout<<"The volume of the box is : "<<(l*b*h)<<endl;
}

Box Box:: operator ++()
{
    l++; b++; h++;
    return *this ;
}
//Box operator ++(int x);
Box Box :: operator --()
{
    l--; h--; b--;
    return *this;
}
//Box operator --(int x);

void Box :: operator ==(Box &a)
{
        if ((a.l == l) && (a.b ==  b) && (a.h == h))
            cout<<"Two Boxes are Equal"<<endl;
        else
            cout<<"Boxes are Unequal"<<endl;
}

void Box :: operator =(Box &a)
{
    l = a.l; b = a.b; h = a.h;
}
void Box :: input()
{
    cout<<"l :"; cin>>l;
    cout<<"b :"; cin>>b;
    cout<<"h :"; cin>>h;
}



int main(){

    Box A;
    Box B(1,1,1);
    Box C;
    C.input();

    A.total_surface_area();
    C.volume();
    C == B;


}


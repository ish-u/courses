#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cmath>


using namespace std;

class Triangle
{
    float a,b,c,s;
    float area;
public:
    Triangle(float x = 0, float y = 0, float z = 0)
    {
        a = x; b = y; c = z;
        s = (a+b+c)/2;
        area = 0;
    }
    void cal_area();
    void cal_area(float p, float q);
    void operator=(Triangle &z);
    friend void operator==(Triangle &x ,Triangle &y);

};

void Triangle::cal_area()
{
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"\nArea :"<<area;
}

void Triangle::cal_area(float p, float q)
{
    cout<<"\nOverloaded Function:";
    cout<<"\nArea :"<<0.5*p*q;
}

void Triangle :: operator=(Triangle &z)
{
    a = z.a;
    b = z.b;
    c = z.c;
    s = z.s;
}
void operator==(Triangle &x, Triangle &y)
{
    if(x.a == y.a  && x.b == y.b && x.c == y.c)
    {
        cout<<"\nThe Triangles are equal\n";
    }
    else{
        cout<<"\nThe Triangles are not equal\n";
    }
}

int main(int argc, char *argv[])
{
    Triangle A(4,13,15);
    A.cal_area();
    A.cal_area(5,10);
    Triangle B(5,14,16);
    B.cal_area();
    A == B;
    A = B;
    A.cal_area();
    B.cal_area();

}




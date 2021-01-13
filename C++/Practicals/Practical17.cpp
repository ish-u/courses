#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>
#include <cmath>

using namespace std;

class Triangle
{
    private:
        int a,b,c;
        int s;
    public:
        Triangle()
        {
            a = b = c = s = 0;
        }
        Triangle(int x, int y, int z)
        {
            a = x; b = y; c = z;
            s = a + b + c;
            s = s/2;
        }

        void show();
        void read();
        void area();
        void area(float x, float y);
        void operator =(Triangle &);
        void operator ==(Triangle &);
};

void Triangle :: show()
{
    cout<<"a: "<<a<<"\nb: "<<b<<"\nc: "<<c<<"\ns: "<<s<<endl;
}

void Triangle :: read()
{
    cout<<"a :"; cin>>a;
    cout<<"b :"; cin>>b;
    cout<<"c :"; cin>>c;
}

void Triangle :: area()
{
    int z = s*(s-a)*(s-b)*(s-c);
    z = sqrt(z);
    cout<<"Area of Triangle is :"<<z<<endl;

}

void Triangle :: area(float x, float y)
{
    cout<<"OVERLOADED\n";
    cout<<"The Area of triangle is :"<< 0.5*x*y<<endl;
}


void Triangle :: operator ==(Triangle &t)
{
    if (a == t.a && b == t.b && c == t.c)
    {
        cout<<"The two Triangles are EQUAL";
    }
    else
    {
        cout<<"The two Triangles are NOT EQUAL\n";
    }
}

void Triangle :: operator =(Triangle &t)
{
    a = t.a; b = t.b; c = t.c;
    s = t.a + t.b + t.c;
    s = s/2;
}
int main()
{
    Triangle A(12,17,25);
    A.show(); cout<<endl;
    A.area();
    Triangle B;
    B.show(); cout<<endl;
    A == B;
    B = A;
    B.show(); cout<<endl;
    B.area();

    return 0;
}

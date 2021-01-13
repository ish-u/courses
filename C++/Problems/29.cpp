
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Complex_Numbers
{
private:
    double img;
    double real;
public:
    Complex_Numbers()
    {
        img = 0;
        real = 0;
    }
    Complex_Numbers(double x, double y)
    {
        img = y;
        real = x;
    }

    Complex_Numbers operator *(Complex_Numbers &a);
    void show();
};

Complex_Numbers Complex_Numbers :: operator *(Complex_Numbers &a)
{
    Complex_Numbers x;
    x.real = (real*a.real) - (img*a.img);
    x.img = (real*a.img) + (img*a.real);
    return x;

}

void Complex_Numbers :: show()
{
    cout<<real<<" + i"<<img<<endl;
}

int main(){

    Complex_Numbers A(5,6);
    Complex_Numbers B(1,1);
    Complex_Numbers C;
    C = A*B;
    C.show();



}


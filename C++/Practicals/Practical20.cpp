#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

using namespace std;


class Length
{
        float feet;
        float inch;
    public:
        Length(float x = 0,float y = 0)
        {
            feet = x;
            inch = y;
            while(inch >=12)
            {
                inch = inch - 12;
                feet++;
            }
        }
        void put();
        void show();
        Length operator +(Length &a);
        Length operator -(Length &a);

};

void Length :: put()
{
    cout<<"Enter the Length in inches:"; cin>>inch;
    feet = 0;
    while(inch >= 12)
    {
        inch = inch - 12;
        feet++;
    }
}

void Length :: show()
{
    cout<<"The Object is:"<<fabs(feet)<<"\'"<<fabs(inch)<<endl;
}

Length Length :: operator +(Length &a)
{
    feet += a.feet;
    inch += a.inch;
    while(inch >= 12)
    {
        inch = inch - 12;
        feet++;
    }
    return *this;
}

Length Length :: operator -(Length &a)
{
    feet -= a.feet;
    inch -= a.inch;
    while(inch >=12)
    {
        inch = inch - 12;
        feet++;
    }
    return *this;

}

int main()
{
    Length A,B, C;

    A.put();
    A.show();

    cout<<"\n";

    B.put();
    B.show();

    cout<<"\n";

    cout<<"Performing C = A + B"<<endl;
    C = A+B;
    C.show();

    cout<<"\n";

    cout<<"Performing C = A - B"<<endl;
    Length D(6,3),E(7,3);
    C = D-E;
    C.show();


    return 0;


}


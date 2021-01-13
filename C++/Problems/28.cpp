
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

class Figure
{
private:
    int side_1;
    int side_2;
public:
    Figure()
    {
        side_1 = 0;
        side_2 = 0;
    }
    
    Figure(int x, int y)
    {
        side_1 = x;
        side_2 = y;
    }
    
    void area(int x, int y);
    void  area(int x);
    
};

void Figure :: area(int x, int y)
{
    cout<<"Area of the rectangle is :"<<(side_1*side_2)<<endl;
}
void Figure :: area(int x)
{
    cout<<"The area of the circle is :"<<(2*3.14*x)<<endl;
}

int main(){



}


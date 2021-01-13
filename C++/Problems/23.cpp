#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;

struct Point
{
	int point_x;
	int point_y;
};


int main(){
	Point p1,p2,p3;
	cout<<"Enter the Point 1 co-ordinates ";
	cout<<"x:";
	cin>>p1.point_x;
	cout<<"y:";
	cin>>p1.point_y;

	cout<<endl;

	cout<<"Enter the Point 2 co-ordinates ";
	cout<<"x:";
	cin>>p2.point_x;
	cout<<"y:";
	cin>>p2.point_y;

	p3.point_x = p1.point_x + p2.point_x;
	p3.point_y = p1.point_y + p2.point_y;

	cout<<"Co-ordinates of Point 3 ";
	cout<<"x:"<<p3.point_x<<" "<<"y:"<<p3.point_y<<endl;


	return 0;
}


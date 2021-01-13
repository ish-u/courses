

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main(){
    
    int func,radius,length,width,side,a,b,c,s;
    cout<<"Enter The Function you want to perform from the following choices :"<<"\n"<<"1 - Area Of Circle "<<endl;
    cout<<"2 - Arera of Square"<<"\n"<<"3 - Area of Triangle"<<"\n"<<"4 - Area Of Rectangle"<<endl;
    cout<<"ENTER "<<setw(5)<<": ";
    cin>>func;
    
    switch(func){
        
        case 1:  //area of circle
            cout<<"Enter The Radius of Circle :";
            cin>>radius;
            cout<<"The area Of the Circle is :"<<(3.14*radius*radius);
            break;
        case 2:  //area of square
            cout<<"Enter The Side Of Square :";
            cin>>side;
            cout<<"The area of Square is : "<<side*side;
            break;
        case 3: //area of trangele
            cout<<"Enter The Sides of Triangle a,b,c"<<"\n";
            cin>>a>>b>>c;
            s = (a+b+c)/2;
            cout<<"The area of Triangle is :"<<sqrt(s*(s-a)*(s-b)*(s-c));
            break;
        case 4: //area of rectangle;
            cout<<"Enter the sides of Rectangle :"<<"\n"<<"Length :";
            cin>>length;
            cout<<"Width  :";
            cin>>width;
            cout<<"The area of the Rectangle :"<<(length*width);
            break;
        default:
            cout<<"Please Enter A Valid Function";
            
        
    }
	


}

#include <iostream>
#include <math.h>

using namespace std;


int main(){
	
    float a,b,c,delta,root1,root2;
    cout<<"Enter the a,b,c of :"<<endl<<" ax^2 +bx +c"<<endl;
    cin>>a>>b>>c;
    if(a == 0){
        cout<<"There must be a mistake as this is not a quadratic eq^n";
    }
    else{
        
        delta = (b*b) - (4*a*c);
        
        if(delta > 0){
            root1 = (-b + sqrt(delta))/(2*a);
            root2 = (-b - sqrt(delta))/(2*a);
            cout<<"Roots of the equation "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
            cout<<"Root 1 : "<<root1<<"\n"<<"Root 2 : "<<root2;
            
        }
        else if(delta == 0){
            root1 = (-b)/(2*a);
            cout<<"The Equation "<<a<<"x^2 + "<<b<<"x + "<<c<<" Has same roots :"<<endl;
            cout<<root1;
        }
        else{
            
            cout<<"The Roots are Imaginary and Complex"<<endl;
        }
        
        return 0;
        
    }
	
}
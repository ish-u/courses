//need improvement, alot!
//the program also considers the numbers that are not perfect square, this indeed is a problem as numbers
//with decimal points are not prime 


#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    float num,sQrt,counter = 0;
    bool prime ;
    
    cin>>num;
    sQrt = sqrt(num);
   
    

    for(int i = 2; i < sQrt;++i){
        if(sQrt%i == 0){
            counter++;
        }
        
    }
    
    if(counter>0){
        cout<<"The Square Root of "<<num<<" is "<<sQrt<<"and is ";
        cout<<"Not Prime Number";
    }else{
        cout<<"The Square Root of "<<num<<" is "<<sQrt<<"and is ";
        cout<<"Prime";
    }
    
    
    
    
}

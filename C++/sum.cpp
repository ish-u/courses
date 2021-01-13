#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int sumEven,sumOdd,sumNeg,num;
    sumNeg = sumEven = sumOdd = 0;
    
    do{
        cin>>num;
        if(num > 0 && num % 2 == 0){
            sumEven = sumEven+num;
        }
        else if(num < 0){
            sumNeg = sumNeg + num;
        }
        else{
            sumOdd = sumOdd + num;
        }
        
        
    }while(num != 0);
    
    cout<<"Even "<<sumEven<<endl;
    cout<<"Odd "<<sumOdd<<endl;
    cout<<"Negative "<<sumNeg<<endl;
    
    



}
//I forgot that c++ doesn't have string as a DataType
//This program doesn't work 
//this will be updated as soon as understand how to do what i am not able to do xD ...

#include <iostream>

using namespace std;

int main()
{


    int i,ones,tens;
    char y[],z[];
    cout<<"Enter The Number : ";
    cin>>i;
    
    ones = i%10;
    tens = i/10;
    cout<<ones;
    
    switch(ones){
        case 1:
            y = "one";
            break;
        case 2:
            y = "two";
            break;
        case 3:
            y = "three";
            break;
        case 4:
            y = "four";
            break;
        case 5:
            y = "five";
            break;
        case 6:
            y = "six";
            break;
        case 7:
            y = "seven";
            break;
        case 9 :
            y = "nine";
            break;
        case 8 :
            y = "eight";
            
        
            
            
    }
    switch(tens){
        case 2:
            z = "twenty";
            break;
        case 3:
            z = "thirty";
            break;
        case 4:
            z = "forty";
            break;
        case 5:
            z = "fifty";
            break;
        case 6:
            z = "sixty";
            break;
        case 7:
            z = "seventy";
            break;
        case 9 :
            z = "ninty";
            break;
        case 8 :
            z = "eighty";
            
        
            
            
    }
    
    if(tens == 1 ){
        switch(y){
            case 1:
                cout<<"Eleven";
                break;
            case 2:
                cout<<"Twelve";
                break;
            case 3:
                cout<<"Thirteen";
                break;
            case 4:
                cout<<"Fourteen";
                break;
            case 5:
                cout<<"Fifteen";
                break;
            case 6:
                cout<<"Sixteen";
                break;
            case 7:
                cout<<"Seventeen";
                break;
            case 8:
                cout<<"Eighteen";
                break;
            case 9:
                cout<<"Ninteen;"
                break;
            
                
            
        }
    }
    else if(tens == 2 && ones == 0){
        cout<<"twenty";
    }
    else{
        cout<<z<<" "<<y;
    }
    
    
 
}

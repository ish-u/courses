

//This can be improved.

#include <iostream>

using namespace std;

int main()
{
    int a,b,c,max,min,mid;
    cout<<"Enter The 3 Numbers"<<endl;
    cout<<"A : ";
    cin>>a;
    cout<<"B : ";
    cin>>b;
    cout<<"C : ";
    cin>>c;
    
    max = a;
    min = a;
    mid = a;
    if(max<b){
        max = b;
    }
    if(max>a && max<c){
        max = c;
    }
    if(min>b){
        min = b;
    }
    if(min<a && min>c){
        min = c;
    }
    if(max == a && min == b){
        mid = c;
    }
    else if(max == a && min == c ){
        mid = b;
    }
    else if(max == b && min == a){
        mid = c;
    }
    else if(max == c && min == a){
        mid = b;
    }
    else{
        mid = a;
    }
    
    
    cout<<max<<"\n";
    cout<<mid<<"\n";
    cout<<min<<"\n";
    
    cout<<max<<","<<mid<<","<<min<<".";
    

}
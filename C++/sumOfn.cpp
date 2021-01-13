

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main(){
    
   int n,sum,i;
   sum = 0;
   cout<<"ENTER THE NUMBER :";
   cin>>n;
   
   for(i = 1 ; i <= n;i++){
       sum = sum + (i*i);
       
   }
   cout<<"The sum of first "<<n<<" natural numbers is: "<<endl;
   cout<<sum;
   
	


}
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
   char ch1;
   int ch,l,b,peri,area,diagonal;
   cout<<"\nRetangle Menu";
   cout<<"\n1- Area";
   cout<<"\n2- Perimeter";
   cout<<"\n3- Diagonal";
   cout<<"\n4- EXIT!!!"<<endl;
   
   do{
       cin>>ch;
       if(ch == 1 || ch==2 || ch==3){
           cout<<"Enter The Length Of The Rectangle  ";
           cin>>l;
           cout<<"Enter The Width Of The Rectangle  ";
           cin>>b;
           
       }
       
       switch(ch){
           
           case 1:
            area = l*b;
            cout<<"The Area oF The Recatangle is : "<<area<<endl;
            break;
           case 2:
            peri = 2*(l+b);
            cout<<"The Perimeter Of The Rectangle is  : "<<peri<<endl;
            break;
           case 3:
            diagonal = sqrt((l*l)+(b*b));
            cout<<"The Diagonals Of The Rectangle is : "<<diagonal<<endl;
            break;
           case 4:
            cout<<"Exitting";
            exit(0);
           default:
            cout<<"Please Enter A Valid Choice"<<endl;
            break;
            
        }
        cout<<"Anything you wanna do again!"<<"\n"<<"Enter Y to Perform  ";
        cin>>ch1;
        if(ch1 == 'y' || ch1 == 'Y'){
            cout<<"Enter The Choices Again  ";
        }
        else{
            exit(0);
        }
        
   } while(ch1 == 'y' || ch1 == 'Y');
   return 0;
   
  


}

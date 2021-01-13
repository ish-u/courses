
#include <iostream>

using namespace std;

int main()
{
    int sales;
    cout<<"Enter the amount of sales done by the Salesman"<<"\n";
    cin>>sales;
    
    if(sales >= 30001){
        cout<<"The Commmission earned is :"<<0.15*sales<<"\n";
    }
    else{
        if(sales <=30000 && sales >= 22001){
            cout<<"The Commission earned is  :"<<0.1*sales<<"\n";
        }
        else{
            if(sales <= 22000 && sales >= 12001){
                cout<<"The Commission earned is  :"<<0.07*sales<<"\n";
            }
            else{
                if(sales <= 12000 && sales >= 5001){
                    cout<<"The Commission earned is :"<<0.03*sales<<"\n";
                }
                else{
                    if(sales <= 5000 && sales >= 0){
                        cout<<"The Commission earned is :"<<0*sales<<"\n";
                    }
                }
            }
            
        }
    }

}

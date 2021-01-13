#include <iostream>

using namespace std;

int main()
{

    int n;
    cin>>n;



    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }


    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 2*n; j>= i; j--){
            cout<<"*";
        }
        cout<<"\n";
    }

}






/*
int nAverage(){


  int n,k = 0;
  float l = 0;
  cout<<"Enter The Number you want to input: ";
  cin>>n;

  for(int i = 1; i<=n ; ++i){
        cin>>k;
        l = l + k;




  }     cout<<"The average of all the number entered is : ";
        cout<<l/n;


}

int large(){

    int large,n,k1,k2 = 0;
    cin>>n;
    for(int i = 0; i <= n; ++i){
        cin>>k1;
        if(k1>k2){
            large = k1;
            k2 = k1;

        }else{
            k2 = k1;
        }

    }

        cout<<large;

}


int pattern1(){
    int n;
    cout<<"Enter The Number Of Lines You Want: ";
    cin>>n;

    for(int i = 1; n != 0; ++i){

        for(int j = 1; j <= n; ++j ){

                cout<<j;

        }
        n--;
    cout<<"\n";
    }


}

int bars(){
    int n;
    cout<<"Enter The Number Of rows you wnat";
    cin>>n;

    cout<<"=========="<<endl;

    for(int i=0;i<=n;i++){

        cout<<"*"<<"        "<<"*"<<endl;

    }


    cout<<"==========";

}
int pattern23(){
    int n;
    cin>>n;

    char a;
    cout<<"Pattern A or Pattern B: ";
    cin>>a;
    if(a == 'A' || a == 'a'){
    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}   else if(a == 'B' || a == 'b'){

    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 2*n; j>= i; j--){
            cout<<"*";
        }
        cout<<"\n";
    }

}

}


int patter4()
{

    int n;
    cin>>n;



    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }


    for(int i = 0; i<=2*n;i=i+2){
        for(int j = 2*n; j>= i; j--){
            cout<<"*";
        }
        cout<<"\n";
    }

}
*/

#include <iostream>

using namespace std;

int main()
{

    int n;
    cout<<"Enter a Digit  : ";
    cin>>n;

    if(n >= 0 && n <= 9)
    {
        switch(n){

        case 0 :
            cout<<"ZERO";
            break;
        case 1:
            cout<<"ONE";
            break;
        case 2:
            cout<<"TWO";
            break;
        case 3:
            cout<<"THREE";
            break;
        case 4:
            cout<<"FOUR";
            break;
        case 5:
            cout<<"FIVE";
            break;
        case 6:
            cout<<"SIX";
            break;
        case 7:
            cout<<"SEVEN";
            break;
        case 8:
            cout<<"EIGHT";
            break;
        case 9:
            cout<<"NINE";
            break;


        }

        }
        else{
            cout<<"Please Enter A Digit b/w (0-9)"<<endl;

            }


}

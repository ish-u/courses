#include <iostream>

using namespace std;

int main()
{

    // TO PRINT THE FOLLOWING PATTERN :
    /*
        A
        A B
        A B C
        A B C D
        A B C D E F
        A B C D E F G

    */
    int n;
	cout<<"Enter The number of rows you want (don't exceed 26 !) :";
    cin>>n;
    char z = 'A';
    while( n < 26){
         for(int i = 0; i <  n; ++i )
         {

             for (int j = 0; j <= i ; ++j)
             {
                 cout<<(char)((int)z +j)<<" ";
             }
             cout<<endl;
             z = 'A';
         }
         break;
    }
    if(n >= 26)
    {

        cout<<"Please enter a number in the specified range next time."<<endl;
    }

    }



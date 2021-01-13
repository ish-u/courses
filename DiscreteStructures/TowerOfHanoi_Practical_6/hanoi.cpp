#include <iostream>
#include <iomanip>
using namespace std;

//| Tower Of Hanoi |
//--->The Problem is to move 'n' number of discs from a tower A(source) to tower C(Destination) using 
//a tower C(Spare) 
//--->The Disc are placed in ascending order in the tower A and named in descending order(n,n-1,...,1)
//--->A Larger Disc can't be placed over a Smaller Disc

//For 1 Disc :
//-Move Disc1 From A to C

//For 2 Disc
//-Move Disc2 from A to B using C
//-Move Disc1 From A to C 
//-Move Disc2 from B to C using A 

//This problem can be solved recursively 
//For 3 Disc
//-Move 2 Discs from A to B using C
//-Move Disc1 from A to C
//-Move 2 Discs from B to C using A

//For n Disc
//-Move n-1 Discs from A to B using C
//-Move 1 Disc From A to C
//-Move n-1 Discs from B to C using A

//ref - https://www.youtube.com/watch?v=q6RicK1FCUs&t=487s
//ref - https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

//hanoi function
void hanoi(int n,char a, char b, char c)
{
    if(n > 0)
    {
        hanoi(n-1,a,c,b);
        cout<<"\nMove a Disc "<<n<<" from "<<a<<" to "<<c;
        hanoi(n-1,b,a,c);
    }
}


int main(void)
{
    cout<<"| TOWER OF HANOI |\n";
    int n;
    cout<<"How Many Disc does your Tower have ? : ";
    cin>>n;
    cout<<"These are the steps you have to follow : - \n";
    cout<<setfill('-')<<setw(40)<<" ";
    hanoi(n,'A','B','C');
    cout<<"\n"<<setfill('-')<<setw(40)<<" ";
    return 0;
}
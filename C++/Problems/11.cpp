//CALCULATE THE GRADES OF 3 STUDENTS FROM 3 SUBJECTS

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int avg(int arr[]);
int display(int avg);

int main()
{
    int avg1, avg2, avg3;
    int marks[3];

    cout<<"Enter the Marks of Student 1 :"<<endl;
    avg1 = avg(marks);
    cout<<endl;
    cout<<"Enter the Marks of Student 2 :"<<endl;
    avg2 = avg(marks);
    cout<<endl;
    cout<<"Enter the Marks of Student 3 :"<<endl;
    avg3 = avg(marks);
    cout<<endl;

    cout<<"Student 1 :";
    display(avg1);
    cout<<"Student 2 :";
    display(avg2);
    cout<<"Student 3 :";
    display(avg3);

    return 0;
}

int avg(int arr[])
{
    int avg = 0;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Subject "<<(i+1)<<" : ";
        cin>>arr[i];
        if (arr[i] > 100)
        {
            cout<<"Invalid Marks";
            exit(1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        avg += arr[i];
    }
    avg = avg/3;

    return avg;
}

int display(int avg)
{
    avg = avg/10;
    switch(avg)
    {
    case 9:
        cout<<"Grade A."<<endl;
        break;
    case 8:
        cout<<"Grade B."<<endl;
        break;
    case 7:
        cout<<"Grade C."<<endl;
        break;
    case 6:
        cout<<"Grade D."<<endl;
        break;
    case 5:
        cout<<"Grade E."<<endl;
        break;
    default:
        cout<<"Grade F."<<endl;
    }
}

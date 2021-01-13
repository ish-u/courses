#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>


using namespace std;
class Student
{
    static int num;
    int roll;
    char name[256];
    int year;
    int total_marks;
public:
    Student()
    {
        num++;
        cout<<"Constructor of "<<num<<"\n";
    }
    void get();
    void put();
};

void Student::get()
{
    cout<<"\n Enter the Details of Student: \n";
    cout<<"Enter Name :"; cin>>name;
    cout<<"Enter Roll Number :"; cin>>roll;
    cout<<"Enter the Marks :"; cin>>total_marks;
    cout<<"Enter the Year :"; cin>>year;
}

void Student::put()
{
    cout<<"\n";
    cout<<"\nName :"<<name;
    cout<<"\nRoll  Number :"<<roll;
    cout<<"\nMarks :"<<total_marks;
    cout<<"\nYear  :"<<year;
}

int Student::num = 0;

int main(int argc, char *argv[])
{
    cout<<"\nCREATING 5 STUDENT OBJECTS WRITING AND READING FROM THE FILE \'data.txt\' \n";

    //cretaing a array of 5 Student objects.
    Student students[2];
    //creating a file object
    fstream fdata("data.txt", ios::in | ios::out);
    //loop to take input of 5 students and writing them on the specified file
    for (int i = 0; i < 2; i++)
    {
        students[i].get();
        fdata.write((char*)&students[i],sizeof(students[i]));
    }
    //moving the file pointer to starting
    fdata.seekg(0);

    //reading from the file
    cout<<"\nThe Students from the data.txt file are:";
    for (int i = 0; i < 2; i++)
    {
        fdata.read((char*)&students[i],sizeof(students[i]));
        students[i].put();

    }

    return 0;
}




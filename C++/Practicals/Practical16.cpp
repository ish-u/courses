#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string>

using namespace std;


class Person
{
        char name[10];
        int age;
    public:
        virtual void show()
        {
            cout<<"\nName :"<<name<<endl;
            cout<<"Age :"<<age<<endl;
        }
        virtual void put()
        {
            cout<<"ENTER NAME : "; cin>>name;
            cout<<"ENTER AGE : "; cin>>age;
        }

        virtual ~Person()
        {
            cout<<"DESTRUCTOR PERSON"<<endl;
        }

};

class Professor : public Person
{
        char subjectName[10];
        int joined;
    public:
        void show()
        {
            cout<<"\nPROFESSOR :";
            Person::show();
            cout<<"Subject Name :"<<subjectName<<endl;
            cout<<"Year Joined :"<<joined<<endl;

        }

        void put()
        {
            cout<<"Enter Professor's Details"<<endl;
            Person::put();
            cout<<"Enter subject teaching :"; cin>>subjectName;
            cout<<"Years Joined :"; cin>>joined;
        }

        ~Professor()
        {
            cout<<"\nDESTRUCTOR PROFESSOR"<<endl;
        }


};

class Student : public Person
{
        int standard;
        int marks;
    public:
        void show()
        {
            cout<<"\nSTUDENT: ";
            Person::show();
            cout<<"Class : "<<standard<<endl;
            cout<<"Marks obtained last year: "<<marks<<" %"<<endl;
        }

        void put()
        {
            cout<<"Enter Student's Details"<<endl;
            Person::put();
            cout<<"Enter Class : "; cin>>standard;
            cout<<"Enter Marks obtained last year: "; cin>>marks;
        }

        ~Student()
        {
            cout<<"\nDESTRUCTOR STUDENT"<<endl;
        }

};

int main()
{
    Person *b;

    b = new Student();
    b->put();
    b->show();
    delete b;

    cout<<"\n\n";
    b = new Professor();
    b->put();
    b->show();
    delete b;
    return 0;


}


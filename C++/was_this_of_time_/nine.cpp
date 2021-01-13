#include <iostream>
#include <stdlib.h>
#include <cstring>


using namespace std;
class Person
{
    char name[256];
public:
    Person(){cout<<"Constructing Person\n";}
    virtual void get()
    {
        cout<<"\nEnter Name:";
        cin>>name;
    }
    virtual void display()
    {
        cout<<"Name:"<<name;
    }
    virtual ~Person(){cout<<"Destructing Person\n";}

};

class Student : public Person
{
    char course[10];
    int marks;
    int year;
public:
    Student(){cout<<"Constructing Student\n";}
    void get()
    {
        Person::get();
        cout<<"Enter the Course :"; cin>>course;
        cout<<"Enter the marks obtained last year:"; cin>>marks;
        cout<<"Enter the year of enrollment:"; cin>>year;
    }
    void display()
    {
        cout<<":Student:\n";
        Person::display();
        cout<<"\nCourse :"<<course;
        cout<<"\nMarks :"<<marks;
        cout<<"\nYear of Enrollment :"<<year<<"\n";
    }

    ~Student(){cout<<"Destructing Student\n";}
};

class Emp: public Person
{
    int sal;
    char department[64];
public:
    Emp(){cout<<"Constructing Employee\n";}
    void get()
    {
        Person::get();
        cout<<"Enter the Department: "; cin>>department;
        cout<<"Enter the Salary / pm: "; cin>>sal;

    }
    void display()
    {
        cout<<".Employee.\n";
        Person::display();
        cout<<"Department: "<<department;
        cout<<"\nSalary :"<<sal;
    }
    ~Emp(){cout<<"\nDestructing Employee\n";}
};

int main(int argc, char *argv[])
{
    Person *p;

    p =new Student();
    p->get();
    p->display();
    delete p;

    p = new Emp();
    p->get();
    p->display();
    delete p;

}




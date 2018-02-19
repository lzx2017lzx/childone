#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Person
{
public:
    Person(int a)
    {
        this->a=a;
    }

    Person & getSelf()
    {
        return *this;
    }

public:
    int a;
};

void test01()
{
    Person person(10);
    Person &p2=person.getSelf();

    cout<<(int)&person<<endl;
    cout<<(int)&p2<<endl;

    cout<<person.a<<endl;
}

class Student
{
public:
    Student()
    {
        mA=0;
    }

    void func()const
    {
        mC=100;
    }

public:
    int mA;
    int mB;
    mutable int mC;
};

void test02()
{
    const Student student;
    student.func();

    student.mA;
    student.mC=100;
}

class Teacher
{
public:
    void func()
    {
        if(NULL==this)
        {
            return;
        }

        cout<<"hello world"<<this->mA<<endl;
    }

public:
    int mA;
};

void test03()
{
    Teacher *teacher=NULL;
    teacher->func();

    cout<<sizeof(Teacher)<<endl;
    Teacher t[10];
}

int main()
{
    Teacher *t1=new Teacher();
   // test01();
  //  test02();
  //  test03();
//    string *ps=new string(10);
    return 0;
}

#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class Person
{
public:
    Person()
    {
        cout<<"Person 构造函数!"<<endl;

    }

    void init()
    {
        cout<<"初始化函数!"<<endl;
    }

    void clear()
    {
        cout<<"清理函数!"<<endl;
    }

    ~Person()
    {
        cout<<"Person 析构函数!"<<endl;
    }

public:
    char buf[1024*1024*10];

};

void test01()
{
    Person *person=(Person *)malloc(sizeof(Person));
    if(NULL==person)
    {
        return;
    }

    person->init();

    person->clear();
    free(person);
}

void my_new_handler()
{
    cout<<"内存申请失败!"<<endl;
}


void test02()
{
    set_new_handler(&my_new_handler);

    while(true)
     {
    Person *person=new Person;
    }
   // delete person;
}

class Teacher
{
public:
    Teacher()
    {
        pName="hello world";
    }

    ~Teacher()
    {

    }
public:
    string pName;
};


void test03()
{
   // Teacher *teacher=(Teacher *)malloc(sizeof(Teacher));
    Teacher *teacher=new Teacher;
    teacher->pName="aaa";

    delete teacher;
}

void test04()
{
    char *p1=new char[10];
    double *p2=new double[10];

    delete[] p1;
    delete[] p2;
}

class Student
{
public:
    Student()
    {
        cout<<"构造函数!"<<endl;
    }

    Student(int a)
    {
        cout<<"构造函数!"<<endl;
    }

    ~Student()
    {
        cout<<"析构函数!"<<endl;
    }
};

void test05()
{
    //聚合初始化
    //Student *stus=new Student[2]{Student(10),Student(10)};
    Student *stus=new Student[2];

    Student stu(100);
    stus[0]=stu;

    delete[] stus;
}

void test06()
{
    void *p=new Student;
    delete (Student *)p;
}
class Person1{
public:
    Person1(char* name, int age){
        pName = (char*)malloc(strlen(name)+1);
        cout<<"sizeof(name)"<<sizeof(name)<<endl;
        strcpy(pName,name);
        mAge = age;
    }
    ~Person1(){
        if (pName != NULL){
            delete pName;
        }
    }
public:
    char* pName;
    int mAge;
};

void test(){
    Person1 * person =new Person1("john000ppppppppppppppppppppppppppp",20);
    cout<<person->pName<<endl;
    delete person;
}
int main01(void)
{
    //test02();
    //test03();
    //test04();
    //test05();
    test();
    test06();
    printf("Hello World!\n");
    return 0;
}
class Personx
{
public:
    static int getCount()
    {
       // mA=100;
        return mCount;
    }

    void show()
    {
        mA=100;
        sB=200;
    }

public:
    int mA;
    static int sB;
private:
    static int mCount;
};

int Personx::sB=100;
int Personx::mCount=0;

void test01x()
{
    Personx p1;
    Personx p2;
    p1.mA=100;
    p2.mA=200;

    cout<<"p1.mA:"<<p1.mA<<endl;
    cout<<"p2.mA:"<<p2.mA<<endl;

    p1.sB=1000;
    p2.sB=2000;

    cout<<"p1.sB:"<<p1.sB<<endl;
    cout<<"p2.sB:"<<p2.sB<<endl;

    cout<<"Person::sB:"<<Personx::sB<<endl;
}

void test02x()
{
    cout<<Personx::getCount()<<endl;
}

class Studentx
{
public:
    Studentx()
    {
        cout<<"构造函数!"<<endl;
    }

    ~Studentx()
    {
        cout<<"析构函数!"<<endl;
    }

};

static Studentx stu;

int main()
{
    cout<<"hello main!"<<endl;
   test01x();
    test02x();
    system("pause");
    return 0;
}

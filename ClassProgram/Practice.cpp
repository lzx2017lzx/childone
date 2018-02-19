#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
class MyString
{
public:
    MyString(int n)//通过MyString s1=1方式创建对象不能成功
    {
        cout<<"MyString(int n)"<<endl;
    }
    MyString(const char *str)
    {
        cout<<"MyString(const char *str)"<<endl;
    }
};

int main01()
{
    MyString str1=1;
    MyString str2(10);

    MyString str3="abcd";
    MyString str4("mmmm");
    return 0;
}
class Person
{
public:
    Person()
    {
        cout<<"无参构造函数"<<endl;
        pName=(char *)malloc(strlen("undefined")+1);
        strcpy(pName,"undefined");
        mAge=0;
    }

    Person(char *name,int age)
    {
        cout<<"有参构造函数"<<endl;
        pName=(char *)malloc(strlen(name)+1);
        strcpy(pName,name);
        mAge=age;
    }

    void ShowPerson()
    {
        cout<<"Name:"<<pName<<"Age:"<<mAge<<endl;
    }

    ~Person()
    {
        cout<<"析构函数"<<endl;
        if(pName!=NULL)
        {
            delete pName;
            pName=NULL;
        }
    }
public:
    char *pName;
    int mAge;
};
void test()
{
    Person *person1=new Person;
    Person *person2=new Person("John",33);

    person1->ShowPerson();
    person2->ShowPerson();

    delete person1;
    delete person2;
    cout<<"栈变量聚合初始化"<<endl;
    Person person3[]={Person("John",20),Person("Smith",22)};
    cout<<person3[1].pName<<endl;

    Person *workers=new Person[20];

    delete []workers;
}
class Personx
{
public:
    static int sNum;
private:
    static int sOther;
};
int Personx::sNum=0;
int Personx::sOther=0;
void test2()
{

    Personx::sNum=100;
    cout<<"Person::sNum"<<Personx::sNum<<endl;

    Personx p1,p2;
    p1.sNum=200;

    cout<<"p1.sNum:"<<p1.sNum<<endl;
    cout<<"p2.sNum:"<<p2.sNum<<endl;

   // cout<<"Person::sOther"<<Personx::sOther<<endl;
    Personx p3;
   // cout<<"p3.sOther"<<p3.sOther<<endl;
}
int main()
{
//    char *pStr=new char[100];
//    int *pArr1=new int[100];
//    int *pArr2=new int[10]{1,2,3,4,5,5,7,8,9,10};

//    delete []pStr;
//    delete []pArr1;
//    delete []pArr2;
   // test();
    test2();
    return 0;
}

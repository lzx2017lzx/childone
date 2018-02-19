#define _CRT_SECURE_NO_WARINGS
#include<iostream>
using namespace std;
//请写一个单例程序并测试
class Config
{
public:
    static Config *getInstance()//1、定义公有静态成员函数，返回静态成员(一个指向对象的类指针)，供外界访问，实际上是向外界传递了地址
    {
        return pConfig;
    }
private://构造函数、拷贝函数、析构函数全部私有化，说明不能在类外访问这些函数，即不能创建对象，但是私有成员可以访问，所以定义指向对象的指针pConfig可以动态申请一个对象config
    Config()
    {
        mCount=1;
    }
    Config(const Config&){}
    ~Config()
    {
        mCount--;
    }
private:
    static Config *pConfig;//定义指向对象的指针，静态变量说明该变量被所有对象公有。
public:
    int mCount;//用来检测创建了的对象的个数
};

Config *Config::pConfig=new Config;//因为static已经申明了，所以尽管pConfig是私有成员，任然不被视为类外。


void test()
{
    Config *c1=Config::getInstance();
    Config *c2=Config::getInstance();
    Config *c3=Config::getInstance();

    cout<<c1->mCount<<endl;
    cout<<c2->mCount<<endl;
    cout<<c3->mCount<<endl;

    cout<<(int)c1<<endl;//本质是打印c1存储空间的内容(被强制类型转换过后)
    cout<<(int)c2<<endl;
    cout<<(int)c3<<endl;
}

int main()
{
    test();
    return 0;
}

#define _CRT_SECURE_NO_WARINGS
#include<iostream>
using namespace std;
//��дһ���������򲢲���
class Config
{
public:
    static Config *getInstance()//1�����幫�о�̬��Ա���������ؾ�̬��Ա(һ��ָ��������ָ��)���������ʣ�ʵ����������紫���˵�ַ
    {
        return pConfig;
    }
private://���캯����������������������ȫ��˽�л���˵�����������������Щ�����������ܴ������󣬵���˽�г�Ա���Է��ʣ����Զ���ָ������ָ��pConfig���Զ�̬����һ������config
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
    static Config *pConfig;//����ָ������ָ�룬��̬����˵���ñ��������ж����С�
public:
    int mCount;//������ⴴ���˵Ķ���ĸ���
};

Config *Config::pConfig=new Config;//��Ϊstatic�Ѿ������ˣ����Ծ���pConfig��˽�г�Ա����Ȼ������Ϊ���⡣


void test()
{
    Config *c1=Config::getInstance();
    Config *c2=Config::getInstance();
    Config *c3=Config::getInstance();

    cout<<c1->mCount<<endl;
    cout<<c2->mCount<<endl;
    cout<<c3->mCount<<endl;

    cout<<(int)c1<<endl;//�����Ǵ�ӡc1�洢�ռ������(��ǿ������ת������)
    cout<<(int)c2<<endl;
    cout<<(int)c3<<endl;
}

int main()
{
    test();
    return 0;
}

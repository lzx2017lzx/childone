#include <iostream>

using namespace std;
//一、检查类的函数中定义另一个类的变量；（合法的行为)
//二、检查两个头文件中相互包含头文件，一个类中定义另一个类的变量出错问题。(必须合适地去掉一个头文件的包含)
class mm
{
public:
    mm(string name,int age)
    {
        this->name=name;
        this->age=age;
    }

    mm()
    {
        this->name="xiaoming";
        age=30;
    }

public:
    string name;
    int age;
};

class bb
{
public:
    void printbb()
    {
        mm a;
        cout<<a.age<<a.name<<endl;
    }
};

int main(int argc, char *argv[])
{

    mm("lihua",20);
    bb c;
    c.printbb();
    cout << "Hello World!" << endl;
    return 0;
}

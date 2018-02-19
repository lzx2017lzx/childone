#include <iostream>
#include<functional>
using namespace std;

//给出使用bind函数创建新的函数（①相对于被绑定的函数只是参数顺序不变；②相对于被绑定的函数参数缺省一个；
void myfunc(int i,double d,char c)
{
    printf("i is %d,d is %g,c is %c\n",i,d,c);
}

typedef void (*MyFuncType)(int,double,char);

int main(int argc, char *argv[])
{
    Child c;
    Parent *p=&c;

    p->foo();
    p->fool();

   // MyFuncType f=myfunc;
    function<void(int,double,char)>f;
   // f=bind(&myfunc,placeholders::_2
    f=myfunc;
    f(100,1.2,'c');

    function<void(double,int,char)>ff;
    ff=bind(&myfunc,placeholders::_2,placeholders::_1,placeholders::_3);
    ff(100.22,3,'a');

    function<void(double,int)>mm;
    mm=bind(&myfunc,placeholders::_2,placeholders::_1,'d');
    mm(1.2,4);

    cout << "Hello World!" << endl;
    return 0;
}

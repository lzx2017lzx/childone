#include<iostream>
using namespace std;

//#pragma pack(2)
//程序编译器对结构的存储的特殊处理确实提高CPU存储变量的速度，但是有时候也会带来一些麻烦，我们可以自己设定变量对齐方式
//
//编译器中提供了#pragma pack(n)来设定变量以n字节对齐方式。n字节对齐就是说变量存放的起始地址的偏移量有两种情况：
//如果n大于等于该变量所占用的字节数，那么偏移量必须满足默认的对齐方式
//如果n小于该变量的类型所占用的字节数，那么偏移量为n的倍数，不用满足默认的对齐方式
//结构的总大小也有个约束条件，分为下面两种情况：
//如果n大于所有成员变量类型所占用的字节数，那么结构的总大小必须为占用空间最大的变量占用的空间数的倍数
//否则必须为n的倍数

#pragma pack(2)
class A
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo() {    }
	typedef char* (*f)(void*);
	enum { red, green, bule } color;
}a;
int main()
{
	cout << "sizeof(a):" << sizeof(a);
	getchar();

	return 0;
}
#include<stdio.h>
int main()
{
	const char **ptr2=NULL;
	char *ptr="abcdefg";
//	ptr2=&ptr;//编译提示向不同的指针类型赋值，说明const修饰ptr2的值即*ptr2，它是一个字符指针。
	//char *const _ptr="mnopq";
//	ptr2=&_ptr;
	const char *__ptr="acd";
	ptr2=&__ptr;//编译没有报错，说明二级指针const修饰的是char
//*即ptr2存储的指针的类型是const char *
	const char *ptr_="bdf";
	*ptr2=ptr_;//编译没有报错，说明const char *是数据类型，可以和基本数据类型int、char等对比
	const char ptr__='a';
	ptr_=&ptr__;
//	ptr=&(&ptr__);//编译报错，&修饰的对象必须是左值
	*ptr2=&ptr__;//编译没有报错，说明const char *对ptr2来说只是数据类型，并不意味着不能通过ptr2来间接赋值，这与ptr__变量不一样，const char，意味不能改变ptr__的值；
	const char ptr__2='b';
//	ptr__=ptr__2;//ptr__变量是只读变量，编译报错
//	**ptr2='a';//编译报错，因为char **ptr2，意味着不能通过**ptr改变值。	
	return 0;
}
//总结，const char **ptr和const char ptr性质不一样；ptr的存储空间可以改变，但ptr不行。

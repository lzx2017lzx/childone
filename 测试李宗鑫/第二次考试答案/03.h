#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char* pAddress; //字符串实际存储地址
	int mSize; //字符串大小
public:
	MyString(); //无参构造 
	MyString(int n, char c); //有参构造，指定大小和初始值
	MyString(const MyString& str); //拷贝构造
	MyString& operator=(const MyString& str); //赋值运算符重载
	MyString& operator=(const char* str); //赋值运算符重载
	~MyString(); //析构函数


	MyString operator+(const MyString& str); //加号运算符重载
	MyString operator+(const char *s); //加号运算符重载

	MyString& operator+=(const MyString& str); //加等运算符重载
	MyString& operator+=(const char *s); //加等运算符重载

	char& operator[](int index); //下标运算符重载
	int Size(); //返回字符串长度
	friend std::ostream& operator<<(std::ostream &out, MyString &str); //输出运算符重载
	friend std::istream& operator >> (std::istream &in, MyString &str); //输入运算符重载
};

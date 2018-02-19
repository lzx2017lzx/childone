#include "03.h"


MyString::MyString() //无参构造 
{
	this->mSize = 0;
	this->pAddress = new char[1];
	this->pAddress[0] = '\0';
}
MyString::MyString(int n, char c) //有参构造，指定大小和初始值
{
	this->mSize = n;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, c, n);
	this->pAddress[n] = '\0';
}
MyString::MyString(const MyString& str) //拷贝构造
{
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str.pAddress);
}
MyString& MyString::operator=(const MyString& str) //赋值运算符重载
{
	this->mSize = str.mSize;
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str.pAddress);
	return *this;
}
MyString& MyString::operator=(const char* str) //赋值运算符重载
{
	this->mSize = strlen(str);
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str);
	return *this;
}
MyString::~MyString() //析构函数
{
	this->mSize = 0;
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}


MyString MyString::operator+(const MyString& str) //加号运算符重载
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	if (NULL != temp.pAddress)
	{
		delete[] temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.pAddress = new char[temp.mSize + 1];
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);
	return temp;
}
MyString MyString::operator+(const char *s) //加号运算符重载
{
	MyString temp;
	temp.mSize = this->mSize + strlen(s);
	if (NULL != temp.pAddress)
	{
		delete[] temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.pAddress = new char[temp.mSize + 1];
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);
	return temp;
}

MyString& MyString::operator+=(const MyString& str) //加等运算符重载
{
	*this = *this + str;
	return *this;
}
MyString& MyString::operator+=(const char *s) //加等运算符重载
{
	*this = *this + s;
	return *this;
}

char& MyString::operator[](int index) //下标运算符重载
{
	return this->pAddress[index];
}
int MyString::Size() //返回字符串长度
{
	return this->mSize;
}
std::ostream& operator<<(std::ostream &out, MyString &str) //输出运算符重载
{
	out << str.pAddress << endl;
	return out;
}
std::istream& operator >> (std::istream &in, MyString &str) //输入运算符重载
{
	char *buf = new char[1024];
	in >> buf;
	str.mSize = strlen(buf);
	if (NULL != str.pAddress)
	{
		delete[] str.pAddress;
		str.pAddress = NULL;
	}
	str.pAddress = new char[str.mSize + 1];
	strcpy(str.pAddress, buf);
	delete[] buf;
	return in;
}

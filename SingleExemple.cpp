#include<iostream>
using namespace std;

class Printer
{
public:
	static Printer*getInstance()
	{
		return pPrinter;
	}
	void PrintText(string text)
	{
		cout<<"打印内容:"<<text<<endl;
		cout<<"已打印次数:"<<mTimes<<endl;
		cout<<"----------"<<endl;
		mTimes++;//都是同一个变量，每次使用PrintText函数都会让mTimes自加一次。
	}
private:
	Printer()
	{
		mTimes=0;
	}
	Printer(const Printer&)
	{

	}
private:
	static Printer*pPrinter;
	int mTimes;
};

Printer*Printer::pPrinter=new Printer;

void test()
{
	Printer*printer=Printer::getInstance();
	printer->PrintText("离职报告!");
	printer->PrintText("入职合同!");
	printer->PrintText("提交代码!");
}
int main()
{
	test();
	return 0;
}

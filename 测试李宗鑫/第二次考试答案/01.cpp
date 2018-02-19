#include <iostream>
#include <string>
using namespace std;

class Printer
{
private:
	Printer(){}
	Printer(const Printer&){}
	~Printer(){}
private:
	static Printer *instance;
	static int count;
public:
	static Printer * GetInstance()
	{
		return instance;
	}
	void PrintString(string str)
	{
		cout << str << endl;
		++count;
	}
	int GetCount()
	{
		return count;
	}
};

Printer * Printer::instance = new Printer;
int Printer::count = 0;

//int main()
//{
//	Printer *p1 = Printer::GetInstance();
//	Printer *p2 = Printer::GetInstance();
//	p1->PrintString("abc");
//	p2->PrintString("def");
//	cout << p2->GetCount() << endl;
//}
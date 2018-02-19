#include<iostream>
#include<sstream>
using namespace std;


int main()
{
string str;
std::stringstream ss;
int a=10;
int b=20;
ss<<a;

str=ss.str();
cout<<"str:"<<str<<endl;
ss.str("");
#if 0
if(ss.eof())
{
	ss.clear();
	cout<<"s2.eof true"<<endl;
}
#endif
ss<<b;
str=ss.str();
cout<<"str:"<<str<<endl;

	return 0;
}


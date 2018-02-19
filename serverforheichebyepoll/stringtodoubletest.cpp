#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
using namespace std;

int main()
{
	string sa="123.11";
	std::stringstream sstring;
	sstring<<sa;
	
	double sadouble;
	sstring>>sadouble;
	printf("sadouble:%lf\n",sadouble);


	return 0;
}


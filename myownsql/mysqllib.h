#ifndef __MYSQLLIB_H_
#define __MYSQLLIB_H_
#include<mysql.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class mysqllib
{
	private:
		mysqllib();
		mysqllib(mysqllib&);
		~mysqllib();
	public:
		static mysqllib*getInstance();
		int select(char*sql);
		int select(char*sql,char*result_buf);
	private:
		static mysqllib*instance;
		MYSQL*mysql;
};
#endif

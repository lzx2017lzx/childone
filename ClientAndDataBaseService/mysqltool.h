#ifndef _MYSQLTOOL_H
#define _MYSQLTOOL_H
#include<mysql.h>
#include<iostream>

using namespace std;


class mysqltool
{
	private:
		mysqltool();
		mysqltool(mysqltool&);
		~mysqltool();
	public:
		static mysqltool * getInstance();
		int select(char *sql,int &id);
		int select(char *sql,char *result_buf);
		int insert(char *sql);
	private:
	static mysqltool * instance;
	MYSQL *mysql;

};
#endif

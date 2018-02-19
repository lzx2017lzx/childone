#include "mysqllib.h"

mysqllib * mysqllib::instance = new mysqllib;

mysqllib::mysqllib()
{
	mysql = mysql_init(NULL);
	mysql_real_connect(mysql, "127.0.0.1", "root", "123456", "ICE", 3306, NULL, 0);
	if (NULL == mysql)
	{
		cout << "connect error" << endl;
	}
	mysql_query(mysql, "set names utf8");
}

mysqllib::mysqllib(mysqllib&)
{
}

mysqllib::~mysqllib()
{
	mysql_close(mysql);
}

mysqllib * mysqllib::getInstance()
{
	return instance;
}

int mysqllib::select(char *sql)
{
	mysql_query(mysql, sql);
	MYSQL_RES *result = mysql_store_result(mysql);
	int rows = mysql_num_rows(result);
	if (rows)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int mysqllib::select(char *sql, char *result_buf)
{
	if(mysql_query(mysql, sql))
	{
		return -1;
	}
	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		sprintf(result_buf, "%s%s\n", result_buf, row[0]);
	}
	return 0;
}


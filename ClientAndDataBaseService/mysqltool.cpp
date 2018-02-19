#include"mysqltool.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
mysqltool *mysqltool::instance=new mysqltool;

mysqltool::mysqltool()
{
	mysql=mysql_init(NULL);
	mysql_real_connect(mysql,"127.0.0.1","root","lzx19940428","mynetdisk1",3306,NULL,0);

	if(NULL==mysql)
	{

		cout<<"connect error"<<endl;
	}

	mysql_query(mysql,"set names utf8");
}

mysqltool::mysqltool(mysqltool&)
{


}

mysqltool::~mysqltool()
{
	mysql_close(mysql);

}

mysqltool* mysqltool::getInstance()
{
	return instance;
}

int mysqltool:: select(char *sql)
{
	printf("before mysql_query\n");
	mysql_query(mysql,sql);
	printf("after mysql_query\n");
	MYSQL_RES *result=mysql_store_result(mysql);
	printf("before mysql_store_result\n");
	int rows=mysql_num_rows(result);
	printf("after mysql_num_rows\n");
	if(rows)
	{
		return 0;
	}else
	{
		return -1;
	}

}


int mysqltool::select(char *sql,char *result_buf)
{
	if(mysql_query(mysql,sql))
	{
		return -1;
	}
	mysql_query(mysql,sql);

	MYSQL_RES * result=mysql_store_result(mysql);

	MYSQL_ROW row;

	while(row=mysql_fetch_row(result))
	{
		sprintf(result_buf,"%s%s\n",result_buf,row[0]);
	}

	return 0;

}



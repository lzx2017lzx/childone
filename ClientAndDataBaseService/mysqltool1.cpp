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

int mysqltool:: select(char *sql,int &id)
{
	printf("before mysql_query\n");
	if(mysql_query(mysql,sql))
	{
		return -1;
	
	};
	printf("after mysql_query\n");
	MYSQL_RES *result=mysql_store_result(mysql);
	printf("before mysql_store_result\n");
	MYSQL_ROW  row=mysql_fetch_row(result);
	if(row)
	{
		id=atoi(row[0]);		
		
	}
	printf("after mysql_num_rows\n");
	printf("id=%d\n",id);
	return 0;
}


int mysqltool::select(char *sql,char *result_buf)
{
	if(mysql_query(mysql,sql))
	{
		return -1;
	}

	MYSQL_RES * result=mysql_store_result(mysql);
	
	int count=mysql_num_fields(result);
	MYSQL_ROW row;

	while(row=mysql_fetch_row(result))
	{
		for(int i=0;i<count;i++)
		{
		printf("list into while\n");
			sprintf(result_buf,"%s%s\n",result_buf,row[i]);
		}
	}
	printf("count=%d\n",count);
	return 0;

}

int mysqltool::insert(char *sql)
{
	printf("insert sql:%s",sql);
	return mysql_query(mysql,sql);
}

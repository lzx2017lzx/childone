#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>

int main()
{
	MYSQL*mysql=mysql_init(NULL);
	mysql=mysql_real_connect(mysql,"127.0.0.1","root","123456","ICE",3306,NULL,0);
	if(NULL==mysql)
	{
	printf("connect error\n");
	return -1;
}
	char *sql="insert into user values('lihuaA','lihuaA',4)";
	if(mysql_query(mysql,sql))
{
	printf("query error\n");
return -2;

};
	mysql_close(mysql);
	return 0;
}

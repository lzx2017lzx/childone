#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include "mysqllib.h"

int main()
{
	//初始化socket通讯
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = 0;
	addr.sin_port = htons(9998);
	bind(sock, (struct sockaddr*)&addr, sizeof(addr));
	listen(sock, 10);
	//接收客户端连接
	int client = accept(sock, NULL, NULL);
	//获取mysqltool工具
	mysqllib *mysql = mysqllib::getInstance();


	char recv_buf[1024] = {0}; //用于接收客户端消息
	char send_buf[1024] = {0}; //用于给客户端发消息 
	char sql_buf[1024] = {0}; //用于构建sql命令
	char result_buf[1024] = {0}; //用于查询命令返回结果集
	char username[1024] = {0}; //保存客户端用户名

	while (1)
	{
		//重要:清空缓存
		memset(recv_buf, 0, sizeof(recv_buf));
		memset(send_buf, 0, sizeof(send_buf));
		//接收用户登录信息
		recv(client, recv_buf, sizeof(recv_buf), 0);
		char *type = strtok(recv_buf, " "); //获取用户操作类型
		cout << type << endl;
		//验证登录
		if (strcmp(type, "login") == 0)
		{	
			strcpy(username, strtok(NULL, " "));
			char *password = strtok(NULL, " ");
			sprintf(sql_buf, "select * from user where username = '%s' and password = '%s';", username, password);
			if(mysql->select(sql_buf))
			{
				strcpy(send_buf, "login failed");
			}
			else
			{
				strcpy(send_buf, "login success");
			}

			send(client, send_buf, strlen(send_buf), 0); 

		}
		else if (strcmp(type, "list") == 0) //查看网盘文件
		{
			memset(sql_buf,0,sizeof(sql_buf));
			memset(result_buf,0,sizeof(result_buf));
			sprintf(sql_buf, "select file_name from user_file where userid = (select id from user where username = '%s')", username);
			cout << sql_buf << endl;
			if(mysql->select(sql_buf, result_buf))
			{
				strcpy(send_buf, "list failed");
				send(client, send_buf, strlen(send_buf), 0);
			}
			else
			{
				cout << "test" << endl;
				send(client, result_buf, strlen(result_buf), 0);
			}
		}
	}
	return 0;
}

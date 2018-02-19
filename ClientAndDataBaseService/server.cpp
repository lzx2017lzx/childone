#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<netinet/in.h>
#include"mysqltool.h"
#include<string.h>
#include<stdio.h>
int main()
{

	int sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=0;
	addr.sin_port=htons(9998);
	bind(sock,(struct sockaddr*)&addr,sizeof(addr));

	listen(sock,10);

	int client=accept(sock,NULL,NULL);
	mysqltool * mysql=mysqltool::getInstance();

	char recv_buf[1024]={0};
	char send_buf[1024]={0};
	char sql_buf[1024]={0};
	char *username=NULL;
	char pnameclient[1024]={0};
	char result_buf[1024]={0};

	while(1)
	{
		memset(recv_buf,0,sizeof(recv_buf));
		memset(send_buf,0,sizeof(send_buf));
		recv(client,recv_buf,sizeof(recv_buf),0);
		memset(result_buf,0,sizeof(result_buf));
		///printf("revb_buf:%s\n",recv_buf);

		char *type=strtok(recv_buf," ");
		///printf("type=%s\n",type);
		if(strcmp(type,"login")==0)
		{
			memset(pnameclient,0,sizeof(pnameclient));
			username=strtok(NULL," ");
			strcpy(pnameclient,username);
			//		printf("username=%s\n",username);
			char *password=strtok(NULL," ");
			//		printf("password=%s\n",password);
			sprintf(sql_buf,"select * from user where usename= '%s' and password='%s'",username,password);	
			printf("sql=%s\n",sql_buf);
			if(mysql->select(sql_buf))
			{
				strcpy(send_buf,"login failed");
			}else
			{
				strcpy(send_buf,"login success");
			}
			printf("before send client \n");
			send(client,send_buf,strlen(send_buf),0);
		}else if(strcmp(type,"list")==0)
		{
			sprintf(sql_buf,"select file_name from user_file where userid=(select id from user where usename='%s')",pnameclient);
			printf("sql_buf=%s\n",sql_buf);

			if(mysql->select(sql_buf,result_buf))
			{

				strcpy(send_buf,"list failed");
				send(client,send_buf,strlen(send_buf),0);

			}else
			{
				send(client,result_buf,strlen(result_buf),0);

			}
		}
		else if(strcmp(type,"upload")==0)
		{
			char *file_name=strtok(NULL," ");
			char *src_path=strtok(NULL," ");
			int file_size=atoi(strtok(NULL," "));
			int *md5=strtok(NULL," ");

			sprintf(sql_buf,"select dst_path from user.file where md5='%s'",md5);
			if(mysql->select(sql_buf,result_buf))
			{
				cout<<"upload select error"<<endl;
			}
			else
			{
				if(strlen(result_buf))
				{
					result_buf[strlen(result_buf)-1]='\0';
					sprintf(sql_buf,"insert into user_file values(NULL,%d,'%s','%s',NULL,%d,'%s','%s')",userid,file_name,src_path,file_size,result_buf,md5);
					if(mysql->insert(sql_buf))
					{
						strcpy(send_buf,"upload failed");
					}
					else
					{
						strcpy(send_buf,"upload success");
					}
					send(client,send_buf,strlen(send_buf),0);
					continue;
				}else
				{
					strcpy(send_buf,"upload file");
					send(client,send_buf,strlen(send_buf),0);
				}
			}





		}
	}
	return 0;
}

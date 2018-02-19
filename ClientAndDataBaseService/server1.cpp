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
#include<openssl/md5.h>
#include<iomanip>
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
	char temprecv_buf[1024]={0};
	char send_buf[1024]={0};
	char sql_buf[1024]={0};
	char *username=NULL;
	char pnameclient[1024]={0};
	char result_buf[1024]={0};
	int userid=0;

	while(1)
	{
		memset(recv_buf,0,sizeof(recv_buf));
		memset(send_buf,0,sizeof(send_buf));
		recv(client,recv_buf,sizeof(recv_buf),0);
		
		memset(result_buf,0,sizeof(result_buf));
		printf("revb_buf:%s\n",recv_buf);
		if(*recv_buf=='\0')
		{
			return -1;
		}
		strcpy(temprecv_buf,recv_buf);
		memset(recv_buf,0,sizeof(recv_buf));
		char *type=strtok(temprecv_buf," ");
		///printf("type=%s\n",type);
		if(strcmp(type,"login")==0)
		{
			memset(pnameclient,0,sizeof(pnameclient));
			username=strtok(NULL," ");
			strcpy(pnameclient,username);
			//		printf("username=%s\n",username);
			char *password=strtok(NULL," ");
			//		printf("password=%s\n",password);
			sprintf(sql_buf,"select id from user where usename= '%s' and password='%s'",username,password);	
			printf("sql=%s\n",sql_buf);
			if(mysql->select(sql_buf,userid))
			{
				strcpy(send_buf,"login failed");
			}else
			{
				if(userid)
					strcpy(send_buf,"login success");
				else
				{
					strcpy(send_buf,"login failed");
				}
			}
			printf("before send client \n");
			send(client,send_buf,strlen(send_buf),0);
		}else if(strcmp(type,"list")==0)
		{
			
			sprintf(sql_buf,"select src_path from user_file where userid=(select id from user where usename='%s')",pnameclient);
			printf("sql_buf=%s\n",sql_buf);
			memset(result_buf,0,sizeof(result_buf));
			if(mysql->select(sql_buf,result_buf))
			{

				strcpy(send_buf,"list failed");
				send(client,send_buf,strlen(send_buf),0);
				printf("send list failed\n");

			}else
			{
			printf("list result_buf:%s\n",result_buf);
			if(strlen(result_buf)==0)
			{
				strcpy(result_buf,"set is empty");
			}
				send(client,result_buf,strlen(result_buf),0);
			}
		}
		else if(strcmp(type,"upload")==0)
		{
			char *file_name=strtok(NULL," ");
			printf("file_name:%s\n",file_name);
			char *src_path=strtok(NULL," ");
			printf("src_path:%s\n",src_path);
			int file_size=atoi(strtok(NULL," "));
			char *md5=strtok(NULL," ");
			sprintf(sql_buf,"select dst_path from user_file where md5='%s'",md5);
			printf("sql_buf=%s\n",sql_buf);
			memset(result_buf,0,sizeof(result_buf));
			if(mysql->select(sql_buf,result_buf))
			{
				cout<<"upload select error"<<endl;
			}
			else
			{

				if(strlen(result_buf))
				{
				char *temp=strtok(result_buf," ");
				//	result_buf[strlen(result_buf)-1]='\0';
				}else
				{
					strcpy(send_buf,"upload file");
					send(client,send_buf,strlen(send_buf),0);
					char buffer[1024]={0};
					sprintf(buffer,"./data/%s.%s",pnameclient,file_name);
					printf("buffer:%s\n",buffer);

					sprintf(result_buf,"/data/%s",file_name);
					int fd=open(buffer,O_WRONLY|O_CREAT,0777);
					printf("fd=%d\n",fd);

					int tmp=file_size;
					while(tmp)
					{
						memset(recv_buf,0,sizeof(recv_buf));
						int ret=recv(client,recv_buf,sizeof(recv_buf),0);
						write(fd,recv_buf,ret);
						tmp-=ret;
					}
					close(fd);
				}
				printf("after create all files sql_buf\n");
				printf("result_buf:%s\n",result_buf);
				printf("pnameclient:%s\n",pnameclient);
				memset(sql_buf,0,sizeof(sql_buf));
				sprintf(sql_buf,"insert into user_file values(NULL,%d,'%s','%s',NULL,%d,'%s','%s')",userid,file_name,src_path,file_size,result_buf,md5);
				printf("after sprintf insert into:%s\n",sql_buf);
				
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
			}


		}
		else if(strcmp(type,"download")==0)
		{
			char *src_path=strtok(NULL," ");
			sprintf(sql_buf,"select file_size,dst_path,md5 from user_file where userid=%d and src_path='%s'",userid,src_path);
			printf("download sql_buf:%s\n",sql_buf);
			memset(result_buf,0,sizeof(result_buf));
			if(mysql->select(sql_buf,result_buf))
			{
				cout<<"download select error"<<endl;
			}else
			{
			printf("download,result_buf:%s\n",result_buf);
				int file_size =atoi(strtok(result_buf,"\n"));
				char *dst_path=strtok(NULL,"\n");
				printf("download dst_path:%s\n",dst_path);
				char *md5_tmp=strtok(NULL,"\n");
				printf("before send\n");
				send(client,(char *)&file_size,4,0);
				printf("after send\n");
				char buffer[1024]={0};
				char *temp=rindex(dst_path,'/');
				temp=temp+1;
				printf("download:temp:%s\n",temp);
					sprintf(buffer,"./data/%s.%s",pnameclient,temp);
				int fd=open(buffer,O_RDONLY);
				printf("download fd:%d\n",fd);
				while(file_size)
				{
					char buffer[1024]={0};
					int ret=read(fd,buffer,sizeof(buffer));
					send(client,buffer,ret,0);
					file_size -=ret;
				}
				close(fd);

				char md5[1024]={0};
				memset(md5,0,sizeof(md5));
				recv(client,md5,sizeof(md5),0);
				
				if(strcmp(md5,md5_tmp)==0)
				{
					strcpy(send_buf,"download success");

				}else
				{
					strcpy(send_buf,"download failed");
				}
				
				send(client,send_buf,strlen(send_buf),0);
			}
			
		}






	}
	return 0;
}

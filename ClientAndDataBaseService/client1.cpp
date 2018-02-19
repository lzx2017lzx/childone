#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<openssl/md5.h>
#include<iomanip>
using namespace std;



void get_md5(char *path,char *md5)
{

	MD5_CTX c;
	MD5_Init(&c);

	unsigned char md5_tmp[17]={0};
	int len=0;
	char buffer[1024]={0};
	printf("path=%s\n",path);
	int fd=open(path,O_RDONLY);
	while(len=read(fd,buffer,sizeof(buffer)))
	{
		MD5_Update(&c,buffer,len);
	}
	printf("len=%d\n",len);

	MD5_Final(md5_tmp,&c);
	close(fd);
	for(int i=0;i<16;i++)
	{
		//				cout<<hex<<setw(2)<<setfill('0')<<(int)md5_tmp[i];
		sprintf(md5,"%s%02x",md5,md5_tmp[i]);
		printf("md5:%s\n",md5);
	}
}
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("argument error");
		return -1;
	}

	int sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(9998);

	connect(sock,(struct sockaddr*)&addr,sizeof(addr));

	char send_buf[1024]={0};
	char recv_buf[1024]={0};
	char in_buf[1024]={0};
	sprintf(send_buf,"login %s %s",argv[1],argv[2]);
	send(sock,send_buf,strlen(send_buf),0);
	recv(sock,recv_buf,sizeof(recv_buf),0);


	cout<<recv_buf<<endl;
	if(strcmp(recv_buf,"login success")==0)
	{
		while(1)
		{
			memset(send_buf,0,sizeof(send_buf));
			memset(in_buf,0,sizeof(in_buf));
			cout<<"client>";
			fgets(in_buf,sizeof(in_buf),stdin);
			in_buf[strlen(in_buf)-1]='\0';
			printf("stdin in_buf:%s\n",in_buf);
			char *type=strtok(in_buf," ");
			printf("stdin type:%s\n",type);
			if(strcmp(type,"list")==0)
			{
				strcpy(send_buf,"list");
				send(sock,send_buf,strlen(send_buf),0);
				printf("after send list\n");
				recv(sock,recv_buf,sizeof(recv_buf),0);
				cout<<recv_buf<<endl;
			}
			else if(strcmp(type,"upload")==0)
			{
				char *path=strtok(NULL," ");
				char *src_path=strtok(NULL," ");
				char *file_name=rindex(src_path,'/')+1;

				struct stat st;
				stat(path,&st);
				int file_size=st.st_size;
				char md5[1024]={0};	
				get_md5(path,md5);
				sprintf(send_buf,"upload %s %s %d %s",file_name,src_path,file_size,md5);
				send(sock,send_buf,strlen(send_buf),0);
				printf("send_buf:%s\n",send_buf);
				memset(recv_buf,0,sizeof(recv_buf));
				recv(sock,recv_buf,sizeof(recv_buf),0);
				if(strcmp(recv_buf,"upload success")==0||strcmp(recv_buf,"upload failed")==0)
				{
					cout<<recv_buf<<endl;
					continue;
				}else if(strcmp(recv_buf,"upload file")==0)
				{
					int	fd=open(path,O_RDONLY);
					while(file_size)
					{
						char buffer[1024]={0};
						int ret=read(fd,buffer,sizeof(buffer));
						send(sock,buffer,ret,0);
						file_size-=ret;
					}
					close(fd);
					memset(recv_buf,0,sizeof(recv_buf));
					recv(sock,recv_buf,sizeof(recv_buf),0);
					if(strcmp(recv_buf,"upload success")==0||strcmp(recv_buf,"upload failed")==0)
					{
						cout<<recv_buf<<endl;
						continue;
					}
				}
				cout<<md5<<endl;
				cout<<endl;
			}
			else if(strcmp(type,"download")==0)
			{
				char *src_path=strtok(NULL," ");
				char *path=strtok(NULL," ");
				sprintf(send_buf,"download %s",src_path);
				send(sock,send_buf,strlen(send_buf),0);
				printf("downloadclient:send_buf:%s\n",send_buf);
				int file_size=0;
				recv(sock,(char *)&file_size,4,0);
				int fd=open(path,O_WRONLY|O_CREAT,0777);

				while(file_size)
				{
					char buffer[1024]={0};
					int ret=recv(sock,buffer,sizeof(buffer),0);
					write(fd,buffer,ret);
					file_size-=ret;
				}
				close(fd);
				char md5[1024]={0};
				get_md5(path,md5);
				send(sock,md5,strlen(md5),0);
				recv(sock,recv_buf,sizeof(recv_buf),0);
				cout<<recv_buf<<endl;
			}
		}
	}



	return 0;
}

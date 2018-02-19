#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("argument error");
		return -1;
	}
	//建立socket通讯 
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9998);
	//连接服务器
	connect(sock, (struct sockaddr*)&addr, sizeof(addr));
	
	char send_buf[1024] = {0};
	char recv_buf[1024] = {0};
	char in_buf[1024] = {0}; //获取控制台输入

	sprintf(send_buf, "login %s %s", argv[1], argv[2]);
	send(sock, send_buf, strlen(send_buf), 0);
	recv(sock, recv_buf, sizeof(recv_buf), 0);

	cout <<"recv_buf:"<< recv_buf << endl;
	if (strcmp(recv_buf, "login success") == 0)
	{
		while (1)
		{
			memset(recv_buf, 0, sizeof(recv_buf));
			cout << "client > ";
			fgets(in_buf, sizeof(in_buf), stdin);
			in_buf[strlen(in_buf)-1] = '\0';
			if (strcmp(in_buf, "list") == 0)
			{
				strcpy(send_buf, "list");
				send(sock, send_buf, strlen(send_buf), 0);
				memset(recv_buf,0,sizeof(recv_buf));
				recv(sock, recv_buf, sizeof(recv_buf), 0);
				cout << recv_buf << endl;
			}
		}
	}
	return 0;
}


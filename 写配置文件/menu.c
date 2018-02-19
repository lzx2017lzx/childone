#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"cfg_heap.h"
void menu()
{
	printf("============\n");
	printf("1 写配置文件\n");
	printf("2 读配置文件\n");
	printf("3 清屏\n");
	printf("4 退出\n");
	printf("=============\n");
}

void write_cfg_file()
{
	char key[128] = { 0 };
	char value[256] = { 0 };
	int ret = 0;
	printf("请输入key值:");
	scanf("%s", key);
	printf("请输入value值:");
	scanf("%s", value);
	ret = my_write(key, value);
	if (ret != 0)
	{
		printf("my_write err=%d\n", ret);
		return;
	}
	printf("写成功，写入内容为:%s=%s\n", key, value);

}

void read_cfg_file()
{
	char key[128] = { 0 };
	char value[256] = { 0 };
	int ret = 0;
	int len;

	printf("请输入key值:");
	scanf("%s", key);

	ret = my_read(key, value, &len);
	if (ret != 0)
	{
		printf("my_read err=%d\n", ret);
		return;
	}
	printf("读取内容为:%s=%s,len=%d\n", key, value, len);
}
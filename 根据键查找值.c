#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
键值对（“key=value”）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取value。
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格
*/
/*
功能：获取非空字符串
参数：
inbuf：原始字符串buf首地址
outbuf：非空字符串buf首地址
返回值：
成功：0
失败：非0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}
	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0)
	{
		return -2;
	}
	//从左往右移动，如果当前字符为空，而且没有结束
	while (p[begin] == ' ')//或是使用isspace()
	{
		begin++;//位置从右移动一位
	}
	//从右往左移动，如果当前字符为空
	while (p[end] == ' '&&end > 0)
	{
		end--;//往左移动
	}
	if (end == 0)
	{
		return -2;
	}
	n = end - begin + 1;//非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = '\0';//结束符
	return 0;
}
/*
功能：
键值对（"key=value")字符串更据键key查找对应的值value
参数：
keyvalue：键值对（“key=value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0
*/
int getKeyByValue(char *keyval, char *pkey, char *buf, int *len)
{
	if (keyval == NULL || pkey == NULL || buf == NULL || len == NULL)
	{
		return -1;
	}
	//辅助变量把形参接过来
	char *p = keyval;//"key1=    valude1"

					 //查看key是否在母串
					 //查找key1是否在"key1=    valude1"
	p = strstr(p, pkey);
	if (NULL == p)//没有匹配键
	{
		return -2;
	}
	//重新设置起点位置，字符串跳过key值
	//"key1=    valude1"->"=   valude1"
	p = p + strlen(pkey);

	//查找是否包含=号
	p = strstr(p, "=");
	if (NULL == p)//没有
	{
		return -3;
	}
	//字符串跳过"="
	//"=    valude1"->"    valude1"
	p = p + strlen("=");
	//获取非空字符串
	int ret = trimSpace(p, buf);
	if (ret != 0)
	{
		return ret;
	}

	//通过*操作符操作内存
	//间接赋值
	*len = strlen(buf);
	return 0;
}
int main(void)
{
	char keyval[] = "key1=    valuede1";//键值对字符串
	char *pkey = "key1";//键值
	char buf[128] = { 0 };
	int len = 0;

	int ret = getKeyByValue(keyval, pkey, buf, &len);
	if (ret != 0)
	{
		printf("getKeyByValue:%d\n", ret);
		return ret;
	}
	printf("value:%s\n len=%d\n", buf, len);


	printf("\n");
	system("pause");
	return 0;
}

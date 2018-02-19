#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
2. 实现my_strstr()函数，功能和strstr()函数一样。
a. 函数中不使用任何操作字符串的函数(如：strcpy、strcmp等)
b. 函数中的任何地方不使用下标。



功能：在字符串haystack中查找字符串needle出现的位置
参数：
haystack：源字符串首地址
needle：匹配字符串首地址
返回值：
成功：返回第一次出现的needle地址
失败：NULL

char *my_strstr(const char *haystack, const char *needle);
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
	{
		printf("datas are not enough!");
		return NULL;
	}
	int i = 0;//用来遍历haystack
	int j = 0;//用来遍历始地址为needle的字符串
	//char *myhaystack = &haystack[0];//左边是非const类型，右边是const类型想想如何消去该警告
	//char *myneedle = &needle[0];
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i++] != needle[j++])
				break;	
		}
		
		if (needle[j] == '\0')
			return needle - j-1;
		i--;
	}
	return NULL;
}
int main01(void)
{
	 char *haystack = "woshizhongguoren";
	 char *needle = "guoren";
	char*check = strstr(haystack, needle);
	printf("%s\n", check);
	printf("\n");
	system("pause");
	return 0;
}
/*
3. 键值对（"key = value"）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取
要求2：编写测试用例
要求3：键值对中间可能有n多空格，请去除空格

参考库函数：strncpy(), strlen(), strstr(), 不能使用sscanf()函数

注意：键值对字符串格式可能如下：
"key1 = value1"
"key2 =       value2"
"key3  = value3"
"key4        = value4"
"key5   =   "
"key6   ="



功能：
键值对（“key = value”）字符串更加键key查找对应的值value
参数：
keyval：键值对（“key = value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen);

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	在"key1 =    valude1"中查找"key1"匹配的字符串，
	如果找到，获取=后面的字符串，而且去掉多余空格
	
	int ret = getKeyByValue("key1 =    valude1", "key1", buf, &len);
	//调用函数后：buf="valude1", len=7

	return 0;
}
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen)
{
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return -1;
	}
	char *ptr = strstr(keyvaluebuf, keybuf);
	int i = 0;
	ptr = ptr + strlen(keybuf);
	//printf("%c\n", *ptr);
	while (*ptr++ == ' ');
	while (*ptr++ == ' ');
	ptr -= 1;
	strcpy(valuebuf, ptr);
	*valuebuflen = strlen(ptr);
	return 0;
}

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;
	char *data[14] = { "key1 = value1","key2 =       value2","key3  = value3","key4        = value4","key5   =   ","key6   =" };
	int ret = 0;
	int i = 0;
	char*key[14] = { "key1","key2","key3","key4","key5","key6" };
	while(1)
	{ 
		if ((data[i] == NULL) || (key[i] == NULL))
		{
			printf("there is no enough datas!");
			break;
		}
	ret = getKeyByValue(data[i],key[i], buf, &len);
	if (ret == 0)
	{
		printf("%s,%d\n", buf,len);
	}
	else
	{
		printf("getkeybybalue faile!");
	}
	i++;
	}
	system("pause");
	return 0;
}

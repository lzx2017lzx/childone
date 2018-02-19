#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
功能：在字符串haystack中查找字符串needle出现的位置
参数：
haystck：源字符串首地址
needle：匹配字符串首地址
返回值：
成功：返回第一次出现的needle地址
失败：NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
	{
		return NULL;
	}
	//辅助变量，把形参接收过来
	const char *src_str = haystack;
	const char *sub_str = needle;

	while (*src_str != '\0')//源字符串没有到结束符
	{
		if (*src_str != *sub_str)//如果源字符串和匹配字符串对应的元素不相等的话
		{
			src_str++;//结束本次循环，下次继续
			continue;
		}

		const char *tmp_str = src_str;//记录移动后源字符串的地址
		const char *tmp_substr = sub_str;//匹配字符串首地址

		while (*tmp_substr != '\0')//匹配字符串没有到结束符
		{
			if (*tmp_substr != *tmp_str)
			{
				src_str++;//跳过一个字符
				break;//跳出循环
			}
			tmp_substr++;
			tmp_str++;
		}
		if (*tmp_substr == '\0')//如果到匹配字符串的结束符，说明有匹配字符串
		{
			return (char *)src_str;//返回匹配匹配字符串地址
		}
	}
	return NULL;
}
int main(void)
{
	const char *p = "abchellomikeabc";
	char *needle = my_strstr(p, "mike");
	if (needle != NULL)
	{
		printf("needle=%s\n", needle);
	}
	printf("\n");
	system("pause");
	return 0;
}


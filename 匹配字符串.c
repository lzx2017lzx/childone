#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
������
haystck��Դ�ַ����׵�ַ
needle��ƥ���ַ����׵�ַ
����ֵ��
�ɹ������ص�һ�γ��ֵ�needle��ַ
ʧ�ܣ�NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
	{
		return NULL;
	}
	//�������������βν��չ���
	const char *src_str = haystack;
	const char *sub_str = needle;

	while (*src_str != '\0')//Դ�ַ���û�е�������
	{
		if (*src_str != *sub_str)//���Դ�ַ�����ƥ���ַ�����Ӧ��Ԫ�ز���ȵĻ�
		{
			src_str++;//��������ѭ�����´μ���
			continue;
		}

		const char *tmp_str = src_str;//��¼�ƶ���Դ�ַ����ĵ�ַ
		const char *tmp_substr = sub_str;//ƥ���ַ����׵�ַ

		while (*tmp_substr != '\0')//ƥ���ַ���û�е�������
		{
			if (*tmp_substr != *tmp_str)
			{
				src_str++;//����һ���ַ�
				break;//����ѭ��
			}
			tmp_substr++;
			tmp_str++;
		}
		if (*tmp_substr == '\0')//�����ƥ���ַ����Ľ�������˵����ƥ���ַ���
		{
			return (char *)src_str;//����ƥ��ƥ���ַ�����ַ
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


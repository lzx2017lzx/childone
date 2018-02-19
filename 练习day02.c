#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
2. ʵ��my_strstr()���������ܺ�strstr()����һ����
a. �����в�ʹ���κβ����ַ����ĺ���(�磺strcpy��strcmp��)
b. �����е��κεط���ʹ���±ꡣ



���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
������
haystack��Դ�ַ����׵�ַ
needle��ƥ���ַ����׵�ַ
����ֵ��
�ɹ������ص�һ�γ��ֵ�needle��ַ
ʧ�ܣ�NULL

char *my_strstr(const char *haystack, const char *needle);
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
	{
		printf("datas are not enough!");
		return NULL;
	}
	int i = 0;//��������haystack
	int j = 0;//��������ʼ��ַΪneedle���ַ���
	//char *myhaystack = &haystack[0];//����Ƿ�const���ͣ��ұ���const�������������ȥ�þ���
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
3. ��ֵ�ԣ�"key = value"���ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ
Ҫ��2����д��������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�

�ο��⺯����strncpy(), strlen(), strstr(), ����ʹ��sscanf()����

ע�⣺��ֵ���ַ�����ʽ�������£�
"key1 = value1"
"key2 =       value2"
"key3  = value3"
"key4        = value4"
"key5   =   "
"key6   ="



���ܣ�
��ֵ�ԣ���key = value�����ַ������Ӽ�key���Ҷ�Ӧ��ֵvalue
������
keyval����ֵ�ԣ���key = value�����ַ���
pkey����
buf��ƥ�������Ӧ������
len��ƥ�������Ӧ���ݵĳ���
����ֵ��
�ɹ���0
ʧ�ܣ���0

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen);

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	��"key1 =    valude1"�в���"key1"ƥ����ַ�����
	����ҵ�����ȡ=������ַ���������ȥ������ո�
	
	int ret = getKeyByValue("key1 =    valude1", "key1", buf, &len);
	//���ú�����buf="valude1", len=7

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

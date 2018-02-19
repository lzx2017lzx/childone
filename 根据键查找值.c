#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
��ֵ�ԣ���key=value�����ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡvalue��
Ҫ��2����д����������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�
*/
/*
���ܣ���ȡ�ǿ��ַ���
������
inbuf��ԭʼ�ַ���buf�׵�ַ
outbuf���ǿ��ַ���buf�׵�ַ
����ֵ��
�ɹ���0
ʧ�ܣ���0
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
	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (p[begin] == ' ')//����ʹ��isspace()
	{
		begin++;//λ�ô����ƶ�һλ
	}
	//���������ƶ��������ǰ�ַ�Ϊ��
	while (p[end] == ' '&&end > 0)
	{
		end--;//�����ƶ�
	}
	if (end == 0)
	{
		return -2;
	}
	n = end - begin + 1;//�ǿ�Ԫ�ظ���

	strncpy(outbuf, p + begin, n);
	outbuf[n] = '\0';//������
	return 0;
}
/*
���ܣ�
��ֵ�ԣ�"key=value")�ַ������ݼ�key���Ҷ�Ӧ��ֵvalue
������
keyvalue����ֵ�ԣ���key=value�����ַ���
pkey����
buf��ƥ�������Ӧ������
len��ƥ�������Ӧ���ݵĳ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int getKeyByValue(char *keyval, char *pkey, char *buf, int *len)
{
	if (keyval == NULL || pkey == NULL || buf == NULL || len == NULL)
	{
		return -1;
	}
	//�����������βνӹ���
	char *p = keyval;//"key1=    valude1"

					 //�鿴key�Ƿ���ĸ��
					 //����key1�Ƿ���"key1=    valude1"
	p = strstr(p, pkey);
	if (NULL == p)//û��ƥ���
	{
		return -2;
	}
	//�����������λ�ã��ַ�������keyֵ
	//"key1=    valude1"->"=   valude1"
	p = p + strlen(pkey);

	//�����Ƿ����=��
	p = strstr(p, "=");
	if (NULL == p)//û��
	{
		return -3;
	}
	//�ַ�������"="
	//"=    valude1"->"    valude1"
	p = p + strlen("=");
	//��ȡ�ǿ��ַ���
	int ret = trimSpace(p, buf);
	if (ret != 0)
	{
		return ret;
	}

	//ͨ��*�����������ڴ�
	//��Ӹ�ֵ
	*len = strlen(buf);
	return 0;
}
int main(void)
{
	char keyval[] = "key1=    valuede1";//��ֵ���ַ���
	char *pkey = "key1";//��ֵ
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

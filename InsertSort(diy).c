#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ֶ�ģ��������������
int main(void)
{
	//��������
	int a[] = { 2,3,9,4,8,5,1,7,6 };
	int Len = sizeof(a) / sizeof(a[0]);

	int i, j;//i��Ҫ��������ݵ��±꣬ÿ����һ�Σ�i������j��Ϊ�˴����±�Ϊi�����������õı�����ע��j��--�ģ�����j��Ϊ������Ƚϣ����ƶ�Ԫ��
	int temp;//�����洢Ҫ����ı�������ֹ�����λʱ����ɸ���
	for (i = 1; i < Len; i++)
	{
		if (a[i-1] > a[i])
		{
			temp = a[i];
			for (j = i - 1; j >= 0 && temp < a[j]; j--)//jָ��i��ǰһ��Ԫ�أ�ֱ���ҵ���Ԫ�ر�Ҫ�����Ԫ��С.ע���˳�ѭ��ʱj�±�ָ���Ԫ���Ǳ�Ҫ�����Ԫ��ֵС����Ҫ����λ�õ�ǰһ��λ��
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}

	}

	//ѭ����ӡ
	for (i = 0; i < Len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

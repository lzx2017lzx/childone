#include <stdio.h>


int main(void)
{
	/*��1~n�������������ַ�(0��1��2��3��4��5��6��7��8��9)�ֱ���ֵĴ�����
	N�ɼ������롣
	*/

	int count[10] = { 0 }; //�洢0-9�����ַ����ֵĴ���  count[0]�洢0�ַ����ֵĴ���

	int n;
	scanf("%d",&n);
	int i,j;
	for (i = 1; i <= n; ++i)
	{
		//i ����Щ�ַ�

		j = i;
		//��ȡ��i��ÿλ�� 
		while (j)
		{
			count[j % 10] ++;
			j /= 10;
		}
	}

	for(i =0 ;i<10;++i)
		printf("%d ���ֵĴ�����%d\n",i,count[i]);


	return 0;
}
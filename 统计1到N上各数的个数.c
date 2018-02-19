#include <stdio.h>


int main(void)
{
	/*求1~n以内所有数中字符(0、1、2、3、4、5、6、7、8、9)分别出现的次数。
	N由键盘输入。
	*/

	int count[10] = { 0 }; //存储0-9所有字符出现的次数  count[0]存储0字符出现的次数

	int n;
	scanf("%d",&n);
	int i,j;
	for (i = 1; i <= n; ++i)
	{
		//i 有哪些字符

		j = i;
		//获取出i的每位数 
		while (j)
		{
			count[j % 10] ++;
			j /= 10;
		}
	}

	for(i =0 ;i<10;++i)
		printf("%d 出现的次数是%d\n",i,count[i]);


	return 0;
}
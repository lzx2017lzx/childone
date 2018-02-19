#if 0
/*
* 输入一个已经按升序排序过的数组和一个数字
* 在数组中查找两个数，使得它们的和正好是输入的那个数字
* 如果有多对数字的和等于输入的数字，输出任意一对即可
* 例如输入数组：1,2,4,7,11,15 和 数字15，由于 4+11=15，所以输出4和11
*/
#endif
#include <stdio.h>
#include <string.h>
#if 0
/*
* 输入一个字符串，输出其中第一次出现的不重复的字符
* 例如: 输入 aabccdebff 则输出 b
*/
#endif

void foo4()
{
	char *s = "aadbcceff";
	int len = strlen(s);
	//O(n2)
	/*for (int i = 0; i < len; ++i)
	{
		int flag = 1;
		for (int j = 0; j < len; ++j)
		{
			if (i == j)
				continue;
			if (s[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("%c\n", s[i]);
			break;
		}
		else
		{
			continue;
		}
	}*/

	int num[26] = { 0 };
	int index[26] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		++num[s[i] - 'a'];
		index[s[i] - 'a'] = i;
	}
	int min = len;
	for (int i = 0; i < 26; ++i)
	{
		if (num[i] == 1&&index[i]<min)
		{
			min = index[i];
		}
	}
	printf("%c\n", s[min]);
}

#if 0
/*
* 实现一个十进制转二进制的函数，传入一个十进制数，以二进制形式输出
* void dec2bin(int n);
*/
#endif 

void dec2bin(int n)
{
	for (int i = 31; i >= 0; --i)
	{
		printf("%d", n >> i & 1);
	}
}

/*
 * 交换两个变量的值的几种方法
 */

void foo1()
{
	int a = 5;
	int b = 3;
	/*int temp = a;   浪费空间
	a = b;
	b = temp;*/

	//1,3,5,6,3,1
	/*a = a^b;    注意：如果两个值相等，会出现0
	b = a^b;
	a = a^b;*/

	//a = a + b; //5+3=8  数据溢出
	//b = a - b; //8-3=5
	//a = a - b; //8-5=3  

	//a = a - b; //5-3=2
	//b = a + b; //2+3=5
	//a = b - a; //5-2=3
}

void foo2()
{
	//O()
	//int arr[1024]={1,2,3,4....,1024}
	//10
	//arr[9]  O(1);
	//遍历  O(n);
	//循环嵌套 O(n^2)
	//二分法 O(logN);
}

void foo3()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n = 11;
	//O(n2)
	/*for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (arr[i] + arr[j] == n)
			{
				printf("n=%d,arr[i]=%d,arr[j]=%d\n", n, arr[i], arr[j]);
				return;
			}
		}
	}*/

	int begin = 0;
	int end = 8;
	while (begin < end)
	{
		if (arr[begin] + arr[end] > n)
		{
			--end;
		}
		else if (arr[begin] + arr[end] < n)
		{
			++begin;
		}
		else
		{
			printf("n=%d,arr[i]=%d,arr[j]=%d\n", n, arr[begin], arr[end]);
			return;
		}
	}
}

int main()
{
	//foo3();
	//foo4();
	dec2bin(15);
}
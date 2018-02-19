#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isroundyear(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//��ȡ����һ�����ʱ��
int digt1()
{
	return 366 * 24 * 3600;
}
//��ȡƽ��һ�����ʱ��
int digt2()
{
	return 365 * 24 * 3600;
}
//��ȡ����һ�µ���ʱ��
int month1()
{
	return 31 * 24 * 3600;
}
//��ȡС��һ�µ���ʱ��
int month2()
{
	return 30 * 24 * 3600;
}
//��ȡ����һ�µ���ʱ��
int month3()
{
	return 29 * 24 * 3600;
}
//��ȡƽ��һ�µ���ʱ��
int month4()
{
	return 28 * 24 * 3600;
}
//����ʱ���
int getdigt(int year, int month, int day, int hour, int minute, int second)
{

	int sum = 0;
	//��ȡ��һ��1��1��0ʱ0��0��֮ǰ����������
	int i = 1970;
	for (i = 1970; i < year; i++)
	{
		if (isroundyear(i))
			sum += digt1();
		else
			sum += digt2();
	}
	//�ٻ�ȡ��һ��month��֮ǰ����������
	for (i = 1; i < month; i++)
	{
		if (i == 2)
		{
			if (isroundyear(year))
				sum += month3();
			else
				sum += month4();
		}
		else
		{
			switch (i)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum += month1(); break;
			case 4:
			case 6:
			case 9:
			case 11:
				sum += month2(); break;
			default:
				break;
			}
		}
	}
	//�ٻ�ȡ�������һ��֮ǰ���������ʱ��
	sum += (day - 1) * 24 * 3600;
	//�ٻ�ȡ��һ����һʱ��֮ǰ������ʱ��
	sum += hour * 3600 + minute * 60 + second;
	//��ȥʱ��
	sum -= 8 * 3600;
	return sum;
}
int main()
{
	int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
	printf("please input your time:");
	scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
	int totaltime = getdigt(year, month, day, hour, minute, second);
	printf("%d\n", totaltime);
	system("pause");
	return 0;
}
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
//获取闰年一年的总时间
int digt1()
{
	return 366 * 24 * 3600;
}
//获取平年一年的总时间
int digt2()
{
	return 365 * 24 * 3600;
}
//获取大月一月的总时间
int month1()
{
	return 31 * 24 * 3600;
}
//获取小月一月的总时间
int month2()
{
	return 30 * 24 * 3600;
}
//获取闰月一月的总时间
int month3()
{
	return 29 * 24 * 3600;
}
//获取平月一月的总时间
int month4()
{
	return 28 * 24 * 3600;
}
//计算时间戳
int getdigt(int year, int month, int day, int hour, int minute, int second)
{

	int sum = 0;
	//获取这一年1月1日0时0分0秒之前的所有秒数
	int i = 1970;
	for (i = 1970; i < year; i++)
	{
		if (isroundyear(i))
			sum += digt1();
		else
			sum += digt2();
	}
	//再获取这一年month月之前的所有秒数
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
	//再获取这个月这一天之前的所有天的时间
	sum += (day - 1) * 24 * 3600;
	//再获取这一天这一时刻之前的所有时间
	sum += hour * 3600 + minute * 60 + second;
	//减去时区
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
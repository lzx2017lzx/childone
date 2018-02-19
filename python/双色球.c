#include<stdio.h>
#include<time.h>
int ball[7]={0};
//为红球产生随机数（1-33）
int redpro_num(void)
{
	return rand()%33+1;
}
//为蓝球产生随机数(1-16)
int bluepro_num(void)
{
	return rand()%16+1;
}
//比较两次红球和篮球数字是否相同，并将结果分别输出
int compare_result(int *ball,int *input,int *count1,int *count2)
{	
	if((ball==NULL)||(input==NULL)||(count1==NULL)||(count2==NULL))
	return 0;
	int i=0;
	int j=0;
	for(i=0;i<6;i++)
	{
	for(j=0;j<6;j++)
	{
	if(ball[i]==input[j])
	{
	(*count1)++;
	break;
	}
	}
	}
	if(ball[6]==input[6])
	(*count2)++;
	return 0;
}
//中奖结果输出
int result_out(int count1,int count2)
{
	if((count1==6)&&(count2==1))
	printf("一等奖.\n");
	else if((count1==6)&&(count2==0))
	{
	printf("二等奖.\n");
	}else if((count1==5)&&(count2==1))
	{
	printf("三等奖.\n");
	}else if((count1==5)||((count1==4)&&(count2==1)))
	{
	printf("四等奖.\n");
	}else if((count1==4)||((count1==3)&&(count2==1)))
	{
	printf("五等奖.\n");
	}else if(count2==1)
	{
	printf("六等奖.\n");
	}else
	{
	printf("SO BAD!\n");
	}
	printf("the correct number is:%d %d %d %d %d %d %d.\n",ball[0],ball[1],ball[2],ball[3],ball[4],ball[5],ball[6]);
	return 0;
}
int main()
{
	int flag=1;
	srand((unsigned)time(NULL));
//	int ball[7]={0};
	int input[7]={0};
	int i=0;//为所有红球赋值
	int j=0;//判断是否重复
	int count1=0;
	int count2=0;
	for(i=0;i<6;i++)
	{
		ball[i]=redpro_num();
		for(j=0;j<i;j++)
		if(ball[j]==ball[i])
		i--;
	}
	ball[6]=bluepro_num();
//	printf("%d %d %d %d %d %d %d.\n",ball[0],ball[1],ball[2],ball[3],ball[4],ball[5],ball[6]);
	//提醒输入
//	printf("please input six numbers for red balls(1-33):\n");
	while(flag)
	{
	printf("please input six numbers for red balls(1-33):\n");
	scanf("%d %d %d %d %d %d",input,input+1,input+2,input+3,input+4,input+5);
//	flush(stdin);
	flag=0;
	for(i=0;i<6;i++)
	{
	if((input[i]>33)||(input[i]<1))
	{
	flag=1;
	printf("your input is out of ranges.\n");
	break;
	}
	}
	//检测出入是否有重复的数
	for(i=0;i<6;i++)
	{
	for(j=i+1;j<6;j++)
	if(input[i]==input[j])
	{
	flag=1;
	continue;
	}
	if(flag)
	{
	printf("you input two same numbers at least.\n");
	break;
	}
	}
	}
	flag=1;
	while(flag)
	{
	printf("please input one number for blue ball(1-16):\n");
	scanf("%d",input+6);
	flag=0;
	if((input[6]>16)||(input[6]<1))
	{
	flag=1;
	printf("your input is out of range.\n");
	continue;
	}
	//调用比较函数
	}
	compare_result(ball,input,&count1,&count2);
	result_out(count1,count2);
	return 0;
}

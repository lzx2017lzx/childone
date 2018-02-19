#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"
/* 问题
 * 给定一个表达式字符串"5+5*(6)+9/3*1)-1)+3"，判断括号是否匹配，并在黑屏幕上指定不匹配的
 * 括号的位置
 *
 * */
int IsLeft(char ch)
{
    return ch=='(';
}

int IsRight(char ch)
{
    return ch==')';
}

void PrintError(const char *str,char *pos)
{
    printf("%s\n",str);
    int dis=pos-str;
    int i=0;
    for(i=0;i<dis;i++)
    {
        printf(" ");
    }
    printf("A\n");
}

void test()
{
    const char *str="(6)))))))";
    char *p=(char *)str;

    //创建栈
    SeqStack stack=Init_SeqStack();

    while(*p!='\0')
    {
        //如果是左括号，入栈
        if(IsLeft(*p))
        {
            Push_SeqStack(stack,p);
        }

        //如果是有括号
        if(IsRight(*p))
        {
            if(Size_SeqStack(stack)>0)
            {
                Pop_SeqStack(stack);
            }
            else
            {
                printf("没有匹配的左括号!\n");
                PrintError(str,p);
            }
        }
        ++p;
    }

    //如果栈不是空，栈中剩下的是左括号
    while(Size_SeqStack(stack)>0)
    {
        printf("左括号没有匹配的右括号!\n");
        PrintError(str,(char *)Top_SeqStack(stack));
        Pop_SeqStack(stack);
    }

    //销毁栈
    Destroy_SeqStack(stack);
}

int main001(void)
{
    test();
    //printf("Hello World!\n");
    return 0;
}


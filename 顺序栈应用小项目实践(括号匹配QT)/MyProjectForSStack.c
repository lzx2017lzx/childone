#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SeqStack.h"
/* 问题
 * 给定一个表达式字符串"5+5*(6)+9/3*1)-1)+3"，判断括号是否匹配，并在黑屏幕上指定不匹配的
 * 括号的位置
 *
 * */
/*
 * 算法：
 * ①、遍历表达式，遇到左括号进栈，遇到右括号，判断栈是否为空，如果为空，说明没有匹配的左括号
 * 打印结果，并将右括号入栈。②、遍历结束后，判断栈是否为空，如果不为空，弹出并打印栈内所有剩余的
 * 右括号
 *
 * */
//写函数判断是不是左括号，返回布尔类型，C语言布尔类型需要包含头文件stdbool.h
bool IsLeftBra(char ch)
{
    return ch=='(';
}
//写函数判断是不是右括号，返回布尔类型
bool IsRightBra(char ch)
{
    return ch==')';
}
//定义打印输出函数。首先将原始数据打印一行，然后，在第二行打印一个字符(这里是A）标记到对应的括号下
int PrintOut(const char *str,char *pos)
{
    if(NULL==str)
    {
        return -1;
    }
    if(NULL==pos)
    {
        return -2;
    }
    printf("%s\n",str);
    //确定打印字符A的位置,地址相差，且每个地址对应的元素是char类型
    int Pos=pos-str;
    int i=0;
    for(i=0;i<Pos;i++)
    {
        printf(" ");
    }
    printf("A\n");
    return 0;
}

void Test()
{
    /*
     *
     * //入栈
    void Push_SeqStack(SeqStack stack,void *data);
    //出栈
    void Pop_SeqStack(SeqStack stack);
    //获得栈顶元素
    void* Top_SeqStack(SeqStack stack);
    //获得栈中元素个数
    int Size_SeqStack(SeqStack stack);
    //销毁栈
    void Destroy_SeqStack(SeqStack stack);
     * */
    //写死字符串
    const char *ptr="(((6)()))";
    int flag=0;//0表示表达式字符串是不合理的字符串，存在未匹配的括号，反之是括号都匹配的字符串
    char *pptr=(char *)ptr;
    struct SStack * Stack=(struct SStack *)Init_SeqStack();

    while((*pptr)!='\0')
    {
        if(IsLeftBra(*pptr))
        {
            Push_SeqStack(Stack,(char *)pptr);
        }else if(IsRightBra(*pptr))
        {
            if(Stack->size!=0)
            {
                //如果栈中有数据，弹出栈顶元素
                Pop_SeqStack(Stack);
            }
            else
            {
                //如果栈中没有数据，将右括号存入栈顶,并向屏幕打印结果
               // Push_SeqStack(Stack,(char *)pptr);
                printf("对应的右括号没有左括号匹配.\n");
                PrintOut(ptr,(char *)pptr);
                flag=1;
            }
        }
        pptr++;
    }

    //检查栈有没有剩余的括号
    while(Stack->size!=0)
    {
        //访问打印出元素，再弹出元素
        printf("对应的左括号没有右括号匹配.\n");
        PrintOut(ptr,(char *)Top_SeqStack(Stack));
        flag=1;
        Pop_SeqStack(Stack);
    }
    if(0==flag)
    {
        printf("this is a rational expression.\n");
    }
    //销毁栈
    Destroy_SeqStack(Stack);
}

int main()
{
    Test();
    return 0;
}

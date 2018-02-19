#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"
/* ����
 * ����һ�����ʽ�ַ���"5+5*(6)+9/3*1)-1)+3"���ж������Ƿ�ƥ�䣬���ں���Ļ��ָ����ƥ���
 * ���ŵ�λ��
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

    //����ջ
    SeqStack stack=Init_SeqStack();

    while(*p!='\0')
    {
        //����������ţ���ջ
        if(IsLeft(*p))
        {
            Push_SeqStack(stack,p);
        }

        //�����������
        if(IsRight(*p))
        {
            if(Size_SeqStack(stack)>0)
            {
                Pop_SeqStack(stack);
            }
            else
            {
                printf("û��ƥ���������!\n");
                PrintError(str,p);
            }
        }
        ++p;
    }

    //���ջ���ǿգ�ջ��ʣ�µ���������
    while(Size_SeqStack(stack)>0)
    {
        printf("������û��ƥ���������!\n");
        PrintError(str,(char *)Top_SeqStack(stack));
        Pop_SeqStack(stack);
    }

    //����ջ
    Destroy_SeqStack(stack);
}

int main001(void)
{
    test();
    //printf("Hello World!\n");
    return 0;
}


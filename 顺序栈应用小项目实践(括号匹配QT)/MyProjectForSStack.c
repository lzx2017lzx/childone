#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SeqStack.h"
/* ����
 * ����һ�����ʽ�ַ���"5+5*(6)+9/3*1)-1)+3"���ж������Ƿ�ƥ�䣬���ں���Ļ��ָ����ƥ���
 * ���ŵ�λ��
 *
 * */
/*
 * �㷨��
 * �١��������ʽ�����������Ž�ջ�����������ţ��ж�ջ�Ƿ�Ϊ�գ����Ϊ�գ�˵��û��ƥ���������
 * ��ӡ�����������������ջ���ڡ������������ж�ջ�Ƿ�Ϊ�գ������Ϊ�գ���������ӡջ������ʣ���
 * ������
 *
 * */
//д�����ж��ǲ��������ţ����ز������ͣ�C���Բ���������Ҫ����ͷ�ļ�stdbool.h
bool IsLeftBra(char ch)
{
    return ch=='(';
}
//д�����ж��ǲ��������ţ����ز�������
bool IsRightBra(char ch)
{
    return ch==')';
}
//�����ӡ������������Ƚ�ԭʼ���ݴ�ӡһ�У�Ȼ���ڵڶ��д�ӡһ���ַ�(������A����ǵ���Ӧ��������
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
    //ȷ����ӡ�ַ�A��λ��,��ַ����ÿ����ַ��Ӧ��Ԫ����char����
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
     * //��ջ
    void Push_SeqStack(SeqStack stack,void *data);
    //��ջ
    void Pop_SeqStack(SeqStack stack);
    //���ջ��Ԫ��
    void* Top_SeqStack(SeqStack stack);
    //���ջ��Ԫ�ظ���
    int Size_SeqStack(SeqStack stack);
    //����ջ
    void Destroy_SeqStack(SeqStack stack);
     * */
    //д���ַ���
    const char *ptr="(((6)()))";
    int flag=0;//0��ʾ���ʽ�ַ����ǲ�������ַ���������δƥ������ţ���֮�����Ŷ�ƥ����ַ���
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
                //���ջ�������ݣ�����ջ��Ԫ��
                Pop_SeqStack(Stack);
            }
            else
            {
                //���ջ��û�����ݣ��������Ŵ���ջ��,������Ļ��ӡ���
               // Push_SeqStack(Stack,(char *)pptr);
                printf("��Ӧ��������û��������ƥ��.\n");
                PrintOut(ptr,(char *)pptr);
                flag=1;
            }
        }
        pptr++;
    }

    //���ջ��û��ʣ�������
    while(Stack->size!=0)
    {
        //���ʴ�ӡ��Ԫ�أ��ٵ���Ԫ��
        printf("��Ӧ��������û��������ƥ��.\n");
        PrintOut(ptr,(char *)Top_SeqStack(Stack));
        flag=1;
        Pop_SeqStack(Stack);
    }
    if(0==flag)
    {
        printf("this is a rational expression.\n");
    }
    //����ջ
    Destroy_SeqStack(Stack);
}

int main()
{
    Test();
    return 0;
}

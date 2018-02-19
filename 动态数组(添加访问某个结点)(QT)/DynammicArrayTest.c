#include <stdio.h>
#include"DynammicArray.h"

//����ṹ�����ͣ��洢�û�������Ϣ
struct Person
{
    char name[20];
    int age;
};
/*
 * struct DynamicArray
{
    void **DArray;//��������ѿռ䣬�ѵĵ�λԪ����void *
    int Capacity;//��̬���������
    int Size;//��̬����Ĵ�С
};
 * */
//�Զ���VISITFUNCTION����
void PrintDynamicArray(void *Data)
{
    if(NULL==Data)
    {
        return;
    }
    struct Person *PPerson=(struct Person *)Data;
    printf("name:%s,age:%d\n",PPerson->name,PPerson->age);
    return;
}

//������Ժ���
void test()
{
    //�����û�������Ϣ
    struct Person p1={"abc",20};
    struct Person p2={"ddd",21};
    struct Person p3={"mbc",20};
    struct Person p4={"ndd",21};
    struct Person p5={"pbc",20};
    struct Person p6={"ldd",21};

    //��ʼ����̬����
    //��ʼ����̬����
    struct DynamicArray *PDArray=(struct DynamicArray *)InitDynamicArray();

    //��̬����ָ��λ�ò���Ԫ��
    InsertDynamicArray(PDArray,0,&p1);
    InsertDynamicArray(PDArray,0,&p2);
    InsertDynamicArray(PDArray,0,&p3);
    InsertDynamicArray(PDArray,0,&p4);
    InsertDynamicArray(PDArray,0,&p5);
    InsertDynamicArray(PDArray,0,&p6);
    //�Զ�̬�������
    VisitEachNode(PDArray,PrintDynamicArray);
    printf("----------------------------\n");
    //ɾ����̬����ָ��λ�õ�Ԫ��
    DeleteDynamicArray(PDArray,0);
    //�Զ�̬�������
    VisitEachNode(PDArray,PrintDynamicArray);
    //���ٶ�̬����
    DestroyDynamicArray(PDArray);
}

int main(void)
{
    test();
    printf("Hello World!\n");
    return 0;
}


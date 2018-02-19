#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�����û����ݣ�������ṹ��
struct Person
{
    char name[20];
    int age;
};
//void(*VISITLLNode)(void *Data)
void PrintNode(void *Data)
{
    struct Person *PPerson=(struct Person *)Data;
    if(NULL==PPerson)
    {
        return;
    }

    printf("name:%s,age:%d\n",PPerson->name,PPerson->age);
}

void test()
{
    /*
     * //��ʼ������
        void *InitLStack();
        //��ջͷ��������
        void InsertLStack(struct LinkStack *LStack,void *Data);
        //����ջͷԪ��
        void VisitLStack(struct LinkStack *LStack,,void(*VISITLLNode)(void *Data));
        //����ջͷԪ��
        void PopLStack(struct LinkStack *LStack);
        //������ջ�ߴ�
        int VisitLStack(struct LinkStack *LStack);
        //������ջ
        void DestroyLStack(struct LinkStack *LStack);
struct LinkStackNode
{
    void *Data;
    struct LinkStackNode *PLSNode;
};

//����ṹ���������й���
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};

     * */
    //���ݳ�ʼ��
    struct Person p1={"abc",20};
    struct Person p2={"ddd",21};
    struct Person p3={"ccc",22};
    struct Person p4={"abc",26};
    struct Person p5={"ddd",28};
    struct Person p6={"ccc",29};
    //��ջ��ʼ��
    struct LinkStack *PLStack =(struct LinkStack *)InitLStack();
    //��ջͷ��������
    InsertLStack(PLStack,&p1);
    InsertLStack(PLStack,&p2);
    InsertLStack(PLStack,&p3);
    InsertLStack(PLStack,&p4);
    InsertLStack(PLStack,&p5);
    InsertLStack(PLStack,&p6);
    //������ջ�ߴ�
    printf("Size:%d\n",SizeLStack(PLStack));
    //����ջͷԪ�أ���ָ�����ʷ�ʽ��Ҫ�õ��û��Զ��庯��
    VisitLStack(PLStack,PrintNode);

    //����ջͷԪ��
    PopLStack(PLStack);

    //������ջ�ߴ�
    printf("Size:%d\n",SizeLStack(PLStack));

    //������ջ
    DestroyLStack(PLStack);

}

int main()
{
    test();
    return 0;
}

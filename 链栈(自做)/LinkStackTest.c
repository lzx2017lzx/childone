#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//定义用户数据，需借助结构体
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
     * //初始化链表
        void *InitLStack();
        //向栈头插入数据
        void InsertLStack(struct LinkStack *LStack,void *Data);
        //访问栈头元素
        void VisitLStack(struct LinkStack *LStack,,void(*VISITLLNode)(void *Data));
        //弹出栈头元素
        void PopLStack(struct LinkStack *LStack);
        //访问链栈尺寸
        int VisitLStack(struct LinkStack *LStack);
        //销毁链栈
        void DestroyLStack(struct LinkStack *LStack);
struct LinkStackNode
{
    void *Data;
    struct LinkStackNode *PLSNode;
};

//定义结构体对链表进行管理
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};

     * */
    //数据初始化
    struct Person p1={"abc",20};
    struct Person p2={"ddd",21};
    struct Person p3={"ccc",22};
    struct Person p4={"abc",26};
    struct Person p5={"ddd",28};
    struct Person p6={"ccc",29};
    //链栈初始化
    struct LinkStack *PLStack =(struct LinkStack *)InitLStack();
    //向栈头插入数据
    InsertLStack(PLStack,&p1);
    InsertLStack(PLStack,&p2);
    InsertLStack(PLStack,&p3);
    InsertLStack(PLStack,&p4);
    InsertLStack(PLStack,&p5);
    InsertLStack(PLStack,&p6);
    //访问链栈尺寸
    printf("Size:%d\n",SizeLStack(PLStack));
    //访问栈头元素，需指定访问方式，要用到用户自定义函数
    VisitLStack(PLStack,PrintNode);

    //弹出栈头元素
    PopLStack(PLStack);

    //访问链栈尺寸
    printf("Size:%d\n",SizeLStack(PLStack));

    //销毁链栈
    DestroyLStack(PLStack);

}

int main()
{
    test();
    return 0;
}

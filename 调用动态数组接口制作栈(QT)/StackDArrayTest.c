#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"StackDArray.h"
struct Person
{
    char name[64];
    int age;
};


void test()
{
    //初始化栈
    SeqStack stack = Init_SeqStack();
    //创建数据
    struct Person p1 = { "aaa", 10 };
    struct Person p2 = { "bbb", 20 };
    struct Person p3 = { "ccc", 30 };
    //数据入栈
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);

    //输出栈中所有元素
    while (Size_SeqStack(stack) > 0)
    {
        //先获得栈顶元素
        struct Person *person = (struct Person *)Top_SeqStack(stack);
        printf("Name:%s Age:%d\n", person->name,person->age);
        //弹出栈顶元素
        Pop_SeqStack(stack);
    }

    //销毁栈
    Destroy_SeqStack(stack);

}

int main(){

    test();

    system("pause");
    return EXIT_SUCCESS;
}

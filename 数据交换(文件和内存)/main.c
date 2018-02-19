#include <stdio.h>
#include<lianxiti31.c>
//问题描述
//函数原型 int *getSpace(int n);
//分配n个用以存储n个随机数的堆空间  并且通过函数返回值返回。
//函数原型 int createNumber(int n,int *p); //产生n个的随机数 (1<= x <=n)
//即需要控制随机数范围在1到n之间存到p指向的空间
//函数原型 int writeFile(int n,const char *p);
//即将p指向内存的n个不重复的数写入到test.txt文件中
//函数原型 int readFile(int n,const char **p1);
//即将test.txt文件中的n个数（n由读取第一行获得）写入*p1指向内存空间
//函数原型 int deleteSame(int n,const int *p);
//对p指向的n个空间中的数字进行删除重复的操作 函数返回n个数在删除重复的之后剩余数字的个数
//函数原型 int freeSpace(int **p);
//将getSpace申请的空间释放 并且防止产生迷途指针
//函数原型 int printfSpace(int *p,int n);
//将p指向的空间的n个整数打印出来
//1首先输入数字n（n代表我们需要产生多少个随机数用于后面的操作）
//2 调用函数 p=getSpace(n) 根据数字n分配能够容纳n个整数的堆空间用p接收首地址
//3 调用函数createNumber(n,p)用于产生n个不重复的随机数并且存储在p指向的内存中
//3 调用函数 writeFile(n,p);将p指向内存的n个不重复的数写入到test.txt文件中
//在写入文件的时候 第一行写入n的数值
//4 调用函数 freeSpace释放掉p指向的空间
//5. 调用函数 readFile(n,&p1);时先读取第一行 获取到n值 然后调用getSpace(n)获取内存空间之后并且存储首地址到p1中
//6. 调用函数int m= deleteSame(n,p1);删除p1指向的内存中n个数相同的数字
//7.调用函数printfSpace(m,p1);打印出p1指向的内存中剩余的m个整数
//8.释放p1指向的内存 freeSpace(&p1);
int main(void)
{
    int n=0;
    printf("请输入数字n:\n");
    scanf("%d",&n);
    int *p=getSpace(n);
    createNumber(n,p);
    writeFile(n,p);
    freeSpace(&p);
    int *p1=NULL;
    readFile(n,&p1);
    int m=deleteSame(n,p1);
    printf("%d\n",m);
    printSpace(p1,m);
    freeSpace(&p1);
    return 0;
}


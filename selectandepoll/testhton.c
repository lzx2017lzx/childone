#include<stdio.h>


int main()
{
    unsigned short a=0x1234;

    printf("原始数据a=%x\n",a);

    a=htons(a);
    
    printf("htons转一次a=%x\n",a);

    a=htons(a);
    
    printf("htons转第二次a=%x\n",a);




}

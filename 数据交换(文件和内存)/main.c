#include <stdio.h>
#include<lianxiti31.c>
//��������
//����ԭ�� int *getSpace(int n);
//����n�����Դ洢n��������Ķѿռ�  ����ͨ����������ֵ���ء�
//����ԭ�� int createNumber(int n,int *p); //����n��������� (1<= x <=n)
//����Ҫ�����������Χ��1��n֮��浽pָ��Ŀռ�
//����ԭ�� int writeFile(int n,const char *p);
//����pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���
//����ԭ�� int readFile(int n,const char **p1);
//����test.txt�ļ��е�n������n�ɶ�ȡ��һ�л�ã�д��*p1ָ���ڴ�ռ�
//����ԭ�� int deleteSame(int n,const int *p);
//��pָ���n���ռ��е����ֽ���ɾ���ظ��Ĳ��� ��������n������ɾ���ظ���֮��ʣ�����ֵĸ���
//����ԭ�� int freeSpace(int **p);
//��getSpace����Ŀռ��ͷ� ���ҷ�ֹ������;ָ��
//����ԭ�� int printfSpace(int *p,int n);
//��pָ��Ŀռ��n��������ӡ����
//1������������n��n����������Ҫ�������ٸ���������ں���Ĳ�����
//2 ���ú��� p=getSpace(n) ��������n�����ܹ�����n�������Ķѿռ���p�����׵�ַ
//3 ���ú���createNumber(n,p)���ڲ���n�����ظ�����������Ҵ洢��pָ����ڴ���
//3 ���ú��� writeFile(n,p);��pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���
//��д���ļ���ʱ�� ��һ��д��n����ֵ
//4 ���ú��� freeSpace�ͷŵ�pָ��Ŀռ�
//5. ���ú��� readFile(n,&p1);ʱ�ȶ�ȡ��һ�� ��ȡ��nֵ Ȼ�����getSpace(n)��ȡ�ڴ�ռ�֮���Ҵ洢�׵�ַ��p1��
//6. ���ú���int m= deleteSame(n,p1);ɾ��p1ָ����ڴ���n������ͬ������
//7.���ú���printfSpace(m,p1);��ӡ��p1ָ����ڴ���ʣ���m������
//8.�ͷ�p1ָ����ڴ� freeSpace(&p1);
int main(void)
{
    int n=0;
    printf("����������n:\n");
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


#include"lianxiti31.h"
#include<stdlib.h>
#include<string.h>
int *getSpace(int n)
{
    if(n==0)
       return NULL;
    int *ptrn=(int *)malloc(n*sizeof(int));
    memset(ptrn,0,n*sizeof(int));
    return ptrn;
}
int createNumber(int n,int *p)
{
    if((p==NULL)||(n==0))
        return 0;
    int i=0;
    int j=0;
    for(i=0;i<n;i++)
    {
        p[i]=(rand()%n+1);
//        for(j=0;j<i;j++)
//        {
//            if(p[j]==p[i])
//            {
//                i--;
//                break;
//            }
//        }
    }

    return 1;
}
//空格调整函数
//求一个数的位数
int Uni_value(int num)
{
    int i=0;
    while(num)
    {
    i++;
    num/=10;
    }
    return i;
}
int writeFile(int n,int *p)
{
    if((n==0)||(p==NULL))
        return 0;
    char buf[1024]={0};
    FILE *pfile=fopen("d:\\test.txt","w");
    sprintf(buf,"%d\n",n);
    fputs(buf,pfile);
    memset(buf,0,1024);
    int i=0;
    //int j=0;
   // int len=0;//用来统计sprintf的返回值
//    for(i=0;i<n;i++,j++)
//    {
//        if(j==8)
//        {
//            buf[j]='\n';
//            i--;
//            fputs(buf,pfile);
//            memset(buf,0,1024);
//            j=0;
//        }
//        else
//        sprintf(buf+j,"%d   ",p[i]);
//    }
  //  int j=0;//获取整数的位数
   // int temp=0;
    //获得最大数n的位数；
    int number=Uni_value(n);
    int k=0;
    for(i=0;i<n;i++)
    {
        sprintf(buf,"%d",p[i]);
        fputs(buf,pfile);
        memset(buf,0,1024);
        //for循环将空格输入到buf
        for( k=0;k<(number-Uni_value(p[i])+3);k++)
        {
            buf[k]=' ';
        }
        fputs(buf,pfile);
        memset(buf,0,1024);
        if(((i+1)%8==0)&&(i!=0))
        fputs("\n",pfile);
    }
    fclose(pfile);
    return 0;
}
int readFile(int n,int **p1)
{
    if((n==0)||(p1==NULL))
        return 0;
    int i=0;
    int j=0;
    *p1=getSpace(n);
    FILE *pfile=fopen("d:\\test.txt","r");
    char buf[1024]={0};
    char *temp=NULL;
    fgets(buf,1024,pfile);
    sscanf(buf,"%d",&n);
    *p1=(int *)calloc(n,sizeof(int));
    memset(buf,0,1024);
    while(fgets(buf,1024,pfile)!=NULL)
    {
        j=0;
        strtok(buf," ");
        sscanf(buf,"%d",*p1+i);
        i++;
        j++;
        while((j<8)&&(i<n))
        {
        temp=strtok(NULL," ");
        sscanf(temp,"%d",*p1+i);
        i++;
        j++;
        }
        if(i==n)
            break;
    }
    return 0;
}
int deleteSame(int n, int *p)
{
    if((n==0)||(p==NULL))
        return 0;
    int i=0;
    int j=0;
    int len=n;
    int k=0;
    for(i=0;i<len;i++)
    {
        for(j=0;j<i;j++)
        {
            if(*(p+i)==*(p+j))//如果相等，将所有后面元素前移一个位置覆盖掉重复的数据
             {
                for(k=i;k<len;k++)
                {
                    *(p+k)=*(p+k+1);
                }
                *(p+k)=0;
                len--;
                i--;
                break;
             }
        }

    }
    return len;

//    //先用冒泡排序
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n-i;j++)
//        {
//            if(a[j]>a[j+1])
//            {
//                temp=a[j];
//                a[j]=a[j+1];
//                a[j+1]=temp;
//            }
//        }
//    }

}
int freeSpace(int **p)
{
    if(p==NULL)
        return 0;
    free(*p);
    *p=NULL;
    return 0;
}
int printSpace(int *p,int n)
{
    if((p==NULL)||(n==0))

        return 0;
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
        if((i%8==0)&&(i!=0))
        printf("\n");
    }
    return 0;
}

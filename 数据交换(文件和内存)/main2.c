#include <stdio.h>
#include <string.h>
#include <ctype.h>

//分配n个用以存储n个随机数的堆空间  并且通过函数返回值返回。
int *getSpace(int n)
{
    int ret = (int*)calloc(n,sizeof(int));
    return ret;
}
/**函数原型 int createNumber(int n,int *p); //产生n个的随机数 (1<= x <=n)
        即需要控制随机数范围在1到n之间存到p指向的空间
*/
int createNumber(int n,int *p)
{
    srand(time(NULL));
    int i,j;
    for(i=0;i<n;++i)
    {
        p[i] = rand() % n + 1;
        for(j=0;j<i;++j)
        {
            if(p[i] == p[j])
            {
                i--;break;
            }
        }

    }
    return 0;
}

//即将p指向内存的n个不重复的数写入到test.txt文件中
int writeFile(int n,const int *p)
{
    FILE *fp = fopen("test.txt","wb");
    if(fp == NULL)
    {
        fprintf(stderr,"can't open test.txt");
        return 1;
    }
    int i;
    fprintf(fp,"%d\r\n",n);
    for(i=0;i<n;++i)
    {
        fwrite(&p[i],sizeof(p[i]),1,fp); //
    }
    fclose(fp);
    return 0;
}

//pn 即将test.txt文件中的n个数（n由读取第一行获得）写入*p1指向内存空间

int readFile(int *pn,int **p1)
{
    FILE *fp = fopen("test.txt","rb");
    if(fp == NULL)
    {
        fprintf(stderr,"file not found");
        return 1;
    }
    int n;
    fscanf(fp,"%d\r\n",&n);
    int *temp = (int *)calloc(n,sizeof(int));
    if(temp == NULL)
    {
        fclose(fp);
        fprintf(stderr,"can't calloc space\n");
        return 1;
    }
    fread(temp,sizeof(int),n,fp);
    fclose(fp);

    //chuanchu
    *pn = n;
    *p1 = temp;
    return 0;
}

//p指向的n个空间中的数字进行删除重复的操作 函数返回n个数在删除重复的之后剩余数字的个数
int deleteSame(int n,int *p)
{
    int j,i,k;

    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            //pi pj
            if(p[i] == p[j])
            {

                for(k=j;k<n-1;++k)
                    p[k] = p[k+1];

                n--;
            }
        }
    }

    return n;
}

//函数原型 将getSpace申请的空间释放 并且防止产生迷途指针

int freeSpace(int **p)
{
    int *temp = *p;
    free(temp);
    *p = NULL;
    return 0;
}



//函数原型  将p指向的空间的n个整数打印出来

int printfSpace(const int *p,int n)
{
    int i;
    for( i=0;i<n;++i)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *space = getSpace(n);
    if(space == NULL)
    {
        fprintf(stderr,"can't calloc space\n");
        return 1;
    }
    createNumber(n,space);
    printfSpace(space,n);
    writeFile(n,space);
    freeSpace(&space);
    if(space == NULL)
    {
        printf("space is clean\n");
    }

    int count = 0;
    int *data = NULL;
    if(0 != readFile(&count,&data))
        return 1;
    printfSpace(data,count);
    freeSpace(&data);
    if(space == NULL)
    {
        printf("data is clean\n");
    }
    return 0;
}

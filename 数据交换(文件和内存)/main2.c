#include <stdio.h>
#include <string.h>
#include <ctype.h>

//����n�����Դ洢n��������Ķѿռ�  ����ͨ����������ֵ���ء�
int *getSpace(int n)
{
    int ret = (int*)calloc(n,sizeof(int));
    return ret;
}
/**����ԭ�� int createNumber(int n,int *p); //����n��������� (1<= x <=n)
        ����Ҫ�����������Χ��1��n֮��浽pָ��Ŀռ�
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

//����pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���
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

//pn ����test.txt�ļ��е�n������n�ɶ�ȡ��һ�л�ã�д��*p1ָ���ڴ�ռ�

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

//pָ���n���ռ��е����ֽ���ɾ���ظ��Ĳ��� ��������n������ɾ���ظ���֮��ʣ�����ֵĸ���
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

//����ԭ�� ��getSpace����Ŀռ��ͷ� ���ҷ�ֹ������;ָ��

int freeSpace(int **p)
{
    int *temp = *p;
    free(temp);
    *p = NULL;
    return 0;
}



//����ԭ��  ��pָ��Ŀռ��n��������ӡ����

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

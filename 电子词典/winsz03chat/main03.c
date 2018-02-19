#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WORD_COUNT 111102

int format(char *str)//ȥ���ַ������߶���Ŀհ��ַ�
{
    if(str == NULL)
        return 1;
    char *r = str ;
    char *p = r;
    char *q = str + strlen(str) - 1;

    while(isspace(*p)) //isspace�ǿհ��ַ����ط�0
    {
        p++;
    }
    while(isspace(*q))
    {
        q--;
    }
    while(p <= q)
        *r++= *p++;
    *r = '\0';
    return 0;
}

typedef struct word_t
{
    char *key; //?�Դ洢�����ַ�����?��ַ
    char *content; //?�Դ洢�����ַ�����?��ַ
}word_t;



//�ͷŽṹ����ռ�õĿռ�
void freeSpace(word_t *ptr,unsigned int len)
{
    unsigned int i;
    for(i=0;i<len;++i)
    {
        if(ptr[i].key)
        {
            free(ptr[i].key); //��i���ṹ���Ա�е�keyָ���Ա ��ָ��Ŀռ�(�׵�ַ)
            ptr[i].key = NULL;
        }
        if(ptr[i].content)
        {
            free(ptr[i].content); //��i���ṹ���Ա�е�contentָ���Ա ��ָ��Ŀռ�(�׵�ַ)
            ptr[i].content = NULL;
        }
    }
    free(ptr);
}

//���ļ��ж�ȡ���� ���Ҵ洢���ڴ���   word_t * word;  readData(fp,&word);
int readData(FILE *fp,word_t **data,int *len) //data , *data, **data
{
    if(fp == NULL || data == NULL)
        return -1;
    word_t *temp = NULL;
    //(*data)[index].key ;   temp[index]
    int init_size = 1;
    temp = calloc(init_size,sizeof(word_t));
    char buf[1024] = {0}; //
    fseek(fp,0,SEEK_SET); //rewind(fp);
    //char * fgets ( char * str, int num, FILE * stream );
    word_t *t = NULL;
    int i = 0 ;
    while(fgets(buf,sizeof(buf),fp))
    {
        //i=0
        if(i == init_size) // + 1000
        {
            t = realloc(temp,sizeof(word_t)*(init_size+1));
            if(t == NULL)
            {
                fprintf(stderr,"realloc failed\n");
                return -1;
            }
            temp = t;
            init_size++;
        }
        if(buf[0] == '#')
        {
            temp[i].key = calloc(strlen(buf),sizeof(char));
            if(temp[i].key == NULL)
            {
                fprintf(stderr,"û�п����ڴ���\n");
                return 1;
            }
            format(buf+1);
            strcpy(temp[i].key,buf+1); //strtok
            //strlen����ǰ���#���ַ�������  �����ڸ��ƾͿ��Բ�����\0��λ��
        }else if(buf[0] == 'T')
        {
            temp[i].content = calloc(strlen(buf),sizeof(char));
            if(temp[i].content == NULL)
            {
                fprintf(stderr,"û�п����ڴ���\n");
                return 1;
            }
            //trans:fjldsjflds
            strcpy(temp[i].content,buf+6);
            i++;
        }
        memset(buf,0,sizeof(buf));//memset(buf,sizeof(buf),0);xxxxx
    }
    *len = i;
    *data = temp;
    return 0;
}

int search(const word_t *data,int len,char* find)
{
    if(data== NULL || len <1 || find == NULL)
        return 1;


    format(find);
    int i;
    for(i=0;i< len;++i)
    {
        //��Ϊ�����Ѿ��������ַ���ǰ��Ŀհ��ַ�ȫ��ȥ�� ���ԾͿ�����ȫ�ľ�ȷƥ����
        if(strcmp(data[i].key,find) == 0)
        {
            printf("word %s found\n",find);
            printf("trans:%s\n",data[i].content);
            break;
        }
    }
    if(i == len)
    {
        printf("not found\n");
    }
    return 0;
}

int main(void)
{
	FILE *fp = fopen("d:\\dict.txt", "r");
    if(fp == NULL)
    {
        fprintf(stderr,"file not found\n");
        return 1;
    }
    word_t *word = NULL;
    //int word_count = getWordCount(fp);
    //word_t *word = createSpace(word_count);
    int word_count = 0;
    readData(fp,&word,&word_count);
    if(word == NULL)
    {
        fprintf(stderr,"createSpace(WORD_COUNT) failed\n");
        return 1;
    }
    char input[64] = {0};
    while(1)
    {
        printf("please input word:");
        scanf("%s",input);
        if(strcmp(input,"exit-command") == 0)
            break;
        search(word,word_count,input);
    }

    freeSpace(word,word_count);
    fclose(fp);
    return 0;
}


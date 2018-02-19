#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WORD_COUNT 111102

int formart(char *str)//去掉字符串两边多余的空白字符
{
    if(str == NULL)
        return 1;
    char *r = str ;
    char *p = r;
    char *q = str + strlen(str) - 1;

    while(isspace(*p)) //isspace是空白字符返回非0
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
    char *key; //?以存储单词字符串的?地址
    char *content; //?以存储释义字符串的?地址
}word_t;


//函数的作用是根据参数len的大小 申请len个word_t所占用的空间
word_t * createSpace(unsigned int len)
{
    //malloc / calloc void* calloc (size_t num, size_t size);
    word_t *ret = (word_t *)calloc(len,sizeof(word_t));
    return ret;
}

//释放结构体所占用的空间
void freeSpace(word_t *ptr,unsigned int len)
{
    unsigned int i;
    for(i=0;i<len;++i)
    {
        if(ptr[i].key)
        {
            free(ptr[i].key); //第i个结构体成员中的key指针成员 所指向的空间(首地址)
            ptr[i].key = NULL;
        }
        if(ptr[i].content)
        {
            free(ptr[i].content); //第i个结构体成员中的content指针成员 所指向的空间(首地址)
            ptr[i].content = NULL;
        }
    }
    free(ptr);
}

//从文件中读取数据 并且存储在内存中
int readData(FILE *fp,word_t *data)
{
    if(fp == NULL)
        return 1;
    char buf[4096] = {0};
    int i = 0;
    while(fgets(buf,sizeof(buf),fp))
    {
        if(buf[0] == '#')
        {
            data[i].key = calloc(strlen(buf),sizeof(char));
            if(data[i].key == NULL)
            {
                fprintf(stderr,"没有可用内存了\n");
                return 1;
                //
            }
            formart(buf+1);
            strcpy(data[i].key,buf+1); //strtok
            //strlen测的是包含#的字符串长度  所以在复制就可以不考虑\0的位置
        }else if(buf[0] == 'T')
        {
            data[i].content = calloc(strlen(buf),sizeof(char));
            if(data[i].content == NULL)
            {
                fprintf(stderr,"没有可用内存了\n");
                return 1;
            }
            //trans:fjldsjflds
            strcpy(data[i].content,buf+6);
            i++;
        }
        memset(buf,0,sizeof(buf));
    }
    return 0;
}

int search(const word_t *data,int len,char* find)
{
    if(data== NULL || len <1 || find == NULL)
        return 1;

    formart(find);
    int i;
    for(i=0;i< len;++i)
    {
        //因为我们已经将各个字符串前后的空白字符全部去掉 所以就可以完全的精确匹配了
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
    FILE *fp = fopen("dict.txt","r");
    if(fp == NULL)
    {
        fprintf(stderr,"file not found\n");
        return 1;
    }
    word_t *word = createSpace(WORD_COUNT);
    if(word == NULL)
    {
        fprintf(stderr,"createSpace(WORD_COUNT) failed\n");
        return 1;
    }
    readData(fp,word);

    char input[64] = {0};
    while(1)
    {
        scanf("%s",input);
        if(strcmp(input,"exit-command") == 0)
            break;
        search(word,WORD_COUNT,input);
    }

    freeSpace(word,WORD_COUNT);
    fclose(fp);
    return 0;
}


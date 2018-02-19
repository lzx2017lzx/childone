#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WORD_COUNT 111102

int format(char *str)//去掉字符串两边多余的空白字符
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

//从文件中读取数据 并且存储在内存中   word_t * word;  readData(fp,&word);
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
                fprintf(stderr,"没有可用内存了\n");
                return 1;
            }
            format(buf+1);
            strcpy(temp[i].key,buf+1); //strtok
            //strlen测的是包含#的字符串长度  所以在复制就可以不考虑\0的位置
        }else if(buf[0] == 'T')
        {
            temp[i].content = calloc(strlen(buf),sizeof(char));
            if(temp[i].content == NULL)
            {
                fprintf(stderr,"没有可用内存了\n");
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


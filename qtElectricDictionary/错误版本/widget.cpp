#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QTextCodec>
#include<QDebug>

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
int readData(FILE *fp,word_t **data,int *len) //data , *data, **data
{
    if(fp == NULL || data == NULL)
        return -1;
    word_t *temp = NULL;
    //(*data)[index].key ;   temp[index]
    int init_size = 1;
    temp = (word_t*)calloc(init_size,sizeof(word_t));
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

            t = (word_t*)realloc(temp,sizeof(word_t)*(init_size+1));
            if(t == NULL)
            {
               // fprintf(stderr,"realloc failed\n");
                exit(-1);
            }
            temp = t;
            init_size++;
        }
        if(buf[0] == '#')
        {
            qDebug()<<"i"<<i<<endl;
            temp[i].key = (char*)calloc(strlen(buf),sizeof(char));
            if(i==0)
            {
                qDebug()<<"temp[0].key:"<<temp[0].key;
            }
            if(temp[i].key == NULL)
            {
               // fprintf(stderr,"û�п����ڴ���\n");
                exit(-1);
                return 1;
            }
            format(buf+1);
            strcpy(temp[i].key,buf+1); //strtok
            //strlen����ǰ���#���ַ�������  �����ڸ��ƾͿ��Բ�����\0��λ��

            if(i==0)
            {
                qDebug()<<"buf:"<<buf;
                qDebug()<<"i:"<<i<<"key:"<<temp[i].key<<endl;

            }
            if(i==1||i==2)
            {
                qDebug()<<"i:"<<i<<"key:"<<temp[i].key<<endl;
            }
        }else if(buf[0] == 'T')
        {
            temp[i].content = (char *)calloc(strlen(buf),sizeof(char));
            if(temp[i].content == NULL)
            {
               // fprintf(stderr,"û�п����ڴ���\n");
               // return 1;
                exit(-1);
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
int search(const word_t *data,int len,const char* find,char *output)
{
    if(data== NULL || len <1 || find == NULL)
        return 1;

    qDebug()<<"3";
    //format(find);
    int i;
    for(i=0;i< len;++i)
    {
        if(i==0||i==10)
        {
        qDebug()<<"i"<<i;
        qDebug()<<"data[i].key:"<<data[i].key;
        qDebug()<<"find:"<<find;
        }

        //��Ϊ�����Ѿ��������ַ���ǰ��Ŀհ��ַ�ȫ��ȥ�� ���ԾͿ�����ȫ�ľ�ȷƥ����
        if(strcmp(data[i].key,find) == 0)
        {
            //            printf("word %s found\n",find);
            //            printf("trans:%s\n",data[i].content);
            qDebug()<<"4";
            strcpy(output,data[i].content);
            break;
        }
    }
    if(i == len)
    {
        //printf("not found\n");
        strcpy(output,"not found\n");
    }
    return 0;
}
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
FILE *fp=NULL;
word_t *word =NULL;
int word_count=0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    FILE *fp = fopen("d:\\dict_utf8a.txt","r");
    if(fp == NULL)
    {
        qDebug()<<"fopen fails"<<endl;
        // fprintf(stderr,"file not found\n");
        exit(-1);
    }
    readData(fp,&word,&word_count);
    qDebug()<<"word.key:"<<QString(word->key);
      qDebug()<<"word.content:"<<QString(word->content);
    if(word == NULL)
    {
        // fprintf(stderr,"createSpace(WORD_COUNT) failed\n");
        //  return 1;
        exit(-1);
    }
    //char input[64] = {0};
    ui->setupUi(this);
}

Widget::~Widget()
{
    freeSpace(word,word_count);
    if(fp )
        fclose(fp);
    fp = NULL;
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()){
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::on_pushButton_clicked()
{
    // QMessageBox::information(NULL,"hi","yue ma");
    //��������ϵĲ�ѯ��ť���ͻ�ִ������Ĵ���
//    char content[1024] = { 0 };

//    QTextCodec *codec = QTextCodec::codecForName("GBK");//����һ����UTF8��GBKת��������

//    QString input_utf8 = ui->lineEdit->text();//input ��UTF8�����
//    QString input_gbk = codec->fromUnicode(input_utf8);
//    std::string cppstring = input_gbk.toStdString();
//    const char * data = cppstring.c_str(); //��ȡC++�ַ����е�char�׵�ַ

//    search(word,word_count,data,content);

//    search(word,word_count,QString(codec->fromUnicode(ui->lineEdit->text())).toStdString().c_str(),content);
//    //content������GBK��ʽ���ַ���   ������Ҫ��������ĺ���ת��ΪUTF-8���� ������ʾ
//    ui->label->setText(codec->toUnicode(content));
    char content[1024] = { 0 };

        QTextCodec *codec = QTextCodec::codecForName("GBK");//����һ����UTF8��GBKת��������

        QString input_utf8 = ui->lineEdit->text();//input ��UTF8�����
        QString input_gbk = codec->fromUnicode(input_utf8);
        std::string cppstring = input_gbk.toStdString();
        const char * data = cppstring.c_str(); //��ȡC++�ַ����е�char�׵�ַ
        qDebug()<<"word searched:"<<input_utf8;
         qDebug()<<"data:"<<data;
         qDebug()<<"word_count:"<<word_count;
        search(word,word_count,data,content);

        qDebug()<<QString(content);
        //content������GBK��ʽ���ַ���   ������Ҫ��������ĺ���ת��ΪUTF-8���� ������ʾ
        ui->label->setText(codec->toUnicode(content));

        //ui->lineEdit->text();//�õ��û���edit����������ݣ�������QString��QString��QT�ṩ��һ���ַ�����
        //qtĬ�ϵ��ַ�������UTF8�����
}

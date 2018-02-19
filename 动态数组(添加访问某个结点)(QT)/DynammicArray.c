#include"DynammicArray.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * struct DynamicArray
{
    void **DArray;//��������ѿռ䣬�ѵĵ�λԪ����void *
    int Capacity;//��̬���������
    int Size;//��̬����Ĵ�С
};
 *
 * */
//��ʼ����̬����
void *InitDynamicArray()
{
    //����ָ�����ָ��һ����̬����
    struct DynamicArray *PDArray=(struct DynamicArray *)malloc(sizeof(struct DynamicArray));
    memset(PDArray,0,sizeof(struct DynamicArray));


    //����������ָ������ѿռ�洢ָ������
    PDArray->DArray=(void *)malloc(6*sizeof(void *));
    memset(PDArray->DArray,0,sizeof(void *)*6);

    PDArray->Capacity=6;
    PDArray->Size=0;
    return PDArray;
}

//��̬�������Ԫ��
void InsertDynamicArray(struct DynamicArray *PDArray,int Pos,void *Data)
{
    if(NULL==PDArray)
    {
        return;
    }
    if(NULL==Data)
    {
        return;
    }
    if(Pos>PDArray->Size-1&&(PDArray->Size!=0))//Ŀ���ǲ���PosС����
    {
        Pos=PDArray->Size-1;
    }
    if(Pos<0)
    {
        Pos=0;
    }


    //��������ǰҪ�ȼ�鶯̬�����е�Size��Capacity�Ƿ���ȣ������ȣ���ζ��̬����ռ䲻���Դ洢�µ�����
    //��Ҫ��������ռ�

    if(PDArray->Capacity==PDArray->Size)
    {
        //����2����Capacity�Ķѿռ䣬��������void *
        void **NewDArray=(void **)malloc(2*sizeof(void *)*(PDArray->Capacity));
        memset(NewDArray,0,2*(PDArray->Capacity)*sizeof(void *));

        //��ԴDArray�е����ݿ������µĿռ���
        memcpy(NewDArray,PDArray->DArray,(PDArray->Capacity)*sizeof(void *));

        //�ͷŵ�DArrayָ��Ķѿռ�
        free(PDArray->DArray);

        //DArrayָ��NewDArray
        PDArray->DArray=NewDArray;
    }

    //�����µ�����,���ڶ�̬�������ͨ���±�ֱ�ӷ��ʣ�������ͬ���Բ���Ҫ�����ҵ�λ�ã��������ȱ���Ҫ��posλ�ô�Ԫ�ص����һ��Ԫ��֮�������Ԫ�غ���һλ�����Ҵ����һ��Ԫ�ؿ�ʼ��
    int i=0;
    for(i=PDArray->Size-1;i>Pos-1;i--)
    {
            PDArray->DArray[i+1]=PDArray->DArray[i];
    }
    //�����µ�����
    PDArray->DArray[i+1]=Data;
    //����̬���鳤�ȼ�1
    PDArray->Size++;

}

//ɾ����̬����ָ��λ�õ�Ԫ��
void DeleteDynamicArray(struct DynamicArray *PDArray,int Pos)
{
    if(NULL==PDArray)
    {
        return;
    }
    if(Pos<0||Pos>PDArray->Size-1)
    {
        return;
    }

    //ֱ��ͨ�����ǵķ�ʽɾ��Ԫ�أ�����ǰ��,��鷢�ֵ�i=PDArray->Size-1ʱ��i+1�Ѿ�Խ�磬����i���Ͻ�Ҫ����
    int i=0;
    for(i=Pos;i<PDArray->Size-1;i++)
    {
        PDArray->DArray[i]=PDArray->DArray[i+1];
    }
    //��βԪ�ص��������ɿ�
    PDArray->DArray[i]=NULL;
    //�ı�Size
    PDArray->Size--;
}

//�Զ�̬�������,��ָ�������ĺ���������ٺ���ԭ����Ӧ�ö��庯��ָ��
void VisitEachNode(struct DynamicArray *PDArray,VISITFUNCTION VisitFunction)
{
    if(NULL==PDArray)
    {
        return;
    }

    if(NULL==VisitFunction)
    {
        return;
    }
    //ע���κ����ݽṹ��Size����0����û��Ҫ�����ˣ���̬���������������
    if(0==PDArray->Size)
    {
        return;
    }
    //VISITFUNCTION���͵ĺ����β�ʵvoid *Data�����Ա���ѭ��ʹ�ø����ͺ���������ʵ�ֱ���
    int i=0;
    for(i=0;i<PDArray->Size;i++)
    {
        VisitFunction(PDArray->DArray[i]);
    }

    return;
}
 //����ָ��λ�õ�Ԫ��
 void * VisitCertainNode(struct DynamicArray *PDArray,int Pos)
 {
     if(NULL==PDArray)
     {
         return NULL;
     }

     //ע���κ����ݽṹ��Size����0����û��Ҫ�����ˣ���̬���������������
     if(0==PDArray->Size)
     {
         return NULL;
     }
     if(Pos<0||Pos>PDArray->Size-1)
     {
         return NULL;
     }
     //VISITFUNCTION���͵ĺ����β�ʵvoid *Data�����Ա���ѭ��ʹ�ø����ͺ���������ʵ�ֱ���



     return PDArray->DArray[Pos];
 }

/*
 * struct DynamicArray
{
    void **DArray;//��������ѿռ䣬�ѵĵ�λԪ����void *
    int Capacity;//��̬���������
    int Size;//��̬����Ĵ�С
};
 *
 * */
 //���Ԫ�ظ���
 int GetSize(struct DynamicArray *PDArray)
 {
     if(NULL==PDArray)
     {
         return -1;
     }
     return PDArray->Size;
 }

//���ٶ�̬����
void DestroyDynamicArray(struct DynamicArray *PDArray)
{
    if(NULL==PDArray)
    {
        return;
    }
    free(PDArray->DArray);
    PDArray->DArray=NULL;
    free(PDArray);//ע�����PDArray����ָ�����ͣ��Ͳ������ͷŶ�̬����Ķѿռ䣬��̬���鱾��Ҳ���ڶѿռ�洢
    PDArray=NULL;
    return;
}

#pragma once

//����һ���ṹ�����ͣ���Ϊ��̬����
struct DynamicArray
{
    void **DArray;//��������ѿռ䣬�ѵĵ�λԪ����void *
    int Capacity;//��̬���������
    int Size;//��̬����Ĵ�С
};
//���庯��ָ������
typedef void (*VISITFUNCTION)(void *Data);
//Ϊ�˱��ָô����ܱ�C++����������
#ifdef __cplusplus
extern "C"{
#endif
        //��ʼ����̬����
        void *InitDynamicArray();
        //��̬����ָ��λ�ò���Ԫ��
        void InsertDynamicArray(struct DynamicArray *PDArray,int Pos,void *Data);
        //ɾ����̬����ָ��λ�õ�Ԫ��
        void DeleteDynamicArray(struct DynamicArray *PDArray,int Pos);
        //�Զ�̬�������
        void VisitEachNode(struct DynamicArray *PDArray,VISITFUNCTION VisitFunction);
        //����ָ��λ�õ�Ԫ��
        void* VisitCertainNode(struct DynamicArray *PDArray,int Pos);
        //���Ԫ�ظ���
        int GetSize(struct DynamicArray *PDArray);
        //���ٶ�̬����
        void DestroyDynamicArray(struct DynamicArray *PDArray);


#ifdef __cplusplus
}
#endif


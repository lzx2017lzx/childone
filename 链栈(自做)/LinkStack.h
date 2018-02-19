#pragma once
//������ջ�Ľṹ��
struct LinkStackNode
{
    void *Data;
    struct LinkStackNode *PLSNode;
};

//����ṹ���������й���
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};

#ifdef __cplusplus
extern "C"{
#endif
        //��ʼ������
        void *InitLStack();
        //��ջͷ��������
        void InsertLStack(struct LinkStack *LStack,void *Data);
        //����ջͷԪ��
        void VisitLStack(struct LinkStack *LStack,void(*VISITLLNode)(void *Data));
        //����ջͷԪ��
        void PopLStack(struct LinkStack *LStack);
        //������ջ�ߴ�
        int SizeLStack(struct LinkStack *LStack);
        //������ջ
        void DestroyLStack(struct LinkStack *LStack);


#ifdef __cplusplus
}
#endif


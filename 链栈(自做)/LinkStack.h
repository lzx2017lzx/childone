#pragma once
//构建链栈的结构体
struct LinkStackNode
{
    void *Data;
    struct LinkStackNode *PLSNode;
};

//定义结构体对链表进行管理
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};

#ifdef __cplusplus
extern "C"{
#endif
        //初始化链表
        void *InitLStack();
        //向栈头插入数据
        void InsertLStack(struct LinkStack *LStack,void *Data);
        //访问栈头元素
        void VisitLStack(struct LinkStack *LStack,void(*VISITLLNode)(void *Data));
        //弹出栈头元素
        void PopLStack(struct LinkStack *LStack);
        //访问链栈尺寸
        int SizeLStack(struct LinkStack *LStack);
        //销毁链栈
        void DestroyLStack(struct LinkStack *LStack);


#ifdef __cplusplus
}
#endif


#pragma once
//�ýṹ�嶨�����
#define MAXSIZE 1000
struct SeqQue
{
	void *Data[MAXSIZE];
	int Size;
};
typedef void *LinkQueue;
#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ��
	LinkQueue Init_LinkQueue();
	//���
	int Push_LinkQueue(LinkQueue queue, void *data);
	//����
	int Pop_LinkQueue(LinkQueue queue);
	//��ö�ͷԪ��
	void *Front_LinkQueue(LinkQueue queue);
	//��ö�βԪ��
	void *Back_LinkQueue(LinkQueue queue);
	//��С
	int Size_LinkQueue(LinkQueue queue);
	//����
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif
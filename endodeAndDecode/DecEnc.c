#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"des.h"
void menu()
{
	printf("================\n");
	printf("1�������ļ�\n");
	printf("2�������ļ�\n");
	printf("3������\n");
	printf("4���˳�\n");
	printf("================\n");
}
void myDesEnc()
{
	char Org_Fil[200] = { 0 };
	char Des_Fil[200] = { 0 };
	printf("������Ҫ���ܵ��ļ���:\n");
	scanf("%s", Org_Fil);
	printf("��������ܺ���ļ���:\n");
	scanf("%s", Des_Fil);

	//�����ļ�ָ����ļ�
	FILE *Org_fp = NULL;
	FILE *Des_fp = NULL;

	//���建������ȡ��Ϣ
	char buf_bef_Enc[1024*4] = { 0 };
	//���建�������ռ��ܺ����Ϣ
	char buf_aft_Enc[1024 * 8] = { 0 };

	//ѭ����Դ�ļ���ȡ��Ϣ
	Org_fp = fopen(Org_Fil, "rb");
	int ret = 0;
	int len = 0;
	int aft_len = 0;
	if (Org_fp == NULL)
	{
		perror("��ȡԴ�ļ�ʧ�ܡ�\n");
		goto END;
	}
	Des_fp = fopen(Des_Fil, "wb");
	if (Des_fp == NULL)
	{
		perror("����Ŀ���ļ�ʧ�ܡ�\n");
		goto END;
	}
	while (1)
	{
		len = fread(buf_bef_Enc, 1, 1024 * 4, Org_fp);
		if (len <1024*4)
		{
			ret = DesEnc((unsigned char *)buf_bef_Enc, len, (unsigned char *)buf_aft_Enc, &aft_len);
			if (ret != 0)
			{
				perror("���ܴ���.\n");
				printf("ret=%d", ret);
				goto END;
				//return ;
			}
			fwrite(buf_aft_Enc, 1, aft_len, Des_fp);
			break;
		}
		
		ret = DesEnc_raw((unsigned char *)buf_bef_Enc, len, (unsigned char *)buf_aft_Enc, &aft_len);
		if (ret != 0)
		{
			perror("���ܴ���.\n");
			printf("ret=%d", ret);
			goto END;
		}
		fwrite(buf_aft_Enc, 1, aft_len, Des_fp);
		memset(buf_aft_Enc, 0, sizeof(buf_aft_Enc));
		memset(buf_bef_Enc, 0, sizeof(buf_bef_Enc));
	}
END:
	if (Org_fp != NULL)
	{
		fclose(Org_fp);
	}
	if (Des_fp != NULL)
	{
		fclose(Des_fp);
	}
}

void myDesDec()
{
	char Org_Fil[200] = { 0 };
	char Des_Fil[200] = { 0 };
	printf("������Ҫ���ܵ��ļ���:\n");
	scanf("%s", Org_Fil);
	printf("��������ܺ���ļ���:\n");
	scanf("%s", Des_Fil);

	//�����ļ�ָ����ļ�
	FILE *Org_fp = NULL;
	FILE *Des_fp = NULL;

	//���建������ȡ��Ϣ
	char buf_bef_Dec[1024 * 4] = { 0 };
	//���建�������ռ��ܺ����Ϣ
	char buf_aft_Dec[1024 * 8] = { 0 };

	//ѭ����Դ�ļ���ȡ��Ϣ
	Org_fp = fopen(Org_Fil, "rb");
	int ret = 0;
	int len = 0;
	int aft_len = 0;
	if (Org_fp == NULL)
	{
		perror("��ȡԴ�ļ�ʧ�ܡ�\n");
		goto END;
	}
	Des_fp = fopen(Des_Fil, "wb");
	if (Des_fp == NULL)
	{
		perror("����Ŀ���ļ�ʧ�ܡ�\n");
		goto END;
	}
	while (1)
	{
		len = fread(buf_bef_Dec, 1, 1024 * 4, Org_fp);
		if (len <1024 * 4)
		{
			ret = DesDec((unsigned char *)buf_bef_Dec, len, (unsigned char *)buf_aft_Dec, &aft_len);
			if (ret != 0)
			{
				perror("����ʧ��.\n");
				return ;
			}
			fwrite(buf_aft_Dec, 1, aft_len, Des_fp);
			break;
		}

		ret = DesDec_raw((unsigned char *)buf_bef_Dec, len, (unsigned char *)buf_aft_Dec, &aft_len);
		if (ret != 0)
		{
			perror("����ʧ��.\n");
			return ;
		}
		fwrite(buf_aft_Dec, 1, aft_len, Des_fp);
		memset(buf_aft_Dec, 0, sizeof(buf_aft_Dec));
		memset(buf_bef_Dec, 0, sizeof(buf_bef_Dec));
	}
END:
	if (Org_fp != NULL)
	{
		fclose(Org_fp);
	}
	if (Des_fp != NULL)
	{
		fclose(Des_fp);
	}


}
int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("������cmd: ");
		scanf("%d", &cmd);
		switch (cmd)
		{
			case 1:
				myDesEnc();
				break;
			case 2:
				myDesDec();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
		
	}
	printf("\n");
	system("pause");
	return 0;
}

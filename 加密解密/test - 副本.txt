#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"des.h"
#if 0
int main(void)
{
	unsigned char src[] = "abcdefg";
	int src_len = strlen(src);
	unsigned char dst[512] = { 0 };

	int des_len = 0;
	int ret;

	ret = DesEnc(src, src_len, dst, &des_len);
	if (ret != 0)
	{
		printf("Des_Enc err=%d\n", ret);
		return -1;
	}
	printf("加密后的内存:@%s@\n", dst);
	printf("加密后的长度:len=%d\n", des_len);

	memset(src, 0, sizeof(src));
	src_len = 0;

	ret = DesDec(dst, des_len, src, &src_len);
	if (ret != 0)
	{
		printf("DesDec err:%d\n", ret);
		return -1;
	}

	printf("解密后的内容:%s\n", src);
	printf("解密后的长度:len=%d\n", src_len);



	printf("\n");
	system("pause");
	return 0;
}


#endif
#if 0
//int DesEnc(
	//unsigned char *pInData,
	//int            nInDataLen,
	//unsigned char *pOutData,
	//int           *pOutDataLen);
int main(void)
{
	char buf[] = "李宗鑫";
	int buf_len = strlen(buf);

	char buf_de[512] = { 0 };
	int buf_de_len = 0;

	char buf_co[512] = { 0 };
	int buf_co_len = 0;

	int ret = DesEnc(buf, buf_len, buf_de, &buf_de_len);
	if (ret != 0)
	{
		printf("DesEnc err:%d\n",ret);
		return -1;
	}
	printf("DesEnc:%s\n", buf_de);
	printf("lenthfor DesEnc:%d\n", buf_de_len);

	ret = DesDec(buf_de, buf_de_len, buf_co, &buf_co_len);
	if (ret != 0)
	{
		printf("DesDnc err:%d\n", ret);
		return -1;
	}
	printf("DesDnc:%s\n", buf_co);
	printf("lenthofr DesDnc:%d\n", buf_co_len);
	
	printf("\n");
	system("pause");
	return 0;
}



#endif

#if 1
void menu()
{
	printf("============================");
	printf("1、加密文件\n");
	printf("2、解密文件\n");
	printf("3、清屏\n");
	printf("4、退出\n");
	printf("============================");
}

void DesEncFile()
{
	char src_path[512] = { 0 };
	char dst_path[512] = { 0 };
	printf("请输入要加密的文件.\n");
	scanf("%s", src_path);
	printf("请输入要加密后的文件.\n");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src\n");
		goto END;
	}
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst\n");
		goto END;
	}

	int len;
	char buf[1024 * 4] = { 0 };

	unsigned char dst[1024 * 8] = { 0 };
	int dst_len;
	int ret;

	while (1)
	{
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024 * 4)
		{
			ret = DesEnc((unsigned char *)buf, len, dst, &dst_len);
			if (ret != 0)
			{
				printf("DesEnc ret=%d\n", ret);
				goto END;
			}

			fwrite(dst, 1, dst_len, dst_fp);
			break;
		}
		ret = DesEnc_raw((unsigned char *)buf, len, dst, &dst_len);
		if (ret != 0)
		{
			printf("DesEncraw ret=%d\n", ret);
			goto END;
		}

		fwrite(dst, 1, dst_len, dst_fp);
	}

END:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}
}

void DesDec_file()
{
	char src_path[512] = { 0 };
	char dst_path[512] = { 0 };
	printf("请输入要加密的文件.\n");
	scanf("%s", src_path);
	printf("请输入要加密后的文件.\n");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src\n");
		goto END;
	}
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst\n");
		goto END;
	}

	int len;
	char buf[1024 * 4] = { 0 };

	unsigned char dst[1024 * 8] = { 0 };
	int dst_len;
	int ret;

	while (1)
	{
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024 * 4)
		{
			ret = DesDec((unsigned char *)buf, len, dst, &dst_len);
			if (ret != 0)
			{
				printf("DesEnc ret=%d\n", ret);
				goto END;
			}

			fwrite(dst, 1, dst_len, dst_fp);
			break;
		}
		ret = DesDec_raw((unsigned char *)buf, len, dst, &dst_len);
		if (ret != 0)
		{
			printf("DesDecraw ret=%d\n", ret);
			goto END;
		}

		fwrite(dst, 1, dst_len, dst_fp);
	}

END:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}


}
int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("cmd: ");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			DesEncfile();
			break;
		case 2:
			DesDec_file();
			break;
		case 3:
			system("cls");
			break;
		case 4:
			exit(0);
		}

	}

	printf("\n");
	system("pause");
	return 0;
}

	 	


#endif





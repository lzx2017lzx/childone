#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"itcast_asn1_der.h"
#include"itcastderlog.h"

typedef struct Worker
{
	char name[32];
	int age;
	char *resume;
	int resumelen;

}Worker_t;


//ITCAST_INT
//DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);
//ITCAST_INT
//DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf, unsigned char *strOrigin, int strOriginLen);
//ITCAST_INT
//DER_ItAsn1_WriteInteger(ITCAST_UINT32 integer, ITASN1_INTEGER **ppDerInteger);


//ITCAST_INT
//DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);

//ITCAST_INT
//DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);


//DER_ItAsn1_WriteSequence(ITASN1_SEQUENCE *pSequence, ITCAST_ANYBUF **ppDerSequence);
int EncWorker(Worker_t *pworker, unsigned char**pout, int *poutlen)
{
	ITCAST_ANYBUF*phead = NULL;
	ITCAST_ANYBUF*pphead = NULL;
	ITCAST_ANYBUF *pfin = NULL;


	//编码name
	int ret = DER_ITCAST_String_To_AnyBuf(&phead, pworker->name, strlen(pworker->name)+1);//注意strlen(pworker->name)+1不需要加上1，防止解码后因没有\0，不能读出字符串
	if (ret != 0)
	{
		if(phead!=NULL)DER_ITCAST_FreeQueue(phead);
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -1;
	}

	//printf("1%s\n", phead->pData);

	ret=DER_ItAsn1_WritePrintableString((ITASN1_PRINTABLESTRING *)phead, (ITASN1_PRINTABLESTRING **)&pphead);
	if (ret != 0)
	{
		if (phead != NULL)DER_ITCAST_FreeQueue(phead);
		if (pphead != NULL)DER_ITCAST_FreeQueue(pphead);
		printf("DER_ItAsn1_WritePrintableString error:ret=%d\n", ret);
		return -2;
	}
	if (phead != NULL)DER_ITCAST_FreeQueue(phead);

	ITCAST_ANYBUF*ptemp = NULL;
	ptemp = pphead;
	//编码age
	ret = DER_ItAsn1_WriteInteger((ITCAST_UINT32)pworker->age, (ITASN1_INTEGER **)&(ptemp->next));
	if (ret != 0)
	{
		if (pphead != NULL)DER_ITCAST_FreeQueue(pphead);
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -3;
	}

	//printf("2%s\n", ptemp->next->pData);
	ptemp = ptemp->next;
	//编码resume
	/* ret = DER_ITCAST_String_To_AnyBuf(ptemp, pworker->resume, strlen(pworker->resume));
	if (ret != 0)
	{
	printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
	return -3;
	}*/
	//DER_ItAsn1_WritePrintableString((ITASN1_PRINTABLESTRING *)pPrin, ITASN1_PRINTABLESTRING **ppDerPrintString);

	ret = EncodeChar(pworker->resume, strlen(pworker->resume), (ITCAST_ANYBUF **)&(ptemp->next));
	if (ret != 0)
	{
		if (pphead != NULL)DER_ITCAST_FreeQueue(pphead);
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -4;
	}

	//printf("3%s\n", ptemp->next->pData);
	ptemp = ptemp->next;
	//编码resumelen
	ret = DER_ItAsn1_WriteInteger((ITCAST_UINT32)pworker->resumelen, (ITASN1_INTEGER **)&(ptemp->next));
	if (ret != 0)
	{
		if (pphead != NULL)DER_ITCAST_FreeQueue(pphead);
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -5;
	}

	//printf("4%s\n", ptemp->next->pData);
	
	
	ret=DER_ItAsn1_WriteSequence((ITASN1_SEQUENCE *)pphead, (ITCAST_ANYBUF **)&pfin);
	if (ret != 0)
	{
		if (pphead != NULL)DER_ITCAST_FreeQueue(pphead);
		if (pfin != NULL)DER_ITCAST_FreeQueue(pfin);
		printf("DER_ItAsn1_WriteSequence error:ret=%d\n", ret);
		return -6;
	}

	*pout = pfin->pData;
	*poutlen = pfin->dataLen;
	//printf("--%s--\n", *pout);
	return 0;
}

void WriteFile(unsigned char *p, int len)
{
	FILE *fp = fopen("g://mm.ber", "w+");
	if (fp == NULL)
	{
		perror("fopen\n");
	}

	//char buf[1024] = { 0 };

	int lensum = strlen(p);
	
	while (1)
	{
		int temp = lensum > 1024 ? 1024 : lensum;
		int ret=fwrite(p, 1, temp, fp);
		if (ret < 0)
		{
			perror("fwrite\n");
			return;
		}

		p = p + ret;
		lensum -= ret;
		if (lensum <= 0)
		{
			return;
		}
	}

	fclose(fp);

}


int DesWorker(Worker_t *pworker, unsigned char*pin, int pinlen)
{
	//生成ANYBUF
	ITCAST_ANYBUF*panybuf = NULL;
	ITCAST_ANYBUF*readsequence = NULL;
	ITCAST_ANYBUF*phead = NULL;
	ITCAST_ANYBUF*ptemp = NULL;

	//printf("pin:%s\n", pin);
	//printf("pinlen:%d\n", pinlen);
	int ret = DER_ITCAST_String_To_AnyBuf((ITCAST_ANYBUF **)&panybuf, pin, pinlen);
	if (ret != 0)
	{
		if (panybuf != NULL)DER_ITCAST_FreeQueue(panybuf);
		printf("DER_ITCAST_String_To_AnyBuf:%d\n", ret);
		return -1;
	}

	//printf("panybuf:%s\n", panybuf->pData);
	//解sequence
	ret = DER_ItAsn1_ReadSequence(panybuf, (ITASN1_SEQUENCE **)&readsequence);
	if (ret != 0)
	{
		if (panybuf != NULL)DER_ITCAST_FreeQueue(panybuf);
		if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}
	if (panybuf != NULL)DER_ITCAST_FreeQueue(panybuf);
	//printf("readsequence:%s\n", readsequence->pData);

	ptemp = readsequence;
	//解name
	ret = DER_ItAsn1_ReadPrintableString((ITASN1_PRINTABLESTRING *)readsequence, (ITASN1_PRINTABLESTRING **)&phead);
	if (ret != 0)
	{
		if (phead != NULL)DER_ITCAST_FreeQueue(phead);
		if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}

	//memcpy(pworker->name, phead->pData, strlen(phead->pData));
	strcpy(pworker->name, phead->pData);
	//pworker->name[strlen(pworker->name)] = '\0';
	//printf("------pworker->name:%s-----%d-----\n", pworker->name,strlen(pworker->name));
	//printf("------phead->pDa:%d-----\n", pworker->name, strlen(pworker->name));

	ptemp = ptemp->next;
	if (phead != NULL)DER_ITCAST_FreeQueue(phead);

	//解整数age
	ret = DER_ItAsn1_ReadInteger((ITASN1_INTEGER *)ptemp, &(pworker->age));
	if (ret != 0)
	{
		if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}

	//printf("pworker->age:%d\n", pworker->age);

	ptemp = ptemp->next;
	//解resume
	ret = DecodeChar((ITASN1_INTEGER *)ptemp, &(pworker->resume), &(ptemp->dataLen));
	if (ret != 0)
	{
		if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}
	
	
	
	//	printf("pworker->resume:%s\n", pworker->resume);
	ptemp = ptemp->next;

	//解resumelen
	ret = DER_ItAsn1_ReadInteger((ITASN1_INTEGER *)ptemp, &(pworker->resumelen));
	if (ret != 0)
	{
		if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}
	if (readsequence != NULL)DER_ITCAST_FreeQueue(readsequence);

	//printf("pworker->resumelen:%d\n", pworker->resumelen);

	return 0;

}
int main()
{
	//初始化数据
	Worker_t worker;
	Worker_t worker1 = {0};
	strcpy(worker.name, "lihua");
	worker.age = 18;
	worker.resume = (char *)malloc(1024);
	memset(worker.resume, 0, 1024);
	strcpy(worker.resume, "i am a graduate student.And i think that i have the ability to join in your company");

	worker.resumelen = strlen(worker.resume);


	unsigned char* pout = NULL;
	int poutlen = 0;
	int ret = EncWorker(&worker, &pout, &poutlen);//注意这里的poutlen是anybuf结构体内的长度记录,不是里面的char *data类型的数据
	if (ret != 0)
	{
		printf("EncWorker error:ret=%d\n", ret);
		return -1;
	}
	WriteFile(pout, poutlen);
	printf("------worker.name%s------\n", worker.name);
	printf("------worker.age%d-------\n", worker.age);
	printf("------worker.resume%s-------\n", worker.resume);
	printf("------worker.resumelen%d--------\n", worker.resumelen);
	DesWorker(&worker1, pout, poutlen);//注意这里的poutlen是anybuf结构体内的长度记录

	printf("-----%s-----\n", pout);
	printf("-----%d-----\n", poutlen);

	printf("------worker1.name%s------%d----\n", worker1.name,strlen(worker1.name));
	printf("------worker1.age%d-------\n", worker1.age);
	printf("------worker1.resume%s-------\n", worker1.resume);
	printf("------worker1.resumelen%d--------\n", worker1.resumelen);

	if ((strcmp(worker.name, worker1.name) == 0) && (strcmp(worker.resume, worker1.resume) == 0))
	{
		printf("编码==解码\n");
	}
	else
	{
		printf("编码!=解码\n");
	}
	
	system("pause");
	return 0;
}
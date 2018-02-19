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


	//±àÂëname
	int ret = DER_ITCAST_String_To_AnyBuf(&phead, pworker->name, strlen(pworker->name));
	if (ret != 0)
	{

		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -1;
	}

	printf("1%s\n", phead->pData);

	ret=DER_ItAsn1_WritePrintableString((ITASN1_PRINTABLESTRING *)phead, (ITASN1_PRINTABLESTRING **)&pphead);
	if (ret != 0)
	{

		printf("DER_ItAsn1_WritePrintableString error:ret=%d\n", ret);
		return -2;
	}

	ITCAST_ANYBUF*ptemp = NULL;
	ptemp = pphead;
	//±àÂëage
	ret = DER_ItAsn1_WriteInteger((ITCAST_UINT32)pworker->age, (ITASN1_INTEGER **)&(ptemp->next));
	if (ret != 0)
	{
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -3;
	}

	printf("2%s\n", ptemp->next->pData);
	ptemp = ptemp->next;
	//±àÂëresume
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
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -4;
	}

	printf("3%s\n", ptemp->next->pData);
	ptemp = ptemp->next;
	//±àÂëresumelen
	ret = DER_ItAsn1_WriteInteger((ITCAST_UINT32)pworker->resumelen, (ITASN1_INTEGER **)&(ptemp->next));
	if (ret != 0)
	{
		printf("DER_ITCAST_String_To_AnyBuf error:ret=%d\n", ret);
		return -5;
	}

	printf("4%s\n", ptemp->next->pData);
	
	
	ret=DER_ItAsn1_WriteSequence((ITASN1_SEQUENCE *)pphead, (ITCAST_ANYBUF **)&pfin);
	if (ret != 0)
	{
		printf("DER_ItAsn1_WriteSequence error:ret=%d\n", ret);
		return -6;
	}

	*pout = pfin->pData;
	*poutlen = pfin->dataLen;
	printf("--%s--\n", *pout);
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

int main()
{
	//³õÊ¼»¯Êý¾Ý
	Worker_t worker;
	strcpy(worker.name, "lihua");
	worker.age = 18;
	worker.resume = (char *)malloc(1024);
	memset(worker.resume, 0, 1024);
	strcpy(worker.resume, "i am a graduate student.And i think that i have the ability to join in your company");

	worker.resumelen = strlen(worker.resume);


	unsigned char* pout = NULL;
	int poutlen = 0;
	int ret = EncWorker(&worker, &pout, &poutlen);
	if (ret != 0)
	{
		printf("EncWorker error:ret=%d\n", ret);
		return -1;
	}


	WriteFile(pout, poutlen);
	printf("-----%s-----\n", pout);
	printf("-----%d-----\n", poutlen);

	
	system("pause");
	return 0;
}
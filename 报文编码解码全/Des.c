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


int ReadFile(unsigned char **readout, int *preadlen)
{
	FILE *fp = fopen("g://mm.ber", "r");
	if (fp == NULL)
	{
		perror("fopen\n");
		return -1;
	}

	char buf[1024] = { 0 };
	int ret=fread(buf, 1, sizeof(buf), fp);
	if (ret < 0)
	{
		perror("fread\n");
		return -2;
	}

	*readout = (unsigned char *)calloc(strlen(buf) + 1, 1);

	memcpy(*readout, buf, strlen(buf));
	*preadlen = strlen(*readout)+1;
}
//DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);
//DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf,	unsigned char *strOrigin, int strOriginLen);

//ITCAST_INT
//DER_ItAsn1_ReadSequence(ITCAST_ANYBUF *pDerSequence, ITASN1_SEQUENCE **ppSequence);

//DER_ItAsn1_ReadInteger(ITASN1_INTEGER *pDerInteger, ITCAST_UINT32 *pInteger);


//int DecodeChar(ITCAST_ANYBUF *inBuf, char **Data, int *pDataLen);

//ITCAST_INT
//DER_ItAsn1_ReadPrintableString(ITASN1_PRINTABLESTRING *pDerPrintString, ITASN1_PRINTABLESTRING **ppPrintString);

int DesWorker(Worker_t *pworker, unsigned char*pin, int pinlen)
{
	//生成ANYBUF
	ITCAST_ANYBUF*panybuf = NULL;
	ITCAST_ANYBUF*readsequence = NULL;
	ITCAST_ANYBUF*phead = NULL;
	ITCAST_ANYBUF*ptemp = NULL;

	printf("pin:%s\n", pin);
	printf("pinlen:%d\n", pinlen);
	int ret = DER_ITCAST_String_To_AnyBuf((ITCAST_ANYBUF **)&panybuf,pin, pinlen);
	if (ret != 0)
	{
		printf("DER_ITCAST_String_To_AnyBuf:%d\n", ret);
		return -1;
	}

	printf("panybuf:%s\n", panybuf->pData);
	//解sequence
	 ret=DER_ItAsn1_ReadSequence(panybuf, (ITASN1_SEQUENCE **)&readsequence);
	if(ret!=0)
	{
		printf("DER_ItAsn1_ReadSequence:%d\n", ret);
		return -1;
	}
	printf("readsequence:%s\n", readsequence->pData);

	ptemp = readsequence;
	//解name
	DER_ItAsn1_ReadPrintableString((ITASN1_PRINTABLESTRING *)readsequence, (ITASN1_PRINTABLESTRING **)&phead);

	
	memcpy(pworker->name,phead->pData,strlen(phead->pData));

	printf("pworker->name:%s\n", pworker->name);

	ptemp = ptemp->next;

	//解整数age
	DER_ItAsn1_ReadInteger((ITASN1_INTEGER *)ptemp, &(pworker->age));

	printf("pworker->age:%d\n", pworker->age);

	ptemp = ptemp->next;
	//解resume
	DecodeChar((ITASN1_INTEGER *)ptemp, &(pworker->resume), &(ptemp->dataLen));
	printf("pworker->resume:%s\n", pworker->resume);
	ptemp = ptemp->next;

	//解resumelen
	DER_ItAsn1_ReadInteger((ITASN1_INTEGER *)ptemp, &(pworker->resumelen));
	printf("pworker->resumelen:%d\n", pworker->resumelen);

	return 0;

}

int main()
{
	Worker_t worker;
	unsigned char *src = NULL;
	int srclen = 0;
	ReadFile(&src, &srclen);
	printf("src:%s\n", src);
	printf("srclen:%d\n", srclen);
	DesWorker(&worker, src, srclen);

	printf("------%s------\n", worker.name);
	printf("------%d-------\n", worker.age);
	printf("------%s-------\n", worker.resume);
	printf("------%d--------\n", worker.resumelen);
	return 0;
}
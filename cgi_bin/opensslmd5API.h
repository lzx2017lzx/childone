#ifndef OPENSSLMD5API_H
#define OPENSSLMD5API_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<openssl/md5.h>

#ifdef __cplusplus
extern "C"
{
#endif

	unsigned char md5buf[MD5_DIGEST_LENGTH]={0};
	char sprinttemp[10]={0};
 	 char finaltemp[40]={0};
	MD5_CTX c;
	const  char*MYMD5( const char*buf)
	{
		memset(md5buf,0,sizeof(md5buf));
		memset(sprinttemp,0,sizeof(sprinttemp));
		memset(finaltemp,0,sizeof(finaltemp));
		MD5_Init(&c);

		MD5_Update(&c,buf,strlen(buf));
		MD5_Final(&(md5buf[0]),&c);
		for(int i=0;i<MD5_DIGEST_LENGTH;++i)
		{
				sprintf(sprinttemp,"%02x",md5buf[i]);
		strcat((char*)finaltemp,(const char*)sprinttemp);
		}
		return finaltemp;
	}

#ifdef __cplusplus
	}
#endif

#endif

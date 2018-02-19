#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<openssl/md5.h>

int main()
{
	MD5_CTX c;
	MD5_Init(&c);
	unsigned char buf[1024]="333";
	unsigned char md5buf[MD5_DIGEST_LENGTH];

	MD5_Update(&c,buf,strlen(buf));
	MD5_Final(&(md5buf[0]),&c);
for(int i=0;i<MD5_DIGEST_LENGTH;i++)
	printf("%02x",md5buf[i]);
	printf("\n");
	return 0;
}

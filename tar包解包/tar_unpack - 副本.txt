#include <string.h>
#include <stdio.h>
#include <math.h>
struct tar_header
{
    char name[100];//文件名
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12]; //文件大小的八进制数的字符串形式
    char mtime[12];
    char chksum[8];
    char typeflag;
    char linkname[100];
    char magic[6];
    char version[2];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char padding[12];
};


int zhuanhuan(char *str)
{
    int sum = 0;
    int i;
    for( i = 0; i < 11 ; ++i)
    {
        sum += (str[i] - '0') * (int)pow(8,10-i);
    }
    return sum;
}
int main(int argc,char **argv)
{
    if(argc <2)
    {
        fprintf(stderr,"USAGE %s tar_filename\n",argv[0]);
        return 1;
    }
    char buf[sizeof(struct tar_header)];
    FILE *fp = fopen(argv[1],"rb");
    if( fp == NULL )
    {
        fprintf(stderr,"file not found");
        return 0;
    }
    fread(buf,1,sizeof(struct tar_header),fp);
    struct tar_header * head = (struct tar_header *)buf;
    printf("name %s,size %s\n",head->name,head->size);
    int filelen = zhuanhuan(head->size);
    
    char fbuf[4096] = {0};
    int need_len ;
    FILE * newfile = fopen(head->name,"wb");
    while(filelen)//要求是将tar中的文件重新写到另一个文件，而且必须是以512字节的整数倍结尾。这个循环体能很好解决这个问题
 //主要是两个方面：一是、怎样将大于512字节的文件每次都用按12字节拷贝，而且最后小于512字节的一段按512字节拷贝；二是、怎样将
 //一个本来就不大于512字节的文件，按512字节拷贝。显然第二个问题是第一个问题的子问题。
	{
        memset(fbuf,0,sizeof(fbuf));
        need_len = sizeof(fbuf)>filelen?filelen:sizeof(fbuf);//确定每次拷贝的大小，如果文件长度大于容器大小，就
//取容器大小为要读的长度,如果文件长度小于容器大小，就选择文件长度大小作为要读的长度。可以用if else替换，但是？：表达式更合适与
//只有两个条件的情况。而且更简洁。
        fread(fbuf,1,need_len,fp);
        fwrite(fbuf,1,need_len,newfile);
        filelen -= need_len;//生成未读的文件长度
    }
    fclose(newfile);

    fclose(fp);
    return 0;
}

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

#define TAR_BASESIZE 10240
#define TAR_HEADSIZE sizeof(struct tar_header)

//fp表示tar文件游标 usesize表示已经占用的大小  tar_size是tar文件已经开辟的大小 need_size需要被打包的文件所占用的大小
#define CHECK_SIZE_AND_EXTEND(fp,usesize,tar_size,need_size)\
{\
    while( tar_size - usesize - 512 < need_size )\
    {   long int pos = ftell(fp);\
        fseek(fp,0,SEEK_END);\
        fseek(fp,TAR_BASESIZE-1,SEEK_END);\
        fputc(0,fp);\
        tar_size += TAR_BASESIZE;\
        fseek(fp,pos,SEEK_SET);\
    }\
}

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

void unpack(const char *tar_filename)
{
    char buf[sizeof(struct tar_header)];
    FILE *fp = fopen(tar_filename,"rb");
    if( fp == NULL )
    {
        fprintf(stderr,"file not found");
        return ;
    }

    char fbuf[512] = {0};
    struct tar_header * head = (struct tar_header *)buf;
    while(1)
    {
        
        memset(buf,0,sizeof(buf));

        fread(buf,1,sizeof(struct tar_header),fp);
        if(head->name[0] == '\0') //代表文件结束  读取到了空的tar_header数据
            break;

        printf("name %s,size %s\n",head->name,head->size);
        int filelen = zhuanhuan(head->size); //获取到指定文件的长度  长度存在于tar_header
    
        //读取文件
        int need_len ;

        FILE * newfile = fopen(head->name,"wb");
        if(newfile == NULL)
        {
            fprintf(stderr,"%s write faild\n",head->name);
            continue;
        }
        while(filelen >0)
        {
            memset(fbuf,0,sizeof(fbuf));
            need_len = sizeof(fbuf)>filelen?filelen:sizeof(fbuf);
            fread(fbuf,1,sizeof(buf),fp);
            fwrite(fbuf,1,need_len,newfile);
            filelen -= need_len;
        }
        fclose(newfile);
    }
    fclose(fp);
}
void set_magic_mode_checksum(struct tar_header *header)
{
         size_t i ;
         strcpy(header->magic,"ustar");
         int sum = 0; 
         sprintf(header->mode,"%07o",0400+0200+0040+0004); //0644
         char *buf = (char *)header;
         for (i = 0; i< (size_t)&(((struct tar_header*)NULL)->chksum); ++i)
		{
			sum += buf[i];
        }
        sum += sizeof(header->chksum)*0x20; //space
        for( i+= sizeof(header->chksum);i < TAR_HEADSIZE; ++i)
        {
            sum += buf[i];
        }
         sprintf(header->chksum,"%07o",sum);
}

int pack(const char *tar_name,int argc,char **argv)
{
    if(tar_name == NULL)
        return -1;

    //创建tar文件  tar_name是文件名
    FILE *tar_fp = fopen(tar_name,"wb");
    if(tar_fp == NULL)
    {
        fprintf(stderr,"%s can't create\n",tar_name);
        return -1;
    }
    int i;
    long len  = 0;
    long use  = 0;
    long tsize= 0;

    struct tar_header header = {0};
    char buf[512] = {0};
    for( i = 3 ; i < argc; ++i)
    {
        //argv[i] 是文件名
        //打开文件 并 获取文件大小  让文件读写位置 复位 
        FILE * sfp = fopen(argv[i],"rb");
        if(sfp == NULL)
        {
            fprintf(stdout,"%s file not found\n",argv[i]);
            continue;
        }
        fseek(sfp,0,SEEK_END);
        printf("%ld    \n",ftell(tar_fp));
        len = ftell(sfp);
        rewind(sfp);
        use +=  TAR_HEADSIZE;

        //根据文件大小 拓展文件   #define CHECK_SIZE_AND_EXTEND(fp,usesize,tar_size,need_size)
        CHECK_SIZE_AND_EXTEND(tar_fp,use,tsize,len);
        //构造tar头 
        memset(&header,0,TAR_HEADSIZE);
        strcpy(header.name,argv[i]);
        sprintf(header.size,"%011lo",len);
        set_magic_mode_checksum(&header);
        
        //写tar头
        fwrite(&header,TAR_HEADSIZE,1,tar_fp);

        //读取目标  写入tar文件
        memset(buf,0,sizeof(buf));
        while( 0 != fread(buf,1,TAR_HEADSIZE,sfp) )
        {
            fwrite(buf,1,TAR_HEADSIZE,tar_fp);
            memset(buf,0,sizeof(buf));
        }
        //计算出 占用的块  * TAR_HEADSIZE
        use   += ( len / 512  + len%512==0?0:1) * 512;

        fclose(sfp);
    }
    //写入tar文件结束标志 以0填充的header
    memset(buf,0,sizeof(buf));
    fwrite(buf,1,TAR_HEADSIZE,tar_fp);
    fclose(tar_fp);
    return 0;
}
int main(int argc,char **argv)
{
    if(argc <3)
    {
        fprintf(stderr,"USAGE %s [-xvf] tar_filename\n",argv[0]);
        return 1;
    }
    if( 0 == strncmp(argv[1],"-xvf",4))
    {
        unpack(argv[2]);
    }else if( 0 == strncmp(argv[1],"-cvf",4) )
    {
        //tar -cvf 1.tar m1.c m2.c m3.c
        pack(argv[2],argc,argv);
    } 
   return 0;
}

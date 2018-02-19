#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
//写入空头
//int write_empty_head()
//{
//	struct tar_header *str=(struct tar_header *)malloc(sizeof(struct tar_header));
//	memset(str,0,sizeof(struct tar_header));
//	fwrite(str,1,sizeof(struct tar_header),tp);
//	return 0;
//}
//按正确格式填写tar头
#define TAR_HEADSIZE sizeof(struct tar_header)
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
int pack_tar(char *file_name,FILE *tp)
{
	char *buf=(char *)calloc(1,sizeof(struct tar_header));
	//向头中写入文件信息，首先要获得文件信息
	//向头中填入文件的名，首先要用buf读取头信息，为此要将文件头游标回移y一个头的字节
	//tp=fopen(tar_name,"wb");
	fseek(tp,-sizeof(struct tar_header),SEEK_END);
	//fread(buf,1,sizeof(struct tar_header),tp);//如果文件是空，是不能fread出来的。
	//用一个头结构体指针指向它
	struct tar_header *thead=(struct tar_header *)buf;
	strcpy(thead->name,file_name);//将文件名放入缓冲区的名字符串里
	//将文件大小写进缓冲区
	FILE *fp=fopen(file_name,"rb");
	fseek(fp,0,SEEK_END);
//long int length=ftell(fp);
//return length;
	long int length=ftell(fp);//还要将size转换成12位8进制字符串，策略是直接用sprintf格式化输入
	sprintf(thead->size,"%011lo",length);//size中最后一个必须是空字符，剩余位要用零填补
	//按正确格式填写tar头
	set_magic_mode_checksum(thead);
	//将正确的tar头信息写入tar文件，先将tp中的文件游标回退一个头结构体大小
//	fseek(tp,-sizeof(struct tar_header),SEEK_END);
	fwrite(buf,sizeof(struct tar_header),1,tp);
	//文件头写好后，再清空buf缓冲区
	memset(buf,0,sizeof(struct tar_header));
	//开始将数据写入tar文件，首先要将fp指针置头，因为之前读取文件数据时，已经置尾，采用rewind函数
	rewind(fp);
	//先读一次,截止是fread返回的字节数是零
	while(fread(buf,1,sizeof(struct tar_header),fp)!=0)
	{
	//fread(buf,1,sizeof(struct tar_header),fp);
	fwrite(buf,1,sizeof(struct tar_header),tp);
	memset(buf,0,sizeof(struct tar_header));
	}
	//判断此时文件大小，先看符不符合扇区必须为512字节的倍数，等所有文件读写完毕后，再判断是否超过10240字节
//	length=ftell(tp);
	//设置变量need_length来表示拓展以后的文件长度，采用fseek来拓展
//	long int need_length=0;
//	if(length%512!=0)
//	{
//	need_length=(length/512+1)*512;
//	fseek(tp,need_length-length-1,SEEK_END);
//	fprintf(tp,"%s","\\0");
//	}
//	else
//	{
//	need_length=length;
//	}
//	fseek(tp,need_length-length-1,SEEK_END);
	//必须写入一个字符才能让拓展生效，即使是空字符也是如此
//	fread(buf,1,1,tp);
//	fprintf(tp,"%s","\\0");
	//在某尾写入一个空的文件头
//	 write_empty_head();
	 struct tar_header *str=(struct tar_header *)malloc(sizeof(struct tar_header));
	 memset(str,0,sizeof(struct tar_header));
	 fwrite(str,1,sizeof(struct tar_header),tp);
	free(str);
//	fclose(tp);
	fclose(fp);
	return 0;
}
int main(int argc,char **args)//先打包一个文件
{
	if(argc<4)
	{
	return 0;
	}
	int i=0;
	if(strcmp(args[1],"-cvf")==0)
	{
	FILE *tp=fopen(args[2],"wb");
	struct tar_header *str=(struct tar_header *)malloc(sizeof(struct tar_header));
	memset(str,0,sizeof(struct tar_header));
	fwrite(str,1,sizeof(struct tar_header),tp);
	free(str);
//	fclose(tp);
	//以tar_name名创建新文件
//	FILE *tp=fopen(args[2],"wb");
	//先向要创建的tar文件写入结构体的头
	//write_empty_head();
	for(i=3;i<argc;i++)	
	pack_tar(args[i],tp);//file_name是要打包的文件名
	//判断文件是否是10240的倍数，如果不是要添加空字符到10240的倍数
	fseek(tp,0,SEEK_END);
	long int length=ftell(tp);
	printf("%ld",length);
	long int need_length=0;
	//用need_length来存储应该要表示的倍数
	if(length%10240!=0)
	{
	need_length=(length/10240+1)*10240;
	fseek(tp,need_length-length-1,SEEK_END);
//	fprintf(tp,"%s","\\0");//为什么这种办法不行，无法拓展文件
	fputc(0,tp);
	}else
	{
	need_length=length;
	}
	fclose(tp);
	}
	else
	{
	printf("the order is not right.\n");
	};
	return 0;
}

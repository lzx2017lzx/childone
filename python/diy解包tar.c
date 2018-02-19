#include<string.h>
#include<stdio.h>
#include<math.h>
struct tar_header
{
	char name[100];
	char mode[8];
	char uid[8];
	char gid[8];
	char size[12];
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
int zhuanhuan(char *str)//将表示数字的字符串转化为整数(字符通过与零字符相减,得到相对差，正好等于所要表示的相应的整数)
{
	int sum=0;//存储和值
	int i;//为遍历字符串设置的下标
	for(i=0;i<11;i++)//for循环遍历字符串
	{
	sum+=(str[i]-'0')*(int)pow(8,10-i);//单个字符处理，求和
	}
//	printf("sum=%d",sum);
	return sum;
}
void unpack(const char *tar_filename)
{
	char buf[sizeof(struct tar_header)];//
	FILE *fp=fopen(tar_filename,"rb");
	if(fp==NULL)
	{
	fprintf(stderr,"file not found");
	return ;
	}
	char fbuf[512]={0};
	//fread(buf,1,sizeof(struct tar_header),fp);
	struct tar_header *head=(struct tar_header*)buf;//将字节相同，但类型不同的变量强转为另一种变量
	//printf("name %s,size %s\n",head->name,head->size);
	//int filelen=zhuanhuan(head->size);
	//char fbuf[4096]={0};
	//int need_len;
	//FILE *newfile=fopen(head->name,"wb");
	while(1)
	{
	memset(buf,0,sizeof(buf));//用来从tar文件中接收数据的缓冲区，必须在每次使用完后被清零。
//	need_len=sizeof(buf)>filelen?filelen:sizeof(fbuf);
	fread(buf,1,sizeof(struct tar_header),fp);//将tar文件数据的头数据写进内存缓冲区
//	head=(struct tar_header*)fbuf;
	if(head->name[0]=='\0')//判断是否存在文件数据
	break;
	//fwrite(fbuf,1,need_len,newfile);
	printf("name %s,size %s\n",head->name,head->size);//读取文件名及文件大小信息
	int filelen=zhuanhuan(head->size);//将文件大小信息转换成十进制
	int need_len;
	FILE *newfile=fopen(head->name,"wb");//以头信息中文件名创建新的文件，并准备写入信息
	if(newfile==NULL)//文件打开不成功，继续读下一个512字节？？不应该退出吗？
	{
	fprintf(stderr,"%s write faild\n",head->name);	//显示写错误信息
	continue;
	}
	while(filelen>0)
	{
//	printf("sucess\n");
	memset(fbuf,0,sizeof(fbuf));//大型文件因为超过512，会出现多次使用fbuf缓冲区读数据，因此要设置清空缓冲区程序
	need_len=sizeof(fbuf)>filelen?filelen:sizeof(fbuf);//确定要读文件长度，？没有将剩余字节填充'\0'，不需要考虑因为每次读都是512字节，所以最后会将512字节写入。
	fread(fbuf,1,sizeof(fbuf),fp);//从tar包读信息
	fwrite(fbuf,1,need_len,newfile);//向新文件写数据，不需要用追加的方式打开信息
	filelen-=need_len;//设置该循环终止条件
	}
	fclose(newfile);
}
	fclose(fp);
}
int main(int argc,char **argv)
{
	if(argc<3)//处理不对的命令
	{
	fprintf(stderr,"USAGE %s [-xvf] tar_filename\n",argv[0]);
	return 1;
	}
	if(strncmp(argv[1],"-xvf",4)==0)//设置机制使黑窗口信息能够执行本命令(一般这种机制都是通过字符串函数strcmp系列)
	{
	unpack(argv[2]);
	}
	return 0;
}






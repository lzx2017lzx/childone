#include <stdio.h>
//char *streplace(char *str,const char *sub,const char *rep)
//{
//    if((str==NULL)||(sub==NULL)||(rep==NULL))
//        return NULL;
//    int i=0;//遍历原字符串
//    int j=0;//替换
//    int length=0;//获得原字符串长度,包括零字符
//    while(str[i])
//    {
//     i++;
//    }
//    length=i+1;
//    //找到sub在str中的位置
//   for(i=0;i<length;i++)
//   {
//       if((str[i]!=sub[j])&&(sub[j]!=0))
//           j=0;
//       else if((str[i]==sub[j])&&(str[j]!=0))
//       {
//           j++;
//       }else if(sub[j]==0)
//       {
//           //进行替换
//           i=i-j;
//           j=0;
//           while(rep[j]!=0)
//           {
//               str[i]=rep[j];
//               i++;
//               j++;
//           }
//           j=0;i=i-1;
//       }

//   }
//   printf("----");
//    return str;
//}
void proc(char *str)
{
    FILE *p=fopen("d:\\a.dat","rb");
   // char buf[1024]={0};
    //char temp[2]={0};
    str=(char *)malloc(1024);
    while(fread(buf,1,1,p))
    {
        if(buf[0]!='k')
          continue;
        else if((fread(buf,1,1,p)==0)||(buf[0]!='e'))
        {
            continue;
        }else if((fread(buf,1,1,p)==0)||(buf[0]!='y'))
        {
            continue;
        }else if((fread(buf,1,1,p)==0)||(buf[0]!=':'))
        {
            continue;
        }else
        {
            while(fread(buf,1,1024,p))
            {
            printf("%s",buf);
            }
            break;
        }
    }
}
int main001(void)
{
    char str[]="abcdefgde";
    char sub[]="de";
    char rep[]="DE";
    streplace(str,sub,rep);
    printf("%s\n",str);
    //printf("Hello World!\n");
    return 0;
}
int main()
{
    char *str=NULL;
    proc(str);
    return 0;
}


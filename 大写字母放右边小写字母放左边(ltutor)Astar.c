#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*30.将一串随机形成的字符串中的大写字母按照原来的顺序放置到字符串后半部分
小写字母置于字符串前半部分。
形如 AbCdefGHijLKdfkjf
ACGHLKbdefijdfkjf
函数原型如下 int TransString(const char *pstr, char len);
实现上述函数对字符串进行转换  提示额外空间尽量少。
*/
int TransString( char *pstr,int len)
{
    char temp ;
    int i,j;
    for(i=0;i<len;++i)
    {
        for(j=0;j<len-i-1;++j)
        {
#if 0
            //pstr[j] pstr[j+1]
//            if(pstr[j] > pstr[j+1])
//            {
//                temp = pstr[j];
//                pstr[j] = pstr[j+1];
//                pstr[j+1] = temp;
//            }
#endif
            if( isupper(pstr[j]) && islower(pstr[j+1]) )
            {

                temp = pstr[j];
                pstr[j] = pstr[j+1];
                pstr[j+1] = temp;
            }

        }
    }
}
int main()
{

    char data[] = "BAbCdefGHijLKdfkjf";
    TransString(data,strlen(data));
    printf("%s\n",data);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*30.��һ������γɵ��ַ����еĴ�д��ĸ����ԭ����˳����õ��ַ�����벿��
Сд��ĸ�����ַ���ǰ�벿�֡�
���� AbCdefGHijLKdfkjf
ACGHLKbdefijdfkjf
����ԭ������ int TransString(const char *pstr, char len);
ʵ�������������ַ�������ת��  ��ʾ����ռ価���١�
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

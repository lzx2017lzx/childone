#include <iostream>
#include<string.h>
#include<stdlib.h>

#include"getnext.h"
using namespace std;
// the question is:一串英文字符串，求这段字符串的next数组的值。next数组下标从1开始，最大下标
// 值是字符串长度，表示第几次匹配，值存储的是每一次匹配时不成功，选取模式串比较的最合适位置。

// param:T[0]存储字符串总长度，next作为输出参数

// 用来匹配的两个源字符串的开始第一个字节存储字符串的长度。next开始第一个元素分为有效和无效。
// 其中无效表意更加清晰。



int main(int argc, char *argv[])
{

#if 1
    // next[0] has valid value.

    // test get_next;
    char str[1024]={0};
    int next[8]={0};

    str[0]=8;
    memcpy(str+1,"abaabcac",8);

    get_nextOne(str,next);

    // test KMP;
    char source[1024]={0},Test[1024]={0};
    source[0]=strlen("abcabaaabaabcac");
    Test[0]=strlen("abaabcac");

    memcpy(source+1,"abcabaaabaabcac",source[0]);
    memcpy(Test+1,"abaabcac",Test[0]);

    cout<<"source:"<<source<<endl;
    cout<<"Test:"<<Test<<endl;

//    int resultOne=KMPOne(source,Test,next,8);
//    cout<<"resultOne:"<<resultOne<<endl;
    for(int i=0;i<source[0];i++)
    {
            int resultOne=KMPOne(source,Test,next,i);
            cout<<"i:"<<i<<".resultOne:"<<resultOne<<endl;
    }
    return 0;
#endif


#if 0
    // next[0] has  no valid value.

    // test next;
    char str[1024]={0};
    int next[9]={0};

    str[0]=8;
    memcpy(str+1,"abaabcac",8);

    get_nextTwo(str,next);
    for(int i=0;i<9;i++)
    {
        cout<<"next[i]:"<<next[i]<<endl;
    }

    // test KMP;
    char source[1024]={0},Test[1024]={0};
    source[0]=strlen("abcabaaabaabcac");
    Test[0]=strlen("abaabcac");

    memcpy(source+1,"abcabaaabaabcac",source[0]);
    memcpy(Test+1,"abaabcac",Test[0]);

    cout<<"source:"<<source<<endl;
    cout<<"Test:"<<Test<<endl;

//    int resultOne=KMPTwo(source,Test,next,4);
//    cout<<"resultOne:"<<resultOne<<endl;

    for(int i=0;i<source[0];i++)
    {
            int resultOne=KMPTwo(source,Test,next,i);
            cout<<"i:"<<i<<".resultOne:"<<resultOne<<endl;
    }
//    int resultTwo=KMPTwo(source,Test,next,8);
//    cout<<"resultTwo:"<<resultTwo<<endl;

    return 0;
#endif



}

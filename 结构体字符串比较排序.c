#include <iostream>
#include <cstring>
#include <cstdio> //#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
struct stu
{
    char name[32];
    int  age;
};
int mycompare(const void*s1,const void*s2)
{
    const stu * stu1 = (const stu *)s1;
    const stu * stu2 = (const stu *)s2;
    //return strcmp(stu1->name,stu2->name);
    if( stu2 ->age == stu1->age )
        return 0;
    else if(stu2 ->age > stu1->age)
        return -1;
    else
        return 1;
}
/*
 * void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));
*/
//c with class   .cc
//c plus plus    .cpp  .cxx .h  .hpp
int main()
{
    char *str = "jiangshifsadlfjdsalkfjdsalkjfldsajfhdsafkjsahdkjfhadskjhfhfdsakjfhkdsafkjdsahfkjdsahkjfhdsalkfjhdsalkjhflkjdsahflsadhflak";
    size_t len = strlen(str);
    stu arr[100];
    memset(arr,0,sizeof(arr));
    srand(time(NULL));
    for(int i=0;i<100;++i)
    {
        for(int j=0;j<31;++j)
            arr[i].name[j]= str[rand() % len];
        arr[i].age = rand() % 150;
    }
    qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),mycompare);
    for(int i=0;i<100;++i)
    {
       cout<<"name:"<<arr[i].name<<"age:"<<arr[i].age<<endl;
    }
    return 0;
}
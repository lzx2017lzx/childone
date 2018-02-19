#include<stdio.h>
#include"cJSON.h"
#include<string.h>
int main()
{

cJSON *cjson=cJSON_CreateObject();

cJSON_AddNumberToObject(cjson,"1",1);
cJSON_AddNumberToObject(cjson,"2",2);
cJSON_AddNumberToObject(cjson,"3",3);
cJSON_AddStringToObject(cjson,"name","lihua");


cJSON *cjson1=cJSON_CreateObject();

cJSON_AddNumberToObject(cjson1,"1",1);
cJSON_AddNumberToObject(cjson1,"2",2);
cJSON_AddNumberToObject(cjson1,"3",3);
cJSON_AddStringToObject(cjson1,"name","liming");

cJSON *cjsonarray=cJSON_CreateArray();

cJSON_AddItemToArray(cjsonarray,cjson);

cJSON_AddItemToArray(cjsonarray,cjson1);

printf("cjsonarray:%s\n",cJSON_Print(cjsonarray));
printf("cjson:%s\n",cJSON_Print(cjson));
printf("cjson1:%s\n",cJSON_Print(cjson1));

printf("---------------getdatafromarray-------------\n");
int size=cJSON_GetArraySize(cjsonarray);
printf("size of cjsonarray:%d\n",size);
#if 0
printf("--------------------析构jsonarray-------------\n");
cJSON_Delete(cjsonarray);
printf("--------------------析构jsonarray成功-------------\n");
#endif

cJSON*getjson=cJSON_GetArrayItem(cjsonarray,0);
cJSON*obj=cJSON_GetObjectItem(getjson,"1");
int a=obj->valueint;
printf("a:%d\n",a);
obj=cJSON_GetObjectItem(getjson,"name");
char* str=obj->valuestring;
printf("str:%s\n",str);
printf("-------------------jsonarrayandother----------------\n");

cJSON *cjson4=cJSON_CreateObject();

cJSON_AddNumberToObject(cjson4,"1",11);
cJSON_AddNumberToObject(cjson4,"2",21);
cJSON_AddNumberToObject(cjson4,"3",31);
cJSON_AddStringToObject(cjson4,"name","xuezhe");
cJSON_AddItemToObject(cjson4,"drivers",cjsonarray),

printf("cjson4:%s\n",cJSON_Print(cjson4));

printf("-------------------getjsonarray from jsonobject-------------\n");
cJSON*getcjson4jsonarray=cJSON_GetObjectItem(cjson4,"drivers");

size=cJSON_GetArraySize(getcjson4jsonarray);
printf("size of getcjson4jsonarray:%d\n",size);


printf("-------------获得cJSON中的字符串-----------------\n");

char*cjsonchar=cJSON_Print(cjson1);
printf("cjsonchar:%s\n",cjsonchar);

printf("delte json对象后，测试cjsonchar指向的内存空间有没有被释放.\n");
cJSON_Delete(cjson1);
printf("after delete cjson1 cjsonchar:%s\n",cjsonchar);

printf("将cjsonchar重新封装成cjson对象");

cJSON *chartocjson=cJSON_Parse(cjsonchar);
printf("chartocjson:%s\n",cJSON_Print(chartocjson));

cJSON *chartocjson1=cJSON_CreateString(cjsonchar);
printf("chartocjson1:%s\n",cJSON_Print(chartocjson1));
obj=cJSON_GetObjectItem(chartocjson,"1");
a=obj->valueint;
printf("a:%d\n",a);
obj=cJSON_GetObjectItem(chartocjson,"name");
str=obj->valuestring;
printf("str:%s\n",str);
printf("--------------析构jsonarray----------------\n");
cJSON_Delete(getcjson4jsonarray);
#if 0
//chartocjson1不是一个真正的cjson对象
obj=cJSON_GetObjectItem(chartocjson1,"1");
a=obj->valueint;
printf("a:%d\n",a);
obj=cJSON_GetObjectItem(chartocjson1,"name");
str=obj->valuestring;
printf("str:%s\n",str);
#endif
	return 0;
}	

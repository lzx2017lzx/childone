#include "json.h"
#include<stdlib.h>
#include<stdio.h>

Json::Json()
{
//	printf("Json() is working.\n");
    root=cJSON_CreateObject();
//	printf("Json() is working.after cJSON_CreateObject\n");
    buf=NULL;
}

Json::~Json()
{
//	printf("~Json() is working.\n");
    cJSON_Delete(root);
//	printf("~Json() is working.after cJSON_Delete\n");
	root=NULL;
    if(buf) free(buf);
}

void Json::add(string key, string value)
{
    cJSON_AddStringToObject(root,key.c_str(),value.c_str());
}
void Json::add(string key,double value)
{
    cJSON_AddNumberToObject(root,key.c_str(),value);
}

void Json::add(string key,int value)
{
    cJSON_AddNumberToObject(root,key.c_str(),value);
}

void Json::add(string key,cJSON*obj)
{
	char*temp=cJSON_Print(obj);
	 chartocjson=cJSON_Parse(temp);
	free(temp);	
    cJSON_AddItemToObject(root,key.c_str(),chartocjson);
	
}

cJSON* Json::getroot()
{
	return root;

}


char* Json::print()
{
    if(buf!=NULL)free(buf);

    buf=cJSON_Print(root);
    return buf;
}

void Json::parse(string json_buf)
{
    cJSON* obj=cJSON_Parse(json_buf.c_str());
    if(obj==NULL)return;

    cJSON_Delete(root);
    root=obj;
}

string Json::getString(string key)
{
   cJSON*obj= cJSON_GetObjectItem(root,key.c_str());
    return obj->valuestring;
}

double Json::getDouble(string key)
{
   cJSON*obj= cJSON_GetObjectItem(root,key.c_str());
	return obj->valuedouble;

}

int Json::getInt(string key)
{
   cJSON*obj= cJSON_GetObjectItem(root,key.c_str());
	return obj->valueint;	

}

cJSON*Json::getObject(string key)
{
    cJSON *obj=cJSON_GetObjectItem(root,key.c_str());
    return obj;
}

JsonArray::JsonArray()
{
    jsonarray=cJSON_CreateArray();
	buf=NULL;	

}

void JsonArray::addarray(cJSON*item)
{
	char*temp=cJSON_Print(item);
	 chartocjson=cJSON_Parse(temp);
	
	free(temp);
	cJSON_AddItemToArray(jsonarray,chartocjson);
}

cJSON*JsonArray::getJsonArray()
{
	return jsonarray;
}

JsonArray::~JsonArray()
{
printf("~jsonarray is working.\n");
    cJSON_Delete(jsonarray);
printf("~jsonarray is done.\n");
	jsonarray=NULL;
	if(buf!=NULL)
	{
	//	free(buf);
	}
	
}

char *JsonArray::print()
{
    if(buf!=NULL)free(buf);

    buf=cJSON_Print(jsonarray);
    return buf;

}

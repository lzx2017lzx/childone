#include"mongotool.h"


mongotool *mongotool::tool=new mongotool;

mongotool::mongotool()
{
	db=client["mynetdisk1"];
	collection=db["file_system"];

}

mongotool::mongotool(mongotool&)
{


}


mongotool::~mongotool()
{


}

mongotool *mongotool::getInstance()
{
	return tool;
}


int mongotool::insert(int user_file_id,char *dst_path,char *md5)
{
	bsoncxx::document::value doc_value=document{}<<"user_file_id"<<user_file_id<<"dst_path"<<dst_path<<"md5"<<md5<<finalize;
	bsoncxx::stdx::optional<mongocxx::result::insert_one> result=collection.insert_one((bsoncxx::document::value&&)doc_value);
	if(result)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


#ifndef JSON_H
#define JSON_H
#include"cJSON.h"
#include<string>

using namespace std;
class Json
{
	public:
		Json();
		~Json();

		void add(string key,string value);
		void add(string key,double value);
		void add(string key,int value);
		void add(string key,cJSON*obj);
		char* print();
		void parse(string json_buf);
		cJSON*getroot();

		string getString(string key);
		double getDouble(string key);
		int getInt(string key);
		cJSON * getObject(string key);
		//  int getInt(string key);
	private:
		Json(const Json&);
		Json& operator=(const Json &);
		cJSON*chartocjson;
		cJSON* root;
		char *buf;
};

class JsonArray
{
public:
	JsonArray();
	~JsonArray();
	void addarray(cJSON*item);
	cJSON*getJsonArray();

	char* print();


private:
	 cJSON *chartocjson;
	cJSON*jsonarray;
	char *buf;

};
#endif // JSON_H

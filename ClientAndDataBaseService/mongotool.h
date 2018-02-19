#ifndef _MONGOTOOL_H
#define _MONGOTOOL_H
#include<cstdint>
#include<iostream>
#include<bsoncxx/json.hpp>
#include<mongocxx/client.hpp>
#include<mongocxx/stdx.hpp>
#include<mongocxx/uri.hpp>
#include<mongocxx/instance.hpp>

using namespace std;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

class mongotool
{
	private:
		mongotool();
		mongotool(mongotool&);
		~mongotool();
	public:
		static mongotool * getInstance();
		int insert(int user_file_id,char *dst_path,char *msd5);
	private:
		static mongotool * tool;
		mongocxx::instance instance{};
		mongocxx::client client{mongocxx::uri{}};
		mongocxx::database db;
		mongocxx::collection collection;
};







#endif

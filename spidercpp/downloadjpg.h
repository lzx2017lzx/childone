#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<curl/curl.h>
#include<curl/easy.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include <curl/curl.h>
using namespace std;

size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata);
bool download_jpeg(char* url);
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

bool download_jpeg2(char* url);
int downloadjpg(string url);

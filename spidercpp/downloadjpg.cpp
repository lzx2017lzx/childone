#include"downloadjpg.h"
#include<sstream>
static int i=0;

struct MemoryStruct{
    char *memory;
    size_t size;
};

size_t modcallbackfunction(void *contents, size_t size, size_t nmemb, void*userp)
{
    size_t realsize=size*nmemb;
    struct MemoryStruct*mem=(struct MemoryStruct*)userp;

    mem->memory=(char*)realloc(mem->memory,mem->size+realsize+1);
    if(mem->memory==NULL)
    {
        printf("not enough memory\n");
        return 0;
    }
    memcpy(&(mem->memory[mem->size]),(char*)contents,realsize);
    mem->size+=realsize;
    mem->memory[mem->size]=0;
        return realsize;
}


size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata)
{
    FILE* stream = (FILE*)userdata;
    if (!stream) {
        printf("!!! No stream\n");
        return 0;
    }

    size_t written = fwrite((FILE*)ptr, size, nmemb, stream);
    return written;
}

bool download_jpeg(char* url)
{

    cout<<"download_jpeg works."<<endl;
    string temp;
    std::stringstream strint;
    strint<<i;
    strint>>temp;
    cout<<"download_jpeg:temp:"<<temp<<endl;
    temp+=".jpg";
    FILE* fp = fopen(temp.c_str(), "wb");
    if (!fp) {
        printf("!!! Failed to create file on the disk\n");
        return false;
    }
    i++;
    struct MemoryStruct chunk;
    chunk.memory=(char*)malloc(1);
    chunk.size=0;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curlCtx = curl_easy_init();
    curl_easy_setopt(curlCtx, CURLOPT_URL, url);
    cout<<"url in dowload_jpeg:"<<string(url)<<endl;
    curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fp);
    //curl_easy_setopt(curlCtx, CURLOPT_PROXY,"http://www.baidu.com");
    curl_easy_setopt(curlCtx, CURLOPT_USERAGENT," Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36");
// curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, modcallbackfunction);
 curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, true);
        curl_easy_setopt(curlCtx, CURLOPT_VERBOSE, 1);
//    curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, (void*)&chunk);

    CURLcode rc = curl_easy_perform(curlCtx);
    if (rc) {
        printf("!!! Failed to download: %s\n", url);
        return false;
    }

    long res_code = 0;
    curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK)) {
        printf("!!! Response code: %ld\n", res_code);
        return false;
    }
    
  //  size_t written = fwrite((char*)chunk.memory,1,strlen((char*)chunk.memory), fp);
//    cout<<"written:"<<written<<endl;
    curl_easy_cleanup(curlCtx);
    fclose(fp);
    curl_global_cleanup();

    return true;
}
#if 0
char res_buf[60240];
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    memcpy(res_buf+strlen(res_buf),ptr,size*nmemb);
    return size*nmemb;
}
#endif
bool download_jpeg2(char* url)
{
    cout<<"download_jpeg2 works."<<endl;
    CURL *curl;
    string temp;
    std::stringstream strint;
    strint<<i;
    strint>>temp;
    cout<<"download_jpeg:temp:"<<temp<<endl;
    temp+=".jpg";
    FILE *fp;
    CURLcode res;
    char* outfilename = (char*)temp.c_str();
    i++;
    CURLcode gloret=curl_global_init(CURL_GLOBAL_ALL);
    if(gloret!=0)
    {
        cout<<"curl_global_init is wrong."<<endl;
        return false;
    }
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        //  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        res = curl_easy_perform(curl);

        // size_t written = fwrite(res_buf, strlen(res_buf),1, fp);
        // cout<<"written:"<<written<<endl;
        /* always cleanup */
        curl_global_cleanup();
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    else {
        printf("!!!curl init failed\n");
        return false;
    }

    return true;
}

int downloadjpg(string url)
{
    char* tempurl =(char*)url.c_str();
    //memset(res_buf,0,sizeof(res_buf));

#if 1
    if (!download_jpeg(tempurl)) {
        printf("!! Failed to download file: %s\n", tempurl);
        return -1;
    }
#else
    if (!download_jpeg2(tempurl)) {
        printf("!! Failed to download file: %s\n", tempurl);
        return -1;
    }
#endif

    std::cout << "ok!" << std::endl;
    return 0;
}

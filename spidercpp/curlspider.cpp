#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<iostream>
#include<fstream>
#include<unistd.h>
#include<regex>
#include<vector>
#include<string>
#include<errno.h>
#include"downloadjpg.h"
using namespace std;
vector<string>vstrrawurl;
vector<string>vstrintodsc;

int geturlfun(string html)
{
    cout<<"html"<<html<<endl;
    std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");

    pattern="[[:alpha:]]*"+ pattern +"[[:alpha:]]*";
    std::regex r(pattern);
    cout<<"geturlfun is working"<<endl;
    for(std::sregex_iterator it(html.cbegin(),html.cend(),r),end;it!=end;++it)
    {
        //    std::cout<<it->str()<<std::endl;
        cout<<"this geturlfun for"<<endl;

        vstrrawurl.push_back("curl "+it->str());
        //cout<<"vstrrawurl.size():"<<vstrrawurl.size()<<endl;
        string temp=it->str()+"\n";
        //cout<<"temp:"<<temp<<endl;
        vstrintodsc.push_back(it->str()+"\n");
        //cout<<"vstrintodsc.size():"<<vstrintodsc.size()<<"vstrintodsc:back()"<<vstrintodsc.back()<<endl;
        if(vstrintodsc.size()>20)//vstrintodsc尺寸大于100才会写磁盘
        {
            char * fileName=(char*)"url.txt";
            ofstream osm(fileName,ios::app | ios::binary);
            if(!osm)
            {

                cout<<"打开失败"<<endl;
            }
            for(vector<string>::iterator it=vstrintodsc.begin();it!=vstrintodsc.end();it++)
            {
                osm.write((const char*)(*it).c_str(),(*it).size());
                cout<<"write url.txt works"<<endl;
                string temp=(*it).substr((*it).size()-5,(*it).size());
                cout<<"after write url.txt temp:"<<temp<<endl;
                int ret=0;
                if((ret=temp.compare(".jpg"))==1)
                {
                    cout<<"before dowlaodjpg"<<endl;
                    cout<<"jpgurl:"<<*it<<endl;
                    int ret=downloadjpg(*it);
                    if(ret)
                    {
                        cout<<"downloadjpg wrong.\n";
                    }else
                    {
                        cout<<"downloadjpg right.\n";
                    }
                }
                cout<<"ret:"<<ret<<endl;
            }
            osm.close();
            cout<<"write url.txt works"<<endl;
            vstrintodsc.clear();
        }

    }
    cout<<"---------this geturlfun for----end"<<endl;
    return 0;
}


int main()
{
    FILE *fp;
    char buf[20480]={0};
    FILE *fwr;
    std::string url;
    //url="http://www.mmjpg.com/";
//    char* temp =(char*) "curl http://img.mmjpg.com/small/2017/1093.jpg";
//    url=temp;
         url=string("curl http://www.rayli.com.cn/juhe/").c_str();
    if(url.size()==0)
    {
        return 0;
    }
    cout<<"url"<<url<<endl;
    vstrrawurl.push_back(url);
    vstrintodsc.push_back(url);

    while(vstrrawurl.size()!=0)
    {
        memset(buf,0,sizeof(buf));
        if(NULL!=(fp=popen(vstrrawurl.back().c_str(),"r")))
        {
            fread(buf,20480,1,fp);
            vstrrawurl.pop_back();
        }
        geturlfun(string(buf));

        pclose(fp);
#if 0
        char *fileName=(char*)"socketurl.txt";
        ofstream osm(fileName,ios::out | ios::binary);
        if(!osm)
        {

            cout<<"打开失败"<<endl;
        }
        osm.write((const char*)buf,strlen(buf));
        osm.close();
        cout<<"strlen(buf):"<<strlen(buf);
        printf("buf=%s\n",buf);
    }
#endif
}
return 0;
}

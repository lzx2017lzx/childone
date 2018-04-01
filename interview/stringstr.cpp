#include <iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

class mystring
{
    friend ostream &operator<<(ostream &os,mystring &mstr);
    public:
    mystring();
    mystring(const char *src);
    mystring(const mystring &mtr);
    mystring &operator=(const mystring &mtr);
    ~mystring();

    private:
    char *mstr;
    unsigned int len;
};

mystring::mystring()
{
    mstr=new char[1];
    len=0;
}

mystring::mystring(const char *src)
{
    len=strlen(src);
    mstr=new char[len+1];
    strcpy(mstr,src); 
}
mystring::mystring(const mystring &mystr)
{
    len=mystr.len; 
    mstr=new char[len+1];
    strcpy(mstr,mystr.mstr);
}

mystring & mystring::operator=(const mystring &mystr)
{
    if(len!=0)
    {
        delete []mstr;
        mstr=NULL;
    }
    len=mystr.len; 
    mstr=new char[len+1];
    strcpy(mstr,mystr.mstr);
}

mystring::~mystring()
{
    if(this->mstr!=NULL)
    {
        delete []mstr;
        mstr=NULL;
    }
}

ostream &operator<<(ostream &os,mystring &mstr)
{
    os<<mstr.mstr;
    return os;

}
int main(int argc, char *argv[])
{
    mystring s1("hello");
    mystring s2=s1;
    mystring s3;
    s3=s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}

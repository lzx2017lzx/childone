#include <iostream>
#include<string>
#include<ctime>
using namespace std;

unsigned long GetTickCount()  
{  
    struct timespec ts;  

    clock_gettime(CLOCK_MONOTONIC, &ts);  

    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);  
}  

int main(int argc, char *argv[])
{
    int m=GetTickCount();
    cout<<"m:"<<m<<endl;

    return 0;
}

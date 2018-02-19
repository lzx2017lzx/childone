#include "getnext.h"


// next[0] has a valid value
void get_nextOne(char T[],int next[]){
    int i=1,j=0;
    next[0]=0;
    while(i<=T[0])
    {
        if(j==0||T[i]==T[j])
        {
            ++i;
            ++j;
            next[i-1]=j;
        }
        else
        {
            j=next[j-1];
        }
    }
}

int KMPOne(char S[],char T[],int next[],int pos)
{
    if(pos==0)
    {
        return -1;
    }

    int i=pos,j=1;
    while(i<S[0]&&j<T[0]){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j-1];
        }

    }

    if(j==T[0])
    {
        return 0;
    }else
    {
        return -1;
    }
}


// next[0] doesn't hava a valid value
void get_nextTwo(char T[],int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<=T[0])
    {
        if(j==0||T[i]==T[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int KMPTwo(char S[],char T[],int next[],int pos)
{
    if(pos==0)
    {
        return -1;
    }

    int i=pos,j=1;
    while(i<=S[0]&&j<=T[0]){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];
        }

    }

    if(j>T[0])
    {
        return 0;
    }else
    {
        return -1;
    }
}



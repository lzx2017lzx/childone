#ifndef GETNEXT_H
#define GETNEXT_H


void get_nextOne(char T[],int next[]);
void get_nextTwo(char T[],int next[]);

int KMPOne(char S[],char T[],int next[],int pos);
int KMPTwo(char S[],char T[],int next[],int pos);
#endif // GETNEXT_H

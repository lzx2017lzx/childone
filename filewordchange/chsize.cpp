#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    fstream OpenFile("text.txt",ios::in | ios::out | ios::trunc);
    OpenFile.close();


	return 0;
}

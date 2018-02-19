#include"NETWORK.h"

int main()
{
   int fd= myConnect2(9988,"127.0.0.1");

   myWriteBuf(fd,"hello");
   myWriteBuf(fd,"world");
   close(fd);
    return 0;

}

#include"NETWORK.h"

int main()
{


        int fd=myConnect2(9988,"127.0.0.1");
        int ret=write(fd,"hello world",11);
        printf("ret=%d\n",ret);
        close(fd);

    return 0;
}

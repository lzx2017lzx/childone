#include <stdio.h>
#include <stdlib.h>    //exit()
#include <string.h>    //strerror()
#include <errno.h>     //errno
#include <sys/types.h> //stat()
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    char *filename;
    struct stat buf;

    if (argc != 2) {
        printf("Please input filename\n");
        exit(-1);
    }
    filename = argv[1];
    if (stat(filename, &buf) < 0) {
        printf("Mesg: %s\n", strerror(errno));
        exit(-1);
    }
    printf("%s's size is %-4ld bytes\n", filename, buf.st_size);
    printf("%s's t_blksize is %-4ld bytes\n", filename, buf.st_blksize);
    printf("%s's blocks is %-4ld blocks\n",filename, buf.st_blocks);
}

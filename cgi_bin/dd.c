#include <stdlib.h>
#include<stdio.h>
int main(void)
{
        printf("Content-Type: test/html\r\n\r\n");
        printf("<html>\n");
//      printf("<head><title>CGI Output</title></head>\n");
        printf("<body><pre>\n");
        printf("hello,world\n");
        printf("</body>\n");
        printf("</html>\n");
//"body"
//"h1The c cgi hello /h1"
//"p"
//"hello %s world!"
//"/p"
//"/body"
//"/html",s
        return 0;
}

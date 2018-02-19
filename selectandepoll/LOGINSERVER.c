#include"NETWORK.h"

int main()
{
    int server=myServer(9989,"0.0.0.0");

    close(open("user.data",O_CREAT|O_EXCL,0777));
    while(1)
    {
        int newfd=myAccept(server,NULL,NULL);
        if(newfd==-1)
        {
            break;
        }
        char *buf= myReadBuf(newfd);
        char *saveptr;
        const char *type=strtok_r(buf,"|",&saveptr);
        if(type==NULL)
        {
            break;
        }
        const char *user=strtok_r(NULL,"|",&saveptr);
        if(user==NULL)
        {
            break;
        }
        const char*pass=strtok_r(NULL,"|",&saveptr);
        if(user==NULL)
        {
            break;
        }

        if(type[0]=='r')
        {
            FILE *fp=fopen("user.data","a+");
            fprintf(fp,"%s\n%s\n",user,pass);
            fclose(fp);

            myWriteBuf(newfd,"r|ok");    
        }
        else if(type[0]=='l')
        {
            char ubuf[1024];
            char pbuf[1024];
            char *p;
            FILE *fp=fopen("user.data","r");
            while(1)
            {
                p=fgets(ubuf,sizeof(ubuf),fp);
                if(p==NULL)break;
                fgets(pbuf,sizeof(pbuf),fp);
                ubuf[strlen(ubuf)-1]=0;
                pbuf[strlen(pbuf)-1]=0;
                if(strcmp(ubuf,user)==0&&strcmp(pbuf,pass)==0)
                {
                    myWriteBuf(newfd,"l|ok");
                    break;

                }
            }

            if(p==NULL)
            {
                myWriteBuf(newfd,"l|err");
            }
            fclose(fp);

        }
        else
        {
            myWriteBuf(newfd,"unknown command");
        }
        free(buf); 
        close(newfd);


















    } 
    return 0;
}



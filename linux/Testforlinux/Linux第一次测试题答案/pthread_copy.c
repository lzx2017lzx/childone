#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>

typedef struct
{
	char src_file[1024];
	char dsc_file[1024];
	int start;
	int length;
}Args;

void *pthread_func(void *args)
{
	Args *arg = (Args *)args;
	int src_fd = open(arg->src_file, O_RDONLY);
	int dsc_fd = open(arg->dsc_file, O_WRONLY);

	lseek(src_fd, arg->start, SEEK_SET);
	lseek(dsc_fd, arg->start, SEEK_SET);

	char buf[1024];
	while (arg->length > 0)
	{
		memset(buf, 0, sizeof(buf));
		int ret = read(src_fd, buf, arg->length > 1024 ? 1024 : arg->length);
		if (ret <= 0)
			break;
		write(dsc_fd, buf, ret);
		arg->length -= ret;
	}
	free(arg);
	close(src_fd);
	close(dsc_fd);
}

void copyfile(int n, char *src_file, char *dsc_file)
{
	struct stat st;
	stat(src_file, &st);

	int avgsize = st.st_size / n;
	int lastsize = st.st_size % n;
	int dsc_fd = open(dsc_file, O_CREAT, 0777);
	ftruncate(dsc_fd, st.st_size);
	close(dsc_fd);

	pthread_t *tids = (pthread_t *)malloc(sizeof(pthread_t) * n);
	for (int i = 0; i < n; ++i)
	{
		Args *arg = (Args *)malloc(sizeof(Args));
		strcpy(arg->src_file,src_file);
		strcpy(arg->dsc_file,dsc_file);
		arg->start = avgsize * i;
		if (i == n - 1)
			arg->length = avgsize + lastsize;
		else
			arg->length = avgsize;
		pthread_create(tids + i, NULL, pthread_func, (void *)arg);
	}
	for (int i= 0; i < n; ++i)
	{
		pthread_join(tids[i], NULL);
	}
	free(tids);
}

// ./a.out n src dsc
int main(int argc, char *argv[])
{
	if (4 != argc)
	{
		printf("arg error\n");
		return -1;
	}
	int n = atoi(argv[1]);
	char *src = argv[2];
	char *dsc = argv[3];
	copyfile(n, src, dsc);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
int count = 0;

void regular_count(const char *path)
{
	DIR *dir = opendir(path);
	if (NULL == dir)
	{
		return;
	}
	while(1)
	{
		struct dirent *de = readdir(dir);
		if (de == NULL)
			break;
		if (strcmp(".",de->d_name)==0||strcmp("..",de->d_name)==0)
		{
			continue;
		}
		if (de->d_type == DT_REG)
		{
			++count;
			continue;
		}
		if (de->d_type == DT_DIR)
		{
			char buf[1024] = {0};
			sprintf(buf,"%s/%s",path,de->d_name);
			regular_count(buf);
		}
	}
	closedir(dir);
}

// ./a.out dir
int main(int argc, char *argv[])
{
	if (2 != argc)
	{
		printf("arg error\n");
		return -1;
	}
	char *path = argv[1];
	struct stat st;
	stat(path, &st);

	if (!S_ISDIR(st.st_mode))
	{
		printf("not dir\n");
		return -2;
	}

	regular_count(path);
	printf("count is %d\n", count);
	return 0;
}

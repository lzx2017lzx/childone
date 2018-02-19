#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CFGPATH "./cfg_heap.dat"

int trimSpace(char *inbuf, char*outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0)
	{
		return -2;
	}

	while (p[begin] == ' ')
	{
		begin++;
	}

	while ((p[end] == ' ') && (end > 0))
	{
		end--;
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1;
	strncpy(outbuf, p + begin, n);
	outbuf[n - 1] = '\0';
	return 0;
}
int getKeyByValue(char *keyval, char *pkey, char *buf, int *len)
{
	if (keyval == NULL || pkey == NULL || buf == NULL || len == NULL)
	{
		return -1;
	}

	char *p = keyval;
	p = strstr(p, pkey);
	if (NULL == p)
	{
		return -2;
	}

	p = p + strlen(pkey);
	p = strstr(p, "=");
	if (NULL == p)
	{
		return -3;
	}

	p = p + strlen("=");

	int ret = trimSpace(p, buf);
	if (ret != 0)
	{
		return ret;
	}
	*len = strlen(buf);
	return 0;
}

int my_write(char *key, char *value)
{
	FILE *fp = NULL;
	int ret = 0;

	fp = fopen(CFGPATH, "r+");
	if (fp == NULL)
	{
		fp = fopen(CFGPATH, "w+");
		if (fp == NULL)
		{
			perror("fopen");
			ret = -1;
			goto END;
		}
	}
	//fseek(fp, 0, SEEK_END);
	//long size = ftell(fp);
	

	//rewind(fp);

	//char tmp[SIZE] = { 0 };
	char *tmp = NULL;
	int i = 0;
	char buf[1024] = { 0 };
	char *p = NULL;
	int flag = 0;

	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))
		{
			break;
		}

		p = strstr(buf, key);
		if (p == NULL)
		{
			if (tmp == NULL)
			{
				tmp = (char *)realloc(tmp, strlen(buf) + 1);
				if (tmp == NULL)
				{
					perror("realloc");
					return -1;
				}
			}
			else
			{
				tmp = (char *)realloc(tmp, strlen(tmp) + strlen(buf) + 2);
				if (tmp == NULL)
				{
					perror("realloc");
					return -1;
				}
				
				
			}
			strcat(tmp, buf);
			continue;
		}
		p = strstr(p, "=");
		if (p == NULL)
		{
			if (tmp == NULL)
			{
				tmp = (char *)realloc(tmp, strlen(buf) + 1);
				if (tmp == NULL)
				{
					perror("realloc");
					return -1;
				}
			}
			else
			{
			tmp = (char *)realloc(tmp, strlen(tmp) + strlen(buf) + 2);
			if (tmp == NULL)
			{
				perror("realloc");
				return -1;
			}
			}
			strcat(tmp, buf);
			continue;
		}
		sprintf(buf, "%s=%s\n", key, value);
		if (tmp == NULL)
		{
			tmp = (char *)realloc(tmp, strlen(buf) + 1);
			if (tmp == NULL)
			{
				perror("realloc");
				return -1;
			}
		}
		else
		{
			tmp = (char *)realloc(tmp, strlen(tmp) + strlen(buf) + 2);
			if (tmp == NULL)
			{
				perror("realloc");
				return -1;
			}
			strcat(tmp, buf);
			flag = 1;
		}
	}
	if (0 == flag)
	{
		
		sprintf(buf, "%s=%s\n", key, value);
		if (tmp == NULL)
		{
			tmp = (char *)realloc(tmp, strlen(buf) + 1);
			if (tmp == NULL)
			{
				perror("realloc");
				return -1;
			}
			strcat(tmp, buf);
		}
		else
		{
			tmp = (char *)realloc(tmp, strlen(tmp) + strlen(buf) + 2);
			if (tmp == NULL)
			{
				perror("realloc");
				return -1;
			}
			strcat(tmp, buf);
		}
	}
	fclose(fp);
	fp = fopen(CFGPATH, "w+");
	if (fp == NULL)
	{
		perror("fopen");
		ret = -2;
		goto END;
	}

	fputs(tmp, fp);

END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return ret;
}


int my_read(char *key, char *value, int *len)
{
	FILE *fp = NULL;
	int ret = 0;

	fp = fopen(CFGPATH, "r");
	if (fp == NULL)
	{
		perror("fopen");
		ret = -1;
		goto END;
	}

	char buf[1024] = { 0 };
	char *p;
	int flag = 0;
	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))
		{
			break;
		}
		p = strstr(buf, key);
		if (p == NULL)
		{
			continue;
		}
		p = strstr(p, "=");
		if (p == NULL)
		{
			continue;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if (0 == flag)
	{
		printf("没有这个key值\n");
		ret = -2;
		goto END;
	}

	ret = getKeyByValue(buf, key, value, len);
	if (ret != 0)
	{
		goto END;
	}
END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return ret;
}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
//#pragma pack(2)
#if 0
typedef struct
{
	char a;
	short b;
	double c;
}B;
int main(void)
{
	printf("sizeof(B)=%d\n", sizeof(B));
	printf("%d\n", offsetof(B, c));

	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
//拷贝文件
int main(void)
{
	char *src = "./1.jpg";
	char *dst = "./abc.jpg";
	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;
	src_fp = fopen(src, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src fails");
		goto END;
	}
	dst_fp = fopen(dst, "wb");
	if(dst_fp==NULL)
	{
		perror("fopen dst fails");
		goto END;
	}
	int len;
	char buf[1024 * 4];

	while (1)
	{
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len == 0)
		{
			break;
		}
		fwrite(buf, 1, len, dst_fp);
	}

END:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}

	printf("\n");
	system("pause");
	return 0;
}



#endif
#if 0

typedef struct Teacher
{
	char name[64];
	int age;
} Teacher_t;
int main(void)
{
	int offset = (int)&(((Teacher_t *)0)->age);
	printf("\n");
	system("pause");
	return 0;
}




#endif
#if 0
#pragma pack(4)
typedef struct Teacher
{
	char *name;
	int age;
} Teacher_t;

int main(void)
{
	int offset = (int)&(((Teacher_t *)0)->age) - (int)&(((Teacher_t *)0)->name);
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
#pragma pack(4) 
typedef struct Teacher
{
	char *name;
	int age;
} Teacher_t;



int main(void)
{
	int offset = (int)&(((Teacher_t *)0)->age);
	printf("%d\n", offset);
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
void func()
{

}
int test()
{
	return 0;
}
int main(void)
{
	printf("%p\n", func);
	printf("%p\n", &func);

	if (test)
	{
		printf("条件为真。\n");
	}

	printf("\n");
	system("pause");
	return 0;
}


#endif
#if 0
int *func()
{
	return NULL;
}

void test(int a)
{
	printf("a=%d\n", a);
}
int main(void)
{
	typedef void FUN(int a);
	FUN *p1;
	//p1 = test;
	p1 = &test;
	test(10);

	p1(10);

	void(*p2)(int a) = NULL;
	p2 = test;
	p2(12);

	typedef void(*FUNCP)(int a);
	FUNCP p3;
	p3 = test;
	p3(13);


	printf("\n");
	system("pause");
	return 0;
}


#endif
#include<stdlib.h>
#include<string.h>
#if 0
int my_add(int a, int b)
{
	return a + b;
}
int my_minus(int a, int b)
{
	return a - b;
}
int my_mul(int a, int b)
{
	return a*b;
}
int my_div(int a, int b)
{
	return a / b;
}
int main(void)
{
	char cmd[50];
	int a, b;

	while (1)
	{
		printf("请输入cmd.\n");
		scanf("%s %d %d", cmd, &a, &b);
		if (strcmp(cmd, "add") == 0)
		{
			printf("add=%d\n", my_add(a, b));
		}
		else if (strcmp(cmd, "my_minus") == 0)
		{
			printf("minus=%d\n", my_minus(a, b));
		}
		else if (strcmp(cmd, "mul") == 0)
		{
			printf("mul=%d\n", my_mul(a, b));
		}
		else if(strcmp(cmd, "div") == 0)
		{
		printf("div=%d\n", my_div(a, b));
		}
		else
		{
			printf("指针错误，重新输入\n");
		}
	}
	printf("\n");
	system("pause");
	return 0;
}


#endif
#if 0
int my_add(int a, int b)
{
	return a + b;
}

int my_min(int a, int b)
{
	return a - b;
}

int my_mul(int a, int b)
{
	return a*b;
}

int my_div(int a, int b)
{
	return a / b;
}

int test(int a, int b)
{
	return a%b;
}

int main(void)
{
	int(*p)(int a, int b) = my_add;
	printf("%d\n",p(1, 1));

	char *str[] = { "add","min","mul","div","test" };

	int(*tmp[])(int a, int b) = { my_add,my_min,my_mul,my_div,test};

	printf("%d\n", tmp[0](1, 2));

	int n = sizeof(tmp) / sizeof(tmp[0]);
	printf("%d\n", n);

	char cmd[50];
	int a, b;
	int i = 0;

	while (1)
	{
		printf("请输入cmd.\n");
		scanf("%s %d %d", cmd, &a, &b);
		for (i = 0; i < n; i++)
		{
			if (strcmp(cmd, str[i]) == 0)
			{
				printf("func =%d\n", (tmp[i])(a, b));
				break;
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
typedef void(*PFUNC)(int a);
typedef struct Test
{
	PFUNC func;
}Test;

void func1(int temp)
{
	printf("temp=%d\n", temp);
}

int main(void)
{
	Test obj;

	obj.func = func1;

	obj.func(10);
	printf("\n");
	system("pause");
	return 0;
}
#endif

#if 1
int my_add(int a, int b)
{
	return a + b;
}

int my_min(int a, int b)
{
	return a - b;
}

void func(int a, int b, int(*calc)(int a, int b))
{
	printf("func函数框架.\n");
	printf("回调结果是:%d\n", calc(a, b));
}

typedef int(*PFUNC)(int a, int b);
void func2(int a, int b, PFUNC calc)
{
	printf("func 函数框架.\n");
	printf("回调结果:%d\n", calc(a, b));
}

int main()
{
	func(1, 2, my_min);
	func2(1, 2, my_add);
	printf("\n");
	system("pause");
	return 0;
}
#endif
















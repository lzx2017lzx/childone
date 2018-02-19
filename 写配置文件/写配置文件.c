#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "menu.h"
int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("cmd: ");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			write_cfg_file();
			break;
		case 2:
			read_cfg_file();
			break;
		case 3:
			system("cls");
			break;
		case 4:
			exit(0);
			break;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

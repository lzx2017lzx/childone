#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	
	int i;
	for (i = 0; i < 100; i++)
	{
		char str[100] = { 0 };
		sprintf(str, "G:\\清理\\图片\\%d.jpg", i%11);
		SystemParametersInfoA(20, 0, str, 3);
		//sprintf(str, "g:\\ͼƬ\\%d.mp3", i % 4);
		ShellExecuteA(NULL,"open",str,0,0,SW_HIDE);
		Sleep(800);
	}
	return 0;
}
#include<windows.h>

//
//窗口过程函数
LRESULT CALLBACK WindowProc(
	HWND hwnd,//消息所在的窗口
	UINT uMsg,//获取到的消息
	WPARAM wParam,//附加信息，键盘信息
	LPARAM lParam //附加信息，鼠标信息
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(1);
		break;
	case WM_LBUTTONDOWN:
	
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		char *buf[64] = { 0 };
		wsprintf(buf, TEXT("x=%d,y=%d"), x, y);		
		MessageBox(hwnd, buf,TEXT("info"),MB_OK);
	}
		break;
	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("WM_KEYDOWN"), TEXT("info"), MB_OK);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT pPaint;
		HDC hdc=BeginPaint(hwnd, &pPaint);
		TextOut(hdc, 100, 300, TEXT("hello"), 5);
		EndPaint(hwnd, &pPaint);
	}
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS ws;//窗口类，创建窗口对象
	ws.cbClsExtra = 0;//类额外空间，通常为0
	ws.cbWndExtra = 0;//窗口额外空间，通常为0
	ws.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);//设置背景色。

	ws.hCursor = LoadCursor(NULL,IDC_CROSS);//设置光标，第一个参数为NULL采用系统提供的标准光标

	ws.hIcon = LoadIcon(NULL,IDI_ERROR);//设置图标，第一个参数为NULL采用系统提供的标准图标

	ws.hInstance = hInstance;//应用程序实例句柄，winMain函数第一个参数
	ws.lpfnWndProc = WindowProc;//窗口过程函数
	ws.lpszClassName = TEXT("win");//窗口类名
	ws.lpszMenuName = NULL;//设为NULL，表示没有菜单栏
	ws.style = 0;//最大化、最小化、放大、缩小，默认为0，是风格

	RegisterClass(&ws);

	HWND hWnd = CreateWindow(
		TEXT("win"),//窗口类名
		TEXT("winTest"),//窗口标题
		WS_OVERLAPPEDWINDOW,//风格，WS_OVERLAPPEDWINDOW组合风格
		200, 300,//窗口坐标
		1000,600,//窗口大小
		NULL,//设为NULL，没有父窗口
		NULL,//设为NULL，没有菜单栏
		hInstance,//应用程序实例句柄
		NULL
		);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (1)
	{
		BOOL ret = GetMessage(
			&msg,//获取到的消息
			NULL,//消息所在的窗口，设为NULL获取所有窗口的消息
			0,0//设为0，获取所有消息
			);

		if (FALSE==ret)
		{
			break;
		}

		TranslateMessage(&msg);


		DispatchMessage(&msg);

	}

	return 0;
}
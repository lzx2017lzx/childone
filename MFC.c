#include<windows.h>

//
//���ڹ��̺���
LRESULT CALLBACK WindowProc(
	HWND hwnd,//��Ϣ���ڵĴ���
	UINT uMsg,//��ȡ������Ϣ
	WPARAM wParam,//������Ϣ��������Ϣ
	LPARAM lParam //������Ϣ�������Ϣ
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
	WNDCLASS ws;//�����࣬�������ڶ���
	ws.cbClsExtra = 0;//�����ռ䣬ͨ��Ϊ0
	ws.cbWndExtra = 0;//���ڶ���ռ䣬ͨ��Ϊ0
	ws.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);//���ñ���ɫ��

	ws.hCursor = LoadCursor(NULL,IDC_CROSS);//���ù�꣬��һ������ΪNULL����ϵͳ�ṩ�ı�׼���

	ws.hIcon = LoadIcon(NULL,IDI_ERROR);//����ͼ�꣬��һ������ΪNULL����ϵͳ�ṩ�ı�׼ͼ��

	ws.hInstance = hInstance;//Ӧ�ó���ʵ�������winMain������һ������
	ws.lpfnWndProc = WindowProc;//���ڹ��̺���
	ws.lpszClassName = TEXT("win");//��������
	ws.lpszMenuName = NULL;//��ΪNULL����ʾû�в˵���
	ws.style = 0;//��󻯡���С�����Ŵ���С��Ĭ��Ϊ0���Ƿ��

	RegisterClass(&ws);

	HWND hWnd = CreateWindow(
		TEXT("win"),//��������
		TEXT("winTest"),//���ڱ���
		WS_OVERLAPPEDWINDOW,//���WS_OVERLAPPEDWINDOW��Ϸ��
		200, 300,//��������
		1000,600,//���ڴ�С
		NULL,//��ΪNULL��û�и�����
		NULL,//��ΪNULL��û�в˵���
		hInstance,//Ӧ�ó���ʵ�����
		NULL
		);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (1)
	{
		BOOL ret = GetMessage(
			&msg,//��ȡ������Ϣ
			NULL,//��Ϣ���ڵĴ��ڣ���ΪNULL��ȡ���д��ڵ���Ϣ
			0,0//��Ϊ0����ȡ������Ϣ
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
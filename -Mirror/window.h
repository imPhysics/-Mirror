//本文件主要定义了对窗口的操作、控制等
#define My_WINDOW

#ifndef VS_Windows
#define VS_Windows
#include<Windows.h>
#endif // !VS_Windows

#ifndef VS_STRING
#define VS_STRING
#include<string>
#endif // !VS_STRING

#ifndef My_SETTING
#include"setting.h"
#endif // !My_SETTING

#ifndef My_HARDWARE
#include"hardware.h"
#endif // !My_HARDWARE

//Main
extern int WndClassReg[1];

typedef enum
{
	Main = 0
}WndClassName;

class window {
private:
	//MemoryDC
	WndClassName eWndClassName;
	HINSTANCE hInstance;
public:
	HWND hWnd;
	window(WndClassName iWndClassName, HINSTANCE ihInstance);
	~window();
	int Show(int inShowCmd, int iWidth, int iHeight, int iX, int iY);
	int Rua();
};

LRESULT CALLBACK WndProc_Main(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
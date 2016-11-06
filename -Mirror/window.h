//本文件主要定义了对窗口的操作、控制等
#pragma once
#include<Windows.h>
#include<string>
#include"setting.h"

//Main
int * WndClassReg[1] = { 0 };

typedef enum WndClassName
{
	Main = 0
};

class window {
private:
	WndClassName eWndClassName;
	HINSTANCE hInstance;
public:
	HWND hWnd;
	window(WndClassName iWndClassName, HINSTANCE ihInstance);
	~window();
	HRESULT Show(int inShowCmd, int iWidth = 0, int iHeight = 0, int iX = 0, int iY = 0);
	HRESULT Rua();
};

LRESULT CALLBACK WndProc_Main(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
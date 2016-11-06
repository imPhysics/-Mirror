#include"window.h"

window::window(WndClassName iWndClassName, HINSTANCE ihInstance) 
{
	this->eWndClassName = iWndClassName;
	this->hInstance = ihInstance;
	if (*WndClassReg[this->eWndClassName] == 0)
	{
		WNDCLASSEX wndClass = { 0 };
		wndClass.cbSize = sizeof(WNDCLASSEX);
		switch (this->eWndClassName)
		{
		case Main:
			wndClass.lpfnWndProc = WndProc_Main;
			wndClass.lpszClassName = L"Main";
		default:
			throw iWndClassName;
		}
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = this->hInstance;
		wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndClass.lpszMenuName = NULL;

		if (!RegisterClassEx(&wndClass))
			throw wndClass;
	}
	*WndClassReg[this->eWndClassName]++;

	wchar_t *ClassName, *WndName;
	switch (this->eWndClassName)
	{
	case Main:
		ClassName = L"Main";
		WndName = ProcName L" - Version " ProcVersion;
	default:
		throw this->eWndClassName;
	}
	this->hWnd = CreateWindow(ClassName, WndName, WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT,
		1, 1, NULL, NULL, this->hInstance, NULL);
	if (this->hWnd == NULL)
		throw this->hWnd;
}

window::~window()
{
	if (*WndClassReg[this->eWndClassName] == 1)
		switch (this->eWndClassName)
		{
		case Main:
			UnregisterClass(L"Main", this->hInstance);
		default:
			throw this->eWndClassName;
		}
	*WndClassReg[this->eWndClassName]--;
}

HRESULT window::Show(int inShowCmd, int iWidth = 0, int iHeight = 0, int iX = 0, int iY = 0)
{
	if(iWidth != 0 && iHeight != 0)
		MoveWindow(this->hWnd, iX, iY, iWidth, iHeight, true);
	ShowWindow(this->hWnd, inShowCmd);
	UpdateWindow(this->hWnd);
	return S_OK;
}

HRESULT window::Rua()
{
	return E_NOTIMPL;
}

LRESULT CALLBACK WndProc_Main(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT paintStruct;

	switch (message)
	{
	case WM_PAINT:
		//g_hdc = BeginPaint(hwnd, &paintStruct);
		//EndPaint(hwnd, &paintStruct);
		ValidateRect(hwnd, NULL);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)//如果被按下的键是ESC
			DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
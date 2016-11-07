#define My_MAIN

#ifndef _WIN64
#error "Not Support Any Other System"
#endif //_WIN64

#ifndef VS_Windows
#define VS_Windows
#include<Windows.h>
#endif // !VS_Windows

#ifndef My_HARDWARE
#include"hardware.h"
#endif // !HARDWARE

#ifndef My_SETTING
#include"setting.h"
#endif // !SETTING

#ifndef My_WINDOW
#include"window.h"
#endif // !WINDOW
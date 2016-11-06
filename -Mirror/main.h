#pragma once
#include"hardware.h"
#include"setting.h"

#ifdef _WIN64
#include<Windows.h>
#include"window.h"
#else
#error "Not Support Any Other System"
#endif //_WIN64
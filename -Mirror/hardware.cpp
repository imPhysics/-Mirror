#include "hardware.h"

hardware::hardware()
{
	this->DisplayPixelMaxX = GetSystemMetrics(SM_CXSCREEN);
	this->DisplayPixelMaxY = GetSystemMetrics(SM_CYSCREEN);
	LARGE_INTEGER CurrectTime;
	QueryPerformanceCounter(&CurrectTime);
	LestCPUOscillationCount = CurrectTime.QuadPart;
}

hardware::~hardware() {}

LONGLONG hardware::QueryCPUFrequency()
{
	LARGE_INTEGER CPUFreq;
	QueryPerformanceFrequency(&CPUFreq);
	return CPUFreq.QuadPart;
}

double hardware::QueryTimeInterval()
{
	LARGE_INTEGER CurrectTime;
	QueryPerformanceCounter(&CurrectTime);
	return (double)(CurrectTime.QuadPart - this->LestCPUOscillationCount) / (double)this->QueryCPUFrequency();
}

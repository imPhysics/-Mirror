//���ļ��㼯�� Ӳ����ش���
#define My_HARDWARE

#ifndef VS_Windows
#define VS_Windows
#include<Windows.h>
#endif // !VS_Windows

class hardware {
private:
	LONGLONG LestCPUOscillationCount;
public:
	int DisplayPixelMaxX;
	int DisplayPixelMaxY;
	int MaxFrame = 60;

	hardware();
	~hardware();

	LONGLONG QueryCPUFrequency();
	double QueryTimeInterval();
};
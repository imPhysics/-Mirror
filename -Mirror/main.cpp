#include"main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd) {
	hardware * Hardware = new hardware();
	window * Window = new window(Main, hInstance);
	if (Window->Show(nShowCmd, 800, 600, 200, 200)) return -1;
	if (Window->Rua())	return -1;
	delete Window;
	return 0;
}
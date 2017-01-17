#pragma once
#include <Windows.h>
#include <process.h>
using namespace std;


#define WINTHREADEX_RUNNING 2
#define WINTHREADEX_PAUSE 4

class WinThreadEx
{
private:
	HANDLE Thread;
	DWORD ThreadID;
	DWORD ExitCode;
	int ThreadState = 0;
public:
	WinThreadEx(LPVOID ThreadFunction, LPVOID FunctionPara, DWORD ExitCode ,bool StartRightNow = false);
	~WinThreadEx();

	void Resume();
	void Suspend();
	void Abort();
	bool IsAlive();
	int GetThreadState();
};


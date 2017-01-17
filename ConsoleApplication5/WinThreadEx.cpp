#include "WinThreadEx.h"



WinThreadEx::WinThreadEx(LPVOID ThreadFunction,LPVOID FunctionPara, DWORD ExitCode_,bool StartRightNow )
{
	this->ExitCode = ExitCode_;
	Thread = CreateThread(0, 0, LPTHREAD_START_ROUTINE(ThreadFunction), FunctionPara, CREATE_SUSPENDED, &ThreadID);
	StartRightNow ? Resume(), ThreadState = WINTHREADEX_RUNNING : ThreadState = WINTHREADEX_PAUSE;
}


WinThreadEx::~WinThreadEx()
{
}

void WinThreadEx::Resume()
{
	//_beginthread()
	ThreadState = WINTHREADEX_RUNNING;
	ResumeThread(Thread);
}

void WinThreadEx::Suspend()
{
	ThreadState = WINTHREADEX_PAUSE;
	SuspendThread(Thread);
}

void WinThreadEx::Abort()
{
	TerminateThread(Thread, 0);
	CloseHandle(Thread);
	
}

bool WinThreadEx::IsAlive()
{
	DWORD *exitCode = new DWORD();
	GetExitCodeThread(Thread, exitCode);
	if (*exitCode == this->ExitCode)
	{
		delete exitCode;
		return false;
	}
	delete exitCode;
	return true;
}

int WinThreadEx::GetThreadState()
{
	return this->ThreadState;
}

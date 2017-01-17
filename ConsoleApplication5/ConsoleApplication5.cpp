// ConsoleApplication5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "WinThreadEx.h"
#include <list>

#define SleepSecond 500

DWORD WINAPI threadFunction(int* a)
{
	while (1) {
		cout << *a <<endl;
		Sleep(SleepSecond);
		
	}
	return 1;
}

DWORD WINAPI threadFunction1()
{
	while (1)
	{
		cout << "Bye" << endl;
		Sleep(SleepSecond);
	}
	return 0;
}

DWORD WINAPI threadFunction2()
{
	while (1)
	{
		cout << "Hey" << endl;
		Sleep(SleepSecond);
	}
	return 0;
}

int main()
{
	bool isA = false;
	bool isB = false;
	bool isC = false;
	static int* a = new int (5);

	WinThreadEx* m_Thread = new WinThreadEx(threadFunction, a,0);
	m_Thread->Resume();
	WinThreadEx* m_Thread1 = new WinThreadEx(threadFunction1, 0,0);
	m_Thread1->Resume();

	list<WinThreadEx*> m_ThreadList;
	while (1)
	{
		
		char ch = getch();
		cout << ch << "Pressed" <<endl;
		if (ch == '1')
		{
			if(isA)
				m_Thread->Resume();
			else
				m_Thread->Suspend();
			isA = !isA;
		}
		if (ch == '2')
		{
			if (isB)
				m_Thread1->Resume();
			else
				m_Thread1->Suspend();
			isB = !isB;
		}
		if (ch == '3')
		{
			if (isC)
				m_Thread = new WinThreadEx(threadFunction, &a,0,true);
			else
				m_Thread->Abort();
			isC = !isC;
		}
		if (ch == '4')
		{
			
			m_Thread->Abort();
			
		}
		if (ch == '5')
		{
			cout << m_Thread->IsAlive() << endl;
		}
		
	}
    return 0;
}


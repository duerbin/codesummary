
//CBaseThread.h 
//base class of thread opration

#pragma once

#if !defined(AFX_BASETHREAD_H__2150A70D_EE7C_4754_B9D7_FA7FF5E86990__INCLUDED_)
#define AFX_BASETHREAD_H__2150A70D_EE7C_4754_B9D7_FA7FF5E86990__INCLUDED_


#include<IceUtil/Thread.h>
#include<IceUtil/Monitor.h>
#include<Ice/Ice.h>
#include<string>
//typedef unsigned int UINT;
typedef void * LPVOID;
class CBaseThread:public IceUtil::Thread
{
private:
	bool  m_bRunning;
	IceUtil::Monitor<IceUtil::Mutex> m_StopMonitor;
	virtual void run();
public:
	virtual bool Stop();
	bool Start(unsigned int t= 0);
	CBaseThread();
	CBaseThread(char* thName);
	virtual ~CBaseThread();
	bool IsRunning();
	void Sleep(unsigned int milliseconds );
		void setRunning(bool );
	bool IsExit();
protected:
	virtual int ControlFunc(LPVOID lpParam) = 0;

	char m_strName[64];
	
};
typedef IceUtil::Handle<CBaseThread> CBaseThreadPtr;
#endif // !defined(AFX_BASETHREAD_H__2150A70D_EE7C_4754_B9D7_FA7FF5E86990__INCLUDED_)

#include "basethread.h"
#include <stdio.h>
#include <string.h>
#ifndef WIN32
#include <sys/select.h>
#include "sys/time.h"
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBaseThread::CBaseThread(): m_bRunning(false)
{

};
CBaseThread::CBaseThread(char* strname):m_bRunning(false)
{
	strcpy(m_strName,strname);
};

CBaseThread::~CBaseThread()
{

};
void CBaseThread::run()
{
	ControlFunc(NULL);
	m_bRunning=false;
};
bool CBaseThread::Start(unsigned int t)
{
	m_bRunning=true;
	 Thread::start(t);
	return true;
};

bool CBaseThread::Stop()
{
	if(m_bRunning==false)
		return true;
	//终止事件接收线程
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock mylock(this->m_StopMonitor);
		m_bRunning=false;
		this->m_StopMonitor.notify();
	}
	IceUtil::ThreadControl control=getThreadControl();

	control.join();

	return true;
};

bool CBaseThread::IsExit()
{
	return !m_bRunning;
};

bool CBaseThread::IsRunning()
{
	return m_bRunning;
};
void CBaseThread::Sleep(unsigned int milliseconds )
{
	//IceUtil::Monitor<IceUtil::Mutex>::Lock mylock(this->m_StopMonitor);
	//this->m_StopMonitor.timedWait(IceUtil::Time::milliSeconds(milliseconds));
	#ifndef WIN32
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 1000*milliseconds;
		select( 0, NULL, NULL, NULL, & timeout );
	#else
		::Sleep(milliseconds);
	#endif

};

void CBaseThread::setRunning(bool para)
{
	this->m_bRunning=para;
}

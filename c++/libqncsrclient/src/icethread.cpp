// ICEThread.cpp: implementation of the CICEThread class.
//
//////////////////////////////////////////////////////////////////////

#include <Ice/Ice.h>
#include <Ice/Communicator.h>
#include "icethread.h"
#include "qncsrinterface.h"
#include "log.h"
#include "common.h"
#include "commontools.h"

#include <sstream>
#include <iostream>
#define UINT unsigned int
using namespace QNCSR;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void ResultCallbackProxyI::sendStreamResult(const ::std::string& sessionid, const ::std::string& result, const ::Ice::Current& current)
{
	LINFO("[recv] sessionid:"<<sessionid<<" result:"<<result);
	g_callBackFun(sessionid.c_str(),result.c_str());

	//ResultData data;
	//data.strsessionid=sessionid;
	//data.strresult=result;
	//g_queResultData.put(data);
}


CICEThread::CICEThread(const string& servername_callback,const string& ipinfo_callback,const string& strIce_qncsr):m_servantname_callback(servername_callback),m_ipinfo_callback(ipinfo_callback),m_strIceQncsr(strIce_qncsr)
{
	m_status=0;
}

CICEThread::~CICEThread()
{
}

int CICEThread::ControlFunc(LPVOID lpParam)
{
		LINFO("[icethread] xxxxxxruning ");
		while (true)
		{
			if(m_status==-2)
			{
				if(this->initQncsrClient(m_strIceQncsr)==true)
				{
					m_status=0;
					LINFO("[icethread] reconect qncsrservice="<<m_strIceQncsr<<";success");
				}
				if(this->sendCallbackProxy()==true)
				{
					m_status=0;
					LINFO("[icethread] reconect set callbackproxy;success ");
				}
				LINFO("[icethread] need recoonect;but failed ");
			}
			LINFO("[icethread]xxxxxxxxxxxx runing ");
			CTOOLS::MySleep(1000*5);
		}
		m_pComm->waitForShutdown();
		return 0;
}

int CICEThread::Init()
{
	m_status=0;
	try
	{
		LINFO("ice thread ipinfo:"<<m_ipinfo_callback<<" servantname:"<<m_servantname_callback);
		int m_argc = 0;
		Ice::InitializationData initData;
		m_pComm = Ice::initialize( m_argc,NULL,initData );

		m_pComm->getProperties()->setProperty("Ice.ThreadPool.Server.Size", "50");
		m_pComm->getProperties()->setProperty("Ice.ThreadPool.Server.SizeWarn", "50");
			
		Ice::ObjectAdapterPtr adaptee = m_pComm->createObjectAdapterWithEndpoints ("QNCSR","default: -p 16010");
		Ice::ObjectPtr obj = new ResultCallbackProxyI;	

		adaptee->add(obj,m_pComm->stringToIdentity(m_servantname_callback));
		//adaptee->add(obj,m_pComm->stringToIdentity(m_servantname_callback));
		
		 m_receive=ResultCallbackProxyPrx::uncheckedCast(adaptee->createProxy(m_pComm->stringToIdentity(m_servantname_callback)));
		if(!m_receive)
		{
			LERROR("callback proxy create error");
			m_status=-1;
		}
		
		adaptee->activate();
	}
	catch ( const Ice::Exception& e ) 
	{
		m_status = -1;
		LERROR("catch exception "<<e.ice_name()<<"file:"<<e.ice_file()<< "line: "<<e.ice_line());
	}
	catch ( const char* msg ) 
	{
		m_status = -1;
		LERROR("catch exception:"<<msg);
	}
	catch( string& strE )
	{
		m_status = -1;
		LERROR("catch exception:"<<strE);
	}
	catch( ... )
	{
		m_status = -1;
		LERROR("init failede");
	}	
	
		
	if( m_status != -1 )
	{
		if(initQncsrClient(m_strIceQncsr)==false)
		{
			LERROR("init qncsrclient connect qncsr error "<<m_strIceQncsr);
		}
		else
		{
			LINFO("[icethread] initok");
		}
	}
	return m_status;
}


bool CICEThread::Stop()
{
	if( m_pComm )
	{
		m_pComm->destroy();
		m_pComm = NULL;
	}
	return CBaseThread::Stop();
}

void CICEThread::run()
{	
	this->m_status=ControlFunc(NULL);
	bool para=false;
	//gInitIce=true;
	//IceUtil::Monitor<IceUtil::Mutex>::Lock lock(gIceMonitor);
	//gIceMonitor.notify();
	CBaseThread::setRunning(para);	
}



bool CICEThread::initQncsrClient(const string& strice_qncsr)
{
	try{
		Ice::ObjectPrx base=m_pComm->stringToProxy(strice_qncsr);
		m_qncsrclient=StreamInterfacePrx::checkedCast(base);
		if(!m_qncsrclient)
			throw "Invaild proxy";
	}
	catch (const Ice::Exception & ex) 
	{
		//m_IC->destroy();
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "connect to qncsr failed "<<myStream.str());
		return false;
	}
	catch (const char * msg) 
	{
		//m_IC->destroy();
		LERROR( "connect to qncsr failed error "<<msg );
		return false;
	}
	return true;	
}

bool CICEThread::sendCallbackProxy()
{
	if(!m_receive)
	{
		LERROR("callback proxy is null,need restart")
		m_status=-2;
		return false;
	}
	try
	{
		m_qncsrclient->initCallbackProxy(m_receive);
	}
	catch (const Ice::ConnectionRefusedException &ex)
	{
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "sendcallbackproxy qncsr failed "<<myStream.str());
		m_status=-2;
		return false;
	}
	catch (const Ice::Exception & ex) 
	{
		//m_IC->destroy();
		stringstream myStream;
		myStream<< ex << endl;
		m_status=-2;
		LERROR( "sendcallbackproxy qncsr failed "<<myStream.str());
		return false;
	}
	catch (...) 
	{
		//m_IC->destroy();
		LERROR( "sendcallbackproxy qncsr failed error " );
		m_status=-2;
		return false;
	}
	LINFO("initcallbackproxy success;now test");
	string  tmp="testiddd";
	sendStreamData("testid",tmp,8);
	return true;
}


int CICEThread::sendStreamData(const string& sessionid,const std::string& strData,int sampbit)
{
	if(!m_qncsrclient)
	{
		LERROR("[send] csrclient null ;reconnect ");
		m_status=-2;
		return -1;
	}
	try{
		m_qncsrclient->sendStreamData(sessionid,strData,sampbit);
		LINFO("[send] success; sessionid:"<<sessionid<<" length: "<<strData.size()<<" sampbit: "<<sampbit);
		return 0;
	}
	catch (const Ice::ConnectionRefusedException &ex)
	{
		m_status=-2;
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "sendstreamdata to qncsr failed "<<myStream.str());
		return -1;
	}
	catch (const Ice::Exception &ex)
	{
		m_status=-2;
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "sendstreamdata to qncsr failed "<<myStream.str());
		LERROR("[send] failed; sessionid:"<<sessionid<<" length: "<<strData.size()<<" sampbit: "<<sampbit);
		return -1;
	}
	catch (...)
	{
		LERROR("[send] failed; sessionid:"<<sessionid<<" length: "<<strData.size()<<" sampbit: "<<sampbit);
		return -1;
	}
}

int CICEThread::sendPackageData(const string& channelid,const std::string& strPackageData)
{
	if(!m_qncsrclient)
	{
		LERROR("[send] csrclient null ;reconnect ");
		m_status=-2;
		return -1;
	}

	try
	{
		m_qncsrclient->sendPackageData(channelid,strPackageData);
		LINFO("[send] success; channelid:"<<channelid<<" package: "<<strPackageData);
		return 0;
	}
	catch (const Ice::ConnectionRefusedException &ex)
	{
		m_status=-2;
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "sendpackagedata to qncsr failed "<<myStream.str());
		return -1;
	}
	catch (const Ice::Exception &ex)
	{
		m_status=-2;
		stringstream myStream;
		myStream<< ex << endl;
		LERROR( "sendpackagedata to qncsr failed "<<myStream.str());
		LERROR("[send] failed; channelid:"<<channelid);
		return -1;
	}
	catch (...)
	{
		LERROR("[send] failed; channelid:"<<channelid);
		return -1;
	}
}

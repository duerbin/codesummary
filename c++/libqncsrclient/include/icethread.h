// ICEThread.h: interface for the CICEThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICETHREAD_H__80B269EC_583C_4144_BC59_81347C4C5CDB__INCLUDED_)
#define AFX_ICETHREAD_H__80B269EC_583C_4144_BC59_81347C4C5CDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "basethread.h"
#include "qncsrinterface.h"
#include <string>
#include <list>
using namespace std; 
using namespace csr;
namespace QNCSR
{
	class ResultCallbackProxyI : public ResultCallbackProxy
	{
	public:
		ResultCallbackProxyI()
		{

		}
		virtual	~ResultCallbackProxyI()
		{

		}
	public:
		virtual void sendStreamResult(const ::std::string& sessionid, const ::std::string& strresult,const Ice::Current&);
		//int getStreamResult(const std::string sessionid,const std::string result);		
	};



	class CICEThread : public CBaseThread  
	{
	private:
		Ice::CommunicatorPtr m_pComm;

	public:
		CICEThread(const std::string&,const std::string&,const std::string&);
		CICEThread();
		virtual ~CICEThread();
		int ControlFunc(LPVOID lpParam);  
		bool Stop();
		void run();
		int Init();
	private:
		int m_status;
		string m_servantname_callback;
		string m_ipinfo_callback;
		string m_strIceQncsr;
		ResultCallbackProxyPrx m_receive;
		StreamInterfacePrx m_qncsrclient;
		bool m_needReconnect;
	public:
		bool sendCallbackProxy();
		bool initQncsrClient(const string& strice_qncsr);
		int sendStreamData(const string& channelid,const std::string& strData,int sampbit);	
		int sendPackageData(const string& channelid,const std::string& strData);	

	};
	typedef IceUtil::Handle<CICEThread> CICEThreadPtr;
};
#endif // !defined(AFX_ICETHREAD_H__80B269EC_583C_4144_BC59_81347C4C5CDB__INCLUDED_)

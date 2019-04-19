//*******************************************************
//  @filename:	qncsrclientAdapterImp.h
//  @function:	Implementation of the qncsrclientAdapter.h
//  @author: 	dueb
//*******************************************************

#pragma once


#include <string>
#include "qncsrclientAdapter.h"
#include "inifile.h"
#include "log.h"
#include "icethread.h"
#include "qncsrinterface.h"
#include "safequeue.h"

namespace QNCSR
{

	struct SConfigInfo
	{
		string strIce_qncsr;
		string strIce_callback;
		string strLogconfigpath;
		int iLoglevel;
	};



	class CQncsrClient
	{
	public:
		CQncsrClient();
		virtual ~CQncsrClient();

	public:
		int initialize(const char* strConfigfile);
		int sendStreamData(const std::string& strSessionid, const std::string& strData,const int iSamplingBit);
		int sendPackageData(const std::string& strChannelid, const std::string& strPackage);
		int getStreamResult(string& strSessionid,string& strResult); 
	private:
		bool create_icethread();
	private:
		bool m_initOK;
		comLib::IniFile* m_inifilePtr;
		SConfigInfo m_configInfo;
		CICEThread* m_icethread;
		StreamInterfacePrx m_qncsrclient;
	};	
};




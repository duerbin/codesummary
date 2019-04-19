//*******************************************************
//  @filename:	qncsrclientAdapterImp.cpp
//  @function:	Implementation of the qncsrclientAdapter.h
//  @author: 	dueb
//*******************************************************
#include <vector>
#include "commontools.h"
#include "common.h"
#include "qncsrclientAdapterImp.h"
using namespace QNCSR;
CQncsrClient::CQncsrClient()
{
	m_initOK=false;
	m_inifilePtr=new comLib::IniFile();
	m_icethread=NULL;
}

CQncsrClient::~CQncsrClient()
{
	if(m_inifilePtr!=NULL)
		delete m_inifilePtr;
}


int CQncsrClient::initialize(const char* strConfigfile)
{
	if(m_initOK)
	{
		std::cout<<"CQncsrClient init OK"<<std::endl;
		return 0;
	}

	
	if(m_inifilePtr->LoadIniFile(strConfigfile)==false)
	{
		std::cout<<"load inifile error"<<std::endl;
		return -1;
	}

	m_configInfo.strIce_qncsr=m_inifilePtr->GetString("csrserver","ice_qncsr","qncsrinterface:tcp -h 10.130.41.230 -p 16109");	
	m_configInfo.strIce_callback=m_inifilePtr->GetString("csrserver","ice_callback","qncsrcallback:tcp -h 10.130.74.55 -p 16110");
	m_configInfo.strLogconfigpath=m_inifilePtr->GetString("logconfig","configfile","./cfg/qncsrclent_log4cpp.confg");
	m_configInfo.iLoglevel=m_inifilePtr->GetInteger("logconfig","loglevel",5);

	if(log::ins()->init(m_configInfo.strLogconfigpath.c_str(),"qncsrc")==false)
	{
		std::cout<<"qncsrclient config error"<<std::endl;
		return -1;
	}
	LINFO("[conf] strIce_qncsr: "<<m_configInfo.strIce_qncsr);
	LINFO("[conf] strIce_callback: "<<m_configInfo.strIce_callback);
	LINFO("[conf] strLogconfpath: "<<m_configInfo.strLogconfigpath);
	LINFO("[conf] iLoglevel: "<<m_configInfo.iLoglevel);

	if(create_icethread()==true)
	{
		LINFO("qncsrclient load success");
	}
	else
	{
		LERROR("qncsrclient load error");
		return -1;
	}

	return 0;		
}


bool CQncsrClient::create_icethread()
{
	string addresssinfo=m_configInfo.strIce_callback;
	vector<string> listAdd=CTOOLS::stringSplit(addresssinfo,":");
	if(listAdd.size()!=2)
	{
		LERROR("ice server addressinfo error:"<<addresssinfo);
		return false;
	}
	string servantnamne=listAdd[0];
	string ipinfo=listAdd[1];
	if(servantnamne.empty() || ipinfo.empty())
	{
		LERROR("ice server addressinfo error:"<<addresssinfo);
		return false;
	}

	m_icethread=new CICEThread(servantnamne,ipinfo,m_configInfo.strIce_qncsr);
	m_icethread->Init();

	m_icethread->Start();

	CTOOLS::MySleep(2);
	if(m_icethread->sendCallbackProxy()==false)
	{
		LERROR("send callback proxy error");
		return false;
	}
	return true;

}

int CQncsrClient::sendStreamData(const std::string& strsessionid, const std::string& strData,const int iSamplingBit)
{
	int iret= m_icethread->sendStreamData(strsessionid,strData,iSamplingBit);
	LINFO("##send streamdata result="<<iret);
	return iret;
}


int CQncsrClient::getStreamResult(std::string& strSessionid, std::string& strResult)
{
	ResultData tmp;
	if(g_queResultData.timedGet(tmp,1)==true)
	{
		strSessionid=tmp.strsessionid;
		strResult=tmp.strresult;
		LINFO("[get] sessionid:"<<strSessionid<<" result:"<<strResult<<" queuesize:"<<g_queResultData.size());
		return 0;
	}
	else
	{
		LINFO("[get] queuesize: 0");
		return -1;
	}
}

int CQncsrClient::sendPackageData(const std::string& strChannelid, const std::string& strPackage)
{

	int iret= m_icethread->sendPackageData(strChannelid,strPackage);
	LINFO("##send packagedata result="<<iret);
	return iret;
}

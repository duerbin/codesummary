//*******************************************************
//  @filename:	qncsrclientAdapter.cpp
//  @function:	Implementation of the qncsrclientAdapter.h
//  @author: 	dueb
//*******************************************************
//
#include "qncsrclientAdapter.h"
#include "qncsrclientAdapterImp.h"
#include "commontools.h"
#include "common.h"
#include "inifile.h"
#include <stdlib.h>
#include <string.h>
using namespace QNCSR;
QNCSR::CQncsrClient* g_qncsrclientPtr=NULL;


int QNCSR_initialize(const char* strConfigfile,CallBackFun pCallBackFun)
{
	if(!CTOOLS::IsFileExist(strConfigfile))
	{
		std::cout<<"QNCSR_initialize error configfile not exist: "<<strConfigfile<<endl;
		return -1;
	}
	if (g_qncsrclientPtr==NULL)
	{
		g_qncsrclientPtr= new QNCSR::CQncsrClient();
	}
	if(g_qncsrclientPtr==NULL)
	{
		return -1;
	}
	if(!pCallBackFun)
	{
		return -1;
	}
	g_callBackFun=pCallBackFun;
	return g_qncsrclientPtr->initialize(strConfigfile);

}

int QNCSR_sendStreamData(const char* strSessionid, const char* strdata, long lDataLen, const int iSamplingBit)
// int QNCSR_sendStreamData(const std::string& strSessionid, const std::string& strdata,const int iSamplingBit)
{
	std::cout<<"QNCSR_sendStreamData start" << std::endl;
	if(!strSessionid || !strdata)
	{	
		std::cout<<"QNCSR_sendStreamData info NULL" << std::endl;
		return -1;
	}
	if(strlen(strSessionid) == 0 || 
			lDataLen == 0)
	{
		std::cout<<"QNCSR_sendStreamData length error," << strlen(strSessionid) << ", " << lDataLen << std::endl;
		return -1;
	}
	
	string strSendData(strdata, lDataLen);
	std::cout<<"QNCSR_sendStreamData seesion:" << strSessionid << "length:"<<lDataLen<< std::endl;
	int iret= g_qncsrclientPtr->sendStreamData(strSessionid,strSendData,iSamplingBit);
	std::cout<<"QNCSR_sendStreamData over=== " << iret<<std::endl;
	return iret;
}


//int QNCSR_getStreamResult(std::string& strSessionid, std::string& strResult)
int QNCSR_getStreamResult(const char* strSessionid, char** strResult)
{
	if(!strSessionid ||
		strlen(strSessionid) == 0)
	{
		return -1;
	}

	string strID(strSessionid);
	string strStreamResult;
	int iResult;
	
	iResult = g_qncsrclientPtr->getStreamResult(strID, strStreamResult);
	{
		int iStrLength = strStreamResult.length();
		if(iStrLength < 1)
			return -1;

		iStrLength++;
		*strResult = (char*)malloc((iStrLength)*sizeof(char));
		if((*strResult) == NULL)
			return -1;
	
		memset(*strResult, 0, iStrLength);
		strStreamResult.copy(*strResult, iStrLength, 0);
		(*strResult)[iStrLength-1] = '\0';
	}	
	
	return iResult;
}

int QNCSR_sendPackageData(const char* strChannelid,const char* strPackage)
{
	if(!strChannelid ||
		strlen(strChannelid) == 0)
	{
		return -1;
	}
	if(!strPackage || strlen(strPackage)==0)
	{
		return -1;
	}
	string strChannel(strChannelid);
	string strPack(strPackage);
	int iret= g_qncsrclientPtr->sendPackageData(strChannel,strPack);
	std::cout<<"[Send Package] channelid is "<<strChannel<<std::endl;
	std::cout<<"[Send Package] Package content is "<<strPack<<std::endl;
	return iret;
}

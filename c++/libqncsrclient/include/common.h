#if !defined(AFX_COMMON_H__80B269EC_583C_4144_BC59_81347C4C5CDB__INCLUDED_)
#define AFX_COMMON_H__80B269EC_583C_4144_BC59_81347C4C5CDB__INCLUDED_
#include <string>
#include "qncsrclientAdapter.h"
#include "safequeue.h"
//namespace QNCSR
//{
	struct ResultData
	{
		std::string strsessionid;
		std::string strresult;
	};

	extern SafeQueue<ResultData> g_queResultData;

	extern CallBackFun g_callBackFun;
//};
#endif


#if!defined(__QNCSR_CLINENT_INTERFACE_H)
#define __QNCSR_CLINENT_INTERFACE_H

//dll init macro (common use)
#ifdef WIN32
	#ifdef __cplusplus
		#define SYMBOL_EXPORT_DECL extern "C" __declspec(dllexport)
		#define SYMBOL_IMPORT_DECL extern "C" __declspec(dllimport)
		#define SYMBOL_EXPORT_CPP_DECL extern __declspec(dllexport)
		#define SYMBOL_IMPORT_CPP_DECL extern __declspec(dllimport)
		#define SYMBOL_EXPORT_CPP_CLASS_DECL __declspec(dllexport)
		#define SYMBOL_IMPORT_CPP_CLASS_DECL __declspec(dllimport)
	#else
		#define SYMBOL_EXPORT_DECL __declspec(dllexport)
		#define SYMBOL_IMPORT_DECL __declspec(dllimport)
	#endif
#else
	#ifdef __cplusplus
		#define SYMBOL_EXPORT_DECL extern "C"
		#define SYMBOL_IMPORT_DECL extern "C"
		#define SYMBOL_EXPORT_CPP_DECL extern
		#define SYMBOL_IMPORT_CPP_DECL extern
		#define SYMBOL_EXPORT_CPP_CLASS_DECL
		#define SYMBOL_IMPORT_CPP_CLASS_DECL
	#else
		#define SYMBOL_EXPORT_DECL extern
		#define SYMBOL_IMPORT_DECL extern
	#endif
#endif

//define macro in makefile 
#ifdef QNCSRCLIENTDLL_EXPORTS
#define QNCSR_API SYMBOL_EXPORT_DECL
#else
#define QNCSR_API SYMBOL_IMPORT_DECL
#endif 
#include <string>
typedef int (*CallBackFun)(const char* ,const char*); 
#ifdef __cplusplus
extern "C" {
#endif

//function
//
//

	/**
	* 初始化
	* @param  strConfigfile:配置文件(文件地址)
	* @param strLogFilePath: 日志目录
	* @return int: 0 成功, -1 初始化失败
	*/
	QNCSR_API int QNCSR_initialize(const char* strConfigfile,CallBackFun pCallBackFun);



	/**
	* 释放dll
	* @return int: 0 成功, -1 初始化日志失败
	*/
	QNCSR_API int QNCSR_uninitialize();



	/**
	* 发送rtp数据
	* @param  strChannelid:唯一id
	* @param  strData:数据信息	
	* @param  iSamplingBit	
	* @return int: 0 成功, -1 para error
	*/
	QNCSR_API int QNCSR_sendStreamData(const char* strChannelid, const char* strData, long lDataLen, int iSamplingBit);
//	QNCSR_API int QNCSR_sendStreamData(const std::string& strSessionid, const std::string& strData,int iSamplingBit);

	/**
	* 发送结果
	* @param  strChannelid:唯一id
	* @param  strResult:结果字符串		
	* @return int: 0 成功, -1 初始化失败
	*/
	QNCSR_API int QNCSR_getStreamResult(const char* strChannelid, char** strResult);

	/**
	* 发送协议包 包含业务数据 sessionid channelid,phone
	* @param  strChannelid:唯一id 
	* @param  strPackage:数据包
	* @return int: 0 成功, -1 para error 
	*/
	QNCSR_API int QNCSR_sendPackageData(const char* strChannelid,const char* strPackage);

	





#ifdef __cplusplus
}
#endif
#endif


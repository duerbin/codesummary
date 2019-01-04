////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (C) 2014,ChannelSoft(版权声明)
/// All rights reserved.
///
/// @file COMMONTOOLS.H    
/// @brief
///
/// 详述：
///
/// @author	lenovo
/// @date	2014/9/3 10:41
///
///
/// 修订说明:最新说明
////////////////////////////////////////////////////////////////////////////////
//#pragma warning(disable:4996)   //全部关掉
#pragma warning(once:4996)      //仅显示一个
#ifndef _commontools_h_
#define _commontools_h_


//#pragma warning(disable:4996)   //全部关掉
#pragma warning(once:4996)      //仅显示一个
#include <ctime>
#ifdef WIN32

#include <WinSock2.h>
#define    WIN32_LEAN_AND_MEAN   
#include <windows.h>

#pragma comment( lib,"ws2_32.lib" )
#else
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <errno.h> 
#include <iconv.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#endif

#ifdef WIN32
#include <objbase.h>
#else
#include <uuid/uuid.h>
#endif


#ifdef _WIN32
#define MYSNPRINTF _snprintf
#define MYSTRCMP stricmp
#define THREAD_INFO GetCurrentThreadId()
#else
#define MYSNPRINTF snprintf
#define MYSTRCMP strcasecmp
#define sprintf_s(buffer,size,format, ...) sprintf(buffer,format,__VA_ARGS__)
#define SERVICE_RUNNING 0x00000004
#define SERVICE_STOPPED 0x00000001
#define THREAD_INFO ((unsigned int) pthread_self)
#endif



typedef unsigned long ULONG;
using namespace std;
/// \brief 工具类，包过常用的函数
/// 
namespace COMMONUTILS
{
	static int DeleteFile(string path)
	{
		if(remove(path.c_str()) != 0)
		{
			return errno;
		}
		return 0;
	}

	static bool MkDir(string path,int mode)
	{
		string tmp;
		DIR* pDir = NULL;
		std::string::size_type idx = 1;
		while(1)
		{
			idx = path.find("/",idx+1);
			tmp.assign(path,0,idx);
			pDir = opendir(tmp.c_str());
			if(pDir == NULL)
			{
				if(mkdir(tmp.c_str(),mode) == 0)
				{
					if(chmod(tmp.c_str(),mode) != 0)
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				continue;
			}
			if(idx == std::string::npos || idx > path.length())
			{
				break;
			}
		}
		return true;
	}

	static std::string StringToLower( const std::string s )
	{
		std::string str(s.c_str());
		char* tmp = (char*)str.c_str();

		while( *tmp )  
		{
			if( *tmp >= 0x41 && *tmp <= 0x5a )
				*tmp += 0x20;
			tmp++;
		}

		return str;
	}

	static std::vector<std::string> stringSplit(std::string str,std::string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str+=pattern;//扩展字符串以方便操作
		int size=str.size();

		for(int i=0; i<size; i++)
		{
			pos=str.find(pattern,i);
			if(pos<size)
			{
				std::string s=str.substr(i,pos-i);
				result.push_back(s);
				i=pos+pattern.size()-1;
			}
		}
		return result;
	}
	static std::string StringSubstr(std::string str,std::string pattern)
	{
		std::string::size_type pos;
		pos=str.find(pattern);
		if (pos==std::string::npos)
		{
			return "";
		}
		else
			return str.substr(0,pos);
	}


	static bool IsExtent(std::string dir,std::string ext)
	{
		if(dir.rfind(ext)==dir.size()-ext.size())
			return true;
		else
			return false;
	}

	static std::string GetCurrentStringTime(void)
	{
		char tmp[100];
		time_t tim_t;
		time( &tim_t );
		struct tm struTm;
		struTm = *(localtime( &tim_t ));
		sprintf( tmp,"%d-%02d-%02d %02d:%02d:%02d",
			struTm.tm_year + 1900,struTm.tm_mon + 1,struTm.tm_mday,struTm.tm_hour,struTm.tm_min,struTm.tm_sec );

		return tmp;
	}

	static std::string GetCrrentShortStringTime( void )
	{
		char tmp[100];
		time_t tim_t;
		time( &tim_t );
		struct tm struTm;
		struTm = *(localtime( &tim_t ));
		sprintf( tmp,"%04d%02d%02d%02d%02d%02d",
			struTm.tm_year + 1900,struTm.tm_mon + 1,struTm.tm_mday,struTm.tm_hour,struTm.tm_min,struTm.tm_sec );

		return tmp;
	}

	////没有用到的函数
	//static bool RecursionCopyFolder( const char* src, const char* dst )
	//{
	//	if( !src || !dst )
	//		return false;

	//	if( stricmp( src,dst ) == 0 ) //源与目标的目录相同
	//		return true;

	//	std::string srcDir = src;
	//	std::string dstDir = dst;
	//	HANDLE hFile = INVALID_HANDLE_VALUE;
	//	WIN32_FIND_DATA wfd;

	//	if( srcDir.rfind( '\\' )  != srcDir.size() -1  )
	//		srcDir +="\\";

	//	if( dstDir.rfind( '\\' )  != dstDir.size() -1  )
	//		dstDir +="\\";

	//	hFile = ::FindFirstFile( ( srcDir + "*.*" ).c_str(),&wfd );
	//	if( hFile == INVALID_HANDLE_VALUE )
	//		return false;

	//	CreateDirectory( dstDir.c_str(),NULL );  //成功或失败都无所谓。

	//	do
	//	{
	//		if( wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
	//		{
	//			if( strcmp( wfd.cFileName,"." ) == 0 || strcmp( wfd.cFileName,".." ) == 0  )
	//				continue;

	//			CreateDirectory( ( dstDir  + wfd.cFileName ).c_str(),NULL );
	//			std::string tmpSrc = srcDir + wfd.cFileName;
	//			RecursionCopyFolder( tmpSrc.c_str() , ( dstDir + wfd.cFileName ).c_str() );
	//			continue;
	//		}

	//		SetFileAttributes(  (dstDir + wfd.cFileName).c_str()  ,FILE_ATTRIBUTE_NORMAL ) ;

	//		CopyFile( ( srcDir + wfd.cFileName ).c_str() , (dstDir + wfd.cFileName).c_str() ,false );

	//	}while( FindNextFile( hFile, &wfd ) );

	//	FindClose( hFile );

	//	Sleep( 55 );

	//	return true;
	//}


	bool static TrimBlank(std::string &srcStr)
	{
		if (srcStr.empty())
		{
			return true;
		}
		while (srcStr[0]==' ')
		{
			srcStr.erase(0,1);
		}
		size_t index=srcStr.size();
		while (srcStr[index-1]==' ')
		{
			srcStr.erase(index-1,1);
			index=srcStr.size();
		}
		return true;
	}

	static void TrimChar(string &str,char character)
	{
		char *begin=&str[0];
		char *end=begin+str.size();
		while(*begin==character)
		{
			++begin;
		}
		while(end>begin&&end[-1]==character)
		{
			--end;
		}
		str=string(begin,end-begin);
	}
#ifdef WIN32
	static std::string WChar2Ansi( const wchar_t* pwszSrc)
	{
		int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
		if (nLen<= 0) 
			return std::string("");
		char* pszDst = new char[nLen];
		if (NULL == pszDst) 
			return std::string("");
		WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
		pszDst[nLen -1] = 0;
		std::string strTemp(pszDst);

		delete [] pszDst;
		return strTemp;
	}

	static std::wstring Ansi2WChar( const char* pszSrc, int nLen)
	{
		int nSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, 0, 0);
		if(nSize <= 0) 
			return std::wstring(L"");
		WCHAR *pwszDst = new WCHAR[nSize+1];
		if( NULL == pwszDst) 
			return std::wstring(L"");
		MultiByteToWideChar(CP_ACP, 0,(LPCSTR)pszSrc, nLen, pwszDst, nSize);
		pwszDst[nSize] = 0;
		if( pwszDst[0] == 0xFEFF) // skip Oxfeff
			for(int i = 0; i < nSize; i ++) 
				pwszDst[i] = pwszDst[i+1]; 

		std::wstring wcharString(pwszDst);
		delete pwszDst;

		return wcharString;
	}
#endif

#ifndef WIN32
	int static code_convert(char* from_charset, char* to_charset, char *inbuf, int inlen, char* outbuf, int outlen)
        {
                iconv_t cd;
                char** pIn=&inbuf;
                char** pOut=&outbuf;

                cd = iconv_open(to_charset,from_charset);
                if(cd ==0)
                {
                        return -1;
                }
                memset(outbuf, 0, outlen);
                if(iconv(cd, pIn, (size_t*)&inlen, pOut, (size_t*)&outlen ) == -1)
                {
                        return -1;
                }
                iconv_close(cd);
                return 0;
        }
#endif
	bool static Utf8ToGBK(const char * utf8, char* gbk, int inlen = 0, int outlen = 0)
	{
#ifdef WIN32
		WCHAR  wText[100];
		int ret=MultiByteToWideChar(
			CP_UTF8,         // code page
			NULL,         // character-type options
			utf8, // string to map
			-1,       // number of bytes in string
			wText,  // wide-character buffer
			100        // size of buffer
			);
		if(ret==0)
		{
			printf("MultiByteToWideChar fail errorCode=%d\n",GetLastError());
			return false;
		}
		ret= WideCharToMultiByte( 
			CP_OEMCP, 
			NULL, 
			wText,
			-1, 
			gbk,   
			256,NULL,false);
		if(ret==0)
		{
			printf("WideCharToMultiByte fail errorCode=%d\n",GetLastError());
			return false;
		}
		//gbk[ret-1]=NULL;
		return true;
#else
		char* pUtf8=(char*)utf8;
		return (0 == code_convert("utf-8", "gbk", pUtf8, inlen, gbk, outlen));
#endif

	}

	bool static GBKToUtf8(const char * gbk, char* utf8, int inlen = 0, int outlen = 0)
	{
#ifdef WIN32
		WCHAR  wText[100];
		int ret=MultiByteToWideChar(
			CP_OEMCP,         // code page
			NULL,         // character-type options
			gbk, // string to map
			-1,       // number of bytes in string
			wText,  // wide-character buffer
			100        // size of buffer
			);
		if(ret==0)
		{
			printf("MultiByteToWideChar fail errorCode=%d\n",GetLastError());
			return false;
		}
		ret= WideCharToMultiByte( 
			CP_UTF8, 
			NULL, 
			wText,
			-1, 
			utf8,   
			256,NULL,false);
		if(ret==0)
		{
			printf("WideCharToMultiByte fail errorCode=%d\n",GetLastError());
			return false;
		}
		//utf8[ret-1]=NULL;
		return true;
#else
		char* pGBK=(char*)gbk;
                return (0 == code_convert("gbk", "utf-8", pGBK, inlen, utf8, outlen));
#endif
	}

	


	static std::string ToString( long longData )
	{
		std::stringstream ss;
        ss << longData;
        std::string str;
        ss >> str;
		return str;
	}

	static long ToLong( std::string s )
	{
		std::stringstream ss;
        ss << s;
       long l;
        ss >> l;
		return l;
	}
	static bool MyCreateFolder(const char * path)
	{
#ifdef WIN32
		if(! CreateDirectory( path,NULL ) )
		{
			LDEBUG("[ServiceUnit][CreateFolder]Create Fail  "<<path<<"[  "<<GetLastError()<<"]");
			return false;
						
        }
#else
		if(!mkdir(path, S_IRWXU | S_IRWXG))
		{
			LDEBUG("[ServiceUnit][CreateFolder]Create Fail "<<path<<"["<<errno<<"]");
			return false;
		}
#endif
		return true;
	}
	static bool MyDelFile(const char * file)
	{
#ifdef WIN32
	if(0==DeleteFile( file))
	{
		LERROR("[ServiceUnit][CommonTools][MyDelFile]Delete file "<<file<<" <Fail>"<<GetLastError());  //为了防止文件覆盖的时候出现问题，直接删除本地，不论当前的目录是否存在该文件
		return true;
	}
	else
		LINFO ("[ServiceUnit][CommonTools][MyDelFile]Delete file "<<file<<" <SUCC>");
#else
	if(remove(file)!=0)
		LERROR("[ServiceUnit][CommonTools][MyDelFile]Delete file "<<file<<"<Fail>"<<errno); 
#endif
		return true;
	}
	static bool MyCPFile(const char *srcpath,const char * destpath)
	{
#ifdef WIN32

		if(srcpath==NULL||destpath==NULL)
			return false;
		if(strcmp(srcpath,destpath)==0)
			return true;
		if(!CopyFile(srcpath , destpath ,false ))
		{
			
			if(3==GetLastError())
			{
				char* temp=(char *)destpath;
				string str =string(srcpath);
				size_t index=str.rfind("/");
				if(index==-1)
					return false;
				string direct = str.substr(0,index);
				if(!CreateDirectory( direct.c_str(),NULL ))
				{
					LDEBUG("[ServiceUnit][CIVR_New_ChgDealThread][AddIVR]the director create again wrong["<<(direct).c_str()<<"] "<<GetLastError());
					return false;
				}
			if(CopyFile(srcpath,destpath,false))
			{
				LDEBUG("[ServiceUnit][CPFile]Copy Fail From["<<srcpath<<"] To ["<<destpath<<"] ["<<GetLastError()<<"]");
				return true;
			}
			else
			{
				return false;
			}
		}
	}
#else
	char 	buf[8192];
	int 	fd_src, fd_dst;
	int 	size_r=0;


	if((fd_src = open(srcpath, O_RDONLY)) < 0)
	{
		LFAIL("[ServiceUnit][CommonTools][MoveFolder]Open Error:"<<errno<<",Path:"<<srcpath);
		return false;
	}

	if((fd_dst = open(destpath, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG)) < 0)
	{        
		if( 2 == errno )
                {
			string str =string(destpath);
			//size_t index=str.rfind("/");
			int index=str.rfind("/");
			if(index==-1)
				return false;
			string direct = str.substr(0,index);
			if( -1 == mkdir(direct.c_str(), S_IRWXU | S_IRWXG))
			{
				LDEBUG("[ServiceUnit][CreateFolder]Create Fail "<<direct.c_str()<<" "<<errno);
				return false;
			}
			if((fd_dst = open(destpath, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG)) < 0)
			{
				LFAIL("[ServiceUnit][CommonTools][CPFile]Open Error:"<<errno<<",Path:"<<destpath<<", after mkdir");
				return false;
			}	
		}
		else
		{
			LFAIL("[ServiceUnit][CommonTools][CPFile]Open Error:"<<errno<<",Path:"<<destpath);
			return false;
		}
	}

	memset(buf, 0, 8192);
	while(1)
	{
		size_r = read(fd_src, buf, 8192);
		if(size_r == -1)
		{
			LFAIL("[ServiceUnit][CommonTools][CPFile]Read Error:"<<errno<<",Path:"<<srcpath);
			return false;
		}

		if(size_r == 0)
		{
			break;
		}

		if(size_r != write(fd_dst, buf, size_r))
		{
			LFAIL("[ServiceUnit][CommonTools][CPFile]Read Error:"<<errno<<",Path"<<destpath);
			return false;
		}
	}

	close(fd_src);
	close(fd_dst);
#endif

		return true;
	}

	static void  MySleep(int p)
	{
#ifndef WIN32
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 1000*p;
		select( 0, NULL, NULL, NULL, & timeout );
#else
		::Sleep(p);
#endif
	}
	
	static ULONG MyGetTickCount(void)
	{
		ULONG currentTime;
#ifdef WIN32
		currentTime = GetTickCount();
#else
		struct timeval current;
		gettimeofday(&current, NULL);
		currentTime = current.tv_sec * 1000 + current.tv_usec/1000;
#endif
		return currentTime;
	}


	static string IVR_GetParamValue(string param)
	{
		int idx = param.find( "=" );
		if ( idx == -1  )
			return "";
		string paramValue = param.substr( idx+1,param.size() - idx - 1 );
		return paramValue;
	}



	int static GetHostIp(std::string & ip)
	{
#ifdef WIN32
		if(0==strcmp("127.0.0.1",ip.c_str()))
		{
			WORD   wVersionRequested   =   MAKEWORD(1,   1);   
			WSADATA   wsaData;   

			if   (WSAStartup(wVersionRequested,   &wsaData))     
			{
				LERROR("[ServiceUnit][GetHostIp]WSAStartup Err:"<<WSAGetLastError());
				return   1;   
			}
			char   hostname[256];   
			if( gethostname(hostname,   sizeof(hostname)))
			{
				LERROR("[ServiceUnit][GetHostIp]gethostname Err:"<<WSAGetLastError());
				return   1;   
			}
			hostent *phe   =   gethostbyname(hostname);   
			if   (phe==NULL)   
			{
				LERROR("[ServiceUnit][GetHostIp]gethostbyname Err:"<<WSAGetLastError());
				return   1;   
			}  
			for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
				struct in_addr addr;
				memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
				ip=std::string (inet_ntoa(addr));
				break;
			}

			WSACleanup(); 

		}
#else
		if(0==strcmp("127.0.0.1",ip.c_str()))
		{

			int s;
			struct ifconf conf;
			struct ifreq *ifr;
			char buff[BUFSIZ];
			int num;
			int i;

			s = socket(PF_INET, SOCK_DGRAM, 0);
			conf.ifc_len = 256;
			conf.ifc_buf = buff;

			ioctl(s, SIOCGIFCONF, &conf);
			num = conf.ifc_len / sizeof(struct ifreq);
			ifr = conf.ifc_req;

			for(i=0;i < num;i++)
			{
				struct sockaddr_in *sin = (struct sockaddr_in *)(&ifr->ifr_addr);

				ioctl(s, SIOCGIFFLAGS, ifr);
				if(((ifr->ifr_flags & IFF_LOOPBACK) == 0) && (ifr->ifr_flags & IFF_UP))
				{
					ip=inet_ntoa(sin->sin_addr);
					break;

				}
				ifr++;
			}
		}

#endif
		LDEBUG("[Commontools][GetHostIp]the ip is "<<ip);

		return 0;
	}

	std::string static GetGuidString()
	{
		GUID guid;
#ifdef WIN32
		CoCreateGuid(&guid);
#else
		uuid_generate(reinterpret_cast<unsigned char *>(&guid));
#endif
		char buf[64] = {0};
#ifdef __GNUC__
		snprintf(
#else // MSVC
		_snprintf_s(
#endif
			buf,
			sizeof(buf),
			"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
			guid.Data1, guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1],
			guid.Data4[2], guid.Data4[3],
			guid.Data4[4], guid.Data4[5],
			guid.Data4[6], guid.Data4[7]);
		return std::string(buf);
	}


}

#endif

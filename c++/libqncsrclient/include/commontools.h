/*************************************************************************
    > File Name: FileTools.h
    > Author: w
    > Mail: wangchao@channelsoft.com 
    > Created Time: 2016年04月15日 星期五 16时33分42秒
 ************************************************************************/

#ifndef _commontools_h_
#define _commontools_h_


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
#include <linux/sockios.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <errno.h> 
#include <iconv.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <dirent.h>
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

#include <string>
#include <sstream>
typedef unsigned long ULONG;
using namespace std;
 
namespace CTOOLS
{
	static int DeleteFile(string path)
	{
		if(remove(path.c_str()) != 0)
		{
			return errno;
		}
		return 0;
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

	vector<std::string> static stringSplit(std::string str,std::string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str+=pattern;
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




	static void  MySleep(int p)
	{
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 1000*p;
		select( 0, NULL, NULL, NULL, & timeout );
	}







	bool static IsFolderExist(string path)
	{
		DIR *dp;
		if ((dp = opendir(path.c_str())) == NULL)
		{
			return false;
		}

		closedir(dp);
		return true;
	}

	bool static IsFileExist(string path)
	{
		
		if(access(path.c_str(),F_OK)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static std::vector<std::string> readFileList(char *basePath)
	{	
   		std::vector<std::string> result;
   		DIR *dir;
   		struct dirent *ptr;
   		char base[1000];

   		if ((dir=opendir(basePath)) == NULL)
   		{
    		perror("Open dir error...");
       		exit(1);
   		}

   		while ((ptr=readdir(dir)) != NULL)
   		{
			if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
				continue;
        	else if(ptr->d_type == 8)    ///file
            {
            	printf("d_name:%s/%s\n",basePath,ptr->d_name);
            	result.push_back(std::string(ptr->d_name));
            }
        	else if(ptr->d_type == 10)    ///link file
            {
            	printf("d_name:%s/%s\n",basePath,ptr->d_name);
            	result.push_back(std::string(ptr->d_name));
            }
        	else if(ptr->d_type == 4)    ///dir
        	{
            	memset(base,'\0',sizeof(base));
            	strcpy(base,basePath);
            	strcat(base,"/");
            	strcat(base,ptr->d_name);
            	result.push_back(std::string(ptr->d_name));
            	readFileList(base);
            }
		}
        closedir(dir);
        return result;

	}



};
#endif


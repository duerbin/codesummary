//*******************************************************
//  @filename:	test.cpp
//  @function:	test qncsrclient.so
//  @author: 	dueb
//*******************************************************
#include <iostream>
#ifdef _WIN32
#include <stdio.h>
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#endif


#ifdef _WIN32
#define OpenLibrary(p)   LoadLibrary(p)
#define LoadFunction     GetProcAddress
#define CloseLibrary     FreeLibrary
#else
#define OpenLibrary(p)   dlopen(p,RTLD_LAZY)
#define LoadFunction     dlsym
#define CloseLibrary     dlclose
#endif


#ifdef _WIN32
#define   SO_HANDLE HMODULE
#else
#define  SO_HANDLE void* 
#define HANDLE void* 
#endif

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "qncsrclientAdapter.h"
#include "commontools.h"
SO_HANDLE g_qncsrclientM;

typedef int (*PQNCSRINIT)(const char*,CallBackFun);
typedef int (*QNCSRSEND)(const char* ,const char*,long,int);
typedef int (*QNCSRSEND_PACKAGE)(const char*,const char*);

PQNCSRINIT g_qncsrinit;
QNCSRSEND g_qncsrsend;
QNCSRSEND_PACKAGE g_qncsrsendPack;

struct structfileinfo
{
	string filedata;
	int filesize;
};

std::vector<structfileinfo> gVecfileinfo;


//Resut callback funciton
int StreamResult(const char* sessionid,const char* result)
{
	std::cout<<"XXXXXXXXXXResult:"<<sessionid<<" result:"<<result<<endl;
}

/*
 * 
*/
void *testSend(char* str,int ilength,int sendnum)
{
	int i=0;
	while(true&&sendnum>i)
	{
		i++;
		stringstream ss;
		ss<<i;
		int iret=(g_qncsrsend)(ss.str().c_str(),str,ilength,8);
		std::cout<<"####sendresult::"<<iret<<std::endl;
		ss.clear();
		CTOOLS::MySleep(10000);
	}

}

void* testSend1(void *arg)
{

	int threadid=*(int*) arg;
	int i=0;
	int sendnum=100;
	int size=gVecfileinfo.size();
	cout<<"+++++++++++++++"<<threadid<<"size::"<<size<<endl;
	while(true&&sendnum>i)
	{
		i++;
		cout<<"MMMMMM"<<i%size<<endl;
		string  str=gVecfileinfo[i%size].filedata;
		int ilength=gVecfileinfo[i%size].filesize;
		stringstream ss;
		string stra="initialagentid=95559;curuserdn=13701724727;talkertype=13701724727;begintime=20180529144914552359;endtime=20180529144914552359;parms1=15b0cf7d2000083;parma";
		//ss<<"duebtest"
		ss<<threadid<<"_"<<i;
		(g_qncsrsendPack)(ss.str().c_str(),stra.c_str());
		int iret=(g_qncsrsend)(ss.str().c_str(),str.c_str(),ilength,8);
		std::cout<<"[MMMMM"<<threadid<<"]"<<ss.str()<<":##sendresult::"<<iret<<std::endl;
		ss.clear();
		CTOOLS::MySleep(5000);
	}

}



int readpcmfile(string filename )
{

	ifstream fppcm(filename.c_str(),ios::in|ios::binary);
	if(!fppcm.is_open())
	{
		cout<<"test pcm file open failed"<<endl;
	}
	std::ostringstream tmp;
	tmp<<fppcm.rdbuf();
	string str=tmp.str();
	
	int ilength=str.length();
	cout<<ilength<<endl;
	
	
	structfileinfo _tmp;
	_tmp.filedata=str;
	_tmp.filesize=ilength;
	gVecfileinfo.push_back(_tmp);
	
	fppcm.close();
}

int readAllPcmFile()
{
	vector<string>  vecfilename;
	//vecfilename=CTOOLS::readFileList("/tmp/dat1/");
	vecfilename.push_back("./5010.wav.pcm");
	for (int i=0;i<vecfilename.size();i++)
	{
		cout<<"read file:"<<vecfilename[i]<<endl;
		//readpcmfile("/tmp/dat1/"+vecfilename[i]);
		readpcmfile(vecfilename[i]);
	}
	for( int i =0;i<gVecfileinfo.size();i++)
	{
		cout<<"file:"<<i<<" sizeis:"<<gVecfileinfo[i].filesize<<endl;
	}
}

int createthread(int args)
{
	pthread_t sendT3;
	int threadid=args;
	cout<<"TTTT"<<threadid<<endl;
	cout<<&threadid<<endl;
	int ret=pthread_create(&sendT3,NULL,testSend1,&threadid);
	if(ret)
	{
		cout<<"create pthread2 error\n";
		return -1;
	}
	else{
		cout<<"[TT] success:"<<threadid<<endl;
	}


}
int main()
{
	g_qncsrclientM=OpenLibrary("./libqncsrclient.so");
	if(!g_qncsrclientM)
		std::cout<<"open qncsrclient lib error"<<endl;

	g_qncsrinit=(PQNCSRINIT)LoadFunction(g_qncsrclientM,"QNCSR_initialize");
	if(!g_qncsrinit)
	{
		CloseLibrary(g_qncsrclientM);
		std::cout<<"function init failed"<<endl;
	}
	else
	{
		std::cout<<"function init success"<<endl;
	}
	
	int intresult=(g_qncsrinit)("/home/dueb/gitcode/cc/qncsr/clientadapter/cfg/qncsrclient.ini",StreamResult);
	
	g_qncsrsendPack=(QNCSRSEND_PACKAGE)LoadFunction(g_qncsrclientM,"QNCSR_sendPackageData");
	string stra="initialagentid=95559;curuserdn=13701724727;talkertype=13701724727;begintime=20180529144914552359;endtime=20180529144914552359;parms1=15b0cf7d2000083;parma";
	//g_qncsrsendPack("111111",stra.c_str());
	g_qncsrsend=(QNCSRSEND)LoadFunction(g_qncsrclientM,"QNCSR_sendStreamData");
	if(!g_qncsrinit)
	{
		CloseLibrary(g_qncsrclientM);
		std::cout<<"function send init failed"<<endl;
	}
	else
	{
		std::cout<<"function send init success"<<endl;
	}
	int _put;
	//readAllPcmFile();
	stringstream ss;

	/*for (int i=1;i<10;i++)
	{
		createthread(i+9000);
		CTOOLS::MySleep(1000);

	}*/
	//testSend1((void*)"9001");
	while (1)
	{
		std::cout<<"sleep 100"<<endl;
		CTOOLS::MySleep(100000);
	}

	std::cin>>_put;
}

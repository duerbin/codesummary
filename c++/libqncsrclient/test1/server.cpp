// ICEThread.cpp: implementation of the CICEThread class.
//
//////////////////////////////////////////////////////////////////////

#include <Ice/Ice.h>
#include <Ice/Communicator.h>
#include "qncsrinterface.h"
#include <sstream>
#include <iostream>
#define UINT unsigned int
using namespace std;
using namespace csr;
#include <Printer.h>
using namespace Demo;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
class ResultCallbackProxyI : public ResultCallbackProxy
{
	public:
		virtual void sendStreamResult(const ::std::string& sessionid, const ::std::string& strresult,const Ice::Current&);
};

void ResultCallbackProxyI::sendStreamResult(const string& sessionid,const string& result,const Ice::Current&)
{
	cout<<sessionid<<endl;
}

class PrinterI:public Printer {
public :
	virtual void printString(const string& s,const Ice::Current &);
};

void PrinterI::printString(const string& s,const Ice::Current &)
{
	cout<<s<<endl;
}

Ice::CommunicatorPtr m_pComm;
int Init()
{
	int m_status=0;
	try
	{
		int m_argc = 0;
		Ice::InitializationData initData;
		m_pComm = Ice::initialize( );

			
		Ice::ObjectAdapterPtr adaptee = m_pComm->createObjectAdapterWithEndpoints ("qncsrcallback","default -h 10.130.41.12 -p 10000");
		 Ice::ObjectPtr obj = new ResultCallbackProxyI;	
		//Ice::ObjectPtr obj= new PrinterI;
		
		
		adaptee->add(obj,m_pComm->stringToIdentity("qncsrcallback"));
		//adaptee->add(obj,m_pComm->stringToIdentity(m_servantname_callback));
		
		
		adaptee->activate();
		cout<<"2222"<<std::endl;
		m_pComm->waitForShutdown();
		cout<<"2222"<<std::endl;
	}
	catch ( const Ice::Exception& e ) 
	{
		cout<<"12222"<<std::endl;
		cout<<e<<std::endl;
		m_status = -1;
	}
	catch ( const char* msg ) 
	{
		cout<<"12222"<<std::endl;
		cout<<msg<<std::endl;
		m_status = -1;
	}
	catch( ... )
	{
		cout<<"12222"<<std::endl;
		m_status = -1;
	}	
	
		
	return m_status;
}


int main()
{
	Init();
}


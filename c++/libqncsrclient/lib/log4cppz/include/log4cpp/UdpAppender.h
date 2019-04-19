/*
* UdpAppender.hh
*
* Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
* Copyright 2000, Bastiaan Bakker. All rights reserved.
*
* See the COPYING file for the terms of usage and distribution.
*/

#ifndef _LOG4CPP_UdpAppender_HH
#define _LOG4CPP_UdpAppender_HH

#include <log4cpp/Portability.hh>
#include <log4cpp/LayoutAppender.hh>
#include <log4cpp/Priority.hh> 
#include <string>
#include <stdarg.h>

namespace log4cpp {
    
    class LOG4CPP_EXPORT UdpAppender : public LayoutAppender 
    {
    public:        

        UdpAppender(
            const std::string& name, 
            const std::string& ip, 
            int port,
            const std::string& minPriority,
            int sendBufLen = 2048);
        

        UdpAppender(const std::string& name, int sock, const std::string& minPriority);
       
        virtual ~UdpAppender();
        
        virtual bool connect(const std::string & p_serverIP, int p_serverPort);

        virtual void close();
        
        virtual int getSendBufLen();
    protected:

        virtual void _append(const LoggingEvent& event);
        
        virtual bool checkPriority(Priority::Value priority);

        virtual int sendData(const char* msg, int len);

        const std::string _ip;
        int _port;
        int _socket; 
        int _flags;
        int _sendBufLen;
        bool _externSocket;
        Priority::Value _priority;

    private:
        void convertPriority(const std::string& minPri);            
    };
}

#endif // _LOG4CPP_UdpAppender_HH


/*
* MonitorUdpAppender.hh
*
* Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
* Copyright 2000, Bastiaan Bakker. All rights reserved.
*
* See the COPYING file for the terms of usage and distribution.
*/

#ifndef _LOG4CPP_MonitorUdpAppender_HH
#define _LOG4CPP_MonitorUdpAppender_HH

#include <log4cpp/Portability.hh>
#include <log4cpp/LayoutAppender.hh>
#include <log4cpp/Priority.hh> 
#include <log4cpp/UdpAppender.h> 
#include <string>
#include <stdarg.h>

#define MAX_MONITOR_UDP_PACKET_CONTENT 2048

namespace log4cpp {
    
    class LOG4CPP_EXPORT MonitorUdpAppender : public UdpAppender 
    {
    public:        

        MonitorUdpAppender(
            const std::string& name, 
            const std::string& ip, 
            int port,
            const std::string& minPriority,
            int sendBufLen = 2048);
        

        MonitorUdpAppender(const std::string& name, int sock, const std::string& minPriority);
       
        virtual ~MonitorUdpAppender();        
        
        enum _log_field_len
        {
            D_LEN_HOST_ID = 32,
            D_LEN_LOG_CATEGORY = 32,
            D_LEN_LOG_LEVEL = 8,
            D_LEN_LOG_TIME = 20,
            D_LEN_LOG_CONTENT = 512
        };

        typedef struct _head
        {
            unsigned int TotalLength;
            unsigned int ComandID;
        }_head;

        typedef struct _bodylog
        {
            char HostID     [D_LEN_HOST_ID];
            char LogCategory[D_LEN_LOG_CATEGORY];
            char LogLevel   [D_LEN_LOG_LEVEL];
            char LogTime    [D_LEN_LOG_TIME];
            char LogContent [D_LEN_LOG_CONTENT];
        }_bodylog;

        struct _packlog
        {
            _head    head;
            _bodylog body;
        };

    protected:
        
        void changeMessage(const LoggingEvent& event, const std::string& msg, 
            _packlog& pack, int* plen);
            
        virtual std::string getTimeString();
        virtual std::string getFormattedTimeString();
        virtual void _append(const LoggingEvent& event);
    };
}

#endif // _LOG4CPP_MonitorUdpAppender_HH

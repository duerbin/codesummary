/*
 * CN_Layout.h
 *
 * Writen by walker(LinWZ), 2004-11-19 
 *
 */

#ifndef _LOG4CPP_CN_LAYOUT_HH
#define _LOG4CPP_CN_LAYOUT_HH

#include <log4cpp/Portability.hh>
#include <log4cpp/Layout.hh>

namespace log4cpp {

    /**
     * CN_Layout is a simple fixed format Layout implementation. 
     **/
    class LOG4CPP_EXPORT CN_Layout : public Layout {
        public:
        CN_Layout();
        virtual ~CN_Layout();

        virtual std::string format(const LoggingEvent& event);
    };        
}

#endif // _LOG4CPP_CN_LAYOUT_HH

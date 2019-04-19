
#ifndef _LOG_H_
#define _LOG_H_

#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include "log4cpp/BasicLayout.hh"

#include <iostream>

#define MPrint log::ins()->write_log

#define ErrorLog(cpFormat...) MPrint(LEVEL_ERROR,__FILE__,__LINE__,__FUNCTION__, ##cpFormat)
#define WarnLog(cpFormat...) MPrint(LEVEL_WARN,__FILE__,__LINE__,__FUNCTION__, ##cpFormat)
#define NoticeLog(cpFormat...) MPrint(LEVEL_WARN,__FILE__,__LINE__,__FUNCTION__, ##cpFormat)
#define InfoLog(cpFormat...) MPrint(LEVEL_INFO,__FILE__,__LINE__,__FUNCTION__, ##cpFormat)
#define DebugLog(cpFormat...) MPrint(LEVEL_DEBUG,__FILE__,__LINE__,__FUNCTION__, ##cpFormat)



#define LDEBUG(y) 	    do { std::ostringstream os; os << y; DebugLog(os.str().c_str();)} while (0);
#define LINFO(y) 	    do { std::ostringstream os; os << y; InfoLog(os.str().c_str()); } while (0);
#define LWARN(y) 	    do { std::ostringstream os; os << y; WarnLog(os.str().c_str()); } while (0);
#define LERROR(y) 	    do { std::ostringstream os; os << y; ErrorLog(os.str().c_str()); } while (0);






typedef enum
{
    LEVEL_NONE = 0,
    LEVEL_ERROR,
    LEVEL_WARN,
    LEVEL_NOTICE,
    LEVEL_INFO,
    LEVEL_DEBUG
} level_type;


class log
{
public:
	log();
	~log();
	static log* ins();

	bool init(const char* cfg_file, const char* category_name);
	bool write_log(level_type level, const char* file, int line, const char* func, const char* format, ...);

private:
	log4cpp::Category * _log;
	static log *		_ins; 
};

#endif

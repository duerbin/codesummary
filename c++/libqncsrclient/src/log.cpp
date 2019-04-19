

#include "log.h"
#include "stdarg.h"

static const char* error[] =
{
    "[NONE ]",
    "[ERROR]",
    "[WARN ]",
    "[NOTCE]",
    "[INFO ]",
    "[DEBUG]"

};

log* log::_ins = NULL;
log::log()
{
}

log::~log()
{
	if (_ins)
		delete _ins;
}

log* log::ins()
{
	if (!_ins)
		_ins = new log;

	return _ins;
}

bool log::init(const char* cfg_file, const char* category_name)
{
	if (!cfg_file || !category_name)
	{
		std::cout << "cfg file or category name is null." << std::endl;
		return false;
	}

	try
    {
        log4cpp::PropertyConfigurator::configure(cfg_file);
    }
    catch(log4cpp::ConfigureFailure& f)
    {
        std::cout << "log configure problem" << std::endl;
        return false;
    }

    log4cpp::Category& root = log4cpp::Category::getRoot();
    this->_log = &log4cpp::Category::getInstance(std::string(category_name));

    return true;
}

bool log::write_log(level_type level, const char* file, int line, const char* func, const char* format, ...)
{
	if (format == NULL)
    	return false;
    
    char msg[2048];
    
    va_list val;
    va_start(val, format);
    vsnprintf(msg, sizeof(msg)-1, format, val);
    va_end(val);
    switch (level)
    {
        case LEVEL_DEBUG:
            _log->debug("%s", msg);
            break;
        case LEVEL_INFO:
            _log->info("%s", msg);
            break;
        case LEVEL_NOTICE:
            _log->notice("%s", msg);
            break;
        case LEVEL_WARN:
            _log->warn("%s", msg);
            break;
        case LEVEL_ERROR:
            _log->error("%s:%d %s", file, line, msg);
            break;
    }
	
	return true;
}


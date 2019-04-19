/*
 * CN_FileAppender.h
 *
 * Writen by Walker(LinWZ)
 *
 */

#ifndef _LOG4CPP_CN_FILEAPPENDER_HH
#define _LOG4CPP_CN_FILEAPPENDER_HH

#include <log4cpp/Portability.hh>
#include <log4cpp/FileAppender.hh>
#include <string>
#include <stdarg.h>

namespace log4cpp {

     /**
       CN_FileAppender 每天生成一个日志文件
	   文件名的命名格式：filename_YYYYMMDD.ext
	   或者:filename_DD.ext
       @since 0.3.1
    **/
   class LOG4CPP_EXPORT CN_FileAppender : public LayoutAppender 
   {
    public:

        /**
           Constructs a CN_FileAppender.
           @param name the name of the Appender.
           @param fileName the name of the file to which the Appender has 
           to log.
		   @param rollingOnMonth whether the file rolling per month
           @param append whether the Appender has to truncate the file or
           just append to it if it already exists. Defaults to 'true'.
           @param mode file mode to open the logfile with. Defaults to 00644.
        **/  
        CN_FileAppender(const std::string& name, 
                            const std::string& fileName,
							bool rollingOnMonth = true,
                            bool append = true,
                            mode_t mode = 00644);

        virtual ~CN_FileAppender();

        /**
           Reopens the logfile. 
           This can be useful for logfiles that are rotated externally,
           e.g. by logrotate. This method is a NOOP for FileAppenders that
           have been constructed with a file descriptor.           
           @returns true if the reopen succeeded.
        **/
        virtual bool reopen();

        /**
           Closes the logfile.
        **/
        virtual void close();

        /**
           Sets the append vs truncate flag.
           NB. currently the FileAppender opens the logfile in the 
           constructor. Therefore this method is too late to influence the 
           first file opening. We'll need something similar to log4j's
           activateOptions().
           @param append false to truncate, true to append
        **/
        virtual void setAppend(bool append);

        /**
           Gets the value of the 'append' option.
        **/
        virtual bool getAppend() const;

        /**
           Sets the file open mode.
        **/
        virtual void setMode(mode_t mode);

        /**
           Gets the file open mode.
        **/
        virtual mode_t getMode() const;

    protected:
        virtual void _append(const LoggingEvent& event);

		std::string _getFileName();

        bool _rollingOnMonth;
		std::string _fileName;
        int _flags;
        mode_t _mode;
     };
}

#endif // _LOG4CPP_CN_FILEAPPENDER_HH

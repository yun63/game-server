/// =====================================================================================
/// 
///    @filename         :  MyLayout.hh
/// 
///    @description      :  log4cpp自定义布局类及实现
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2013年12月02日 11时27分41秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  H_GHLAYOUT_INC
#define  H_GHLAYOUT_INC

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <log4cpp/Portability.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FactoryParams.hh>
#include <log4cpp/Layout.hh>

namespace log4cpp {
	class LOG4CPP_EXPORT MyLayout : public Layout
	{
	public:
		MyLayout() {}
		virtual ~MyLayout() {}
		virtual std::string format(const LoggingEvent &event)
		{
			std::ostringstream message;
			char buff[64];
			time_t time = static_cast<time_t>(event.timeStamp.getSeconds());

			struct tm *local;
			local = localtime(&time);
			int year  = local->tm_year + 1900;
			int month = local->tm_mon + 1;
			int day   = local->tm_mday;
			int hour  = local->tm_hour;
			int min   = local->tm_min;
			int sec   = local->tm_sec;

			snprintf(buff, 64, "[%04d-%02d-%02d %02d:%02d:%02d]", year, month, day, hour, min, sec);

			const std::string &priority_name = Priority::getPriorityName(event.priority);
			message << buff << " " << priority_name << " " << event.ndc << ": " << event.message << std::endl;
			return message.str();
		}
	};
}

#endif   // ----- #ifndef GHLAYOUT_INC  -----

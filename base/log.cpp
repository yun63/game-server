/// =====================================================================================
/// 
///    @filename         :  Log.cpp
/// 
///    @description      :  基于log4cpp日志系统的轻量级实现，
//							只用到了日志loginfo的相关操作，其他日志等级一概忽略
/// 
///    @version          :  1.0
///    @created          :  2013年12月02日 12时06分48秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @company          :  
/// 
/// =====================================================================================



#ifdef USE_LOG4CPP
#	include <string>
#	include "base/Log.h"

#	include "log4cpp/Category.hh"
#	include "log4cpp/RollingFileAppender.hh"
#	include "my_layout.hh"

int InitLog(const char *log_name,
			const char *log_dir,
			int priority,
			unsigned int max_file_szie,
			unsigned int max_backup_index,
			bool append
		   )
{
	if (log_name == NULL || log_dir == NULL) return ERR_FAIL;

	log4cpp::Category *category = log4cpp::Category::exists(log_name);
	if (category != NULL)
	{
		// 删除所有的appender
		category->removeAllAppenders();
		// 实例化一个layout对象
		log4cpp::Layout *layout = new log4cpp::MyLayout();
		// 初始化一个appender
		log4cpp::Appender *ap = new log4cpp::RollingFileAppender(log_name, log_dir, max_file_szie, max_backup_index, append);
		// 把layout对象附着到appender上
		ap->setLayout(layout);
		category->setAdditivity(false);
		// 把appender对象绑定到category对象上
		category->setAppender(ap);
		// 设置category的优先级，低于此优先级的日志不被记录
		category->setPriority((log4cpp::Priority::PriorityLevel)priority);
		return SUCCESS;
	}

	// 实例化一个layout对象
	log4cpp::Layout *layout = new log4cpp::MyLayout();
	// 初始化一个appender
	log4cpp::Appender *ap = new log4cpp::RollingFileAppender(log_name, log_dir, max_file_szie, max_backup_index, append);
	// 把layout对象附着到appender上
	ap->setLayout(layout);
	// 实例化一个category对象
	log4cpp::Category &c = log4cpp::Category::getInstance(log_name);
	// 替换appender
	c.setAppender(ap);
	// 设置category的优先级，低于此优先级的日志不被记录
	c.setPriority((log4cpp::Priority::PriorityLevel)priority);
	return SUCCESS;
}

int ShutdownLog(const char *log_name)
{
	log4cpp::Category *c = log4cpp::Category::exists(log_name);
	if (c != NULL)
	{
		c->removeAppender(c->getAppender(log_name));
	}
	return SUCCESS;
}

int ShutdownAllLog()
{
	log4cpp::Category::shutdown();
	return SUCCESS;
}

int LogInfo(const char *log_name, const char *fmt, ...)
{
	log4cpp::Category *c = log4cpp::Category::exists(log_name);
	if (c == NULL)
	{
		static char str[20240] = {0};

		va_list pa;
		va_start(pa, fmt);
		vsnprintf(str, sizeof(str), fmt, pa);
		va_end(pa);
		printf("%s\n", str);

		return ERR_FAIL;
	}

	va_list va;

	va_start(va, fmt);
	c->logva(log4cpp::Priority::INFO, fmt, va);
	return SUCCESS;
}

int LogInfo_va(const char *log_name, const char *fmt, va_list ap)
{
	if (log_name == NULL) return ERR_NULL;

	log4cpp::Category *c = log4cpp::Category::exists(log_name);
	if (c == NULL)
	{
		char str[256];
		vsnprintf(str, sizeof(str), fmt, ap);
		printf("%s\n", str);
		return ERR_FAIL;
	}

	c->logva(log4cpp::Priority::INFO, fmt, ap);
	return SUCCESS;
}

#endif


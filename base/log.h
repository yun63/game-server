/// =====================================================================================
/// 
///    @filename         :  log.h
/// 
///    @description      :  基于log4cpp，在log4cpp的基础上进行了封装和宏定义，支持日志分级
///							对所有日志进行统一管理
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2013年12月02日 10时25分14秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  H_LOG_INC
#define  H_LOG_INC

#include <cstdarg>

#define SUCCESS    		 0 
#define ERR_FAIL  		-1 
#define ERR_UNKNOWN		-2
#define ERR_NULL		-3

#ifdef USE_LOG4CPP
#	define INIT_ROLLING_FILE_LOG				InitLog
#	define LOG_CLOSE_ALL						ShutdownAllLog() // 关闭所有日志
#	define LOG_CLOSE							ShutdownLog 	 // 根据日志名称关闭日志
#	define LOG_INFO_C(logname, fmt, ...)		LogInfo(logname, fmt, ##__VA_ARGS__)
#else
#	define INIT_ROLLING_FILE_LOG(logname, fmt, ...)	printf(fmt"\n", ##__VA_ARGS__)
#	define LOG_INFO_C(logname, fmt, ...)	printf(fmt"\n", ##__VA_ARGS__)

#endif // ----- #ifdef USE_LOG4CPP

// 初始化日志.如果日志文件不存在,则创建日志文件
int InitLog(const char *log_name,
			const char *log_dir,
			int	priority = 800,                 // 日志等级
			unsigned int max_file_size = 10 * 1024 * 1024,
			unsigned int max_backup_index = 40, /* 回卷文件个数 */
			bool append = true                  /* 是否截断 */
			);

// 关闭所有日志
// 删除文件句柄并且清除相关对象，在程序退出前调用
int ShutdownAllLog();

// 关闭指定名称的日志
int ShutdownLog(const char *log_name);

int LogInfo(const char *log_name, const char *fmt, ...);

int LogInfo_va(const char *log_name, const char *fmt, va_list ap);

#endif  // ----- #ifndef LOG_INC  -----

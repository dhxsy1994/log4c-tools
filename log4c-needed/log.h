 ///
 /// @file    log.h
 /// @author  hessen(dhxsy1994@gmail.com)
 /// @date    2018-12-07 22:54:17
 ///
#ifndef _LOG_H_
#define _LOG_H_
 
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
#ifdef __cplusplus
extern "C"
{
#endif
 
#include <log4c.h>
 
#ifdef __cplusplus
}
#endif
 
#define LOG_PRI_ERROR 		LOG4C_PRIORITY_ERROR
#define LOG_PRI_WARN 		LOG4C_PRIORITY_WARN
#define LOG_PRI_NOTICE 		LOG4C_PRIORITY_NOTICE
#define LOG_PRI_DEBUG 		LOG4C_PRIORITY_DEBUG
#define LOG_PRI_TRACE 		LOG4C_PRIORITY_TRACE
 
extern int log_open(const char *category);
extern void log_message(int priority ,const char* fmt, ...);
extern void log_trace(const char *file , int line , const char *func, const char *fmt ,...);
extern int log_close();
 
#define LOG_ERROR(fmt , args...)	\
	log_message(LOG_PRI_ERROR, fmt, ##args)
#define LOG_WARN(fmt, args...)		\
	log_message(LOG_PRI_WARN, fmt , ##args)
#define LOG_NOTICE(fmt , args...)	\
	log_message(LOG_PRI_NOTICE, fmt , ##args)
#define LOG_DEBUG(fmt , args...)	\
	log_message(LOG_PRI_DEBUG, fmt , ##args)
#define LOG_TRACE(fmt,args...) 		\
	log_trace(__FILE__ , __LINE__ , __FUNCTION__ , fmt ,## args)
 
 
#endif

/*
 
static log4c_category_t *log_category = NULL;
 
int log_open(const char *category)
{
    if (log4c_init() != 0)
    {
		printf("log_open fail\n");
        return -1;
    }
	printf("log_open is %s ok\n",category);
    log_category = log4c_category_get(category);
    return 0 ;
}
 
void log_message(int priority , const char *fmt , ...)
{
//	printf("this a log_message\n");
	va_list ap;
	
	assert(log_category != NULL);
 
	va_start(ap, fmt);
	log4c_category_vlog(log_category , priority , fmt , ap);
	va_end(ap);
}
 
void log_trace(const char *file, int line, const char *fun, 
			const char *fmt , ...)
{
	char new_fmt[2048];
	const char *head_fmt = "[file:%s, line:%d, function:%s]"; 
	va_list ap;
	int n;
	
	assert(log_category != NULL);
	n = sprintf(new_fmt, head_fmt , file , line , fun);
	strcat(new_fmt + n , fmt);
 
	va_start(ap , fmt);
	log4c_category_vlog(log_category , LOG4C_PRIORITY_TRACE, new_fmt , ap);
	va_end(ap);
}
 
 
int log_close()
{
    return (log4c_fini());
}



*/

 ///
 /// @file    log.c
 /// @author  hessen(dhxsy1994@gmail.com)
 /// @date    2019-03-11 21:38:11
 ///

#include "log.h"

 
static log4c_category_t *log_category = NULL;
 
int log_open(const char *category)
{
    if (log4c_init() != 0)
    {
		printf("log_open fail\n");
        return -1;
    }
	//printf("log_open is %s ok\n",category);
    log_category = log4c_category_get(category);
    return 0 ;
}
 
void log_message(int priority , const char *fmt , ...)
{
//	printf("this a log_message\n");
	va_list ap;
	
	assert(log_category != NULL);
 
	va_start(ap, fmt);
	log4c_category_log(log_category , priority , fmt , ap);
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
	log4c_category_log(log_category , LOG4C_PRIORITY_TRACE, new_fmt , ap);
	va_end(ap);
}
 
 
int log_close()
{
    return (log4c_fini());
}



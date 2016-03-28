#ifndef __LOGGER__
#define  __LOGGER__

#include <syslog.h>

#define ERR      3  /* error conditions */
#define WARNING  4  /* warning conditions */
#define INFO     6  /* informational*/
#define DEBUG    7  /* debug-level messages */

#define LOG_MSG(level, fmt, ...) log_message(level, "Function:%s:Line%lu: "fmt, __FUNCTION__,\
							__LINE__, __VA_ARGS__)

void log_message(int prio, char *format, ...);

#endif

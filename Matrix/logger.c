
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "logger.h"

void log_message(int prio, char *format, ...)
{
	va_list argptr;

	printf("%s\n", format);
	va_start(argptr, format);
	vsyslog(prio, format, argptr);
	va_end(argptr);
}

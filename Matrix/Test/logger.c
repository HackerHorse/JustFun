#include <stdio.h>
#include <syslog.h>

int main()
{
	syslog(0, "This is from me");
	return 0;
}

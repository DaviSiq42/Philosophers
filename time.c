#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_sec/1000);
	return (0);
}

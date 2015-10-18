#include "timer.h"

#ifdef _WIN32
int gettimeofday(struct timeval * tp, struct timezone * tzp)
{
	// Note: some broken versions only have 8 trailing zero's, the correct epoch has 9 trailing zero's
	static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

	SYSTEMTIME  system_time;
	FILETIME    file_time;
	uint64_t    time;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	time = ((uint64_t)file_time.dwLowDateTime);
	time += ((uint64_t)file_time.dwHighDateTime) << 32;

	tp->tv_sec = (long)((time - EPOCH) / 10000000L);
	tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
	return 0;
}
#endif

Timer::Timer(long time)
{
	countTime = time;
	timeLeft = time;
}

void Timer::countDown(long elapsedTime, bool start)
{
	if (start)
	{
		if (timeLeft > 0)
			timeLeft -= elapsedTime;
	}
	if (timeLeft <= 0)
		timeLeft = 0;
	printf("time left: %.2f\n\n", (double)timeLeft / 333333);
}
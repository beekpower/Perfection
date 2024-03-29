#ifndef TIMER_H
#define TIMER_H

#ifdef __linux__
#include <sys/time.h>

#elif _WIN32
#include <Windows.h>
#include <stdint.h> // portable: uint64_t   MSVC: __int64 
#include <winsock.h>
// Put your windows imports here

extern int gettimeofday(struct timeval * tp, struct timezone * tzp);

#elif __APPLE__
#include <sys/time.h>
#endif

#include <stdio.h>
#include <math.h>
#include "util.h"

class Timer
{
private:
	long countTime;
	long timeLeft;
	bool timeUp;
	GLuint outline;
	void drawTicks();
public:
	Timer(long);
	bool countDown(long elapsedTime, bool start);
	void reset();
	void drawTimer();
};

#endif
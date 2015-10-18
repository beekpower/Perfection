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

	outline = glGenLists(1);
	glNewList(outline, GL_COMPILE);
	{
		glBegin(GL_POLYGON);
		for (double i = 0; i < (2 * 3.14159); i += (3.14159 / 18))
			glVertex2f((cos(i) * 75) - 180, (sin(i) * 75) + 310);
		glEnd();
	}
	glEndList(); 
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

void Timer::drawTimer()
{
	glPushMatrix();
		glColor3f(0, 0, 1);
		glCallList(outline);
		glBegin(GL_POLYGON);
		for (double i = 0; i < (2 * 3.14159); i += (3.14159 / 18))
			glVertex2f((cos(i) * 75) - 180, (sin(i) * 75) + 310);
		glEnd();

		glTranslatef(-180, 310, 0);
		glRotatef(-((float)timeLeft / 333333) * 12, 0, 0, 1);
		glBegin(GL_QUADS);
		glColor3f(0, 0, .75);
		glVertex2f(-70, -20);
		glVertex2f(-70, 20);
		glColor3f(0, 0, .35);
		glVertex2f(70, 20);
		glVertex2f(70, -20);
		glEnd();
	glPopMatrix();


}
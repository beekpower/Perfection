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
	timeUp = false;

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

bool Timer::countDown(long elapsedTime, bool start)
{
	if (start)
	{
		if (timeLeft > 0)
			timeLeft -= elapsedTime;
	}
	if (timeLeft <= 0)
	{
		timeLeft = 0;
		timeUp = true;
	}
	printf("time left: %.2f\n\n", (double)timeLeft / 333333);

	return timeUp;
}

void Timer::reset()
{
	timeLeft = countTime;
	timeUp = false;
}

void Timer::drawTimer()
{
	glPushMatrix();
		glColor3f(0, 0, 1);
		glCallList(outline);
		glBegin(GL_POLYGON);
		for (double i = 0; i < (2 * 3.14159); i += (3.14159 / 18))
			glVertex2f((cos(i) * 65) - 180, (sin(i) * 65) + 310);
		glEnd();

		drawTicks();

		glTranslatef(-180, 310, 0);
		glRotatef(-((float)timeLeft / 333333) * 6, 0, 0, 1);
		glBegin(GL_QUADS);
		glColor3f(0, 0, .75);
		glVertex2f(-60, -20);
		glVertex2f(-60, 20);
		glColor3f(0, 0, .35);
		glVertex2f(60, 20);
		glVertex2f(60, -20);
		glEnd();
	glPopMatrix();


}

void Timer::drawTicks()
{
	glColor3f(1, 1, 0);			//"0" of 60
	glBegin(GL_LINE_STRIP);
	glVertex2f(-103 + 12, 315);
	glVertex2f(-97 + 12, 315);
	glVertex2f(-97 + 12, 305);
	glVertex2f(-103 + 12, 305);
	glVertex2f(-103 + 12, 315);
	glEnd();

	glColor3f(1, 1, 0);			//"6" of 60
	glBegin(GL_LINE_STRIP);
	glVertex2f(-97, 315);
	glVertex2f(-103, 315);
	glVertex2f(-103, 305);
	glVertex2f(-97, 305);
	glVertex2f(-97, 310);
	glVertex2f(-103, 310);
	glEnd();

	glColor3f(1, 1, 0);			//"4" of 45
	glBegin(GL_LINE_STRIP);
	glVertex2f(-103 - 82, 315 + 75);
	glVertex2f(-103 - 82, 310 + 75);
	glVertex2f(-97 - 82, 310 + 75);
	glVertex2f(-97 - 82, 315 + 75);
	glVertex2f(-97 - 82, 305 + 75);
	glEnd();

	glColor3f(1, 1, 0);			//"5" of 45
	glBegin(GL_LINE_STRIP);
	glVertex2f(-97 - 70, 315 + 75);
	glVertex2f(-103 - 70, 315 + 75);
	glVertex2f(-103 - 70, 310 + 75);
	glVertex2f(-97 - 70, 310 + 75);
	glVertex2f(-97 - 70, 305 + 75);
	glVertex2f(-103 - 70, 305 + 75);
	glEnd();

	glColor3f(1, 1, 0);			//"3" of 30
	glBegin(GL_LINE_STRIP);
	glVertex2f(-103 - 165, 315);
	glVertex2f(-97 - 165, 315);
	glVertex2f(-97 - 165, 310);
	glVertex2f(-103 - 165, 310);
	glVertex2f(-97 - 165, 310);
	glVertex2f(-97 - 165, 305);
	glVertex2f(-103 - 165, 305);
	glEnd();

	glColor3f(1, 1, 0);			//"0" of 30
	glBegin(GL_LINE_STRIP);
	glVertex2f(-103 - 153, 315);
	glVertex2f(-97 - 153, 315);
	glVertex2f(-97 - 153, 305);
	glVertex2f(-103 - 153, 305);
	glVertex2f(-103 - 153, 315);
	glEnd();

	glColor3f(1, 1, 0);			//"1" of 15
	glBegin(GL_LINE_STRIP);
	glVertex2f(-100 - 82, 315 - 75);
	glVertex2f(-100 - 82, 305 - 75);
	glEnd();

	glColor3f(1, 1, 0);			//"5" of 15
	glBegin(GL_LINE_STRIP);
	glVertex2f(-97 - 70, 315 - 75);
	glVertex2f(-103 - 70, 315 - 75);
	glVertex2f(-103 - 70, 310 - 75);
	glVertex2f(-97 - 70, 310 - 75);
	glVertex2f(-97 - 70, 305 - 75);
	glVertex2f(-103 - 70, 305 - 75);
	glEnd();
}
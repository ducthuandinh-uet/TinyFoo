#include "LTime.h"

TIME::TIME()
{
	start_ticks = 0;
	pause_ticks = 0;
	paused = false;
	started = false;
}

void TIME::start()
{
	started = true;
	paused = false;

	start_ticks = SDL_GetTicks();
	pause_ticks = 0;
}

void TIME::stop()
{
	started = false;
	paused = false;

	start_ticks = 0;
	pause_ticks = 0;
}

void TIME::pause()
{
	if (started && !paused)
	{
		paused = true;

		pause_ticks = SDL_GetTicks() - start_ticks;
		start_ticks = 0;
	}
}

void TIME::unpause()
{
	if (started && paused)
	{
		paused = false;

		start_ticks = SDL_GetTicks() - pause_ticks;
		pause_ticks = 0;
	}
}

Uint32 TIME::getTicks()
{
	Uint32 time = 0;

	if (started)
	{
		if (paused)
		{
			time = pause_ticks;
		}
		else
		{
			time = SDL_GetTicks() - start_ticks;
		}
	}

	return time;
}

bool TIME::isStarted()
{
	return started;
}

bool TIME::isPaused()
{
	return started && paused;
}
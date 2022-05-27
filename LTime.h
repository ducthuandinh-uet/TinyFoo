#pragma once

#include <SDL.h>

class TIME
{
public:
	TIME();
	~TIME(){}
	void start();
	void stop();
	void pause();
	void unpause();
	Uint32 getTicks();
	bool isStarted();
	bool isPaused();
private:
	Uint32 start_ticks;
	Uint32 pause_ticks;

	bool paused, started;
};
#include "Character.h"
#include <SDL_render.h>

CHARACTER::CHARACTER()
{
	rChar.x = 600;
	rChar.y = 636;
	rChar.w = CHAR_WIDTH;
	rChar.h = CHAR_HEIGHT;

	mVelX = 0,
	status = IDLE;
	frame = 0;

	fliptype = SDL_FLIP_NONE;
}
CHARACTER::~CHARACTER(){}

bool CHARACTER::load_Char(SDL_Renderer* screen)
{
	if (!IdleTex.loadFromFile("Media/CHARACTER/Idle.png", screen))
	{
		return false;
	}
	else
	{
		idleClips[0].x = 0;
		idleClips[0].y = 0;
		idleClips[0].w = 64;
		idleClips[0].h = 64;

		idleClips[1].x = 64;
		idleClips[1].y = 0;
		idleClips[1].w = 64;
		idleClips[1].h = 64;

		idleClips[2].x = 128;
		idleClips[2].y = 0;
		idleClips[2].w = 64;
		idleClips[2].h = 64;

		idleClips[3].x = 192;
		idleClips[3].y = 0;
		idleClips[3].w = 64;
		idleClips[3].h = 64;

	}

	if (!RunTex.loadFromFile("Media/CHARACTER/Run.png", screen))
	{
		return false;
	}
	else
	{
		runClips[0].x = 0;
		runClips[0].y = 0;
		runClips[0].w = 64;
		runClips[0].h = 64;

		runClips[1].x = 64;
		runClips[1].y = 0;
		runClips[1].w = 64;
		runClips[1].h = 64;

		runClips[2].x = 128;
		runClips[2].y = 0;
		runClips[2].w = 64;
		runClips[2].h = 64;

		runClips[3].x = 192;
		runClips[3].y = 0;
		runClips[3].w = 64;
		runClips[3].h = 64;

		runClips[4].x = 256;
		runClips[4].y = 0;
		runClips[4].w = 64;
		runClips[4].h = 64;

		runClips[5].x = 320;
		runClips[5].y = 0;
		runClips[5].w = 64;
		runClips[5].h = 64;
	}

	return true;
}

void CHARACTER::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_a: mVelX -= CHAR_VEL; fliptype = SDL_FLIP_HORIZONTAL; if (status == IDLE) status = RUN; break;
		case SDLK_LEFT: mVelX -= CHAR_VEL; fliptype = SDL_FLIP_HORIZONTAL; if (status == IDLE) status = RUN; break;
		case SDLK_d: mVelX += CHAR_VEL; fliptype = SDL_FLIP_NONE; if (status == IDLE) status = RUN; break;
		case SDLK_RIGHT: mVelX += CHAR_VEL; fliptype = SDL_FLIP_NONE; if (status == IDLE) status = RUN; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_a: mVelX += CHAR_VEL; status = IDLE; break;
		case SDLK_LEFT: mVelX += CHAR_VEL; status = IDLE; break;
		case SDLK_d: mVelX -= CHAR_VEL; status = IDLE; break;
		case SDLK_RIGHT: mVelX -= CHAR_VEL; status = IDLE; break;
		}
	}
}
void CHARACTER::move()
{
	rChar.x += mVelX;
}

void CHARACTER::render(SDL_Renderer* screen)
{
	if (status == RUN)
	{
		RunTex.render(screen, (rChar.x - 20), (rChar.y - 16), &runClips[frame / 5], 0, 0, fliptype);
		frame++;
		if (frame / 5 >= RUN_FRAME) frame = 0;
	}
	else if (status == IDLE)
	{
		IdleTex.render(screen, (rChar.x - 20), (rChar.y - 16), &idleClips[frame / 10], 0, 0, fliptype);
		frame++;
		if (frame / 10 >= IDLE_FRAME) frame = 0;
	}
}

void CHARACTER::reset_from_start()
{
	rChar.x = 600;
	rChar.y = 636;
	rChar.w = 24;
	rChar.h = 48;

	mVelX = 0;

	status = IDLE;
}
#pragma once

#include <SDL.h>
#include "LTexture.h"	
#include "Button.h"
#include <SDL_render.h>


static LTexture IdleTex;
static LTexture RunTex;

static const int CHAR_WIDTH = 24;
static const int CHAR_HEIGHT = 48;
static int CHAR_VEL = 3;



const int IDLE_FRAME = 4;
const int RUN_FRAME = 6;

static SDL_Rect idleClips[IDLE_FRAME];
static SDL_Rect runClips[RUN_FRAME];

class CHARACTER
{
public:

	CHARACTER();
	~CHARACTER();
	bool load_Char(SDL_Renderer* screen);
	void handleEvent(SDL_Event& e);
	void move();
	void render(SDL_Renderer* screen);
	void reset_from_start();
	void set_mVelX(const int& val) { mVelX = val; }
	SDL_Rect get_rect() const { return rChar; }

private:
	SDL_RendererFlip fliptype;
	SDL_Rect rChar;
	int mVelX;
	int status;
	int frame;
	enum STATUS_CHAR
	{
		IDLE,
		RUN,
	};

};



static CHARACTER oChar;
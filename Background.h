#pragma once

#include "LTexture.h"
#include <SDL.h>

class BACKGROUND : public LTexture
{
public:
	BACKGROUND();
	~BACKGROUND();
	bool load_image(std::string path,SDL_Renderer* screen);
	void render(SDL_Renderer* screen);
private:
	int pos_x, pos_y;
};

static BACKGROUND oBackGround;
static BACKGROUND Intro;
static BACKGROUND Tutorial;
static BACKGROUND Lose;

 inline bool load_background(SDL_Renderer* screen)
{
	bool success = true;
	if (!oBackGround.load_image("Media/BACKGROUND/play_ground.png", screen)) success = false;
	if (!Intro.load_image("Media/BACKGROUND/start_ground.png", screen)) success = false;
	if (!Lose.load_image("Media/BACKGROUND/lose_ground.png", screen)) success = false;
	if (!Tutorial.load_image("Media/BACKGROUND/tutorial_ground.png", screen)) success = false;
	return screen;
}
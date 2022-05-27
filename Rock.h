#pragma once
#include "LTexture.h"
#include "CommonFunc.h"
#include <vector>

static LTexture rock_texture;

const int ROCK_WIDTH = 20;
const int ROCK_HEIGHT = 20;

class ROCK
{
public:
	ROCK();
	~ROCK();
	void set_start_falling_position(const int& x);
	void set_falling_speed(const short& val);
	void set_is_rock_falling_down(const bool& val);
	void auto_fall(SDL_Rect player_rect);
	void render_rock(SDL_Renderer* screen)
	{
		if (is_rock_falling_down) rock_texture.render(screen, rock_rect.x, rock_rect.y);
	}
	bool get_is_rock_falling_down() const { return is_rock_falling_down; }
	SDL_Rect get_rect() const { return rock_rect; }

private:
	SDL_Rect rock_rect;
	short falling_speed;
	bool is_rock_falling_down;
};

static vector<ROCK*> list_rock;

#pragma once

#include <SDL.h>
#include <vector>
#include "LTexture.h"
#include "CommonFunc.h"

class BUTTON : public LTexture
{
public:
	enum BUTTON_STATUS
	{
		OVER = 0,
		OUT = 1,
		MOUSE_DOWN = 2,

		ON = 3,
		OUT_ON = 4,
		MOUSE_DOWN_ON = 5
	};

	BUTTON();
	~BUTTON();
	bool load_button(string path, SDL_Renderer* screen);
	void handle_mouse_position_with_button(SDL_Event& e);
	void render_button(SDL_Renderer* screen, SDL_Rect clip_list[]);
	void set_rect(const int& x, const int& y, const int& w, const int& h);
	void set_using_in_screen(const bool& val) { using_in_screen = val; }
	void set_click_button(const bool& val) { click_button = val; }
	SDL_Rect get_rect() const { return button_rect; }
	bool get_click_button() const { return click_button; }

protected:
	SDL_Rect button_rect;
	int status;
	bool using_in_screen;
	bool click_button;
};



static BUTTON play_button;
static BUTTON tutorial_button;
static BUTTON exit_button;
static BUTTON pause_button;
static BUTTON continue_play_button;
static BUTTON back_to_start_button;
static BUTTON music_button;
static BUTTON restart_button;
static BUTTON rank_button;


static SDL_Rect play_button_clip[3] = {
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};

static SDL_Rect tutorial_button_clip[3] = {
	
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};

static SDL_Rect exit_button_clip[3] = {
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};

static SDL_Rect pause_button_clip[3] = {
	{0,0,70,55},
	{0,55,70,55},
	{0,110,70,55}
};

static SDL_Rect continue_play_button_clip[3] = {
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};


static SDL_Rect music_button_clip[3] = {
	{0,0,70,55},
	{0,55,70,55},
	{0,110,70,55}
};

static SDL_Rect restart_button_clip[3] = {
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};

static SDL_Rect back_to_start_button_clip[3] = {
	{0,0,350,75},
	{0,75,350,75},
	{0,150,350,75}
};


static SDL_Rect rank_button_clip[3] = {
	{0,0,70,55},
	{0,55,70,55},
	{0,110,70,55}
};

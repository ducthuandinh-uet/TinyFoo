#include "Rock.h"

ROCK::ROCK()
{
	rock_rect = { 0,0 - ROCK_HEIGHT,ROCK_WIDTH, ROCK_HEIGHT };
	falling_speed = 0;
	is_rock_falling_down = false;
}
ROCK::~ROCK()
{

}

void ROCK::set_start_falling_position(const int& x)
{
	rock_rect.x = x;
}

void ROCK::set_falling_speed(const short& val)
{
	falling_speed = val;
}

void ROCK::set_is_rock_falling_down(const bool& val)
{
	is_rock_falling_down = val;
}


void ROCK::auto_fall(SDL_Rect player_rect)
{
	rock_rect.y += falling_speed;
	if (rock_rect.y > SCREEN_HEIGHT - 60 || checkCollision(rock_rect, player_rect)) is_rock_falling_down = false;
}


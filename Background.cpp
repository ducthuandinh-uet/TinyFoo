#include "Background.h"
#include <string>
BACKGROUND::BACKGROUND()
{
	pos_x = 0;
	pos_y = 0;
}
BACKGROUND::~BACKGROUND() {}

bool BACKGROUND::load_image(std::string path , SDL_Renderer* screen)
{
	bool load = LTexture::loadFromFile(path, screen);
	return load;
}
void BACKGROUND::render(SDL_Renderer* screen)
{
	LTexture::render(screen, pos_x, pos_y);
}
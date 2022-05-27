#include "Button.h"

BUTTON::BUTTON()
{
	button_rect = { 0,0,0,0 };
	status = OUT;
	using_in_screen = false;
	click_button = false;
}

BUTTON::~BUTTON()
{

}

bool BUTTON::load_button(string path, SDL_Renderer* screen)
{
	bool load = LTexture::loadFromFile(path, screen);
	return load;
}

void BUTTON::handle_mouse_position_with_button(SDL_Event& e)
{
	if (using_in_screen)
	{
		if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);

			bool inside = true;

			if (x < button_rect.x) inside = false;
			if (x > button_rect.x + button_rect.w) inside = false;
			if (y < button_rect.y) inside = false;
			if (y > button_rect.y + button_rect.h) inside = false;


			if (!inside)
			{
				status = OUT;
			}
			else
			{
				switch (e.type)
				{
				case SDL_MOUSEMOTION: status = OVER; break;
				case SDL_MOUSEBUTTONDOWN: status = MOUSE_DOWN; break;
				case SDL_MOUSEBUTTONUP: status = OVER; click_button = true; break;
				}
			}
		}
	}
}

void BUTTON::set_rect(const int& x, const int& y, const int& w, const int& h)
{
	button_rect.x = x; button_rect.y = y; button_rect.w = w; button_rect.h = h;
}

void BUTTON::render_button(SDL_Renderer* screen, SDL_Rect clip_list[])
{
	if (using_in_screen) LTexture::render(screen, button_rect.x, button_rect.y, &clip_list[status]);
}


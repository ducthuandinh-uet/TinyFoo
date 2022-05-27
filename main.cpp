#include <vector>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "CommonFunc.h"
#include "LTexture.h"
#include "BackGround.h"
#include "Rock.h"
#include "Button.h"
#include "Character.h"
#include "Menu.h"
#include "LTime.h"
#include "Music.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		gWindow = SDL_CreateWindow("TinyFoo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}

				if (TTF_Init() != 0)
				{
					printf("SDL_ttf error\n");
					success = false;
				}
			}
		}
	}

	return success;
}
bool loadMedia()
{
	bool success = true;
	if (!load_background(gRenderer)) success = false;
	if (!oChar.load_Char(gRenderer)) success = false;
	if (!rock_texture.loadFromFile("Media/BigRock.png", gRenderer)) success = false;
	if (!load_menu_button(gRenderer)) success = false;
	if (!load_main_font()) success = false;
	if (!load_sound()) success = false;

	return success;
}
void close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
void game_play_in_main();

int main(int argc, char* argv[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			game_play_in_main();
		}

		close();
	}

	return 0;
}


void game_play_in_main()
{
	bool quit = 0;
	SDL_Event e;

	srand((unsigned int)time(NULL));

	Uint32 hard_mode[3] = { 500,200,50 };

	Uint32 time_delay = hard_mode[0];
	bool playing = true;

	TIME count_3_second;
	TIME delay_time_create_rock;

	if (start_music.is_music_play() == false) start_music.play_or_pause_music();

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			game_menu.handle_menu(e, quit);
			if (game_menu.get_screen_status() == PLAY_SCREEN) oChar.handleEvent(e);
		}

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
		SDL_RenderClear(gRenderer);

		if (game_menu.get_screen_status() == START_SCREEN)
		{
			Intro.render(gRenderer);
		}
		else if (game_menu.get_screen_status() == TUTORIAL_SCREEN)
		{
			Tutorial.render(gRenderer);
		}
		else if (game_menu.get_screen_status() == PLAY_SCREEN)
		{
                       
			oChar.move();

			if (game_menu.get_player_playing_time() < 15000) time_delay = hard_mode[0];
			else if (game_menu.get_player_playing_time() > 15000 && game_menu.get_player_playing_time() < 30000) time_delay = hard_mode[1];
			else time_delay = hard_mode[2];
	

			if (!delay_time_create_rock.isStarted()) delay_time_create_rock.start();
			else
			{
				if (delay_time_create_rock.getTicks() >= time_delay)
				{
					int pos = rand() % (SCREEN_WIDTH - ROCK_WIDTH);
					short speed = rand() % 11 + 8;

					ROCK* newRock = new ROCK;

					newRock->set_start_falling_position(pos);
					newRock->set_falling_speed(speed);
					newRock->set_is_rock_falling_down(true);

					list_rock.push_back(newRock);

					delay_time_create_rock.stop();
				}
			}

			if (!count_3_second.isStarted()) count_3_second.start();
			else
			{
				if (count_3_second.getTicks() >= 2000)
				{
					SDL_Rect player_rect = oChar.get_rect();

					ROCK* newBox = new ROCK;
					short speed = rand() % 5 + 8;
					newBox->set_start_falling_position(player_rect.x);
					newBox->set_falling_speed(speed);
					newBox->set_is_rock_falling_down(true);


					ROCK* newBox1 = new ROCK;
					int pos = rand() % (player_rect.x - 50);
					newBox1->set_start_falling_position(pos);
					newBox1->set_falling_speed(12);
					newBox1->set_is_rock_falling_down(true);
					

					ROCK* newBox2 = new ROCK;
					pos = rand() % (player_rect.x + 50);
					newBox2->set_start_falling_position(pos);
					newBox2->set_falling_speed(15);
					newBox2->set_is_rock_falling_down(true);


					list_rock.push_back(newBox);
					list_rock.push_back(newBox1);
					list_rock.push_back(newBox2);

					count_3_second.stop();
				}
			}
			

			oBackGround.render(gRenderer);

			oChar.render(gRenderer);

			if (!list_rock.empty())
			{
				for (int i = 0; i < list_rock.size(); ++i)
				{
					if (list_rock[i]->get_is_rock_falling_down())
					{
						list_rock[i]->auto_fall(oChar.get_rect());
						list_rock[i]->render_rock(gRenderer);
					}
					else
					{
						list_rock.erase(list_rock.begin() + i);
					}

					if (checkCollision(oChar.get_rect(), list_rock[i]->get_rect()))
					{
						game_menu.set_screen_status(LOSING_SCREEN);
						game_menu.set_end_game_time();
						
						game_menu.set_losing_screen();
						oChar.reset_from_start();
						list_rock.clear();

						losing_game.set_play_effect(true);
					}
				}
			}
			


		}
		else if (game_menu.get_screen_status() == PAUSE_SCREEN)
		{
			delay_time_create_rock.stop();
			count_3_second.stop();
			oBackGround.render(gRenderer);
			oChar.render(gRenderer);
			oChar.set_mVelX(0);
		}
		else if (game_menu.get_screen_status() == LOSING_SCREEN)
		{
			losing_game.play_sound_effect();
			losing_game.set_play_effect(false);
			delay_time_create_rock.stop();
			count_3_second.stop();
			Lose.render(gRenderer);
		}
		

		game_menu.handle_sound();
		game_menu.render_menu(gRenderer);

		//--UPDATE SCREEN
		SDL_RenderPresent(gRenderer);

	}
}
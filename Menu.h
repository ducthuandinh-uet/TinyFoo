#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <fstream>
#include <sstream>
#include "Button.h"
#include "Rock.h"
#include "Ltime.h"
#include "music.h"



enum screen_status
{
	START_SCREEN = 0,
	PLAY_SCREEN = 1,
	PAUSE_SCREEN = 2,
	LOSING_SCREEN = 3,
	TUTORIAL_SCREEN = 4,
	RANK_SCREEN = 5
};

bool load_sound()
{
	if (!soundtrack_playing_music.load_music("Media/SOUND/playing_game.wav"))
	{
		return false;
	}

	if (!start_music.load_music("Media/SOUND/intro.wav"))
	{
		return false;
	}

	if (!losing_game.load_sound__effect("Media/SOUND/lose_game.wav"))
	{
		return false;
	}

	return true;
}



bool load_menu_button(SDL_Renderer* screen)
{
	bool success = true;
	if (!play_button.load_button("Media/BUTTOM/play_button.png", screen)) success = false;
	else
	{
		play_button.set_rect(825, 313, 350, 75);
		play_button.set_using_in_screen(true);
	}

	if (!tutorial_button.load_button("Media/BUTTOM/tutorial_button.png", screen)) success = false;
	else
	{
		tutorial_button.set_rect(825, 413, 350, 75);
		tutorial_button.set_using_in_screen(true);
	}

	if (!exit_button.load_button("Media/BUTTOM/quit_button.png", screen)) success = false;
	else
	{
		exit_button.set_rect(825, 513, 350, 75);
		exit_button.set_using_in_screen(true);
	}

	if (!pause_button.load_button("Media/BUTTOM/option_button.png", screen)) success = false;
	else
	{
		pause_button.set_rect(1170, 25, 70, 55);
		pause_button.set_using_in_screen(false);
	}

	if (!continue_play_button.load_button("Media/BUTTOM/continue_button.png", screen)) success = false;
	else
	{
		continue_play_button.set_rect(800, 500, 350, 75);
		continue_play_button.set_using_in_screen(false);
	}

	if (!music_button.load_button("Media/BUTTOM/music_button.png", screen)) success = false;
	else
	{
		music_button.set_rect(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 70, 70, 55);
		music_button.set_using_in_screen(true);
	}

	if (!restart_button.load_button("Media/BUTTOM/restrart_button.png", screen)) success = false;
	else
	{
		restart_button.set_rect(800, 500, 350, 75);
		restart_button.set_using_in_screen(false);
	}


	if (!back_to_start_button.load_button("Media/BUTTOM/back_button.png", screen)) success = false;
	else
	{
		back_to_start_button.set_rect(800, 600, 350, 75);
		back_to_start_button.set_using_in_screen(false);
	}

	if (!rank_button.load_button("Media/BUTTOM/rank_button.png", screen)) success = false;
	else
	{
		rank_button.set_rect(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 70, 70, 55);
		rank_button.set_using_in_screen(true);
	}

	return success;
}



class MENU
{
public:
	MENU()
	{
		status = START_SCREEN;
		play_music = true;
		turn_on = true;
	}

	~MENU()
	{

	}

	void handle_menu(SDL_Event& e, bool& quit)
	{
		play_button.handle_mouse_position_with_button(e);
		tutorial_button.handle_mouse_position_with_button(e);
		exit_button.handle_mouse_position_with_button(e);
		pause_button.handle_mouse_position_with_button(e);
		continue_play_button.handle_mouse_position_with_button(e);
		back_to_start_button.handle_mouse_position_with_button(e);
		music_button.handle_mouse_position_with_button(e);
		restart_button.handle_mouse_position_with_button(e);
		rank_button.handle_mouse_position_with_button(e);

		if (play_button.get_click_button())
		{
			play_button.set_click_button(false);
			status = PLAY_SCREEN;

			turn_on = true;
			timer.start();

			set_play_screen();
		}
		else if (tutorial_button.get_click_button())
		{
			tutorial_button.set_click_button(false);
			status = TUTORIAL_SCREEN;

			set_tutorial_screen();
		}
		else if (exit_button.get_click_button())
		{
			quit = true;
		}
		else if (pause_button.get_click_button())
		{
			pause_button.set_click_button(false);
			status = PAUSE_SCREEN;

			timer.pause();

			set_option_screen();
		}
		else if (continue_play_button.get_click_button())
		{
			continue_play_button.set_click_button(false);
			status = PLAY_SCREEN;

			timer.unpause();

			set_play_screen();
		}
		else if (back_to_start_button.get_click_button())
		{
			back_to_start_button.set_click_button(false);
			status = START_SCREEN;

			
			if (status == PAUSE_SCREEN)
			{
				turn_on = true;
				if (play_music)
				{
					soundtrack_playing_music.play_or_pause_music();
					start_music.play_or_pause_music();
				}
			}

			if (!list_rock.empty()) list_rock.clear();

			timer.stop();

			set_start_screen();
		}
		else if (music_button.get_click_button())
		{
			music_button.set_click_button(false);

			if (play_music) play_music = false;
			else play_music = true;

			if (Mix_PlayingMusic() == 0)
			{
				if (status == START_SCREEN) start_music.play_or_pause_music();
				else if (status == PAUSE_SCREEN) soundtrack_playing_music.play_or_pause_music();

				music_button_clip[0] = { 0,0,70,55 };
				music_button_clip[1] = { 0,55,70,55 };
				music_button_clip[2] = { 0,110,70,55 };
			}
			else
			{
				Mix_HaltMusic();
				start_music.set_play_music(false);
				soundtrack_playing_music.set_play_music(false);

				music_button_clip[0] = { 70,0,70,55 };
				music_button_clip[1] = { 70,55,70,55 };
				music_button_clip[2] = { 70,110,70,55 };
			}
		}
		else if (restart_button.get_click_button())
		{
			restart_button.set_click_button(false);
			status = PLAY_SCREEN;

			soundtrack_playing_music.play_or_pause_music();
			
			timer.stop();
			timer.start();

			set_play_screen();
		}
		else if (rank_button.get_click_button())
		{
			rank_button.set_click_button(false);
			status = RANK_SCREEN;

			set_rank_screen();
		}
	}

	void render_menu(SDL_Renderer* screen)
	{
		play_button.render_button(screen, play_button_clip);
		tutorial_button.render_button(screen, tutorial_button_clip);
		exit_button.render_button(screen, exit_button_clip);
		pause_button.render_button(screen, pause_button_clip);
		continue_play_button.render_button(screen, continue_play_button_clip);
		back_to_start_button.render_button(screen, back_to_start_button_clip);
		music_button.render_button(screen, music_button_clip);
		restart_button.render_button(screen, restart_button_clip);
		rank_button.render_button(screen, rank_button_clip);

		if (timer.isStarted())
		{
			time_text.str("");
			time_text << (timer.getTicks() / 1000.f);

			if (!time_texture.loadFromRenderedText(time_text.str().c_str(), font_color, screen))
			{
				cout << "fail to load time_texture\n";
			}
			else
			{
				if (status == PLAY_SCREEN || status == PAUSE_SCREEN)
				{
					time_texture.render(screen, 10, 10);
				}
				else if (status == LOSING_SCREEN)
				{
					time_texture.render(screen, 380, 500);
				}
				
			}
		}

		if (status == RANK_SCREEN)
		{
			ifstream file;
			file.open("high_score.txt");

			string s;
			stringstream ss;
			ss.str("");
			ss << "The highest score of the best Chicken: ";
			if (getline(file, s))
			{
				ss << s;
			}
			else
			{
				ss << "NONE";
			}
			file.close();

			LTexture score_text;
			if (!score_text.loadFromRenderedText(ss.str().c_str(), font_color, screen)) cout << "can not laod point text\n";

			score_text.render(screen, 100, 300);
		}
	}

	void handle_sound()
	{
		if (status == START_SCREEN)
		{
			if (play_music)
			{
				if (turn_on)
				{
					start_music.set_play_music(false);
					start_music.play_or_pause_music();
					turn_on = false;
				}
			}
			
		}
		else if (status == PLAY_SCREEN)
		{
			if (play_music)
			{
				if (turn_on)
				{
					soundtrack_playing_music.set_play_music(false);
					soundtrack_playing_music.play_or_pause_music();
					turn_on = false;
				}
			}
		}

	}

	void set_start_screen()
	{
		play_button.set_using_in_screen(true);
		tutorial_button.set_using_in_screen(true);
		exit_button.set_using_in_screen(true);
		pause_button.set_using_in_screen(false);
		continue_play_button.set_using_in_screen(false);
		back_to_start_button.set_using_in_screen(false);
		music_button.set_using_in_screen(true);
		restart_button.set_using_in_screen(false);
		rank_button.set_using_in_screen(true);
	}


	void set_tutorial_screen()
	{
		play_button.set_using_in_screen(false);
		tutorial_button.set_using_in_screen(false);
		exit_button.set_using_in_screen(false);
		pause_button.set_using_in_screen(false);
		continue_play_button.set_using_in_screen(false);
		back_to_start_button.set_using_in_screen(true);
		music_button.set_using_in_screen(false);
		restart_button.set_using_in_screen(false);
		rank_button.set_using_in_screen(false);
	}

	void set_play_screen()
	{
		play_button.set_using_in_screen(false);
		tutorial_button.set_using_in_screen(false);
		exit_button.set_using_in_screen(false);
		pause_button.set_using_in_screen(true);
		continue_play_button.set_using_in_screen(false);
		back_to_start_button.set_using_in_screen(false);
		music_button.set_using_in_screen(false);
		restart_button.set_using_in_screen(false);
		rank_button.set_using_in_screen(false);
	}

	void set_option_screen()
	{
		play_button.set_using_in_screen(false);
		tutorial_button.set_using_in_screen(false);
		exit_button.set_using_in_screen(false);
		pause_button.set_using_in_screen(false);
		continue_play_button.set_using_in_screen(true);
		back_to_start_button.set_using_in_screen(true);
		music_button.set_using_in_screen(true);
		restart_button.set_using_in_screen(false);
		rank_button.set_using_in_screen(false);
	}

	void set_losing_screen()
	{
		Mix_HaltMusic();
		start_music.set_play_music(false);
		soundtrack_playing_music.set_play_music(false);

		play_button.set_using_in_screen(false);
		tutorial_button.set_using_in_screen(false);
		exit_button.set_using_in_screen(false);
		pause_button.set_using_in_screen(false);
		continue_play_button.set_using_in_screen(false);
		back_to_start_button.set_using_in_screen(true);
		music_button.set_using_in_screen(false);
		restart_button.set_using_in_screen(true);
		rank_button.set_using_in_screen(false);
	}

	void set_rank_screen()
	{
		play_button.set_using_in_screen(false);
		tutorial_button.set_using_in_screen(false);
		exit_button.set_using_in_screen(false);
		pause_button.set_using_in_screen(false);
		continue_play_button.set_using_in_screen(false);
		back_to_start_button.set_using_in_screen(true);
		music_button.set_using_in_screen(false);
		restart_button.set_using_in_screen(false);
		rank_button.set_using_in_screen(false);
	}


	void set_end_game_time()
	{
		timer.pause();
		high_score.str("");

		high_score << timer.getTicks() / 1000.f;

		ifstream file;
		file.open("high_score.txt", ios::in);

		string s;
		double old_score;
		if (getline(file, s))
		{
			old_score = stod(s); 
		}
		else
		{
			old_score = 0.0;
		}

		file.close();


		ofstream FILE;
		FILE.open("high_score.txt", ios::out);

		if (old_score < double(timer.getTicks() / 1000.f))
		{
			FILE << double(timer.getTicks() / 1000.f);
		}
		else FILE << old_score;


		FILE.close();
	}

	void set_screen_status(const int& val) { status = val; }
	int get_screen_status() const { return status; }	
	Uint32 get_player_playing_time() { return timer.getTicks();}

private:
	LTexture time_texture;
	int status;
	stringstream time_text;
	stringstream high_score;
	bool play_music;
	bool turn_on;
	TIME timer;
};

static MENU game_menu;

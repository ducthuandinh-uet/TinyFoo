#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

class MUSIC
{
public:
	MUSIC();
	~MUSIC();
	bool load_music(string path);
	void play_or_pause_music();
	void set_play_music(const bool& val) { play_music = val; }
	bool is_music_play() const { return play_music; }

private:
	Mix_Music* mMusic;
	bool play_music;
};



class SOUND_EFFECT
{
public:
	SOUND_EFFECT();
	~SOUND_EFFECT();
	bool load_sound__effect(string path);
	void play_sound_effect();
	void set_play_effect(const bool& val) { play_effect = val; }
	bool play_sound_effect() const { return play_effect; }

private:
	Mix_Chunk* meffect;
	bool play_effect;
};

static MUSIC start_music;
static MUSIC soundtrack_playing_music;
static SOUND_EFFECT losing_game;



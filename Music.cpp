#include "Music.h"

MUSIC::MUSIC()
{
	mMusic = NULL;
	play_music = false;
}

MUSIC::~MUSIC()
{

}

bool MUSIC::load_music(string path)
{
	mMusic = Mix_LoadMUS(path.c_str());
	if (mMusic == NULL)
	{
		return false;
	}
	return true;
}

void MUSIC::play_or_pause_music()
{
	if (play_music == false)
	{
		Mix_PlayMusic(mMusic, -1);
		play_music = true;

	}
	else
	{
		Mix_HaltMusic();
		play_music = false;
	}
}




SOUND_EFFECT::SOUND_EFFECT()
{
	meffect = NULL;
	play_effect = false;
}
SOUND_EFFECT::~SOUND_EFFECT()
{
}

bool SOUND_EFFECT::load_sound__effect(string path)
{
	meffect = Mix_LoadWAV(path.c_str());
	if (meffect == NULL)
	{
		return false;
	}
	return true;
}

void SOUND_EFFECT::play_sound_effect()
{
	if (play_effect) Mix_PlayChannel(-1, meffect, 0);
}
#include "Music.h"

Music::Music(double musician_professionalism, double write_lyrics_ability, MOOD authors_specialization, MOOD mood_work, bool musician_inspiration)
{
	mood = mood_work;
	quality = (rand() % 3) * (musician_professionalism + write_lyrics_ability * 2);
	if (authors_specialization == mood_work) quality += 0.5;
	if (musician_inspiration) quality += 0.5;
}

Music::Music(double music_quality, MOOD mood_work)
{
	mood = mood_work;
	quality = music_quality;
}

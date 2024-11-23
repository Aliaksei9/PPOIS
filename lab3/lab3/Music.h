#pragma once
#include "Creative_product.h"
class Musician;
class Music:public Creative_product
{
private:
	Music(double musician_professionalism, double write_lyrics_ability, MOOD authors_specialization, MOOD mood_work,bool musician_inspiration);
	Music(double music_quality,MOOD mood_work);
public:
	Music() = default;
	friend class Musician;
};


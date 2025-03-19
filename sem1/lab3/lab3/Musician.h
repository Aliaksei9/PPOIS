#pragma once
#include <vector>
#include "Creative_worker.h"
#include "Music.h"
#include <fstream>

class Musician:public Creative_worker
{
private:
	double ability_to_write_lyrics;
	void parser(std::vector<Music> *music, MOOD mood_work, std::string list_of_works);
public:
	Musician(std::string musician_name,double musician_professionalism, double write_lyrics_ability, MOOD musician_specialization, Accounting* place_of_work_musician);
	void learn_writing_lyrics();
	void display_list_of_applicants_for_ñopying(std::string list_of_works);
	void soundtrack_show();
	Music Create_composition(MOOD mood_work);
	Music plagiarize(MOOD mood_work, std::string list_of_works,int position_list_of_works);
	void modify(Music* music);
	double get_ability_to_write_lyrics() const { return ability_to_write_lyrics; }
};


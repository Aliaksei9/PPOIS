#include "Musician.h"


void Musician::parser(std::vector<Music>* music, MOOD mood_work, std::string list_of_works)
{
	std::ifstream music_file(list_of_works);// окрываем файл для чтения
	if (!music_file.is_open()) throw std::runtime_error("Файл не открылся");
	while (!music_file.eof())
	{
		std::string str;
		char s;
		double quality;
		getline(music_file, str, ':');
		music_file >> quality;
		music_file.get(s);
		getline(music_file, str, ':');
		getline(music_file, str, ';');
		music_file.get(s);
		switch (str.length())
		{
		case 7:
			music->push_back(Music(quality, NEUTRAL));
			break;
		case 8:
			music->push_back(Music(quality, CHEERFUL));
			break;
		case 10:
			music->push_back(Music(quality, RIDICULOUS));
			break;
		case 11:
			music->push_back(Music(quality, SAD_ANGUISH));
			break;
		case 16:
			music->push_back(Music(quality, VERY_MELANCHOLIC));
			break;
		}
		//getline(music_file, str);
	}
}

Musician::Musician(std::string musician_name,double musician_professionalism, double write_lyrics_ability,MOOD musician_specialization, Accounting* place_of_work_musician)
{
	name = musician_name;
	professionalism = musician_professionalism;
	ability_to_write_lyrics = write_lyrics_ability;
	place_of_work = place_of_work_musician;
	place_of_work->increased_costs(700);
}
void Musician::learn_writing_lyrics()
{
	ability_to_write_lyrics += 0.5;
	if (ability_to_write_lyrics>4)std::cout << "Skill mastered";
}

void Musician::display_list_of_applicants_for_сopying(std::string list_of_works)
{
	std::ifstream music_file(list_of_works);// окрываем файл для чтения
	if (!music_file.is_open()) throw std::runtime_error("Файл не открылся");
	std::string str;
	while (!music_file.eof())
	{
		getline(music_file, str);
		std::cout << str;
	}
}

void Musician::soundtrack_show()
{
	place_of_work->one_time_payment(500);
}

Music Musician::Create_composition(MOOD mood_work)
{
	genre_fatigue += 0.3;
	if (genre_fatigue > 1) throw std::runtime_error("The musician burned out");
	Music music (professionalism, ability_to_write_lyrics, specialization, mood_work,inspiration);
	inspiration = 0;
	return music;
}


Music Musician::plagiarize(MOOD mood_work, std::string list_of_works, int position_list_of_works)
{
	std::vector<Music> music;
	parser(&music, mood_work, list_of_works);
	if(position_list_of_works>=music.size()) throw std::runtime_error("This number is not in the list");
	if(music[position_list_of_works].mood!=mood_work) throw std::runtime_error("Plagiarized work does not match the mood");
	return music[position_list_of_works];
}

void Musician::modify(Music* music)
{
	if (professionalism * (rand() % 4) > 1) music->quality += 0.5;
}

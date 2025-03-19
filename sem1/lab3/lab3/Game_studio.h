#pragma once
#include "Scriptwriter.h"
#include "Programmer.h"
#include "Artist_3D.h"
#include "Accountant.h"
#include "Musician.h"
#include "Level_designer.h"
#include "Game.h"
#include "Scene.h"
class Game_studio
{
private:
	Accounting* accounting;
	Scriptwriter* scriptwriter;
	Musician* musician;
	Programmer* programmer;
	Artist_3D* artist;
	Level_designer* level_designer;
	Accountant* accountant;
	Game* game_in_development;
	Scene* scene_in_development;
	void creation_of_a_creative_worker(std::string name,double proffesionalism, MOOD specialization,int position);
	void creation_of_a_technical_worker(std::string name, double proffesionalism,int position);
	void scriptwriter_distribution();
	void musician_distribution();
	void programer_distribution();
	void artist_3D_distribution();
	void level_designer_distribution();
public:
	Game_studio(Accounting* studio_accounting, std::string list_of_subordinates);
	~Game_studio();
	void scene_planning(MOOD scene_mood, std::string music_list, int position_in_music_list);
	void scene_planning(MOOD scene_mood);
	void work_distribution();
	void release();
	void new_game();
	Musician* get_musician() { return musician; }
};


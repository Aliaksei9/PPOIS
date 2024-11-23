#include "Game_studio.h"


void Game_studio::creation_of_a_creative_worker(std::string name, double proffesionalism, MOOD specialization, int position)
{
	switch (position)
	{
	case 8:
		musician = new Musician(name, proffesionalism,0, specialization, accounting);
		break;
	case 12:
		scriptwriter = new Scriptwriter(name,proffesionalism,specialization,accounting);
		break;
	}
}

void Game_studio::creation_of_a_technical_worker(std::string name, double proffesionalism, int position)
{
	switch (position)
	{
	case 9:
		artist= new Artist_3D(name, proffesionalism, accounting);
		break;
	case 10:
		programmer = new Programmer(name, proffesionalism, accounting);
		break;
	case 11:
		accountant = new Accountant(name, accounting);
		break;
	case 14:
		level_designer= new Level_designer(name, proffesionalism, accounting);
		break;
	}
}

void Game_studio::scriptwriter_distribution()
{
	char selected_action;
	std::cout << "Select the desired action.'\n' Press 'm' to try to improve the script.'\n'Press 'p' to collect material for the script.'\n' Press 'r' to send the writer to rest.'\n' Press 'f' to send the writer to search for inspiration.'\n'Press 't' to send a writer to courses.'\n'";
	std::cin >> selected_action;
	switch (selected_action)
	{
	case 'm':
		scriptwriter->modify(scene_in_development->get_scene_script());
		break;
	case 'p':
		scriptwriter->preporation();
		break;
	case 'r':
		scriptwriter->rest();
		break;
	case 'f':
		scriptwriter->finding_inspiration();
		break;
	case 't':
		scriptwriter->training();
		break;
	default:
		throw std::runtime_error("scriptwriter distribution error");
	}
}

void Game_studio::musician_distribution()
{
	char selected_action;
	std::cout << "Select the desired action.'\n' Press 'm' to try to improve the composition.'\n'Press 'l' to send a musician to learn how to write lyrics.'\n'Press 's' to make the musician earn money from performances.'\n' Press 'r' to send the musician to rest.'\n' Press 'f' to send the musician to search for inspiration.'\n'Press 't' to send a musician to courses.'\n'";
	std::cin >> selected_action;
	switch (selected_action)
	{
	case 'm':
		musician->modify(scene_in_development->get_scene_music());
		break;
	case 'l':
		musician->learn_writing_lyrics();
		break;
	case 'p':
		musician->soundtrack_show();
		break;
	case 'r':
		musician->rest();
		break;
	case 'f':
		musician->finding_inspiration();
		break;
	case 't':
		musician->training();
		break;
	default:
		throw std::runtime_error("musician distribution error");
	}
}

void Game_studio::programer_distribution()
{
	char selected_action;
	std::cout << "Select the desired action.'\n' Press 'f' to fix bugs.'\n' Press 'o' to optimize the product.'\n' Press 'r' to improve the product.'\n'Press 't' to send a programmer to courses.'\n'";
	std::cin >> selected_action;
	switch (selected_action)
	{
	case 'f':
		programmer->fixing_bugs(scene_in_development->get_scene_code());
		break;
	case 'o':
		programmer->optimization(scene_in_development->get_scene_code());
		break;
	case 'r':
		programmer->revision(scene_in_development->get_scene_code());
		break;
	case 't':
		programmer->training();
		break;
	default:
		throw std::runtime_error("programmer distribution error");
	}
}

void Game_studio::artist_3D_distribution()
{
	char selected_action;
	std::cout << "Select the desired action.'\n' Press 'f' to capture movement.'\n' Press 'o' to optimize the product.'\n' Press 'r' to improve the product.'\n'Press 't' to send a artis to courses.'\n'";
	std::cin >> selected_action;
	switch (selected_action)
	{
	case 'f':
		artist->filming();
		break;
	case 'o':
		artist->optimization(scene_in_development->get_scene_model());
		break;
	case 'r':
		artist->revision(scene_in_development->get_scene_model());
		break;
	case 't':
		artist->training();
		break;
	default:
		throw std::runtime_error("3D artist error");
	}
}

void Game_studio::level_designer_distribution()
{
	char selected_action;
	std::cout << "Select the desired action.'\n' Press 'p' to capture locations.'\n' Press 'o' to optimize the product.'\n' Press 'r' to improve the product.'\n'Press 't' to send a level_designer to courses.'\n'";
	std::cin >> selected_action;
	switch (selected_action)
	{
	case 'p':
		level_designer->trip_for_sketches();
		break;
	case 'o':
		level_designer->optimization(scene_in_development->get_scene_level());
		break;
	case 'r':
		level_designer->revision(scene_in_development->get_scene_level());
		break;
	case 't':
		level_designer->training();
		break;
	default:
		throw std::runtime_error("level designer distribution error");
	}
	
}

Game_studio::Game_studio(Accounting* studio_accounting, std::string list_of_subordinates)
{
	accounting = studio_accounting;
	std::ifstream subordinates_file(list_of_subordinates);// окрываем файл для чтения
	if (!subordinates_file.is_open()) throw std::runtime_error("Файл не открылся");
	for(int i=0;i<2;++i)
	{
		std::string str,name;
		std::string proffesion;
		char s;
		double proffesionalism;
		getline(subordinates_file, str, ':');
		getline(subordinates_file, str, ';');
		proffesion = str;
		getline(subordinates_file, str, ':');
		getline(subordinates_file, str, ';');
		name = str;
		getline(subordinates_file, str, ':');
		subordinates_file >> proffesionalism;
		subordinates_file.get(s);
		getline(subordinates_file, str, ':');
		getline(subordinates_file, str, ';');
		subordinates_file.get(s);
		switch (str.length())
		{
		case 7:
			creation_of_a_creative_worker(name,proffesionalism,NEUTRAL,proffesion.length());
			break;
		case 8:
			creation_of_a_creative_worker(name, proffesionalism, CHEERFUL, proffesion.length());
			break;
		case 10:
			creation_of_a_creative_worker(name, proffesionalism, RIDICULOUS, proffesion.length());
			break;
		case 11:
			creation_of_a_creative_worker(name, proffesionalism, SAD_ANGUISH, proffesion.length());
			break;
		case 16:
			creation_of_a_creative_worker(name, proffesionalism, VERY_MELANCHOLIC, proffesion.length());
			break;
		}
		//getline(music_file, str);
	}
	for (int i = 0; i < 4; ++i)
	{
		std::string str, name;
		std::string proffesion;
		char s;
		double proffesionalism;
		getline(subordinates_file, str, ':');
		getline(subordinates_file, str, ';');
		proffesion = str;
		getline(subordinates_file, str, ':');
		getline(subordinates_file, str, ';');
		name = str;
		getline(subordinates_file, str, ':');
		subordinates_file >> proffesionalism;
		getline(subordinates_file, str);
		creation_of_a_technical_worker(name, proffesionalism, proffesion.length());
	}
}

Game_studio::~Game_studio()
{
	delete accounting;
	delete scriptwriter;
	delete musician;
	delete programmer;
	delete artist;
	delete level_designer;
	delete accountant;
	delete game_in_development;
	delete scene_in_development;
}

void Game_studio::scene_planning(MOOD scene_mood,std::string music_list,int position_in_music_list)
{
	delete scene_in_development;
	switch (scene_mood)
	{
	case CHEERFUL:
		scene_in_development = new Scene(scriptwriter->write_script(CHEERFUL),level_designer->create_level(),artist->create_model(),programmer->write_code(),musician->plagiarize(CHEERFUL,music_list,position_in_music_list),CHEERFUL);
	case RIDICULOUS:
		scene_in_development = new Scene(scriptwriter->write_script(RIDICULOUS), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->plagiarize(RIDICULOUS, music_list, position_in_music_list), RIDICULOUS);
	case SAD_ANGUISH:
		scene_in_development = new Scene(scriptwriter->write_script(SAD_ANGUISH), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->plagiarize(SAD_ANGUISH, music_list, position_in_music_list), SAD_ANGUISH);
	case VERY_MELANCHOLIC:
		scene_in_development = new Scene(scriptwriter->write_script(VERY_MELANCHOLIC), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->plagiarize(VERY_MELANCHOLIC, music_list, position_in_music_list), VERY_MELANCHOLIC);
	case NEUTRAL:
		scene_in_development = new Scene(scriptwriter->write_script(NEUTRAL), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->plagiarize(NEUTRAL, music_list, position_in_music_list), NEUTRAL);
	}
	game_in_development->next_month();
	accounting->new_month();
}
void Game_studio::scene_planning(MOOD scene_mood)
{
	delete scene_in_development;
	switch (scene_mood)
	{
	case CHEERFUL:
		scene_in_development = new Scene(scriptwriter->write_script(CHEERFUL), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->Create_composition(CHEERFUL), CHEERFUL);
	case RIDICULOUS:
		scene_in_development = new Scene(scriptwriter->write_script(RIDICULOUS), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->Create_composition(RIDICULOUS), RIDICULOUS);
	case SAD_ANGUISH:
		scene_in_development = new Scene(scriptwriter->write_script(SAD_ANGUISH), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->Create_composition(SAD_ANGUISH), SAD_ANGUISH);
	case VERY_MELANCHOLIC:
		scene_in_development = new Scene(scriptwriter->write_script(VERY_MELANCHOLIC), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->Create_composition(VERY_MELANCHOLIC), VERY_MELANCHOLIC);
	case NEUTRAL:
		scene_in_development = new Scene(scriptwriter->write_script(NEUTRAL), level_designer->create_level(), artist->create_model(), programmer->write_code(), musician->Create_composition(NEUTRAL), NEUTRAL);
	}
	game_in_development->next_month();
	accounting->new_month();
}

void Game_studio::work_distribution()
{
	accountant->information_from_accounting();
	scriptwriter_distribution();
	musician_distribution();
	programer_distribution();
	artist_3D_distribution();
	level_designer_distribution();
	game_in_development->next_month();
	accounting->new_month();
}
void Game_studio::new_game()
{
	//(int deadline, int resources, int scenes_num, Accounting * corp_accounting)
	delete game_in_development;
	int num_of_months_for_game,num_scenes, number_of_allowed_resources;
	std::cout << "Enter the number of months allocated for game development";
	std::cin >> num_of_months_for_game;
	std::cout << "Enter the number of allowed resources";
	std::cin>> number_of_allowed_resources;
	std::cout << "Enter number of scenes";
	std::cin >> num_scenes;
	game_in_development = new Game(num_of_months_for_game, number_of_allowed_resources, num_scenes, accounting);
}
void Game_studio::release()
{
	if (game_in_development->scene_release(*scene_in_development))
	{
		new_game();
	}
	int plagiarism_choice;
	char mood_choice;
	std::string music_list;
	MOOD mood;
	std::cout << "Select a mood(enter first letter)'\n'";
	std::cin >> mood_choice;
	std::cout << "Press 1 to create a scene without plagiarism, 2 to create one with plagiarism'\n'";
	std::cin >> plagiarism_choice;
	switch (mood_choice)
	{
	case 'c':
		mood = CHEERFUL;
		break;
	case 'r':
		mood = RIDICULOUS;
		break;
	case 's':
		mood = SAD_ANGUISH;
		break;
	case 'v':
		mood = VERY_MELANCHOLIC;
		break;
	case 'n':
		mood = NEUTRAL;
		break;
	default:
		throw std::runtime_error("Error in selecting scene mood");
	}
	switch (mood_choice)
	{
	case 1:
		scene_planning(mood);
		break;
	case 2:
		int num_of_work;
		std::cout << "Enter the path to the list with music'\n'";
		std::cin >> music_list;
		musician->display_list_of_applicants_for_сopying(music_list);
		std::cout << "Number of the work in the list'\n'";
		std::cin >> num_of_work;
		scene_planning(mood, music_list, num_of_work);
		break;
	default:
		throw std::runtime_error("Error in selecting scene creation mode");
	}
}



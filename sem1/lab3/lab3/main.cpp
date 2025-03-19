#include "Game_studio.h"
int main()
{
	Accounting* accounting=new Accounting(1000000, 0, 100);
	Game_studio game_studio(accounting, "list_of_subordinates.txt");
	try
	{
		game_studio.new_game();
		game_studio.scene_planning(NEUTRAL);
		int exit=2;
		std::string music_list;
		while (exit != 1)
		{
			int choice;
			std::cout << "If you want to develop a new scene, press '1'. If you want to distribute work, press '2'";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				int plagiarism_choice;
				char mood_choice;
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
					game_studio.scene_planning(mood);
					break;
				case 2:
					int num_of_work;
					std::cout << "Enter the path to the list with music'\n'";
					std::cin >> music_list;
					game_studio.get_musician()->display_list_of_applicants_for_сopying(music_list);
					std::cout << "Number of the work in the list'\n'";
					std::cin >> num_of_work;
					game_studio.scene_planning(mood, music_list, num_of_work);
					break;
				default:
					throw std::runtime_error("Error in selecting scene creation mode");
				}
				break;
			case 2:
				game_studio.work_distribution();
				break;
			default:
				throw std::runtime_error("Error in main");
			}
			std::cout << "Do you want to continue. If not, press 1, ​​if yes, press 2'\n'";
			std::cin >> exit;
		}
	}
	catch (char a)
	{
		std::cerr << "The studio went bankrupt";
		exit(0);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
		exit(0);
	}
}
#include "Game.h"

Game::Game(int deadline, int resources, int scenes_num, Accounting* corp_accounting):
	number_of_months_for_development(deadline), available_resources(resources), number_of_scenes(scenes_num),accounting(corp_accounting)
{
}

void Game::next_month()
{
	--number_of_months_for_development;
	std::cout << "Left " << number_of_months_for_development << " months";
	if(number_of_months_for_development==0) throw std::runtime_error("Production hell");
}

bool Game::scene_release(Scene& scene)
{
	scene.scene_release(&overal_quality, &available_resources);
	--number_of_scenes;
	if(available_resources<0) throw std::runtime_error("The game does not meet the requirements");
	if (number_of_scenes == 0)
	{
		accounting->one_time_payment(1000 * overal_quality);
		accounting->increased_incomes(200* overal_quality);
		return 1;
	}
	return 0;
}

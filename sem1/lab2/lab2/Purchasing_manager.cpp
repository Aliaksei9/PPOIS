#include "Purchasing_manager.h"

Purchasing_manager::Purchasing_manager(std::string name_purchasing_manager, int purchasing_manager_ID, Accounting& place_of_work_purchasing_manager)
{
	ID = purchasing_manager_ID;
	name = name_purchasing_manager;
	position = PURCHASING_MANAGER;
	place_of_work=&place_of_work_purchasing_manager;
	place_of_work->increased_costs(700);
}

Purchasing_manager::Purchasing_manager(std::string name_purchasing_manager, int purchasing_manager_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_purchasing_manager)
{
	ID = purchasing_manager_ID;
	name = name_purchasing_manager;
	position = PURCHASING_MANAGER;
	place_of_work=&place_of_work_purchasing_manager;
	place_of_work->increased_costs(700);
	reprimands = list_of_reprimands;
}

Purchasing_manager::~Purchasing_manager()
{
	place_of_work->reduce_costs(700);
}

void Purchasing_manager::buy_aquarium(std::vector<Aquarium*>&aquariums,int fish_limit, FISH_TYPE type_in_aquarium)
{
	aquariums.push_back(new Aquarium(fish_limit, Water(1, 1, 1, 1), *place_of_work,type_in_aquarium));
	place_of_work->reduce_free_space(fish_limit * 50);

}

void Purchasing_manager::sell_aquarium(std::vector<Aquarium*>& aquariums,int aquarium_index)
{
	place_of_work->reduce_costs(400*(aquariums[aquarium_index]->get_fishes().size()));
	place_of_work->increased_free_space(aquariums[aquarium_index]->get_fish_limit() * 50);
	place_of_work->selling(300);
	delete aquariums[aquarium_index];
	aquariums.erase(aquariums.begin() + aquarium_index);
}

void Purchasing_manager::buy_fish(Aquarium* aquarium,Water required_water,int max_HP,int damage,FISH_TYPE fish_type,bool sex)
{
	place_of_work->purchase(150);
	aquarium->add_fish(Hydrobiont(required_water,max_HP,max_HP,damage,fish_type,sex));
}

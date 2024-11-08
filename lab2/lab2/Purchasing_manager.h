#pragma once
#include "Worker.h"
#include "Aquarium.h"
class HR;
class Parser;
class Purchasing_manager : public Worker
{
public:
	Purchasing_manager(std::string name_purchasing_manager, int purchasing_manager_ID, Accounting& place_of_work_purchasing_manager);
	Purchasing_manager(std::string name_purchasing_manager, int purchasing_manager_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_purchasing_manager);
	~Purchasing_manager();
	void buy_aquarium(std::vector<Aquarium*>& aquariums, int fish_limit, FISH_TYPE type_in_aquarium);
	//купить рыбу
	void sell_aquarium(std::vector<Aquarium*>& aquariums, int aquarium_index);
	void buy_fish(Aquarium* aquarium, Water required_water, int max_HP, int damage, FISH_TYPE fish_type, bool sex);
	friend class HR;
	friend class Parser;
};


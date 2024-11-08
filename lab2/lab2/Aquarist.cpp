#include "Aquarist.h"
Aquarist::~Aquarist()
{
	place_of_work->reduce_costs(600);
}
Aquarist::Aquarist(std::string name_aquarist, int aquarist_ID, Accounting& place_of_work_aquarist)
{
	ID = aquarist_ID;
	name = name_aquarist;
	position = AQUARIST;
	place_of_work=&place_of_work_aquarist;
	place_of_work->increased_costs(600);
}
Aquarist::Aquarist(std::string name_aquarist,int aquarist_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_aquarist)
{
	ID = aquarist_ID;
	name = name_aquarist;
	reprimands = list_of_reprimands;
	position = AQUARIST;
	place_of_work=&place_of_work_aquarist;
	place_of_work->increased_costs(600);
}

void Aquarist::clean_aquarium(Aquarium& dirty_aquarium)
{
	dirty_aquarium.aquarium_contamination = 1;
}

void Aquarist::feed_the_fish(Aquarium& aquarium)
{
	for (int i = 0; i < aquarium.fishes.size(); ++i)
		aquarium.fishes[i].food = 1;
}

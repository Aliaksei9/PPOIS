#include "Ichthyopathologist.h"

Ichthyopathologist::~Ichthyopathologist()
{
	place_of_work->reduce_costs(1000);
}

Ichthyopathologist::Ichthyopathologist(std::string name_ichthyopathologist, int ichthyopathologist_ID,Accounting& place_of_work_ichthyopathologist)
{
	name = name_ichthyopathologist;
	ID = ichthyopathologist_ID;
	position = ICHTHYOPATHOLOGIST;
	place_of_work=&place_of_work_ichthyopathologist;
	place_of_work->increased_costs(1000);
}

Ichthyopathologist::Ichthyopathologist(std::string name_ichthyopathologist, int ichthyopathologist_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_ichthyopathologist)
{
	name = name_ichthyopathologist;
	reprimands = list_of_reprimands;
	ID = ichthyopathologist_ID;
	position = ICHTHYOPATHOLOGIST;
	place_of_work=&place_of_work_ichthyopathologist;
	place_of_work->increased_costs(1000);
}


void Ichthyopathologist::healing(Hydrobiont& fish)
{
	fish.HP = fish.max_HP;
}

Hydrobiont Ichthyopathologist::fish_breeding(Hydrobiont& fish1, Hydrobiont& fish2)
{
	if ((fish1.sex == 1 && fish2.sex == 0) || (fish1.sex == 0 && fish2.sex == 1))
		if (fish1.comprasion_of_species(fish2)) return Hydrobiont(fish1.required_water, fish1.max_HP, fish1.max_HP, fish1.damage, fish1.fish_type, rand() % 2);
	throw std::runtime_error("Разные рыбки");
}

#include "Aquarium.h"

Aquarium::Aquarium(unsigned int limit, Water water, Accounting& organistion, FISH_TYPE type) :
	fish_limit(limit), water_in_aquarium(water), aquarium_position(&organistion), aquarium_type(type)
{
	profitability = 0;
}


void Aquarium::new_day_aquarium()
{
	for (int i = 0; i < fishes.size(); ++i)
	{
		if (fishes[i].degree_of_hunger() == 0)
		{
			if (aquarium_type == PREDATOR&&fishes.size()>1)
			{
				int a = rand() % fishes.size();
				while(a==i) a = rand() % fishes.size();
				switch (fishes[i].fight(&fishes[a]))
				{
				case 2:
					fishes.erase(fishes.begin() + i);
					fishes.erase(fishes.begin() + a);
					profitability = profitability- 800;
					break;
				case 1:
					fishes[a].food = 1;
					fishes.erase(fishes.begin() + i);
					profitability = profitability-400;
					break;
				case 0:
					fishes[i].food = 1;
					fishes.erase(fishes.begin() + a);
					profitability = profitability-400;
					break;
				}
			}
			else
			{
				profitability = profitability - 400;
				fishes.erase(fishes.begin() + i);
			}
		}
	}
	for(int i=0; i < fishes.size(); ++i)
		fishes[i].food = 0;

	if (last_time_income == 1 && aquarium_contamination == 0)
	{
		aquarium_position->reduce_incomes(profitability);
		std::cout << profitability;
		last_time_income = 0;
	}
	else if (last_time_income == 0 && aquarium_contamination == 1)
	{
		aquarium_position->increased_incomes(profitability);
		last_time_income = 1;
	}
	aquarium_contamination = 0;

}

void Aquarium::add_fish(Hydrobiont new_fish)
{
	if (fishes.size() + 1 <= fish_limit&&new_fish.get_water() == water_in_aquarium&&new_fish.get_type() ==aquarium_type )
	{
		fishes.push_back(new_fish);
		profitability += 400;
	}
	else std::cout << "Рыба не прижилась";
}

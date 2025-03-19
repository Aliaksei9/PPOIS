#include "Hydrochemist.h"
void Hydrochemist::take_samples(Aquarium& aquarium)
{
	std::cout << "Результаты:\n" << "1.Солёность" << (*aquarium.get_water()).salinity << std::endl << "2.Кислотность" << (*aquarium.get_water()).acidity << std::endl << "3.Температура" << (*aquarium.get_water()).temperature << "4.Растворенный кислород" << (*aquarium.get_water()).dissolved_oxygen << std::endl;
}
Hydrochemist::Hydrochemist(std::string name_hydrochemist,int hydrochemist_ID, Accounting& place_of_work_hydrochemist)
{
	ID = hydrochemist_ID;
	name = name_hydrochemist;
	position = HYDROCHEMIST;
	place_of_work=&place_of_work_hydrochemist;
	place_of_work->increased_costs(800);
}
Hydrochemist::~Hydrochemist()
{
	place_of_work->reduce_costs(800);
}
Hydrochemist::Hydrochemist(std::string name_hydrochemist, int hydrochemist_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_hydrochemist)
{
	ID = hydrochemist_ID;
	reprimands = list_of_reprimands;
	name = name_hydrochemist;
	position = HYDROCHEMIST;
	place_of_work=&place_of_work_hydrochemist;
	place_of_work->increased_costs(800);
}
void Hydrochemist::change_water_parameters(Aquarium& aquarium, char changing_parametr,double new_parametr_value)//Передавать аквариум
{
		switch (changing_parametr)
		{
		case 's':
			(*aquarium.get_water()).salinity = new_parametr_value;
			break;
		case 'a':
			(*aquarium.get_water()).acidity = new_parametr_value;
			break;
		case 't':
			(*aquarium.get_water()).temperature = new_parametr_value;
			break;
		case 'd':
			(*aquarium.get_water()).dissolved_oxygen = new_parametr_value;
			break;
		default:
			throw std::runtime_error("Неправильно задан изменяемый параметр");
		}
}
#pragma once
#include "Worker.h"
#include "Aquarium.h"
#include <iostream>
#include <exception>
class HR;
class Parser;
class Hydrochemist: public Worker
{
public:
	~Hydrochemist();
	Hydrochemist(std::string name_hydrochemist, int hydrochemist_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_hydrochemist);
	Hydrochemist(std::string name_hydrochemist, int hydrochemist_ID, Accounting& place_of_work_hydrochemist);
	void take_samples(Aquarium & aquarium);
	void change_water_parameters(Aquarium& aquarium, char changing_parametr,double new_parametr_value);
	friend class HR;
	friend class Parser;
};
#pragma once
#include "Worker.h"
#include "Aquarium.h"
class HR;
class Parser;
class Aquarist : public Worker
{
public:
	~Aquarist();
	Aquarist(std::string name_aquarist, int aquarist_ID,Accounting& place_of_work_cleaner);
	Aquarist(std::string name_aquarist, int aquarist_ID,std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_aquarist);
	void clean_aquarium(Aquarium& dirty_aquarium);
	void feed_the_fish(Aquarium& aquarium);
	friend class HR;
	friend class Parser;
};


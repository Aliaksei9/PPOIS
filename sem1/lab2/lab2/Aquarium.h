#pragma once
#include "Hydrobiont.h"
#include "Accounting.h"
#include <vector>
#include <stdexcept>
#include <cstdlib> 
#include <iostream>
class Aquarist;
class Aquarium
{
private: 
	unsigned int fish_limit;
	Water water_in_aquarium;
	int profitability=0;
	std::vector<Hydrobiont> fishes;
	bool aquarium_contamination=1,last_time_income=0;
	Accounting* aquarium_position;
	FISH_TYPE aquarium_type;
public:
	Aquarium(unsigned int limit, Water water, Accounting& organistion, FISH_TYPE type);
	void new_day_aquarium();
	void add_fish(Hydrobiont new_fish);
	Water* get_water() { return &water_in_aquarium;}
	std::vector<Hydrobiont>& get_fishes() { return fishes;}
	int get_fish_limit() const { return fish_limit; }
	void change_water(Water& new_water) { water_in_aquarium = new_water; }
	friend class Aquarist;
};

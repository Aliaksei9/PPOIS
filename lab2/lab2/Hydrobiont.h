#pragma once
#include <string>
#include "Water.h"
#include <exception>
#include <stdexcept>
class Aquarist;
class Ichthyopathologist;
class Aquarium;
enum FISH_TYPE
{
	PREDATOR,
	HERBIVORE
};
class Hydrobiont
{
protected:
	Water & required_water;
	int max_HP,HP,damage;
	bool food=0;
	FISH_TYPE fish_type;
	bool sex;
public:
	Hydrobiont(Water& water, int hp,int fish_max_HP, int fish_damage, FISH_TYPE type, bool fish_sex) :
		required_water(water), HP(hp), max_HP(fish_max_HP), damage(fish_damage), fish_type(type), sex(fish_sex)
	{
		if (HP > max_HP) throw std::runtime_error("Ќеправильно задан измен€емый параметр");
	}
	Hydrobiont& operator=(Hydrobiont const& right);
	void starvation(){ food = 0; }
	int get_HP() const { return HP; }
	void change_HP(int damage) { HP+=damage; }
	bool degree_of_hunger() const { return food; }
	int get_damage() const { return damage; }
	bool get_sex() const { return sex; }
	FISH_TYPE get_type() const { if (fish_type == PREDATOR) return PREDATOR; else return HERBIVORE; }
	int fight(Hydrobiont* opponent);
	bool comprasion_of_species(Hydrobiont& fish);
	Water get_water()const { return required_water; }
	friend class Aquarist;
	friend class Ichthyopathologist;
	friend class Aquarium;
};


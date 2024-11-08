#include "Hydrobiont.h"
int Hydrobiont::fight(Hydrobiont* opponent)
{
	while (HP > 0 || opponent->get_HP() > 0)
	{
		HP -= opponent->get_damage();
		opponent->change_HP(-damage);
	}
	if (HP < 0 && opponent->get_HP()<0) return 2;
	else if (HP < 0) return 1;
	else return 0;
}
bool Hydrobiont::comprasion_of_species(Hydrobiont& fish)
{
	if (this->required_water == fish.required_water && this->max_HP == fish.max_HP && this->damage == fish.damage && this->fish_type == fish.fish_type) return true;
	else return false;
}
Hydrobiont & Hydrobiont::operator=(Hydrobiont const & right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}
	required_water = right.required_water;
	HP = right.HP;
	damage = right.damage;
	food = right.food;
	fish_type = right.fish_type;
	sex = right.sex;
	return *this;

}
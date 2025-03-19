#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Aquarium.h"
TEST(TestAquarium, FishDeth)
{
	Accounting organisation;
	Aquarium aquarium(5, Water(1, 1, 1, 1), organisation, PREDATOR);
	aquarium.add_fish(Hydrobiont(Water(1, 2, 1, 1), 5, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 5, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 18, 20, 3, PREDATOR, 1));
	EXPECT_EQ(aquarium.get_fishes().size(), 2);
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	EXPECT_EQ(aquarium.get_fishes().size(), 0);
	aquarium.add_fish(Hydrobiont(Water(1, 2, 1, 1), 5, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 18, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 18, 20, 3, PREDATOR, 1));
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	EXPECT_EQ(aquarium.get_fishes().size(), 0);
	aquarium.add_fish(Hydrobiont(Water(1, 2, 1, 1), 5, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 18, 20, 3, PREDATOR, 1));
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 5, 20, 3, PREDATOR, 1));
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	aquarium.new_day_aquarium();
	EXPECT_EQ(aquarium.get_fishes().size(), 0);
}
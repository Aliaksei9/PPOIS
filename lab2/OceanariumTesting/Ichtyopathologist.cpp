#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Ichthyopathologist.h"
#include "/2kurs/PPOIS/lab2/lab2/Aquarium.h"
TEST(TestIchthyopathologist, IchthyopathologistHeal)
{
	Accounting organisation;
	Hydrobiont fish(Water(1, 1, 1, 1), 1, 20, 1, PREDATOR, 1);
	Ichthyopathologist worker("Aliaksei", 123, organisation);
	worker.healing(fish);
	EXPECT_EQ(fish.get_HP(), 20);
}
TEST(TestIchthyopathologist, IchthyopathologistFishBreeding)
{
	Accounting organisation;
	std::vector<REPRIMAND> reprimands;
	Aquarium aquarium(1, Water(1, 1, 1, 1), organisation, PREDATOR);
	Ichthyopathologist worker("Aliaksei", 123, reprimands, organisation);
	Hydrobiont fish1(Water(1, 1, 1, 1), 1, 20, 1, PREDATOR, 1);
	Hydrobiont fish2(Water(1, 1, 1, 1), 1, 20, 1, PREDATOR, 0);
	Hydrobiont fish3(Water(2, 2, 2, 2), 1, 20, 1, PREDATOR, 0);
	EXPECT_THROW({ fish1 = worker.fish_breeding(fish1,fish3); }, std::exception);
	aquarium.add_fish(worker.fish_breeding(fish1, fish2));
}
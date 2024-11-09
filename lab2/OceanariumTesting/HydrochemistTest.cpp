#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Hydrochemist.h"
TEST(TestHydrochemist, HydrochemistTakeSamples)
{
	Accounting organisation;
	std::vector<REPRIMAND> reprimands;
	Aquarium aquarium(1, Water(1, 1, 1, 1), organisation, PREDATOR);
	Water compare_water(1, 1, 1, 1);
	Hydrochemist worker("Aliaksei", 123, reprimands, organisation);
	worker.take_samples(aquarium);
	worker.change_water_parameters(aquarium, 's', 2);
	EXPECT_FALSE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 's', 1);
	EXPECT_TRUE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 'a', 2);
	EXPECT_FALSE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 'a', 1);
	EXPECT_TRUE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 'd', 2);
	EXPECT_FALSE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 'd', 1);
	EXPECT_TRUE(*aquarium.get_water() == compare_water);
	worker.change_water_parameters(aquarium, 't', 2);
	EXPECT_FALSE(*aquarium.get_water() == compare_water);
	EXPECT_THROW({ worker.change_water_parameters(aquarium, 'f', 2); }, std::exception);
}
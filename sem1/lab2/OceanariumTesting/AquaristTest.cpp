#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Aquarist.h"
#include "/2kurs/PPOIS/lab2/lab2/Accountant.h"
TEST(TestAquarist, CleanFeed)
{
	Accounting organisation;
	std::vector<REPRIMAND> reprimands;
	Aquarist worker("Aliaksei", 123, reprimands, organisation);
	Accountant accountant("Aliaksei", 123, reprimands, organisation);
	Aquarium aquarium(5, Water(1, 1, 1, 1), organisation, HERBIVORE);
	aquarium.add_fish(Hydrobiont(Water(1, 1, 1, 1), 5, 20, 3, HERBIVORE, 1));
	worker.feed_the_fish(aquarium);
	worker.clean_aquarium(aquarium);
	aquarium.new_day_aquarium();
	EXPECT_EQ(aquarium.get_fishes().size(), 1);
	EXPECT_EQ(accountant.get_incomes(), 400);
}
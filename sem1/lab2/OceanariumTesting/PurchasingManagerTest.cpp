#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Purchasing_manager.h"
TEST(TestPurchasingManager, BuySellAquarium)
{
	std::vector<REPRIMAND> reprimands;
	Accounting organisation;
	reprimands.push_back(SPREE);
	Purchasing_manager worker("Aliaksei", 123, reprimands, organisation);
	std::vector<Aquarium*> aquariums;
	worker.buy_aquarium(aquariums, 1, PREDATOR);
	EXPECT_EQ(aquariums.size(), 1);
	worker.sell_aquarium(aquariums, 0);
	EXPECT_EQ(aquariums.size(), 0);
}
TEST(TestPurchasingManager, BuyFish)
{
	std::vector<REPRIMAND> reprimands;
	Accounting organisation;
	Purchasing_manager worker("Aliaksei", 123, organisation);
	std::vector<Aquarium*> aquariums;
	Aquarium* aquarium = new Aquarium(1, Water(1, 1, 1, 1), organisation, PREDATOR);
	worker.buy_fish(aquarium, Water(1, 1, 1, 1), 1, 1, PREDATOR, 0);
	worker.buy_fish(aquarium, Water(2, 1, 1, 1), 1, 1, PREDATOR, 0);
	EXPECT_EQ(aquarium->get_fishes().size(), 1);
}
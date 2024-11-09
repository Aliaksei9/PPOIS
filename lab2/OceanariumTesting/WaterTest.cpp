
#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Accountant.h"
#include "/2kurs/PPOIS/lab2/lab2/Aquarist.h"
#include "/2kurs/PPOIS/lab2/lab2/Cleaner.h"
#include "/2kurs/PPOIS/lab2/lab2/HR.h"
#include "/2kurs/PPOIS/lab2/lab2/Head.h"
#include "/2kurs/PPOIS/lab2/lab2/Hydrochemist.h"
#include "/2kurs/PPOIS/lab2/lab2/Ichthyopathologist.h"
#include "/2kurs/PPOIS/lab2/lab2/Purchasing_manager.h"
#include "/2kurs/PPOIS/lab2/lab2/Purchasing_manager.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Accountant.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Accounting.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Aquarist.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Aquarium.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Cleaner.cpp"
#include "/2kurs/PPOIS/lab2/lab2/HEAD.cpp"
#include "/2kurs/PPOIS/lab2/lab2/HR.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Hydrobiont.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Hydrochemist.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Ichthyopathologist.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Oceanarium.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Parser.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Water.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Worker.cpp"
/*TEST(TestClassWorker, WorkerGettersCout)
{
	std::vector<REPRIMAND> start_reprimands;
	start_reprimands.push_back(SPREE);
	start_reprimands.push_back(ABSENCE);
	start_reprimands.push_back(LATE);
	start_reprimands.push_back(LEFT_WORK_EARLY);
	start_reprimands.push_back(FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS);
	int ID = 123;
	Accounting organisation;
	Worker worker("Aliaksei", CLEANER, start_reprimands, &organisation, ID);
	EXPECT_EQ(worker.get_ID(), ID);
	EXPECT_TRUE(worker.get_position() == CLEANER);
	EXPECT_EQ(worker.get_reprimand_list().size(), start_reprimands.size());
	std::cout << worker;
	for (int i = 0; i < worker.get_reprimand_list().size(); ++i)
		EXPECT_TRUE(worker.get_reprimand_list()[i] == start_reprimands[i]);
}

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
}*/
TEST(TestWater, ComparisonOperation)
{
	Water water1(1, 1, 1, 1);
	Water water2(1, 1, 1, 1);
	Water water3(2, 2, 1, 2);
	EXPECT_TRUE(water1 == water2);
	EXPECT_FALSE(water1 == water3);
}
//reading(std::vector<Worker*>& workers, std::vector<Aquarium*>& aquariums, Accounting* place);
/*TEST(TestParser, ParserThrow)
{
	Accounting organisation;
	std::vector<Aquarium*> aquariums;
	std::vector<Worker*> workers;
	EXPECT_THROW({ Parser::reading(workers, aquariums, &organisation,"AB","CD"); }, std::exception);
	Parser::reading(workers, aquariums, &organisation, "/2kurs/PPOIS/lab2/lab2/workers.txt", "/2kurs/PPOIS/lab2/lab2/aquariums.txt");
	EXPECT_EQ(workers.size(), 8);
	EXPECT_EQ(aquariums.size(), 1);
	for (int i = 0; i < aquariums.size(); ++i)
		delete aquariums[i];
	for (int i = 0; i < workers.size(); ++i)
		delete workers[i];
}*/
/*TEST(TestIchthyopathologist, IchthyopathologistHeal)
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
}*/

/*TEST(TestHydrochemist, HydrochemistTakeSamples)
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
}*/
/*TEST(TestHydrobiont, HydrobiontGetters)
{
	Hydrobiont fish(Water(1, 1, 1, 1), 19, 20, 1, PREDATOR, 1);
	EXPECT_TRUE(fish.get_sex() == 1);
	fish.starvation();
	EXPECT_EQ(fish.degree_of_hunger(), 0);
	EXPECT_TRUE(fish.get_water() == Water(1, 1, 1, 1));
	fish.change_HP(-1);
	EXPECT_EQ(fish.get_HP(), 18);
	EXPECT_TRUE(fish.get_type() == PREDATOR);
}
TEST(TestHydrobiont, HPlowerMax_HP)
{
	EXPECT_THROW({ Hydrobiont fish(Water(1, 1, 1, 1), 21, 20, 1, PREDATOR, 1);; }, std::exception);
}*/
/*TEST(TestHR, HRWork)
{
	std::vector<REPRIMAND> reprimands;
	Accounting organisation;
	HR worker("Aliaksei", 123, reprimands, organisation);
	std::vector<Worker*> workers;
	worker.hire(workers, ACCOUNTANT);
	worker.hire(workers, AQUARIST);
	worker.hire(workers, CLEANER);
	worker.hire(workers, HR_specialist);
	worker.hire(workers, PURCHASING_MANAGER);
	worker.display_information_about_employees(workers);
	EXPECT_EQ(workers.size(), 5);
	while (workers.size() != 0) worker.fire_an_employee(workers, workers[workers.size() - 1]->get_ID());
	EXPECT_EQ(workers.size(), 0);
	EXPECT_THROW({ worker.fire_an_employee(workers, 111); }, std::exception);
}*/
/*TEST(TestHead, HeadWork)
{
	std::vector<REPRIMAND> reprimands;
	std::vector<Worker*> workers;
	Accounting organisation;
	Head worker("Aliaksei", 123, reprimands, organisation);
	EXPECT_THROW({ worker.issue_reprimand(SPREE, 111, workers); }, std::exception);
	Cleaner cleaner("Aliaksei", 1234, organisation);
	workers.push_back(&cleaner);
	worker.issue_reprimand(SPREE, 1234, workers);
	EXPECT_EQ(cleaner.get_reprimand_list().size(), 1);
}*/
/*TEST(TestCleaner, CleanerWork)
{
	Accounting organisation;
	Cleaner worker("Aliaksei", 123, organisation);
	worker.cleaning();
	EXPECT_EQ(organisation.get_cleanliness_of_the_premises(), 0);
}*/
/*TEST(TestAquarium, FishDeth)
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
}*/
/*TEST(TestAquarist, CleanFeed)
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
}*/
/*TEST(TestAccountant, AccountantGetterAndWork)
{
	Accounting organisation(1000, 9000, 500, 0);
	std::vector<REPRIMAND> reprimands;
	Accountant accountant("Aliaksei", 123, reprimands, organisation);
	accountant.information_from_accounting();
	EXPECT_EQ(accountant.get_budget(), 9000);
	EXPECT_EQ(accountant.get_incomes(), 0);
	EXPECT_EQ(accountant.get_expenses(), 1000);
}*/
/*TEST(TestAccounting, AccountingGetters)
{
	Accounting organisation(1000, 9000, 500, 0);
	EXPECT_THROW({ organisation.increased_incomes(-100); }, std::exception);
	EXPECT_THROW({ organisation.reduce_incomes(-100); }, std::exception);
	EXPECT_THROW({ organisation.increased_costs(-100); }, std::exception);
	EXPECT_THROW({ organisation.reduce_costs(-100); }, std::exception);
	EXPECT_THROW({ organisation.increased_free_space(-100); }, std::exception);
	EXPECT_THROW({ organisation.reduce_free_space(-100); }, std::exception);
	EXPECT_THROW({ organisation.purchase(-100); }, std::exception);
	EXPECT_THROW({ organisation.selling(-100); }, std::exception);
}*/
/*TEST(TestOceanarium, OceanariumNewDay)
{
	Accounting organisation(1000, 9000, 500, 0);
	EXPECT_THROW({ Oceanarium oceanariumtest(organisation); }, std::exception);
	Oceanarium oceanarium(organisation, "/2kurs/PPOIS/lab2/lab2/workers.txt", "/2kurs/PPOIS/lab2/lab2/aquariums.txt");
	oceanarium.new_day();
	oceanarium.initial_inspection_of_aquariums();
	//oceanarium.distribution_of_work();
	EXPECT_THROW({ oceanarium.new_day(); }, char);
}
TEST(TestOceanarium, DistributionCleanerAccountant)
{
	Accounting organisation;
	Oceanarium oceanarium(organisation, "/2kurs/PPOIS/lab2/lab2/CleanerAccountant.txt", "/2kurs/PPOIS/lab2/lab2/aquariums.txt");
	oceanarium.initial_inspection_of_aquariums();
	oceanarium.distribution_of_work();
	EXPECT_EQ(organisation.get_cleanliness_of_the_premises(), 0);
}*/
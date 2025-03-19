#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Oceanarium.h"
TEST(TestOceanarium, OceanariumNewDay)
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
}
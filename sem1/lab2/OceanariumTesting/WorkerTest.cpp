#include "pch.h"
//#include "WaterTest.cpp"
#include "/2kurs/PPOIS/lab2/lab2/Accountant.h"
TEST(TestClassWorker, WorkerGettersCout)
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
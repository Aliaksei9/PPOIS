#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Cleaner.h"
#include "/2kurs/PPOIS/lab2/lab2/Head.h"
TEST(TestHead, HeadWork)
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
}
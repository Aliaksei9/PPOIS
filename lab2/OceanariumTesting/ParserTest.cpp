#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Parser.h"
TEST(TestParser, ParserThrow)
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
}
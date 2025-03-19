#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/HR.h"
TEST(TestHR, HRWork)
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
}
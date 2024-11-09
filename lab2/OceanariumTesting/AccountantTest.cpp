#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Accountant.h"
TEST(TestAccountant, AccountantGetterAndWork)
{
	Accounting organisation(1000, 9000, 500, 0);
	std::vector<REPRIMAND> reprimands;
	Accountant accountant("Aliaksei", 123, reprimands, organisation);
	accountant.information_from_accounting();
	EXPECT_EQ(accountant.get_budget(), 9000);
	EXPECT_EQ(accountant.get_incomes(), 0);
	EXPECT_EQ(accountant.get_expenses(), 1000);
}
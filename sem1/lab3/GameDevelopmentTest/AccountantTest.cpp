#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"
TEST(TestAccountant, AccountantGetters)
{
	Accounting accounting(5000, 300, 400);
	Accountant accountant("Alexey", &accounting);
	EXPECT_EQ(5000, accountant.get_budget());
	EXPECT_EQ(300, accountant.get_incomes());
	EXPECT_EQ(900, accountant.get_expenses());
}

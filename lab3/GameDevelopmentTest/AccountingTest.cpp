#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Accounting.h"
TEST(TestAccounting, AccountingException)
{
	Accounting organisation(9000, 500, 0);
	EXPECT_THROW({ organisation.increased_incomes(-100); }, std::exception);
	EXPECT_THROW({ organisation.reduce_incomes(-100); }, std::exception);
	EXPECT_THROW({ organisation.increased_costs(-100); }, std::exception);
	EXPECT_THROW({ organisation.reduce_costs(-100); }, std::exception);
	EXPECT_THROW({ organisation.one_time_payment(-100); }, std::exception);
	EXPECT_THROW({ organisation.one_time_waste(-100); }, std::exception);
}

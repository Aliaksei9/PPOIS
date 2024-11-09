#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Accounting.h"
TEST(TestAccounting, AccountingGetters)
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
}
#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Cleaner.h"
TEST(TestCleaner, CleanerWork)
{
	Accounting organisation;
	Cleaner worker("Aliaksei", 123, organisation);
	worker.cleaning();
	EXPECT_EQ(organisation.get_cleanliness_of_the_premises(), 0);
}
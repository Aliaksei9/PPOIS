#include "pch.h"
#include "/2kurs/PPOIS/lab2/lab2/Hydrobiont.h"
TEST(TestHydrobiont, HydrobiontGetters)
{
	Hydrobiont fish(Water(1, 1, 1, 1), 19, 20, 1, PREDATOR, 1);
	EXPECT_TRUE(fish.get_sex() == 1);
	fish.starvation();
	EXPECT_EQ(fish.degree_of_hunger(), 0);
	EXPECT_TRUE(fish.get_water() == Water(1, 1, 1, 1));
	fish.change_HP(-1);
	EXPECT_EQ(fish.get_HP(), 18);
	EXPECT_TRUE(fish.get_type() == PREDATOR);
}
TEST(TestHydrobiont, HPlowerMax_HP)
{
	EXPECT_THROW({ Hydrobiont fish(Water(1, 1, 1, 1), 21, 20, 1, PREDATOR, 1);; }, std::exception);
}
#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Level_designer.h"
#include "/2kurs/PPOIS/lab3/lab3/Level.h"
#include "/2kurs/PPOIS/lab3/lab3/Level.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Level_designer.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"
TEST(TestLevelDesigner, LevelDesignerScetches)
{
	Accounting accounting(5000, 300, 400);
	Level_designer designer("Alexey", 0.5, &accounting);
	designer.trip_for_sketches();
	Accountant accountant("Alexey", &accounting);
	EXPECT_EQ(4900,accountant.get_budget());
	EXPECT_TRUE(designer.get_availability_of_sketches());
}
TEST(TestLevelDesigner, LevelDesignerOptimization)
{
	Accounting accounting(5000, 300, 400);
	Level_designer designer("Alexey", 0.5, &accounting);
	Level level = designer.create_level();
	int start_condition = level.get_resourse_intensity();
	designer.optimization(&level);
	int final_condition = level.get_resourse_intensity();
	EXPECT_TRUE(final_condition - start_condition == -2);
}
TEST(TestLevelDesigner, LevelDesignerRevision)
{
	Accounting accounting(5000, 300, 400);
	Level_designer designer("Alexey", 0.5, &accounting);
	Level level = designer.create_level();
	int start_condition_resource = level.get_resourse_intensity();
	double start_condition_quality = level.get_quality();
	designer.revision(&level);
	int final_condition_resource = level.get_resourse_intensity();
	double final_condition_quality = level.get_quality();
	EXPECT_TRUE(final_condition_resource - start_condition_resource == 3);
	EXPECT_DOUBLE_EQ(final_condition_quality - start_condition_quality, 0.8);
}

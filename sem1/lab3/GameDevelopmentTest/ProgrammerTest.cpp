#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Programmer.h"
#include "/2kurs/PPOIS/lab3/lab3/Code.h"
#include "/2kurs/PPOIS/lab3/lab3/Code.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Programmer.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"

TEST(TestProgrammer, ProgrammerFixingBugs)
{
	Accounting accounting(5000, 300, 400);
	Programmer programmer("Alexey", 0.5, &accounting);
	Code code = programmer.write_code();
	int start_condition = code.get_bugs();
	programmer.fixing_bugs(&code);
	int final_condition = code.get_bugs();
	EXPECT_TRUE(final_condition<start_condition);
}
TEST(TestProgrammer, ProgrammerOptimization)
{
	Accounting accounting(5000, 300, 400);
	Programmer programmer("Alexey", 0.5, &accounting);
	Code code = programmer.write_code();
	int start_condition = code.get_resourse_intensity();
	programmer.optimization(&code);
	int final_condition = code.get_resourse_intensity();
	EXPECT_TRUE(final_condition - start_condition == -1);
}
TEST(TestProgrammer, ProgrammerRevision)
{
	Accounting accounting(5000, 300, 400);
	Programmer programmer("Alexey", 0.5, &accounting);
	Code code = programmer.write_code();
	int start_condition_resource = code.get_resourse_intensity();
	double start_condition_quality = code.get_quality();
	programmer.revision(&code);
	int final_condition_resource = code.get_resourse_intensity();
	double final_condition_quality = code.get_quality();
	EXPECT_TRUE(final_condition_resource - start_condition_resource == 2);
	EXPECT_DOUBLE_EQ(final_condition_quality - start_condition_quality , 1);
}
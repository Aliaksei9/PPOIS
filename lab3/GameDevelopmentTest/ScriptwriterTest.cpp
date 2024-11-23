#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Scriptwriter.h"
#include "/2kurs/PPOIS/lab3/lab3/Scriptwriter.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Script.h"
#include "/2kurs/PPOIS/lab3/lab3/Script.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"

TEST(TestScriptwriter, ScriptwriterPreporation)
{
	Accounting accounting2(5000, 0, 0);
	Scriptwriter scriptwriter("Alexey", 0.5, CHEERFUL, &accounting2);
	scriptwriter.preporation();
	scriptwriter.preporation();
	scriptwriter.preporation();
	scriptwriter.preporation();
	Script script = scriptwriter.write_script(CHEERFUL);
	EXPECT_TRUE(script.get_quality());
}
TEST(TestScriptwriter, ScriptwriterModify)
{
	Accounting accounting(5000, 0, 0);
	Scriptwriter scriptwriter("Alexey", 0.5, CHEERFUL, &accounting);
	Script script = scriptwriter.write_script(CHEERFUL);
	scriptwriter.training();
	scriptwriter.training();
	scriptwriter.training();
	double start_condition = script.get_quality();
	scriptwriter.modify(&script);
	double final_condition = script.get_quality();
	EXPECT_TRUE(final_condition > start_condition);
}

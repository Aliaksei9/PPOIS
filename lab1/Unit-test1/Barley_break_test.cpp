#include "pch.h"
#include "/2kurs/PPOIS/lab1/lab1/Barley_break.h"
#include <set>
#include <stdexcept>
#include "/2kurs/PPOIS/lab1/lab1/Barley_break.cpp"
#include <stdexcept>
TEST(MixCheck, CheakAllValues)//проверяет,чтобы все значения от 0 до 15 были расставлены
{
	Barley_break game_check;
	std::set<int> table_check;
	int k = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			table_check.insert(game_check[i][j]);
	EXPECT_EQ(table_check.size(), 16) << "Not all squares are filled\n";
	for (int n : table_check)
	{
		EXPECT_EQ(n, k) << "Not all values ​​are on the table\n";
		k++;
	}
}
TEST(MixCheck,InitialPositionOfZeroInMix )//проверяет,чтобы 0 был в конце
{
	Barley_break game_check;
	EXPECT_EQ(game_check[3][3], 0) << "Incorrect start zero position\n";
}
TEST(TransChecker, ExitFromField)
{
	Barley_break game_check;
	int a = game_check[3][2], b = game_check[2][3];
	EXPECT_THROW({ game_check.transposition('d'); }, std::exception) << "Wrong Exit(down)\n";
	EXPECT_THROW({ game_check.transposition('r'); }, std::exception)<<"Wrong Exit(right)\n";
	for(int i=0;i<3;++i) game_check.transposition('l');
	EXPECT_THROW({ game_check.transposition('l'); }, std::exception) << "Wrong Exit(left)\n";
	for (int i = 0; i < 3; ++i) game_check.transposition('u');
	EXPECT_THROW({ game_check.transposition('u'); }, std::exception) << "Wrong Exit(up)\n";
}

TEST(TransChecker,Transposition)
{
	Barley_break game_check;
	game_check.transposition('u');
	EXPECT_EQ(game_check[2][3], 0) << "Move up error\n";
	game_check.transposition('l');
	EXPECT_EQ(game_check[2][2], 0) << "Move left error\n";
	game_check.transposition('d');
	EXPECT_EQ(game_check[3][2], 0) << "Move down error\n";
	game_check.transposition('r');
	EXPECT_EQ(game_check[3][3], 0) << "Move right error\n";
}

TEST(TransChecker, AbnormalBehavior)
{
	Barley_break game_check;
	EXPECT_THROW({ game_check.transposition('22'); }, int) << "Wrong Exit(down)\n";
}

TEST(CheckChecker,GameOverCheck)
{
	Barley_break game_check;
	int value = 15;
	for (int i = 3; i>-1 ; --i)
		for (int j = 3; j >-3; --j)
		{
			if (game_check[i][j] != value)
				if (game_check[i][j] != 0) EXPECT_FALSE(game_check.check());
				else continue;
			--value;
		}
	if(value==0) EXPECT_TRUE(game_check.check());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#include "pch.h"
#include "/2 курс/ППОИС/lab1/lab1/Barley_break.h"
#include <set>
#include <stdexcept>
#include "/2 курс/ППОИС/lab1/lab1/Barley_break.cpp"
TEST(MixCheck, CheakAllValues)//проверяет,чтобы все значения от 0 до 15 были расставлены
{
	barley_break game_check;
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
TEST(MixCheck,InitialPositionOfZeroInMix )//проверяет,чтобы все значения от 0 до 15 были расставлены
{
	barley_break game_check;
	EXPECT_EQ(game_check[3][3], 0) << "Incorrect start zero position\n";
}
TEST(TransChecker, UpLeftDownRightExit)
{
	barley_break game_check;
	int a = game_check[3][2], b = game_check[2][3];
	game_check.transposition('d');
	EXPECT_EQ(game_check[3][3], 0) << "Wrong Exit(down)\n";
	EXPECT_EQ(game_check[3][2], a) << "Wrong Exit(down)\n";
	EXPECT_EQ(game_check[2][3], b) << "Wrong Exit(down)\n";
	game_check.transposition('r');
	EXPECT_EQ(game_check[3][3], 0) << "Wrong Exit(right)\n";
	EXPECT_EQ(game_check[3][2], a) << "Wrong Exit(right)\n";
	EXPECT_EQ(game_check[2][3], b) << "Wrong Exit(right)\n";
	a = game_check[3][0];
	b = game_check[2][0];
	for (int i = 0; i < 4; ++i)
		game_check.transposition('l');
	EXPECT_EQ(game_check[3][0], 0) << "Wrong Exit(left)\n";
	EXPECT_EQ(game_check[3][1], a) << "Wrong Exit(left)\n";
	EXPECT_EQ(game_check[2][0], b) << "Wrong Exit(left)\n";
	a = game_check[0][0];
	b = game_check[0][1];
	for (int i = 0; i < 4; ++i)
		game_check.transposition('u');
	EXPECT_EQ(game_check[0][0], 0) << "Wrong Exit(up)\n";
	EXPECT_EQ(game_check[1][0], a) << "Wrong Exit(up)\n";
	EXPECT_EQ(game_check[0][1], b) << "Wrong Exit(up)\n";
}

TEST(TransChecker,TranspositionUpLeftDownRight)
{
	barley_break game_check;
	game_check.transposition('u');
	EXPECT_EQ(game_check[2][3], 0) << "Move up error\n";
	game_check.transposition('l');
	EXPECT_EQ(game_check[2][2], 0) << "Move left error\n";
	game_check.transposition('d');
	EXPECT_EQ(game_check[3][2], 0) << "Move down error\n";
	game_check.transposition('r');
	EXPECT_EQ(game_check[3][3], 0) << "Move right error\n";
}

TEST(CheckChecker,GameOverCheck)
{
	barley_break game_check;
	int zn = 15;
	for (int i = 3; i>-1 ; --i)
		for (int j = 3; j >-3; --j)
		{
			if (game_check[i][j] != zn)
				if (game_check[i][j] != 0) EXPECT_FALSE(game_check.check());
				else continue;
			--zn;
		}
	if(zn==0) EXPECT_TRUE(game_check.check());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

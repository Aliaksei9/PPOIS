#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Game.h"
#include "/2kurs/PPOIS/lab3/lab3/Game.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Artist_3D.h"
#include "/2kurs/PPOIS/lab3/lab3/Level_designer.h"
#include "/2kurs/PPOIS/lab3/lab3/Programmer.h"
#include "/2kurs/PPOIS/lab3/lab3/Scriptwriter.h"
#include "/2kurs/PPOIS/lab3/lab3/Musician.h"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"

TEST(TestGame, GameNewMonth)
{
	Accounting accounting(5000, 0, 0);
	//(int deadline, int resources, int scenes_num, Accounting* corp_accounting):
	Game game(2, 12, 2, &accounting);
	game.next_month();
	EXPECT_THROW({ game.next_month(); }, std::exception);
}
TEST(TestGame, GameRelease)
{
	Accounting accounting(5000, 0, 0);
	Accountant accountant("Alexey", &accounting);
	Scriptwriter scriptwriter("Alexey", 0.5, CHEERFUL, &accounting);
	Programmer programmer("Alexey", 0.5, &accounting);
	Musician musician("Alexey", 0.5, 0, CHEERFUL, &accounting);
	Level_designer designer("Alexey", 0.5, &accounting);
	Artist_3D artist("Alexey", 0.5, &accounting);
	Scene* scene = new Scene(scriptwriter.write_script(CHEERFUL), designer.create_level(), artist.create_model(), programmer.write_code(), musician.Create_composition(CHEERFUL), CHEERFUL);
	//(int deadline, int resources, int scenes_num, Accounting* corp_accounting):
	Game game(2, 12, 1, &accounting);
	EXPECT_TRUE(game.scene_release(*scene));
	delete scene;
}
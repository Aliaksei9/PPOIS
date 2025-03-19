#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Scene.h"
#include "/2kurs/PPOIS/lab3/lab3/Scene.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Artist_3D.h"
#include "/2kurs/PPOIS/lab3/lab3/Level_designer.h"
#include "/2kurs/PPOIS/lab3/lab3/Programmer.h"
#include "/2kurs/PPOIS/lab3/lab3/Scriptwriter.h"
#include "/2kurs/PPOIS/lab3/lab3/Musician.h"
TEST(TestScene, SceneGetters)
{
	Accounting accounting(5000, 0, 0);
	Scriptwriter scriptwriter("Alexey", 0.5, CHEERFUL, &accounting);
	Programmer programmer("Alexey", 0.5, &accounting);
	Musician musician("Alexey", 0.5, 0, CHEERFUL, &accounting);
	Level_designer designer("Alexey", 0.5, &accounting);
	Artist_3D artist("Alexey", 0.5, &accounting);
	EXPECT_THROW({ Scene scene(scriptwriter.write_script(CHEERFUL), designer.create_level(), artist.create_model(), programmer.write_code(), musician.Create_composition(CHEERFUL),RIDICULOUS); }, std::exception);
	Scene* scene = new Scene(scriptwriter.write_script(CHEERFUL), designer.create_level(), artist.create_model(), programmer.write_code(), musician.Create_composition(CHEERFUL), CHEERFUL);
	EXPECT_TRUE(scene->get_scene_code());
	EXPECT_TRUE(scene->get_scene_level());
	EXPECT_TRUE(scene->get_scene_model());
	EXPECT_TRUE(scene->get_scene_music());
	EXPECT_TRUE(scene->get_scene_script());
	delete scene;
}
TEST(TestScene, SceneRelease)
{
	Accounting accounting(5000, 0, 0);
	Scriptwriter scriptwriter("Alexey", 0.5, CHEERFUL, &accounting);
	Programmer programmer("Alexey", 0.5, &accounting);
	Musician musician("Alexey", 0.5, 0, CHEERFUL, &accounting);
	Level_designer designer("Alexey", 0.5, &accounting);
	Artist_3D artist("Alexey", 0.5, &accounting);
	Scene* scene = new Scene(scriptwriter.write_script(CHEERFUL), designer.create_level(), artist.create_model(), programmer.write_code(), musician.Create_composition(CHEERFUL), CHEERFUL);
	int exception_resourses = -5;
	int resourses = 1000;
	double quality = 5;
	EXPECT_NO_THROW({ scene->scene_release(&quality, &resourses); }, std::exception);
	delete scene;
}
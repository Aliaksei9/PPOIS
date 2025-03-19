#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Artist_3D.h"
#include "/2kurs/PPOIS/lab3/lab3/Model.h"
#include "/2kurs/PPOIS/lab3/lab3/Model.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Artist_3D.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"

TEST(TestArtist_3D, ArtistFilming)
{
	Accounting accounting(5000, 300, 400);
	Accountant accountant("Alexey", &accounting);
	Artist_3D artist("Alexey",0.5,&accounting);
	artist.filming();
	EXPECT_TRUE(artist.get_motion_capture());
	EXPECT_EQ(accountant.get_budget(), 3800);
	Model model = artist.create_model();
}
TEST(TestArtist_3D, ArtistOptimization)
{
	Accounting accounting(5000, 300, 400);
	Artist_3D artist("Alexey", 0.5, &accounting);
	Model model = artist.create_model();
	int start_condition = model.get_resourse_intensity();
	artist.optimization(&model);
	int final_condition = model.get_resourse_intensity();
	EXPECT_TRUE(final_condition-start_condition==-3);
}
TEST(TestArtist_3D, ArtistRevision)
{
	Accounting accounting(5000, 300, 400);
	Artist_3D artist("Alexey", 0.5, &accounting);
	Model model = artist.create_model();
	int start_condition_resource = model.get_resourse_intensity();
	double start_condition_quality = model.get_quality();
	artist.revision(&model);
	int final_condition_resource = model.get_resourse_intensity();
	double final_condition_quality = model.get_quality();
	EXPECT_TRUE(final_condition_resource - start_condition_resource == 2);
	EXPECT_DOUBLE_EQ(final_condition_quality - start_condition_quality, 1);
}

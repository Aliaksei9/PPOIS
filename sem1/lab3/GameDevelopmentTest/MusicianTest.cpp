#include "pch.h"
#include "/2kurs/PPOIS/lab3/lab3/Musician.h"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.h"
#include "/2kurs/PPOIS/lab3/lab3/Accountant.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Musician.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Music.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Accounting.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Creative_worker.cpp"
#include "/2kurs/PPOIS/lab3/lab3/Worker.cpp"
TEST(TestMusician, MusicianPlagiat)
{
	Accounting accounting(5000,0,0);
	Musician musician("Alexey", 0.5, 0, CHEERFUL,&accounting);
	musician.display_list_of_applicants_for_ñopying("/2kurs/PPOIS/lab3/lab3/music_plagiarism.txt");
	EXPECT_THROW({ musician.plagiarize(CHEERFUL, "/2kurs/PPOIS/lab3/lab3/music_plagiarism.txt", 2); }, std::exception);
	EXPECT_THROW({ musician.plagiarize(CHEERFUL, "/2kurs/PPOIS/lab3/lab3/music_plagiarism.txt", 9); }, std::exception);
	EXPECT_NO_THROW({ musician.plagiarize(RIDICULOUS, "/2kurs/PPOIS/lab3/lab3/music_plagiarism.txt", 1); });
}
TEST(TestMusician, MusicianGettersLyricsShowRest)
{
	Accounting accounting(5000, 0, 0);
	Accountant accountant("Alexey", &accounting);
	Musician musician("Alexey", 0.5, 0, CHEERFUL, &accounting);
	musician.learn_writing_lyrics();
	EXPECT_DOUBLE_EQ(0.5, musician.get_ability_to_write_lyrics());
	musician.training();
	EXPECT_DOUBLE_EQ(1, musician.get_proffesionalism());
	musician.soundtrack_show();
	EXPECT_EQ(5500, accountant.get_budget());
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	musician.rest();
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	EXPECT_NO_THROW({ musician.Create_composition(CHEERFUL); });
	EXPECT_THROW({ musician.Create_composition(CHEERFUL);}, std::exception);
}
TEST(TestMusician, MusicianMidify)
{
	Accounting accounting(5000, 0, 0);
	Musician musician("Alexey", 0.5, 0, CHEERFUL, &accounting);
	Music music = musician.Create_composition(CHEERFUL);
	musician.training();
	musician.training();
	musician.training();
	int start_condition = music.get_quality();
	musician.modify(&music);
	int final_condition = music.get_quality();
	EXPECT_TRUE(final_condition > start_condition);
}

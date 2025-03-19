#include "Script.h"

Script::Script(double script_writter_professionalism, MOOD authors_specialization, MOOD mood_work, bool errors, bool inspiration)
{
	mood = mood_work;
	quality = (rand() % 3) * script_writter_professionalism;
	if (authors_specialization == mood_work) quality += 5;
	if (!errors) quality += 3;
	else quality -= 2;
	if (inspiration) quality += 0.5;
}

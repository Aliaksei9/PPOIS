#include "Scriptwriter.h"

Scriptwriter::Scriptwriter(std::string scriptwriter_name, double scriptwriter_professionalism, MOOD musician_specialization,Accounting* place_of_work_scriptwriter)
{
	name = scriptwriter_name;
	professionalism = scriptwriter_professionalism;
	place_of_work = place_of_work_scriptwriter;
	place_of_work->increased_costs(500);
}


void Scriptwriter::preporation()
{
	preporation_progress += 30;
}

Script Scriptwriter::write_script(MOOD mood_work)
{
	bool presence_of_errors;
	if (rand() % 101 > preporation_progress) presence_of_errors = 1;
	else presence_of_errors = 0;
	genre_fatigue += 0.3;
	if(genre_fatigue>1) throw std::runtime_error("The scriptwriter is burned_out");
	Script script (professionalism, specialization, mood_work, presence_of_errors,inspiration);
	inspiration = 0;
	preporation_progress = 0;
	return script;
}
void Scriptwriter::modify(Script* script)
{
	if (professionalism * (rand() % 4) > 1) script->quality += 0.5;
}

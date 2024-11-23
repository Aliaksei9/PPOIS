#pragma once
#include "Creative_worker.h"
#include "Script.h"
class Scriptwriter: public Creative_worker
{
private:
	int preporation_progress;
public:
	Scriptwriter(std::string scriptwriter_name,  double scriptwriter_professionalism,  MOOD musician_specialization, Accounting* place_of_work_scriptwriter);
	void preporation();
	Script write_script(MOOD mood_work);
	void modify(Script* script);
};


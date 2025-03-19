#pragma once
#include "Worker.h"
#include "Level.h"
class Level_designer: public Worker
{
private:
	bool availability_of_sketches=0;
public:
	Level_designer(std::string level_designer_name, double level_designer_professionalism, Accounting* place_of_work_level_designer);
	void trip_for_sketches();
	Level create_level();
	void optimization(Level* level);
	void revision(Level* level);
	bool get_availability_of_sketches()const { return availability_of_sketches; }
};


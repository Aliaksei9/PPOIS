#include "Level_designer.h"

Level_designer::Level_designer(std::string level_designer_name,double level_designer_professionalism, Accounting* place_of_work_level_designer)
{
	name = level_designer_name;
	professionalism = level_designer_professionalism;
	place_of_work = place_of_work_level_designer;
	place_of_work->increased_costs(1000);
}

void Level_designer::trip_for_sketches()
{
	place_of_work->one_time_waste(100);
	availability_of_sketches = 1;
}

Level Level_designer::create_level()
{
	bool sketches = availability_of_sketches;
	availability_of_sketches = 0;
	return Level(professionalism,sketches);
}
void Level_designer::optimization(Level *level)
{
	level->resource_intensity -= 2;
}

void Level_designer::revision(Level* level)
{
	level->resource_intensity += 3;
	level->quality += 0.8;
}


#include "Artist_3D.h"

Artist_3D::Artist_3D(std::string artist_3D_name, double artist_3D_professionalism, Accounting* place_of_work_artist_3D)
{
	name = artist_3D_name;
	professionalism = artist_3D_professionalism;
	place_of_work = place_of_work_artist_3D;
	place_of_work->increased_costs(1500);
}

void Artist_3D::filming()
{
	place_of_work->one_time_waste(1200);
	motion_capture = 1;
}

Model Artist_3D::create_model()
{
	bool motion = motion_capture;
	motion_capture = 0;
	return Model(professionalism, motion_capture);
}
void Artist_3D::optimization(Model* model)
{
	model->resource_intensity -= 3.;
}

void Artist_3D::revision(Model* model)
{
	model->resource_intensity += 2;
	model->quality += 1.;
}

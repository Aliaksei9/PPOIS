#include "Model.h"

Model::Model(double artist_professionalism, bool motion_capture)
{
	quality = rand() % 3 * artist_professionalism;
	resource_intensity = 10;
	if (motion_capture == 1) quality += 2;
}

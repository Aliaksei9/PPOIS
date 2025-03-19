#include "Level.h"
Level::Level(double level_disigner_professionalism, bool sketches)
{
	quality = rand() % 3 * level_disigner_professionalism;
	resource_intensity = 10;
	if (sketches == 1) quality += 1;
}
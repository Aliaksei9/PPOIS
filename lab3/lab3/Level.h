#pragma once
#include "Technical_product.h"
class Level_designer;
class Level:public Technical_product
{
private:
	Level(double level_disigner_professionalism, bool sketches);
public:
	Level() = default;
	friend class Level_designer;
};


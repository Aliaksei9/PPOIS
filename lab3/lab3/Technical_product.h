#pragma once
#include "stdlib.h"
class Technical_product
{
protected:
	int resource_intensity;
	double quality;
public:
	Technical_product() = default;
	double get_quality() const { return quality; }
	int get_resourse_intensity() const { return resource_intensity; }
};


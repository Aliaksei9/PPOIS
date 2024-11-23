#pragma once
#include "MOOD.h"
#include "stdlib.h"
#include "Creative_worker.h"
class Creative_product
{
protected:
	MOOD mood;
	double quality=0;
public:
	Creative_product() = default;
	double get_quality() const { return quality; }
	MOOD get_mood() const { return mood; }
};


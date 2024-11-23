#pragma once
#include "Worker.h"
#include "MOOD.h"
class Creative_worker: public Worker
{
protected:
	MOOD specialization;
	double genre_fatigue=0;
	bool inspiration=1;
public:
	void rest();
	void finding_inspiration();
};


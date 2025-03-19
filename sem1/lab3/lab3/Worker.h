#pragma once
#include <iostream>
#include <string>
#include "Accounting.h"
class Worker
{
protected:
	std::string name;
	double professionalism;
	Accounting* place_of_work;
public:
	void training();
	double get_proffesionalism() const { return professionalism; }
};


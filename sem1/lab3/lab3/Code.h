#pragma once
#include "Technical_product.h"
#include <iostream>
class Programmer;
class Code: public Technical_product
{
private:
	int bugs;
	Code(double programmer_proffesionalism);
public:
	Code() = default;
	friend class Programmer;
	int get_bugs() const { return bugs; }
};


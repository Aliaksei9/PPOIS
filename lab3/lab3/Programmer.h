#pragma once
#include "Code.h"
#include "Worker.h"
class Programmer: public Worker
{
public:
	Programmer(std::string programmer_name, double programmer_professionalism, Accounting* place_of_work_programmer);
	Code write_code();
	void optimization(Code* code);
	void revision(Code* code);
	void fixing_bugs(Code* code);
};


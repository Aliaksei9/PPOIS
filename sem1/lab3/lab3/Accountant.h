#pragma once
#include "Worker.h"
class Accountant: public Worker
{public:
	Accountant(std::string accountant_name,Accounting* place_of_work_accountant);
	//Accountant() = default;
	void information_from_accounting();
	int get_budget()const { return place_of_work->budget; }
	int get_incomes()const { return place_of_work->income; }
	int get_expenses()const { return place_of_work->expense; }
};



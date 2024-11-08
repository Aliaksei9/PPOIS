#pragma once
#include "Worker.h"
class HR;
class Parser;
class Accountant: public Worker
{
public:
	~Accountant();
	Accountant(std::string name_accountant, int accountant_ID, Accounting& place_of_work_accountant);
	Accountant(std::string name_accountant, int accountant_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_accountant);
	void information_from_accounting();
	int get_budget()const { return place_of_work->budget; }
	int get_incomes()const { return place_of_work->incomes; }
	int get_expenses()const { return place_of_work->expenses; }
	friend class HR;
	friend class Parser;
};


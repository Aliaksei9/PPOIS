#include "Accountant.h"

Accountant::Accountant(std::string accountant_name,  Accounting* place_of_work_accountant)
{
	name = accountant_name;
	place_of_work = place_of_work_accountant;
	place_of_work->increased_costs(500);
}

void Accountant::information_from_accounting()
{
	std::cout << "Budget: " << place_of_work->budget << std::endl << "Income: " << place_of_work->income << std::endl << "Expenses: " << place_of_work->expense << std::endl;
}

#include "Accountant.h"
Accountant::~Accountant()
{
	place_of_work->reduce_costs(500);
}
Accountant::Accountant(std::string name_accountant,int accountant_ID, Accounting& place_of_work_accountant)
{
	ID = accountant_ID;
	name = name_accountant;
	position = ACCOUNTANT;
	place_of_work=&place_of_work_accountant;
	place_of_work->increased_costs(500);
}
Accountant::Accountant(std::string name_accountant, int accountant_ID,std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_accountant)
{
	ID = accountant_ID;
	name = name_accountant;
	reprimands = list_of_reprimands;
	position = ACCOUNTANT;
	place_of_work=&place_of_work_accountant;
	place_of_work->increased_costs(500);
}
void Accountant::information_from_accounting()
{
	std::cout << "Бюджет: " << place_of_work->budget << std::endl << "Доходы: " << place_of_work->incomes << std::endl << "Расходы: " << place_of_work->expenses << std::endl;
}
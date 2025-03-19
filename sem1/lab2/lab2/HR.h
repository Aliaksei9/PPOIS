#pragma once
#include "Aquarist.h"
#include "Accountant.h"
#include "Cleaner.h"
#include "Hydrochemist.h"
#include "Ichthyopathologist.h"

#include "Purchasing_manager.h"
class Parser;
class HR: public Worker
{
public:
	HR(std::string name_HR, int HR_ID, Accounting& place_of_work_HR);
	HR(std::string name_HR, int HR_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_HR);
	~HR();
	void hire(std::vector<Worker*>& workers, PROFFESIONS position);
	void fire_an_employee(std::vector<Worker*>& workers,int employee_ID);
	void display_information_about_employees(std::vector<Worker*>& workers);
	friend class Parser;
};


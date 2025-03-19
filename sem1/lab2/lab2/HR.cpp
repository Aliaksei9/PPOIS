#include "HR.h"

HR::HR(std::string name_HR, int HR_ID, Accounting& place_of_work_HR)
{
	ID = HR_ID;
	name = name_HR;
	position = HR_specialist;
	place_of_work=&place_of_work_HR;
	place_of_work->increased_costs(600);
}

HR::HR(std::string name_HR, int HR_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_HR)
{
	ID = HR_ID;
	name = name_HR;
	position = HR_specialist;
	reprimands = list_of_reprimands;
	place_of_work=&place_of_work_HR;
	place_of_work->increased_costs(600);
}

HR::~HR()
{
	place_of_work->reduce_costs(600);
}

void HR::hire(std::vector<Worker*>& workers, PROFFESIONS position)
{
	std::string new_name[15]{ "Максим","Михаил","Александр","Дмитрий","Денис","Илья","Андрей","Даниил","Артём","Иван","Алексей","Инокентий","Павел","Никита","Антон" };
	std::string new_second_name[15]{ "Новиков","Назаров","Розанов","Чистяков","Кошелёв","Сергеев","Никитин","Петровский","Паровозов","Савельев","Аксенов","Павлов","Тимофеев","Антонов","Прокофьев" };
	int new_ID = rand();
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i]->get_ID() == new_ID)
		{
			new_ID = rand();
			i = -1;
		}
	}
	std::string worker_name = new_name[rand() % 15] + new_second_name[rand() % 15];
	//Рандомная генерация выводов+увольнения
	if (rand()%2)
	switch (position)
	{
	case ACCOUNTANT:
		//Accountant* accountant(new Accountant(worker_name, new_ID, *place_of_work));
		workers.push_back(new Accountant(worker_name, new_ID, *place_of_work));
		break;
	case AQUARIST:
		workers.push_back(new Aquarist(worker_name, new_ID, *place_of_work));
		break;
	case CLEANER:
		workers.push_back(new Cleaner(worker_name, new_ID, *place_of_work));
		break;
	case HR_specialist:
		workers.push_back(new HR(worker_name, new_ID, *place_of_work));
		break;
	case HYDROCHEMIST:
		workers.push_back(new Hydrochemist(worker_name, new_ID, *place_of_work));
		break;
	case ICHTHYOPATHOLOGIST:
		workers.push_back(new Ichthyopathologist(worker_name, new_ID, *place_of_work));
		break;
	case PURCHASING_MANAGER:
		workers.push_back(new Purchasing_manager(worker_name, new_ID, *place_of_work));
		break;
	}
	else
	{
		std::vector<REPRIMAND> reprimands;
		int number_of_reprimands = rand() % 3+1;
		for (int i = 0; i < number_of_reprimands; ++i)
		{
			reprimands.push_back((REPRIMAND)(rand() % 5));
		}
		if (reprimands.size() * (rand() / 4) > 0.75) place_of_work->increased_costs(150);
		switch (position)
		{
		case ACCOUNTANT:
			//Accountant* accountant(new Accountant(worker_name, new_ID, *place_of_work));
			workers.push_back(new Accountant(worker_name, new_ID,reprimands,*place_of_work));
			break;
		case AQUARIST:
			workers.push_back(new Aquarist(worker_name, new_ID, reprimands, *place_of_work));
			break;
		case CLEANER:
			workers.push_back(new Cleaner(worker_name, new_ID, reprimands, *place_of_work));
			break;
		case HR_specialist:
			workers.push_back(new HR(worker_name, new_ID, reprimands,*place_of_work));
			break;
		case HYDROCHEMIST:
			workers.push_back(new Hydrochemist(worker_name, new_ID, reprimands, *place_of_work));
			break;
		case ICHTHYOPATHOLOGIST:
			workers.push_back(new Ichthyopathologist(worker_name, new_ID, reprimands,*place_of_work));
			break;
		case PURCHASING_MANAGER:
			workers.push_back(new Purchasing_manager(worker_name, new_ID, reprimands,*place_of_work));
			break;
		}
	}
}

void HR::fire_an_employee(std::vector<Worker*>& workers, int employee_ID)
{
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i]->get_ID() == employee_ID)
		{
			if(workers[i]->get_reprimand_list().size()>0) delete workers[i];
			workers.erase(workers.begin() + i);
			return;
		}
	}
	throw std::runtime_error("Такого сотрудника нет");
}

void HR::display_information_about_employees(std::vector<Worker*>& workers)
{
	for (int i = 0; i < workers.size(); ++i) std::cout <<i<<")"<<(*(workers[i]));
}

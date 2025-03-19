#include "Head.h"

Head::Head(std::string name_head, int head_ID, Accounting& place_of_work_head)
{
	ID = head_ID;
	name = name_head;
	position = HEAD;
	place_of_work=&place_of_work_head;
	place_of_work->increased_costs(1600);
}

Head::Head(std::string name_head, int head_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_head)
{
	ID = head_ID;
	name = name_head;
	position = HEAD;
	reprimands = list_of_reprimands;
	place_of_work=&place_of_work_head;
	place_of_work->increased_costs(1600);
}

Head::~Head()
{
	place_of_work->reduce_costs(1600);
}

void Head::issue_reprimand(REPRIMAND reprimand,int worker_ID, std::vector<Worker*>& workers)
{
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i]->get_ID() == worker_ID)
		{
			workers[i]->new_reprimanded(reprimand);
			return;
		}
	}
	throw std::runtime_error("Такого сотрудника нет");
}

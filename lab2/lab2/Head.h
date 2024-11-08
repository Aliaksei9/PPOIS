#pragma once
#include "Worker.h"
class Parser;
class Head : public Worker
{
public:
	Head(std::string name_head, int head_ID, Accounting& place_of_work_head);
	Head(std::string name_head, int head_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_head);
	~Head();
	void issue_reprimand(REPRIMAND reprimand, int worker_ID, std::vector<Worker*>& workers);
	friend class Parser;
};


#pragma once
#include "Worker.h"
class HR;
class Purser;
class Cleaner : public Worker
{
public:
	~Cleaner();
	Cleaner(std::string name_cleaner,int cleaner_ID,Accounting& place_of_work_cleaner);
	Cleaner(std::string name_cleaner, int cleaner_ID, std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_cleaner);
	void cleaning();
	friend class HR;
	friend class Parser;
};


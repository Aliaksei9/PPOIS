#include "Cleaner.h"	
Cleaner::~Cleaner()
{
	place_of_work->reduce_costs(300);
}
Cleaner::Cleaner(std::string name_cleaner,int cleaner_ID,Accounting & place_of_work_cleaner)
	{
		ID = cleaner_ID;
		name = name_cleaner;
		position = CLEANER;
		place_of_work=&place_of_work_cleaner;
		place_of_work->increased_costs(300);
	}
	Cleaner::Cleaner(std::string name_cleaner,int cleaner_ID,std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_cleaner)
	{
		ID = cleaner_ID;
		name = name_cleaner;
		reprimands = list_of_reprimands;
		position = CLEANER;
		place_of_work=&place_of_work_cleaner;
		place_of_work->increased_costs(300);
	}
	void Cleaner::cleaning()
	{
		place_of_work->cleanliness_of_the_premises=0;
	}
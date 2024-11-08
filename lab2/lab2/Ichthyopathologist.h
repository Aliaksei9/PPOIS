#pragma once
#include "Worker.h"
#include "Hydrobiont.h"
class HR;
class Parser;
class Ichthyopathologist : public Worker
{
	public:
		~Ichthyopathologist();
		Ichthyopathologist(std::string name_ichthyopathologist,int ichthyopathologist_ID, Accounting& place_of_work_ichthyopathologist);
		Ichthyopathologist(std::string name_ichthyopathologist,int ichthyopathologist_ID,std::vector<REPRIMAND>& list_of_reprimands, Accounting& place_of_work_ichthyopathologist);
		void healing(Hydrobiont& fish);
		Hydrobiont fish_breeding(Hydrobiont& fish1, Hydrobiont& fish2);
		friend class HR;
		friend class Parser;
};


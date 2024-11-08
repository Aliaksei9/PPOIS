#pragma once
#include "Accountant.h"
#include "Aquarist.h"
#include "Cleaner.h"
#include "HR.h"
#include "Head.h"
#include "Hydrochemist.h"
#include "Ichthyopathologist.h"
#include "Purchasing_manager.h"
#include <fstream>

class Parser
{
public:
	static void reading(std::vector<Worker*>& workers, std::vector<Aquarium*>& aquariums, Accounting* place, std::string path_workers, std::string path_aquariums);
};


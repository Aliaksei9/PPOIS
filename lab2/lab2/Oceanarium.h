#pragma once
#include "Parser.h"

class Oceanarium
{
private:
	std::vector<Worker*> workers;
	std::vector<Aquarium*> aquariums;
	Accounting *organization;
	/*void buffer_clean()
	{
		std::cin.clear();
		std::cin.ignore();
	}*/
	void AccountnantDistribution(int worker_index);
	void AquaristDistribution(int worker_index);
	void HRDistribution(int worker_index);
	void HydrochemistDistribution(int worker_index);
	void IchthyopathologistDistribution(int worker_index);
	void PurchasingManagerDistribution(int worker_index);
	void HeadDistribution(int worker_index);
public:
	Oceanarium(Accounting &oceanarium_organization);
	Oceanarium(Accounting &oceanarium_organization,std::string path_workers,std::string path_aquariums);
	~Oceanarium();
	std::vector<Worker*>& get_workers() { return workers; }
	std::vector<Aquarium*>& get_aquariums() { return aquariums; }
	void new_day();
	void initial_inspection_of_aquariums();
	void worker_information();
	void distribution_of_work();
	/*void HR_hire(HR* worker, int pos_number);
	void HR_fire(HR* worker, int ID);
	void accountant_inform_from_accounting(Accountant* worker);*/
};


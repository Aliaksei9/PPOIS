#pragma once
#include "string"
#include "vector"
#include <iostream>
#include "REPRIMAND.h"
#include "Accounting.h"
enum PROFFESIONS
{
	ACCOUNTANT,
	AQUARIST,
	CLEANER,
	HR_specialist,
	HYDROCHEMIST,
	ICHTHYOPATHOLOGIST,
	PURCHASING_MANAGER,
	HEAD
};
class Head;
class Worker
{
protected:
	std::string name;
	PROFFESIONS position;
	std::vector<REPRIMAND> reprimands;
	Accounting* place_of_work;
	void new_reprimanded(REPRIMAND reprimand);
	int ID;
public:
	Worker() = default;
	Worker(std::string worker_name, PROFFESIONS worker_position, std::vector<REPRIMAND>& worker_reprimands, Accounting* place, int worker_ID) :
		name(worker_name), position(worker_position), reprimands(worker_reprimands), place_of_work(place), ID(worker_ID)
	{}
	virtual ~Worker() {}; // примечание: Деструктор виртуальный
	int get_ID() const { return ID; }
	PROFFESIONS get_position() const { return position; }
	std::vector<REPRIMAND> get_reprimand_list()const { return reprimands; }
	friend std::ostream& operator<< (std::ostream& out, const Worker& worker);
	friend class Head;
};
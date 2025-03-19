#include "Parser.h"
void Parser::reading(std::vector<Worker*>& workers, std::vector<Aquarium*>& aquariums, Accounting* place,std::string path_workers,std::string path_aquariums)
{
	std::ifstream workers_file(path_workers); // окрываем файл для чтения
	if (!workers_file.is_open()) throw std::runtime_error("Файл не открылся");
	while (!workers_file.eof())
	{
		std::string str, name;
		std::vector<REPRIMAND> reprimands;
		char s;
		int ID;
		getline(workers_file, str, ':');
		getline(workers_file, str, ';');//Имя
		name = str;
		getline(workers_file, str, ':');
		str = "";
		workers_file.get(s);
		if (s != '-')
		{
			while (s != ';')
			{
				while (s != ',' && s != ';')
				{
					str += s;
					workers_file.get(s);
				}
				switch (str.length())
				{
				case 4:
					reprimands.push_back(LATE);
					break;
				case 5:
					reprimands.push_back(SPREE);
					break;
				case 7:
					reprimands.push_back(ABSENCE);
					break;
				case 10:
					reprimands.push_back(LEFT_WORK_EARLY);
					break;
				case 41:
					reprimands.push_back(FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS);
					break;
				}
				if (s != ';')workers_file.get(s);
				str = "";
			}
		}//Выговоры
		getline(workers_file, str, ':');
		workers_file >> ID;
		workers_file.get(s);
		getline(workers_file, str, ':');
		getline(workers_file, str, ';');
		switch (str.length())
		{
		case 2:
			if (reprimands.size() == 0)
				workers.push_back(new HR(name, ID, *place));
			else workers.push_back(new HR(name, ID, reprimands, *place));
			break;
		case 4:
			if (reprimands.size() == 0)
				workers.push_back(new Head(name, ID, *place));
			else workers.push_back(new Head(name, ID, reprimands, *place));
			break;
		case 7:
			if (reprimands.size() == 0)
				workers.push_back(new Cleaner(name, ID,* place));
			else workers.push_back(new Cleaner(name, ID, reprimands, *place));
			break;
			break;
		case 8:
			if (reprimands.size() == 0)
				workers.push_back(new Aquarist(name, ID, *place));
			else workers.push_back(new Aquarist(name, ID, reprimands, *place));
			break;
		case 10:
			if (reprimands.size() == 0)
				workers.push_back(new Accountant(name, ID, *place));
			else workers.push_back(new Accountant(name, ID, reprimands, *place));
			break;
		case 12:
			if (reprimands.size() == 0)
				workers.push_back(new Hydrochemist(name, ID, *place));
			else workers.push_back(new Hydrochemist(name, ID, reprimands, *place));
			break;
		case 17:
			if (reprimands.size() == 0)
				workers.push_back(new Purchasing_manager(name, ID, *place));
			else workers.push_back(new Purchasing_manager(name, ID, reprimands, *place));
			break;
		case 18:
			if (reprimands.size() == 0)
				workers.push_back(new Ichthyopathologist(name, ID, *place));
			else workers.push_back(new Ichthyopathologist(name, ID, reprimands, *place));
			break;
		default:
			std::cout << str.length();
		}
		getline(workers_file, str);
	}
	workers_file.close();
	std::ifstream aquariums_file(path_aquariums); // окрываем файл для чтения
	if (!aquariums_file.is_open()) throw std::runtime_error("Файл не открылся");
	while (!aquariums_file.eof())
	{
		std::string str;
		int limit;
		bool type_of_aquarium;
		char s;
		double salinity, acidity, temperature, dissolved_oxygen;
		FISH_TYPE aquarium_type;
		getline(aquariums_file, str, ':');
		aquariums_file >> limit;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> type_of_aquarium;
		if (type_of_aquarium == 1) aquarium_type = PREDATOR;
		else aquarium_type = HERBIVORE;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> salinity;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> acidity;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> temperature;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> dissolved_oxygen;
		getline(aquariums_file, str);
		aquariums.push_back(new Aquarium(limit, Water(salinity, acidity, temperature, dissolved_oxygen), *place, aquarium_type));
	}
}


/*void Parser::reading(std::vector<Worker*>& workers, std::vector<Aquarium*>& aquariums, Accounting* place)
{
	std::ifstream workers_file("workers.txt"); // окрываем файл для чтения
	if (!workers_file.is_open()) throw std::runtime_error("Файл не открылся");
	while (!workers_file.eof())
	{
		std::string str, name;
		std::vector<REPRIMAND> reprimands;
		char s;
		int ID;
		getline(workers_file, str, ':');
		getline(workers_file, str, ';');//Имя
		name = str;
		getline(workers_file, str, ':');
		str = "";
		workers_file.get(s);
		if (s != '-')
		{
			while (s != ';')
			{
				while (s != ',' && s != ';')
				{
					str += s;
					workers_file.get(s);
				}
				switch (str.length())
				{
				case 4:
					reprimands.push_back(LATE);
					break;
				case 5:
					reprimands.push_back(SPREE);
					break;
				case 7:
					reprimands.push_back(ABSENCE);
					break;
				case 10:
					reprimands.push_back(LEFT_WORK_EARLY);
					break;
				case 41:
					reprimands.push_back(FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS);
					break;
				}
				if (s != ';')workers_file.get(s);
				str = "";
			}
		}//Выговоры
		getline(workers_file, str, ':');
		workers_file >> ID;
		workers_file.get(s);
		getline(workers_file, str, ':');
		getline(workers_file, str, ';');
		switch (str.length())
		{
		case 2:
			if (reprimands.size() == 0)
				workers.push_back(new HR(name, ID, *place));
			else workers.push_back(new HR(name, ID, reprimands, *place));
			break;
		case 4:
			if (reprimands.size() == 0)
				workers.push_back(new Head(name, ID, *place));
			else workers.push_back(new Head(name, ID, reprimands, *place));
			break;
		case 7:
			if (reprimands.size() == 0)
				workers.push_back(new Cleaner(name, ID, *place));
			else workers.push_back(new Cleaner(name, ID, reprimands, *place));
			break;
			break;
		case 8:
			if (reprimands.size() == 0)
				workers.push_back(new Aquarist(name, ID, *place));
			else workers.push_back(new Aquarist(name, ID, reprimands,* place));
			break;
		case 10:
			if (reprimands.size() == 0)
				workers.push_back(new Accountant(name, ID, *place));
			else workers.push_back(new Accountant(name, ID, reprimands,*place));
			break;
		case 12:
			if (reprimands.size() == 0)
				workers.push_back(new Hydrochemist(name, ID, *place));
			else workers.push_back(new Hydrochemist(name, ID, reprimands, *place));
			break;
		case 17:
			if (reprimands.size() == 0)
				workers.push_back(new Purchasing_manager(name, ID, *place));
			else workers.push_back(new Purchasing_manager(name, ID, reprimands, *place));
			break;
		case 18:
			if (reprimands.size() == 0)
				workers.push_back(new Ichthyopathologist(name, ID, *place));
			else workers.push_back(new Ichthyopathologist(name, ID, reprimands, *place));
			break;
		default:
			std::cout << str.length();
		}
		getline(workers_file, str);
	}
	workers_file.close();
	std::ifstream aquariums_file("aquariums.txt"); // окрываем файл для чтения
	if (!aquariums_file.is_open()) throw std::runtime_error("Файл не открылся");
	while (!aquariums_file.eof())
	{
		std::string str;
		int limit;
		bool type_of_aquarium;
		char s;
		double salinity, acidity, temperature, dissolved_oxygen;
		FISH_TYPE aquarium_type;
		getline(aquariums_file, str, ':');
		aquariums_file >> limit;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> type_of_aquarium;
		if (type_of_aquarium == 1) aquarium_type = PREDATOR;
		else aquarium_type = HERBIVORE;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> salinity;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> acidity;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> temperature;
		workers_file.get(s);
		getline(aquariums_file, str, ':');
		aquariums_file >> dissolved_oxygen;
		getline(aquariums_file, str);
		aquariums.push_back(new Aquarium(limit, Water(limit, acidity, temperature, dissolved_oxygen), *place, aquarium_type));
	}
}*/


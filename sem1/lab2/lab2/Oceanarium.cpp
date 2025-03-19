#include "Oceanarium.h"


void Oceanarium::AquaristDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
	std::cin >> selected_action;
	/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
	{
		std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
		buffer_clean();
	}*/
	if (selected_action != 3)
	{
		std::cout << "�������� 1 ��������(������ ���������� � 0) �� " << aquariums.size();
		int aquarium_index;
		std::cin >> aquarium_index;
		/*while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
		{
			std::cout << "�������� 1 �������� �� " << aquariums.size();
			buffer_clean();
		}*/
		switch (selected_action)
		{
		case 1:
			dynamic_cast<Aquarist*>(workers[worker_index])->feed_the_fish(*aquariums[aquarium_index]);
			break;
		case 2:
			dynamic_cast<Aquarist*>(workers[worker_index])->clean_aquarium(*aquariums[aquarium_index]);
			break;
		}
	}
}

void Oceanarium::HRDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
	std::cin >> selected_action;
	/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
	{
		std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
		buffer_clean();
	}*/
	switch (selected_action)
	{
	case 1:
		int pos_number;
		PROFFESIONS position;
		std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
		std::cin >> pos_number;
		/*while (!(std::cin >> pos_number) || std::cin.peek() != '\n' || pos_number < 1 || pos_number > 7)
		{
			std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
			buffer_clean();
		}*/
		switch (pos_number)
		{
		case 1:
			position = HR_specialist;
			break;
		case 2:
			position = CLEANER;
			break;
		case 3:
			position = HYDROCHEMIST;
			break;
		case 4:
			position = AQUARIST;
			break;
		case 5:
			position = ICHTHYOPATHOLOGIST;
			break;
		case 6:
			position = PURCHASING_MANAGER;
			break;
		case 7:
			position = ACCOUNTANT;
			break;
		}
		dynamic_cast<HR*>(workers[worker_index])->hire(workers, position);
		break;
	case 2:
		int ID;
		std::cout << "ID ������������ ��������\n";
		std::cin >> ID;
		/*while (!(std::cin >> ID) || std::cin.peek() != '\n')
		{
			std::cout << "ID ������������ ��������\n";
			buffer_clean();
		}*/
		dynamic_cast<HR*>(workers[worker_index])->fire_an_employee(workers, ID);
		break;
	case 3:
		break;
	}
}

void Oceanarium::HydrochemistDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
	std::cin >> selected_action;
	/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
	{
		std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
		buffer_clean();
	}*/
	if (selected_action != 3)
	{
		std::cout << "�������� 1 �������� �� " << aquariums.size();
		int aquarium_index;
		std::cin >> aquarium_index;
		/*while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
		{
			std::cout << "�������� 1 �������� �� " << aquariums.size();
			buffer_clean();
		}*/
		switch (selected_action)
		{
		case 1:
			dynamic_cast<Hydrochemist*>(workers[worker_index])->take_samples(*aquariums[aquarium_index]);
			break;
		case 2:
			char selected_option;
			double new_value;
			std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
			std::cin >> selected_option;
			/*while (!(std::cin >> selected_option) || std::cin.peek() != '\n' || (selected_option != 's' && selected_option != 'a' && selected_option != 't' && selected_option != 'd'))
			{
				std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
				buffer_clean();
			}*/
			std::cout << "�������� ����� �������� ���������\n";
			std::cin >> new_value;
			/*while (!(std::cin >> new_value) || std::cin.peek() != '\n')
			{
				std::cout << "�������� ����� �������� ���������\n";
				buffer_clean();
			}*/
			dynamic_cast<Hydrochemist*>(workers[worker_index])->change_water_parameters(*aquariums[aquarium_index], selected_option, new_value);
			break;
		}
	}
}

void Oceanarium::IchthyopathologistDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� ��������\n1.�������� ����\n2.���������� ���\n3.���������\n";
	std::cin >> selected_action;
	/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
	{
		std::cout << "�������� �������� ��������\n1.�������� ����\n2.���������� ���\n3.���������\n";
		buffer_clean();
	}*/
	if (selected_action != 3)
	{
		std::cout << "�������� 1 �������� �� " << aquariums.size();
		int aquarium_index;
		std::cin >> aquarium_index;
		/*while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
		{
			std::cout << "�������� 1 �������� �� " << aquariums.size();
			buffer_clean();
		}*/
		std::vector < Hydrobiont > fishes = aquariums[aquarium_index]->get_fishes();
		if (fishes.size() < 1) return;
		std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
		int fish_index;
		std::cin >> fish_index;
		/*while (!(std::cin >> fish_index) || std::cin.peek() != '\n' || fish_index < 0 || fish_index >= fishes.size())
		{
			std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
			buffer_clean();
		}*/
		Hydrobiont& fish = fishes[fish_index];
		if (selected_action == 1) dynamic_cast<Ichthyopathologist*>(workers[worker_index])->healing(fish);
		else
		{
			int fish_index2;
			std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
			std::cin >> fish_index2;
			/*while (!(std::cin >> fish_index2) || std::cin.peek() != '\n' || fish_index2 < 0 || fish_index2 >= fishes.size() || fish_index == fish_index2)
			{
				std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
				buffer_clean();
			}*/
			if (fishes.size() < 2) return;
			Hydrobiont& fish1 = fishes[fish_index];
			Hydrobiont& fish2 = fishes[fish_index2];
			aquariums[aquarium_index]->add_fish(dynamic_cast<Ichthyopathologist*>(workers[worker_index])->fish_breeding(fish1, fish2));
			//break;
		}
	}
}

void Oceanarium::PurchasingManagerDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
	std::cin >> selected_action;
	/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 4)
	{
		std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
		buffer_clean();
	}*/
	if (selected_action != 4)
	{
		switch (selected_action)
		{
		case 1:
			std::cout << "������� ����� ���\n";
			int fish_limit, aquarium_type;
			std::cin >> fish_limit;
			/*while (!(std::cin >> fish_limit) || std::cin.peek() != '\n' || fish_limit < 0)
			{
				std::cout << "������� ����� ���\n";
				buffer_clean();
			}*/
			std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
			std::cin >> aquarium_type;
			/*while (!(std::cin >> aquarium_type) || std::cin.peek() != '\n' || aquarium_type < 0 || aquarium_type>2)
			{
				std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
				buffer_clean();
			}*/
			if (aquarium_type == 1) dynamic_cast<Purchasing_manager*>(workers[worker_index])->buy_aquarium(aquariums, fish_limit, PREDATOR);
			else dynamic_cast<Purchasing_manager*>(workers[worker_index])->buy_aquarium(aquariums, fish_limit, HERBIVORE);
			break;
		case 2:
			std::cout << "�������� 1 �������� �� " << aquariums.size();
			int aquarium_index;
			std::cin >> aquarium_index;
			/*while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
			{
				std::cout << "�������� 1 �������� �� " << aquariums.size();
				buffer_clean();
			}*/
			dynamic_cast<Purchasing_manager*>(workers[worker_index])->sell_aquarium(aquariums, aquarium_index);
			break;
		case 3:
			//(Aquarium& aquarium,Water& required_water,int max_HP,int damage,FISH_TYPE fish_type,bool sex)
			//double salinity, acidity, temperature, dissolved_oxygen;
			int salinity, acidity, temperature, dissolved_oxygen;
			int max_HP, damage, aq_index;
			bool sex, fish_type;
			std::cout << "�������� 1 �������� �� " << aquariums.size();
			std::cin >> aq_index;
			/*while (!(std::cin >> aq_index) || std::cin.peek() != '\n' || aq_index < 0 || aq_index >= aquariums.size())
			{
				std::cout << "�������� 1 �������� �� " << aquariums.size();
				buffer_clean();
			}*/
			std::cout << "������� ��������� ����\n1.������� ��������\n";
			std::cin >> salinity;
			/*while (!(std::cin >> salinity) || std::cin.peek() != '\n' || salinity < 0)
			{
				std::cout << "������� ��������\n";
				buffer_clean();
			}*/
			std::cout << "2.������� �����������\n";
			std::cin >> acidity;
			/*while (!(std::cin >> acidity) || std::cin.peek() != '\n' || acidity < 0)
			{
				std::cout << "������� �����������\n";
				buffer_clean();
			}*/
			std::cout << "3.������� �����������\n";
			std::cin >> temperature;
			/*while (!(std::cin >> temperature) || std::cin.peek() != '\n' || temperature < 0)
			{
				std::cout << "������� �����������\n";
				buffer_clean();
			}*/
			std::cout << "4.������� ����������� ��������\n";
			std::cin >> dissolved_oxygen;
			/*while (!(std::cin >> dissolved_oxygen) || std::cin.peek() != '\n' || dissolved_oxygen < 0)
			{
				std::cout << "������� ����������� ��������\n";
				buffer_clean();
			}*/
			std::cout << "������� ��������� ����\n.1.������������ HP\n";
			std::cin >> max_HP;
			/*while (!(std::cin >> max_HP) || std::cin.peek() != '\n' || max_HP <= 0)
			{
				std::cout << "������� ������������ HP\n";
				buffer_clean();
			}*/
			std::cout << "2.����\n";
			std::cin >> damage;
			/*while (!(std::cin >> damage) || std::cin.peek() != '\n' || damage < 0)
			{
				std::cout << "������� ���� ����\n";
				buffer_clean();
			}*/
			std::cout << "3.���(1-�������,0-�������)\n";
			std::cin >> sex;
			/*while (!(std::cin >> sex) || std::cin.peek() != '\n')
			{
				std::cout << "������� ��� ����\n";
				buffer_clean();
			}*/
			std::cout << "4.��� �������(1-������,0-����������)\n";
			std::cin >> fish_type;
			/*while (!(std::cin >> fish_type) || std::cin.peek() != '\n')
			{
				std::cout << "������� ��� �������\n";
				buffer_clean();
			}*/
			if (fish_type == 1)dynamic_cast<Purchasing_manager*>(workers[worker_index])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
			else dynamic_cast<Purchasing_manager*>(workers[worker_index])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
			break;
		}
	}
}

void Oceanarium::HeadDistribution(int worker_index)
{
	int selected_action;
	std::cout << "�������� �������� ��������:\n 1.�������� �������.\n 2.���������\n";
	std::cin >> selected_action;
				/*while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 2)
				{
					std::cout << "�������� �������� ��������:\n 1.�������� �������.\n 2.���������\n";
					buffer_clean();
				}*/
				if (selected_action == 1)
				{
					int ID, reprimand;
					std::cout << "ID ��������,�������� ������������ �������\n";
					std::cin >> ID;
					/*while (!(std::cin >> ID) || std::cin.peek() != '\n')
					{
						std::cout << "ID ��������,�������� ������������ �������\n";
						buffer_clean();
					}*/
					std::cout << "�������� ������� ��������\n1.����������\n2.��������\n3.���������\n4.��������������� ��������� �������� �����\n5.�� ���������� ������� ������������\n";
					std::cin >> reprimand;
					/*while (!(std::cin >> reprimand) || std::cin.peek() != '\n' || reprimand < 1 || reprimand>5)
					{
						std::cout << "�������� ������� ��������\n";
						buffer_clean();
					}*/
					switch (reprimand)
					{
					case 1:
						dynamic_cast<Head*>(workers[worker_index])->issue_reprimand(ABSENCE, ID, workers);
						break;
					case 2:
						dynamic_cast<Head*>(workers[worker_index])->issue_reprimand(SPREE, ID, workers);
						break;
					case 3:
						dynamic_cast<Head*>(workers[worker_index])->issue_reprimand(LATE, ID, workers);
						break;
					case 4:
						dynamic_cast<Head*>(workers[worker_index])->issue_reprimand(LEFT_WORK_EARLY, ID, workers);
						break;
					case 5:
						dynamic_cast<Head*>(workers[worker_index])->issue_reprimand(FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS, ID, workers);
						break;
					}
				}
}

Oceanarium::Oceanarium(Accounting &oceanarium_organization)
{
	organization = &oceanarium_organization;
	Parser::reading(workers, aquariums, organization,"workers.txt","aquariums.txt");
}

Oceanarium::Oceanarium(Accounting &oceanarium_organization, std::string path_workers, std::string path_aquariums)
{
	organization = &oceanarium_organization;
	Parser::reading(workers, aquariums, organization, path_workers, path_aquariums);
}

Oceanarium::~Oceanarium()
{
	for (int i = 0; i < aquariums.size(); ++i)
		delete aquariums[i];
	for (int i = 0; i < workers.size(); ++i)
		delete workers[i];
}

void Oceanarium::new_day()
{
	for (int i = 0; i < aquariums.size(); ++i)
		aquariums[i]->new_day_aquarium();
	organization->new_day();
}

void Oceanarium::initial_inspection_of_aquariums()
{
	std::cout << "���������� ����������: " << aquariums.size()<<std::endl;
	for (int i = 0; i < aquariums.size(); ++i)
	{
		std::cout << "���������� ����� � ��������� ����� " << i << " ����� " << aquariums[i]->get_fishes().size()<<std::endl;
		for (int j = 0; j < aquariums[i]->get_fishes().size(); ++j)
		{ std::cout << "HP:" << aquariums[i]->get_fishes()[j].get_HP() << "\nDamage:" << aquariums[i]->get_fishes()[j].get_damage() << "\nSex:" << aquariums[i]->get_fishes()[j].get_sex()
			<< "\n���:";
		if (aquariums[i]->get_fishes()[j].get_type() == PREDATOR) std::cout << "������";
		else std::cout << "����������";
		//std::cout << "\n------------------------------------";
		}
	}
}
void Oceanarium::worker_information()
{
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i]->get_position() == HR_specialist) dynamic_cast<HR*>(workers[i])->display_information_about_employees(workers);
	}
}

/*void Oceanarium::HR_hire(HR* worker, int pos_number)
{
		PROFFESIONS position;
		switch (pos_number)
		{
		case 1:
			position = HR_specialist;
			break;
		case 2:
			position = CLEANER;
			break;
		case 3:
			position = HYDROCHEMIST;
			break;
		case 4:
			position = AQUARIST;
			break;
		case 5:
			position = ICHTHYOPATHOLOGIST;
			break;
		case 6:
			position = PURCHASING_MANAGER;
			break;
		case 7:
			position = ACCOUNTANT;
			break;
		}
		worker->hire(workers, position);
}
void Oceanarium::HR_fire(HR* worker, int ID)
{
	worker->fire_an_employee(workers, ID);
}
void Oceanarium::accountant_inform_from_accounting(Accountant* worker)
{
	worker->information_from_accounting();
}
void Oceanarium::distribution_of_work()
{
	int num_of_unemployed_workers = workers.size() - 1;
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i]->get_position() == HR_specialist) dynamic_cast<HR*>(workers[i])->display_information_about_employees(workers);
	}
	while (num_of_unemployed_workers = -1)
	{
		int selected_action;
		switch (workers[num_of_unemployed_workers]->get_position())
		{
		case ACCOUNTANT:
			std::cout << "�������� �������� ��������:\n 1.�����.\n 2.������� ���������� � �����������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || (selected_action != 1 && selected_action != 2))
			{
				std::cout << "�������� �������� ��������:\n 1.�����.\n 2.������� ���������� � �����������\n";
				buffer_clean();
			}
			if (selected_action == 2) accountant_inform_from_accounting(dynamic_cast<Accountant*>(workers[num_of_unemployed_workers]));
			//dynamic_cast<Accountant*>(workers[num_of_unemployed_workers])->information_from_accounting();
			break;
		case AQUARIST:
			std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
			{
				std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
				buffer_clean();
			}
			if (selected_action != 3)
			{
				std::cout << "�������� 1 ��������(������ ���������� � 0) �� " << aquariums.size();
				int aquarium_index;
				while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || selected_action < 0 || selected_action >= aquariums.size())
				{
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					buffer_clean();
				}
				switch (selected_action)
				{
				case 1:
					dynamic_cast<Aquarist*>(workers[num_of_unemployed_workers])->feed_the_fish(*aquariums[aquarium_index]);
					break;
				case 2:
					dynamic_cast<Aquarist*>(workers[num_of_unemployed_workers])->clean_aquarium(*aquariums[aquarium_index]);
					break;
				}
			}
		case CLEANER:
			dynamic_cast<Cleaner*>(workers[num_of_unemployed_workers])->cleaning(organization);
			break;
		case HR_specialist:
			std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
			{
				std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
				buffer_clean();
			}
			switch (selected_action)
			{
			case 1:
				int pos_number;
				PROFFESIONS position;
				std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
				while (!(std::cin >> pos_number) || std::cin.peek() != '\n' || pos_number < 1 || pos_number > 7)
				{
					std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
					buffer_clean();
				}
				HR_hire(dynamic_cast<HR*>(workers[num_of_unemployed_workers]), pos_number);
				//dynamic_cast<HR*>(workers[num_of_unemployed_workers])->hire(workers, position);
				break;
			case 2:
				int ID;
				std::cout << "ID ������������ ��������\n";
				while (!(std::cin >> ID) || std::cin.peek() != '\n')
				{
					std::cout << "ID ������������ ��������\n";
					buffer_clean();
				}
				HR_hire(dynamic_cast<HR*>(workers[num_of_unemployed_workers]), ID);
				break;
			case 3:
				break;
			}
		case HYDROCHEMIST:
			std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
			{
				std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
				buffer_clean();
			}
			if (selected_action != 3)
			{
				std::cout << "�������� 1 �������� �� " << aquariums.size();
				int aquarium_index;
				while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
				{
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					buffer_clean();
				}
				switch (selected_action)
				{
				case 1:
					dynamic_cast<Hydrochemist*>(workers[num_of_unemployed_workers])->take_samples(*aquariums[aquarium_index]);
					break;
				case 2:
					char selected_option;
					double new_value;
					std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
					while (!(std::cin >> selected_option) || std::cin.peek() != '\n' || (selected_option != 's' && selected_option != 'a' && selected_option != 't' && selected_option != 'd'))
					{
						std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
						buffer_clean();
					}
					std::cout << "�������� ����� �������� ���������\n";
					while (!(std::cin >> new_value) || std::cin.peek() != '\n')
					{
						std::cout << "�������� ����� �������� ���������\n";
						buffer_clean();
					}
					dynamic_cast<Hydrochemist*>(workers[num_of_unemployed_workers])->change_water_parameters(*aquariums[aquarium_index], selected_option, new_value);
					break;
				}
			}
			break;
		case ICHTHYOPATHOLOGIST:
			std::cout << "�������� �������� ��������\n1.�������� ����\n2.���������� ���\n3.���������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
			{
				std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
				buffer_clean();
			}
			if (selected_action != 3)
			{
				std::cout << "�������� 1 �������� �� " << aquariums.size();
				int aquarium_index;
				while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
				{
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					buffer_clean();
				}
				std::vector < Hydrobiont > fishes = aquariums[aquarium_index]->get_fishes();
				std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
				int fish_index;
				while (!(std::cin >> fish_index) || std::cin.peek() != '\n' || fish_index < 0 || fish_index >= fishes.size())
				{
					std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
					buffer_clean();
				}
				Hydrobiont& fish = fishes[fish_index];
				if (selected_action == 1) dynamic_cast<Ichthyopathologist*>(workers[num_of_unemployed_workers])->healing(fish);
				else
				{
					int fish_index2;
					std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
					while (!(std::cin >> fish_index2) || std::cin.peek() != '\n' || fish_index2 < 0 || fish_index2 >= fishes.size() || fish_index == fish_index2)
					{
						std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
						buffer_clean();
					}
					Hydrobiont& fish1 = fishes[fish_index];
					Hydrobiont& fish2 = fishes[fish_index2];
					std::cout << "�������� ����� �������� ���������\n";
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					int aquarium_index;
					while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					aquariums[aquarium_index]->add_fish(dynamic_cast<Ichthyopathologist*>(workers[num_of_unemployed_workers])->fish_breeding(fish1, fish2));
					break;
				}
			}
			break;

		case PURCHASING_MANAGER:
			std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
			while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 4)
			{
				std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
				buffer_clean();
			}
			if (selected_action != 4)
			{
				switch (selected_action)
				{
				case 1:
					std::cout << "������� ����� ���\n";
					int fish_limit, aquarium_type;
					while (!(std::cin >> fish_limit) || std::cin.peek() != '\n' || fish_limit < 0)
					{
						std::cout << "������� ����� ���\n";
						buffer_clean();
					}
					std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
					while (!(std::cin >> aquarium_type) || std::cin.peek() != '\n' || aquarium_type < 0 || aquarium_type>2)
					{
						std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
						buffer_clean();
					}
					if (aquarium_type == 1) dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_aquarium(aquariums, fish_limit, PREDATOR);
					else dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_aquarium(aquariums, fish_limit, HERBIVORE);
					break;
				case 2:
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					int aquarium_index;
					while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->sell_aquarium(aquariums, aquarium_index);
					break;
				case 3:
					//(Aquarium& aquarium,Water& required_water,int max_HP,int damage,FISH_TYPE fish_type,bool sex)
					//double salinity, acidity, temperature, dissolved_oxygen;
					int salinity, acidity, temperature, dissolved_oxygen;
					int max_HP, damage, aq_index;
					bool sex, fish_type;
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					while (!(std::cin >> aq_index) || std::cin.peek() != '\n' || aq_index < 0 || aq_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					std::cout << "������� ��������� ����\n1.������� ��������\n";
					while (!(std::cin >> salinity) || std::cin.peek() != '\n' || salinity < 0)
					{
						std::cout << "������� ��������\n";
						buffer_clean();
					}
					std::cout << "2.������� �����������\n";
					while (!(std::cin >> acidity) || std::cin.peek() != '\n' || acidity < 0)
					{
						std::cout << "������� �����������\n";
						buffer_clean();
					}
					std::cout << "3.������� �����������\n";
					while (!(std::cin >> temperature) || std::cin.peek() != '\n' || temperature < 0)
					{
						std::cout << "������� �����������\n";
						buffer_clean();
					}
					std::cout << "4.������� ����������� ��������\n";
					while (!(std::cin >> dissolved_oxygen) || std::cin.peek() != '\n' || dissolved_oxygen < 0)
					{
						std::cout << "������� ����������� ��������\n";
						buffer_clean();
					}
					std::cout << "������� ��������� ����\n.1.������������ HP\n";
					while (!(std::cin >> max_HP) || std::cin.peek() != '\n' || max_HP <= 0)
					{
						std::cout << "������� ������������ HP\n";
						buffer_clean();
					}
					std::cout << "2.����\n";
					while (!(std::cin >> damage) || std::cin.peek() != '\n' || damage < 0)
					{
						std::cout << "������� ���� ����\n";
						buffer_clean();
					}
					std::cout << "3.���(1-�������,0-�������)\n";
					while (!(std::cin >> sex) || std::cin.peek() != '\n')
					{
						std::cout << "������� ��� ����\n";
						buffer_clean();
					}
					std::cout << "4.��� �������(1-������,0-����������)\n";
					while (!(std::cin >> fish_type) || std::cin.peek() != '\n')
					{
						std::cout << "������� ��� �������\n";
						buffer_clean();
					}
					if (fish_type == 1)dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
					else dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
					break;
				}
				break;
		case HEAD:
			break;
			}
		}
		--num_of_unemployed_workers;
	}
}*/
void Oceanarium::distribution_of_work()
{
		int num_of_unemployed_workers = workers.size()-1;
		while (num_of_unemployed_workers != -1)
		{
			switch (workers[num_of_unemployed_workers]->get_position())
			{
			case ACCOUNTANT:
				/*std::cout << "�������� �������� ��������:\n 1.�����.\n 2.������� ���������� � �����������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || (selected_action != 1 && selected_action != 2))
				{
					std::cout << "�������� �������� ��������:\n 1.�����.\n 2.������� ���������� � �����������\n";
					buffer_clean();
				}
				if (selected_action == 2) dynamic_cast<Accountant*>(workers[num_of_unemployed_workers])->information_from_accounting();*/
				dynamic_cast<Accountant*>(workers[num_of_unemployed_workers])->information_from_accounting();
				break;
			case AQUARIST:
				/*std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
				{
					std::cout << "�������� �������� ��������:\n 1.��������� �����.\n 2.��������� ��������.\n3.���������\n";
					buffer_clean();
				}
				if (selected_action != 3)
				{
					std::cout << "�������� 1 ��������(������ ���������� � 0) �� " << aquariums.size();
					int aquarium_index;
					while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					switch (selected_action)
					{
					case 1:
						dynamic_cast<Aquarist*>(workers[num_of_unemployed_workers])->feed_the_fish(*aquariums[aquarium_index]);
						break;
					case 2:
						dynamic_cast<Aquarist*>(workers[num_of_unemployed_workers])->clean_aquarium(*aquariums[aquarium_index]);
						break;
					}
				}*/
				AquaristDistribution(num_of_unemployed_workers);
				break;
			case CLEANER:
				dynamic_cast<Cleaner*>(workers[num_of_unemployed_workers])->cleaning();
				break;
			case HR_specialist:
				/*std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
				{
					std::cout << "�������� �������� ��������:\n 1.������ ������ ��������.\n 2.������� ������� ��������.\n3.���������\n";
					buffer_clean();
				}
				switch (selected_action)
				{
				case 1:
					int pos_number;
					PROFFESIONS position;
					std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
					while (!(std::cin >> pos_number) || std::cin.peek() != '\n' || pos_number < 1 || pos_number > 7)
					{
						std::cout << "�������� �������� �������\n1.HR\n2.�������\n3.����������\n4.�����������\n5.������������\n6.�������� �� ��������\n7.����������\n";
						buffer_clean();
					}
					switch (pos_number)
					{
					case 1:
						position = HR_specialist;
						break;
					case 2:
						position = CLEANER;
						break;
					case 3:
						position = HYDROCHEMIST;
						break;
					case 4:
						position = AQUARIST;
						break;
					case 5:
						position = ICHTHYOPATHOLOGIST;
						break;
					case 6:
						position = PURCHASING_MANAGER;
						break;
					case 7:
						position = ACCOUNTANT;
						break;
					}
					dynamic_cast<HR*>(workers[num_of_unemployed_workers])->hire(workers, position);
					break;
				case 2:
					int ID;
					std::cout << "ID ������������ ��������\n";
					while (!(std::cin >> ID) || std::cin.peek() != '\n')
					{
						std::cout << "ID ������������ ��������\n";
						buffer_clean();
					}
					dynamic_cast<HR*>(workers[num_of_unemployed_workers])->fire_an_employee(workers, ID);
					break;
				case 3:
					break;
				}*/
				HRDistribution(num_of_unemployed_workers);
				break;
			case HYDROCHEMIST:
				/*std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
				{
					std::cout << "�������� �������� �������\n1.����� �����\n2.�������� ����\n3.���������\n";
					buffer_clean();
				}
				if (selected_action != 3)
				{
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					int aquarium_index;
					while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					switch (selected_action)
					{
					case 1:
						dynamic_cast<Hydrochemist*>(workers[num_of_unemployed_workers])->take_samples(*aquariums[aquarium_index]);
						break;
					case 2:
						char selected_option;
						double new_value;
						std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
						while (!(std::cin >> selected_option) || std::cin.peek() != '\n' || (selected_option != 's' && selected_option != 'a' && selected_option != 't' && selected_option != 'd'))
						{
							std::cout << "�������� ���������� ��������\n1.'s'-��������\n2.'a'-�����������\n3.'t'-�����������\n4.'d'-����������� ��������\n";
							buffer_clean();
						}
						std::cout << "�������� ����� �������� ���������\n";
						while (!(std::cin >> new_value) || std::cin.peek() != '\n')
						{
							std::cout << "�������� ����� �������� ���������\n";
							buffer_clean();
						}
						dynamic_cast<Hydrochemist*>(workers[num_of_unemployed_workers])->change_water_parameters(*aquariums[aquarium_index], selected_option, new_value);
						break;
					}
				}*/
				HydrochemistDistribution(num_of_unemployed_workers);
				break;
			case ICHTHYOPATHOLOGIST:
				/*std::cout << "�������� �������� ��������\n1.�������� ����\n2.���������� ���\n3.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 3)
				{
					std::cout << "�������� �������� ��������\n1.�������� ����\n2.���������� ���\n3.���������\n";
					buffer_clean();
				}
				if (selected_action != 3)
				{
					std::cout << "�������� 1 �������� �� " << aquariums.size();
					int aquarium_index;
					while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
					{
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						buffer_clean();
					}
					std::vector < Hydrobiont > fishes = aquariums[aquarium_index]->get_fishes();
					if (fishes.size() < 1) break;
					std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
					int fish_index;
					while (!(std::cin >> fish_index) || std::cin.peek() != '\n' || fish_index < 0 || fish_index >= fishes.size())
					{
						std::cout << "�������� 1 ���� �� ������ ��" << fishes.size() << "���\n";
						buffer_clean();
					}
					Hydrobiont& fish = fishes[fish_index];
					if (selected_action == 1) dynamic_cast<Ichthyopathologist*>(workers[num_of_unemployed_workers])->healing(fish);
					else
					{
						int fish_index2;
						std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
						while (!(std::cin >> fish_index2) || std::cin.peek() != '\n' || fish_index2 < 0 || fish_index2 >= fishes.size() || fish_index == fish_index2)
						{
							std::cout << "�������� ������ ���� �� ������ ��" << fishes.size() << "���\n";
							buffer_clean();
						}
						if (fishes.size() < 2) break;
						Hydrobiont& fish1 = fishes[fish_index];
						Hydrobiont& fish2 = fishes[fish_index2];
						std::cout << "�������� ����� �������� ���������\n";
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						int aquarium_index;
						while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
						{
							std::cout << "�������� 1 �������� �� " << aquariums.size();
							buffer_clean();
						}
						aquariums[aquarium_index]->add_fish(dynamic_cast<Ichthyopathologist*>(workers[num_of_unemployed_workers])->fish_breeding(fish1, fish2));
						break;
					}
				}*/
				IchthyopathologistDistribution(num_of_unemployed_workers);
				break;

			case PURCHASING_MANAGER:
				/*std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 4)
				{
					std::cout << "�������� �������� ��������\n1.������ ��������\n2.������� ��������\n3.������ ����\n4.���������\n";
					buffer_clean();
				}
				if (selected_action != 4)
				{
					switch (selected_action)
					{
					case 1:
						std::cout << "������� ����� ���\n";
						int fish_limit, aquarium_type;
						while (!(std::cin >> fish_limit) || std::cin.peek() != '\n' || fish_limit < 0)
						{
							std::cout << "������� ����� ���\n";
							buffer_clean();
						}

						std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
						while (!(std::cin >> aquarium_type) || std::cin.peek() != '\n' || aquarium_type < 0 || aquarium_type>2)
						{
							std::cout << "������� ��� ���������\n1.�������� ��� ��������\n2.�������� ��� ����������\n";
							buffer_clean();
						}
						if (aquarium_type == 1) dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_aquarium(aquariums, fish_limit, PREDATOR);
						else dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_aquarium(aquariums, fish_limit, HERBIVORE);
						break;
					case 2:
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						int aquarium_index;
						while (!(std::cin >> aquarium_index) || std::cin.peek() != '\n' || aquarium_index < 0 || aquarium_index >= aquariums.size())
						{
							std::cout << "�������� 1 �������� �� " << aquariums.size();
							buffer_clean();
						}
						dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->sell_aquarium(aquariums, aquarium_index);
						break;
					case 3:
						//(Aquarium& aquarium,Water& required_water,int max_HP,int damage,FISH_TYPE fish_type,bool sex)
						//double salinity, acidity, temperature, dissolved_oxygen;
						int salinity, acidity, temperature, dissolved_oxygen;
						int max_HP, damage, aq_index;
						bool sex, fish_type;
						std::cout << "�������� 1 �������� �� " << aquariums.size();
						while (!(std::cin >> aq_index) || std::cin.peek() != '\n' || aq_index < 0 || aq_index >= aquariums.size())
						{
							std::cout << "�������� 1 �������� �� " << aquariums.size();
							buffer_clean();
						}
						std::cout << "������� ��������� ����\n1.������� ��������\n";
						while (!(std::cin >> salinity) || std::cin.peek() != '\n' || salinity < 0)
						{
							std::cout << "������� ��������\n";
							buffer_clean();
						}
						std::cout << "2.������� �����������\n";
						while (!(std::cin >> acidity) || std::cin.peek() != '\n' || acidity < 0)
						{
							std::cout << "������� �����������\n";
							buffer_clean();
						}
						std::cout << "3.������� �����������\n";
						while (!(std::cin >> temperature) || std::cin.peek() != '\n' || temperature < 0)
						{
							std::cout << "������� �����������\n";
							buffer_clean();
						}
						std::cout << "4.������� ����������� ��������\n";
						while (!(std::cin >> dissolved_oxygen) || std::cin.peek() != '\n' || dissolved_oxygen < 0)
						{
							std::cout << "������� ����������� ��������\n";
							buffer_clean();
						}
						std::cout << "������� ��������� ����\n.1.������������ HP\n";
						while (!(std::cin >> max_HP) || std::cin.peek() != '\n' || max_HP <= 0)
						{
							std::cout << "������� ������������ HP\n";
							buffer_clean();
						}
						std::cout << "2.����\n";
						while (!(std::cin >> damage) || std::cin.peek() != '\n' || damage < 0)
						{
							std::cout << "������� ���� ����\n";
							buffer_clean();
						}

						std::cout << "3.���(1-�������,0-�������)\n";
						while (!(std::cin >> sex) || std::cin.peek() != '\n')
						{
							std::cout << "������� ��� ����\n";
							buffer_clean();
						}
						std::cout << "4.��� �������(1-������,0-����������)\n";
						while (!(std::cin >> fish_type) || std::cin.peek() != '\n')
						{
							std::cout << "������� ��� �������\n";
							buffer_clean();
						}
						if (fish_type == 1)dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
						else dynamic_cast<Purchasing_manager*>(workers[num_of_unemployed_workers])->buy_fish(aquariums[aq_index], Water(salinity, acidity, temperature, dissolved_oxygen), max_HP, damage, PREDATOR, sex);
						break;
					}*/
				PurchasingManagerDistribution(num_of_unemployed_workers);
				break;
			case HEAD:
				/*std::cout << "�������� �������� ��������:\n 1.�������� �������.\n 2.���������\n";
				while (!(std::cin >> selected_action) || std::cin.peek() != '\n' || selected_action < 1 || selected_action > 2)
				{
					std::cout << "�������� �������� ��������:\n 1.�������� �������.\n 2.���������\n";
					buffer_clean();
				}
				if (selected_action == 1)
				{
					int ID, reprimand;
					std::cout << "ID ��������,�������� ������������ �������\n";
					while (!(std::cin >> ID) || std::cin.peek() != '\n')
					{
						std::cout << "ID ��������,�������� ������������ �������\n";
						buffer_clean();
					}
					std::cout << "�������� ������� ��������\n1.����������\n2.��������\n3.���������\n4.��������������� ��������� �������� �����\n5.�� ���������� ������� ������������\n";
					while (!(std::cin >> reprimand) || std::cin.peek() != '\n' || reprimand < 1 || reprimand>5)
					{
						std::cout << "�������� ������� ��������\n";
						buffer_clean();
					}
					switch (reprimand)
					{
					case 1:
						dynamic_cast<Head*>(workers[num_of_unemployed_workers])->issue_reprimand(ABSENCE, ID, workers);
						break;
					case 2:
						dynamic_cast<Head*>(workers[num_of_unemployed_workers])->issue_reprimand(SPREE, ID, workers);
						break;
					case 3:
						dynamic_cast<Head*>(workers[num_of_unemployed_workers])->issue_reprimand(LATE, ID, workers);
						break;
					case 4:
						dynamic_cast<Head*>(workers[num_of_unemployed_workers])->issue_reprimand(LEFT_WORK_EARLY, ID, workers);
						break;
					case 5:
						dynamic_cast<Head*>(workers[num_of_unemployed_workers])->issue_reprimand(FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS, ID, workers);
						break;
					}
				}*/
				HeadDistribution(num_of_unemployed_workers);
				break;
			}
			--num_of_unemployed_workers;
		}
}
		
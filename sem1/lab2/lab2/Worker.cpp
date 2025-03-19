
#include "Worker.h"
std::ostream& operator<< (std::ostream& out, const Worker& worker)
{
	out << "�.�.�.:" << worker.name << std::endl << "���������:";
	switch (worker.get_position())
	{
	case ACCOUNTANT:
		out << "���������";
		break;
	case AQUARIST:
		out << "�����������";
		break;
	case CLEANER:
		out << "�������";
		break;
	case HR_specialist:
		out << "HR";
		break;
	case HYDROCHEMIST:
		out << "����������";
		break;
	case ICHTHYOPATHOLOGIST:
		out << "������������";
		break;
	case PURCHASING_MANAGER:
		out << "�������� �������";
		break;
	case HEAD:
		out << "��������";
		break;
	}
	out<< std::endl << "ID:" << worker.ID << std::endl;
	if (worker.reprimands.size() != 0)
	{
		for (int i = 0; i < worker.reprimands.size(); ++i)
		{
			switch (worker.reprimands[i])
			{
			case ABSENCE:
				out << "����������; ";
				break;
			case SPREE:
				out << "������; ";
				break;
			case LATE:
				out << "���������; ";
				break;
			case LEFT_WORK_EARLY:
				out << "��������������� ���� � ������; ";
				break;
			case FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS:
				out << "������������ ������ ������������ ;";
				break;
			}
		}
	}
    return out;
}

void Worker::new_reprimanded(REPRIMAND reprimand)
{
    reprimands.push_back(reprimand);
}


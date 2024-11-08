
#include "Worker.h"
std::ostream& operator<< (std::ostream& out, const Worker& worker)
{
	out << "Ф.И.О.:" << worker.name << std::endl << "Должность:";
	switch (worker.get_position())
	{
	case ACCOUNTANT:
		out << "Бухгалтер";
		break;
	case AQUARIST:
		out << "Аквариумсит";
		break;
	case CLEANER:
		out << "Уборщик";
		break;
	case HR_specialist:
		out << "HR";
		break;
	case HYDROCHEMIST:
		out << "Гидрохимик";
		break;
	case ICHTHYOPATHOLOGIST:
		out << "Ихтиопатолог";
		break;
	case PURCHASING_MANAGER:
		out << "Менеджер закупок";
		break;
	case HEAD:
		out << "Директор";
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
				out << "Отсутствие; ";
				break;
			case SPREE:
				out << "Пьянка; ";
				break;
			case LATE:
				out << "Опоздание; ";
				break;
			case LEFT_WORK_EARLY:
				out << "Преждевременный уход с работы; ";
				break;
			case FAILURE_TO_COMPLY_WITH_SAFETY_REGULATIONS:
				out << "Несоблюдение правил безопасности ;";
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


#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "Barley_break.h"
#include <set>
void buffer_clean()
{
	std::cin.clear();
	std::cin.ignore();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	char action;
	bool exit=true;
	barley_break game;
	game.display();
	while (exit==true)
	{
		std::cout << "�������� �������� ��������\n" << "1.������� m,����� ������ ������� ����(���������� ����)\n" << "2.������� t, ����� ����������� �������\n"
			<< "3.������� c, ����� ��������� �������\n" << "4.������� e, ����� ����� �� ����\n";
		while (!(std::cin >> action) || std::cin.peek() != '\n' || (action != 'm' && action != 't' && action != 'c' && action != 'e'))
		{
			std::cout << "�������� �������� ��������\n" << "1.������� m,����� ������ ������� ����(���������� ����)\n" << "2.������� t, ����� ����������� �������\n"
				<< "3.������� c, ����� ��������� �������\n" << "4.������� e, ����� ����� �� ����\n";
			buffer_clean();
		}
		switch (action)
		{
		case 'm':
			game.mix();
			game.display();
			break;
		case 't':
			char place;
			while (1)
			{
				std::cout << "��������,���� �� ������ �������� ������� 0\n" << "1.������� u, ����� �������� ������� 0 �����\n" << "2.������� d, ����� �������� ������� 0 ����\n"
					<< "3.������� l, ����� �������� ������� 0 �����\n" << "4.������� r, ����� �������� ������� 0 ������\n" << "5.������� 'e' ����� ����� �� ������ ������������\n";
				while (!(std::cin >> place) || std::cin.peek() != '\n' || (place != 'u' && place != 'd' && place != 'r' && place != 'l' && place != 'e'))
				{
					std::cout << "��������,���� �� ������ �������� ������� 0\n" << "1.������� u, ����� �������� ������� 0 �����\n" << "2.������� d, ����� �������� ������� 0 �����\n"
						<< "3.������� l, ����� �������� ������� 0 �����\n" << "4.������� r, ����� �������� ������� 0 ������\n" << "5.������� 'e' ����� ����� �� ������ ������������\n";
					buffer_clean();
				}
				if (place == 'e') break;
				game.transposition(place);
				game.display();
			}
				break;
		case 'c':
			int line;
			int column;
			std::cout << "������� ������\n";
			while (!(std::cin >> line) || std::cin.peek() != '\n' || line<0||line>3)
			{
				std::cout << "������� ������\n";
				buffer_clean();
			}
			std::cout << "������� �������\n";
			while (!(std::cin >> column) || std::cin.peek() != '\n' || column < 0 || column>3)
			{
				std::cout << "������� �������\n";
				buffer_clean();
			}
			std::cout << game[line][column];
			break;
		case 'e':
			exit = false;
			break;
		default:
			std::cout << "���-�� ����� �� ���\n";
			break;
		}
	}
}

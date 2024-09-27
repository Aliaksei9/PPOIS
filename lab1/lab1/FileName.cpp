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
		std::cout << "Выберите желаемое действие\n" << "1.Нажмите m,чтобы начать сначала игру(перемешать стол)\n" << "2.Нажмите t, чтобы передвинуть яйчейки\n"
			<< "3.Нажмите c, чтобы проверить яйчейку\n" << "4.Нажмите e, чтобы выйти из игры\n";
		while (!(std::cin >> action) || std::cin.peek() != '\n' || (action != 'm' && action != 't' && action != 'c' && action != 'e'))
		{
			std::cout << "Выберите желаемое действие\n" << "1.Нажмите m,чтобы начать сначала игру(перемешать стол)\n" << "2.Нажмите t, чтобы передвинуть яйчейки\n"
				<< "3.Нажмите c, чтобы проверить яйчейку\n" << "4.Нажмите e, чтобы выйти из игры\n";
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
				std::cout << "Выберите,куда Вы хотите сместить яйчейку 0\n" << "1.Нажмите u, чтобы сместить яйчейку 0 вверх\n" << "2.Нажмите d, чтобы сместить яйчейку 0 вниз\n"
					<< "3.Нажмите l, чтобы сместить яйчейку 0 влево\n" << "4.Нажмите r, чтобы сместить яйчейку 0 вправо\n" << "5.Нажмите 'e' чтобы выйти из режима передвижения\n";
				while (!(std::cin >> place) || std::cin.peek() != '\n' || (place != 'u' && place != 'd' && place != 'r' && place != 'l' && place != 'e'))
				{
					std::cout << "Выберите,куда Вы хотите сместить яйчейку 0\n" << "1.Нажмите u, чтобы сместить яйчейку 0 вверх\n" << "2.Нажмите d, чтобы сместить яйчейку 0 вверх\n"
						<< "3.Нажмите l, чтобы сместить яйчейку 0 влево\n" << "4.Нажмите r, чтобы сместить яйчейку 0 вправо\n" << "5.Нажмите 'e' чтобы выйти из режима передвижения\n";
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
			std::cout << "Введите строку\n";
			while (!(std::cin >> line) || std::cin.peek() != '\n' || line<0||line>3)
			{
				std::cout << "Введите строку\n";
				buffer_clean();
			}
			std::cout << "Введите столбец\n";
			while (!(std::cin >> column) || std::cin.peek() != '\n' || column < 0 || column>3)
			{
				std::cout << "Введите столбец\n";
				buffer_clean();
			}
			std::cout << game[line][column];
			break;
		case 'e':
			exit = false;
			break;
		default:
			std::cout << "Что-то пошло не так\n";
			break;
		}
	}
}

#include "Barley_break.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib> 
void Barley_break::square_filling(int line, int column, int value)//переиминовать переменные empty_line empty_column с большой буквы класс написать вырезать m,zn
{
		for (int i = line; i > -1; --i)
			for (int j = 3; j > -1; --j)
				if (field[i][j] == 0)
				{
					field[i][j] = value;
					return;
				}
		for (int i = line; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (field[i][j] == 0)
				{
					field[i][j] = value;
					return;
				}
}
Barley_break::Barley_break()
{
	mix();
}
void Barley_break::mix()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			field[i][j] = 0;
	int line, column;
	for (int value = 1; value < 16; ++value)
	{
		line = rand() % 4;
		column = rand() % 4;
		square_filling(line, column, value);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (field[i][j] == 0)
			{
				empty_line = i;
				empty_column = j;
			}
	std::swap(field[empty_line][empty_column], field[3][3]);
	empty_column = 3;
	empty_line = 3;
}
void Barley_break::transposition(char place)//пробрасыать throw дальше
{
		switch (place)
		{
		case 'u':
			if (empty_line - 1 != -1)
			{
				std::swap(field[empty_line][empty_column], field[empty_line - 1][empty_column]);
				--empty_line;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'd':
			if (empty_line + 1 != 4)
			{
				std::swap(field[empty_line][empty_column], field[empty_line + 1][empty_column]);
				++empty_line;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'l':
			if (empty_column - 1 != -1)
			{
				std::swap(field[empty_line][empty_column], field[empty_line][empty_column - 1]);
				--empty_column;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'r':
			if (empty_column + 1 != 4)
			{
				std::swap(field[empty_line][empty_column], field[empty_line][empty_column + 1]);
				++empty_column;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		default:
			throw - 1;
			break;
		}
}
bool Barley_break::check()
{
	int value = 1;//zn в value
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (field[i][j] != value)
				if (field[i][j] != 0) return false;
				else continue;
			++value;
		}
	return true;
}
void Barley_break::display()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << field[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
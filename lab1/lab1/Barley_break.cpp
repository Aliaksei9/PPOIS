#include "Barley_break.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib> 
void barley_break::square_filling(int line, int column, int value)
{
	try
	{
		if (line < -1 || column < -1 || column > 3 || line > 3)
			throw std::runtime_error("Строка и/или столбец приняли неожиданное значение");
		for (int i = line; i > -1; --i)
			for (int j = 4; j > -1; --j)
				if (m_field[i][j] == 0)
				{
					m_field[i][j] = value;
					return;
				}
		for (int i = line; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (m_field[i][j] == 0)
				{
					m_field[i][j] = value;
					return;
				}
	}
	catch (std::exception& exception)
	{
		std::cerr << "Стандартное исключение: " << exception.what() << '\n';
		system("PAUSE");
		exit(-1);
	}
	catch (...)
	{
		std::cerr << "Ненормальное поведение\n";
		system("PAUSE");
		exit(-1);
	}
}
barley_break::barley_break()
{
	mix();
}
void barley_break::mix()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m_field[i][j] = 0;
	int line, column;
	for (int value = 1; value < 16; ++value)
	{
		line = rand() % 4;
		column = rand() % 4;
		square_filling(line, column, value);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (m_field[i][j] == 0)
			{
				m_line_0 = i;
				m_column_0 = j;
			}
	std::swap(m_field[m_line_0][m_column_0], m_field[3][3]);
	m_column_0 = 3;
	m_line_0 = 3;
}
void barley_break::transposition(char place)
{
	try {
		switch (place)
		{
		case 'u':
			if (m_line_0 - 1 != -1)
			{
				std::swap(m_field[m_line_0][m_column_0], m_field[m_line_0 - 1][m_column_0]);
				--m_line_0;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'd':
			if (m_line_0 + 1 != 4)
			{
				std::swap(m_field[m_line_0][m_column_0], m_field[m_line_0 + 1][m_column_0]);
				++m_line_0;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'l':
			if (m_column_0 - 1 != -1)
			{
				std::swap(m_field[m_line_0][m_column_0], m_field[m_line_0][m_column_0 - 1]);
				--m_column_0;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		case 'r':
			if (m_column_0 + 1 != 4)
			{
				std::swap(m_field[m_line_0][m_column_0], m_field[m_line_0][m_column_0 + 1]);
				++m_column_0;
			}
			else throw std::runtime_error("Выход за границы поля\n");
			break;
		default:
			throw - 1;
			break;
		}
	}
	catch (std::exception& exception)
	{
		std::cerr<< exception.what() << '\n';
	}
	catch (...)
	{
		std::cerr << "Ненормальное поведение\n";
		system("PAUSE");
		exit(-1);
	}
}
bool barley_break::check()
{
	int zn = 1;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (m_field[i][j] != zn)
				if (m_field[i][j] != 0) return false;
				else continue;
			++zn;
		}
	return true;
}
void barley_break::display()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << m_field[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
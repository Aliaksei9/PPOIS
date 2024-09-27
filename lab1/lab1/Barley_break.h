#pragma once
class barley_break
{
private:
	int m_field[4][4], m_line_0, m_column_0;
	void square_filling(int line, int column, int value);
public:
	barley_break();
	void mix();
	void transposition(char place);
	bool check();
	void display();
	int* operator [] (int index) { return m_field[index]; }
};
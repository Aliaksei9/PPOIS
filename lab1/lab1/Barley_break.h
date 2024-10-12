#pragma once
class Barley_break
{
private:
	int field[4][4], empty_line_index, empty_column_index;
	void square_filling(int line, int column, int value);
public:
	Barley_break();
	void mix();
	void transposition(char place);
	bool check();
	void display();
	int* operator [] (int index) { return field[index]; }
};
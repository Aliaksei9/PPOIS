#include "Accounting.h"
void Accounting::increased_costs(int new_expenses)
{
	if (new_expenses < 0) throw std::runtime_error("Negative number in increasing expenses\n");
	expense += new_expenses;
}
Accounting::Accounting(int budget_accounting, int income_accounting, int expense_accounting)
{
	budget = budget_accounting;
	income = income_accounting;
	expense = expense_accounting;
}
void Accounting::new_month()
{
	budget += income - expense;
	if (budget < 0) throw 'e';
}
void Accounting::increased_incomes(int new_incomes)
{
	if (new_incomes < 0) throw std::runtime_error("Negative number in increasing income\n");
	income += new_incomes;
}

void Accounting::reduce_incomes(int value)
{
	if (value < 0) throw std::runtime_error("Negative number in decreasing income\n");
	income -= value;
}

void Accounting::reduce_costs(int value)
{
	if (value < 0) throw std::runtime_error("Negative number in reducing expenses\n");
	expense -= value;
}

void Accounting::one_time_waste(int value)
{
	if (value < 0) throw std::runtime_error("Negative number in one-time spending\n");
	budget -= value;
}

void Accounting::one_time_payment(int value)
{
	if (value < 0) throw std::runtime_error("Negative number in one-time pay\n");
	budget += value;
}

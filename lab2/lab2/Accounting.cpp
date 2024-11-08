#include "Accounting.h"
Accounting::Accounting(int space, int organization_budget, int organization_expenses, int organization_incomes):free_spase(space),budget(organization_budget),expenses(organization_expenses),incomes(organization_incomes)
{
	if (space < 0 || organization_budget < 0 || organization_expenses < 0 || organization_incomes < 0) throw - 1;
}
void Accounting::increased_costs(int new_expenses)
{
	if (new_expenses < 0) throw std::runtime_error("Отрицательное число в увеличении расходов\n");
	expenses += new_expenses;
}
void Accounting::new_day()
{
	budget += incomes - expenses;
	cleanliness_of_the_premises = 1;
	if (budget < 0) throw 'e';
}
void Accounting::increased_incomes(int new_incomes)
{
	if (new_incomes < 0) throw std::runtime_error("Отрицательное число в увеличении доходов\n");
	incomes += new_incomes;
}

void Accounting::reduce_incomes(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в уменьшении доходов\n");
	incomes -= value;
}

void Accounting::reduce_costs(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в уменьшении расходв\n");
	expenses -= value;
}

void Accounting::reduce_free_space(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в уменьшении пространства\n");
	free_spase -= value;
	if (free_spase < 0) throw 1;
}
void Accounting::increased_free_space(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в увеличении пространства\n");
	free_spase += value;
	if (free_spase < 0) throw 1;
}

void Accounting::purchase(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в покупке\n");
	budget -= value;
}

void Accounting::selling(int value)
{
	if (value < 0) throw std::runtime_error("Отрицательное число в продаже\n");
	budget += value;
}

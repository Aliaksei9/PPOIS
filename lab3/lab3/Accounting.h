#pragma once
#include "stdexcept"
class Accountant;
class Accounting
{
private:
	int budget, income, expense;
public:
	Accounting(int budget_accounting, int income_accounting, int expense_accounting);
	void new_month();
	void increased_costs(int new_expenses);
	void increased_incomes(int new_incomes);
	void reduce_incomes(int value);
	void reduce_costs(int value);
	void one_time_waste(int value);
	void one_time_payment(int value);
	friend class Accountant;
};


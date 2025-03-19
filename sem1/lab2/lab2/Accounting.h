#pragma once
#include <stdexcept>
class Accountant;
class Cleaner;
class Accounting
{
private:
	int free_spase=1000, budget = 9000, expenses = 500, incomes = 0;
	bool cleanliness_of_the_premises = 1;
public:
	Accounting() = default;
	Accounting(int space, int organization_budget, int organization_expenses, int organization_incomes);
	bool get_cleanliness_of_the_premises()const { return cleanliness_of_the_premises; }
	void increased_costs(int new_expenses);
	void increased_incomes(int new_incomes);
	void reduce_incomes(int value);
	void reduce_costs(int value);
	void reduce_free_space(int value);
	void purchase(int value);
	void selling(int value);
	void increased_free_space(int value);
	void new_day();
	friend class Accountant;
	friend class Cleaner;
};
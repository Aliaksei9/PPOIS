#include "Programmer.h"

Programmer::Programmer(std::string programmer_name, double programmer_professionalism, Accounting* place_of_work_programmer)
{
	name = programmer_name;
	professionalism = programmer_professionalism;
	place_of_work = place_of_work_programmer;
	place_of_work->increased_costs(1200);
}

Code Programmer::write_code()
{
	return Code(professionalism);
}

void Programmer::optimization(Code* code)
{
	code->resource_intensity -= 1;
}

void Programmer::revision(Code* code)
{
	code->resource_intensity += 2;
	code->quality += 1;
}
void Programmer::fixing_bugs(Code* code)
{
	code->bugs -= 3;
	if (code->bugs < 0) code->bugs = 0;
	std::cout << "Number of bugs: " << code->bugs << std::endl;
}

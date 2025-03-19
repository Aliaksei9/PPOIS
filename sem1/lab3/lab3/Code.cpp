#include "Code.h"

Code::Code(double programmer_proffesionalism)
{
	quality = rand() % 3 *(programmer_proffesionalism);
	bugs = 10- programmer_proffesionalism;
}


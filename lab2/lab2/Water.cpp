#include "Water.h"
bool approximatelyEqual(double a, double b, double epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool Water::operator==(const Water& water) const
{
    if (approximatelyEqual(this->salinity,water.salinity,0.001) && approximatelyEqual(this->acidity, water.acidity, 0.001) && approximatelyEqual(this->temperature, water.temperature, 0.001) && approximatelyEqual(this->dissolved_oxygen, water.dissolved_oxygen, 0.001)) return true;
    else return false;
}

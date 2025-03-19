#pragma once
#include <cmath> // для функции fabs()

class Hydrochemist;
class Hydrobiont;
class Water
{
private:
	double salinity, acidity, temperature, dissolved_oxygen;
public:
	Water(double water_salinity, double water_acidity, double water_temperature, double water_dissolved_oxygen): 
		salinity(water_salinity), acidity(water_acidity), temperature(water_temperature), dissolved_oxygen(water_dissolved_oxygen)
	{
	}
	bool operator == (const Water& water) const;
	friend class Hydrochemist;
	friend class Hydrobiont;
};
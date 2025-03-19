#pragma once
#include "Technical_product.h"
class Artist_3D;
class Model: public Technical_product
{
private:
	Model(double artist_professionalism, bool motion_capture);
public:
	Model() = default;
	friend class Artist_3D;
};


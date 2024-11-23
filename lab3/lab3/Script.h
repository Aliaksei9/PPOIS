#pragma once
#include "Creative_product.h"
class Scriptwriter;
class Script: public Creative_product
{
private:
	Script(double script_writter_professionalism, MOOD authors_specialization, MOOD mood_work, bool errors, bool inspiration);
	friend class Scriptwriter;
public:
	Script() = default;
	Script(const Script& script) = default;
};


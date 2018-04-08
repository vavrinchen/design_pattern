#pragma once

#include "Dough.h"
#include <iostream>
class ThickCrustDough : public Dough
{
public:

	ThickCrustDough()
	{
		std::cout << "Thick Crust Dough ... \n";
	}
};
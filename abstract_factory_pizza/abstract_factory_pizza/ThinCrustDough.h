#pragma once

#include "Dough.h"
#include <iostream>

class ThinCrustDough : public Dough
{
public:

	ThinCrustDough()
	{
		std::cout << "Thin Crust Dough... \n";
	}
};

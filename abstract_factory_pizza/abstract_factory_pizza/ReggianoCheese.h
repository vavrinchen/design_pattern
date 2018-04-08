#pragma once


#include "Cheese.h"
#include <iostream>

class ReggianoCheese : public Cheese
{
public:

	ReggianoCheese()
	{
		std::cout << "Reggiano Cheese... \n";
	}
};
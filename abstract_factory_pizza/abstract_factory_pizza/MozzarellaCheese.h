#pragma once

#include "Cheese.h"
#include <iostream>

class MozzarellaCheese : public Cheese
{
public:

	MozzarellaCheese()
	{
		std::cout << "Mozzarella Cheese... \n";
	}

};
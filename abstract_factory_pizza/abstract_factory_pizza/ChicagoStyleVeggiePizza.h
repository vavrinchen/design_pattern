#pragma once
#include "Pizza.h"

class ChicagoStyleVeggiePizza : public Pizza
{
public:

	ChicagoStyleVeggiePizza() : Pizza("Chicago Style Veggie Pizza",
		"Extra Thick Crust Sprouted Dough",
		"Chinese Hunan Sauce",
		"Thick grated cottage Cheese")
	{

	}

	void cut()
	{
		std::cout << " Cutting the pizza into rectangular slices" << std::endl;
	}
};
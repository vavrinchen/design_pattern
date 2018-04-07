#pragma once
#include "Pizza.h"
#include <iostream>

class ChicagoStyleCheesePizza : public Pizza
{
public:

	ChicagoStyleCheesePizza() : Pizza("Chicago Style Deep Dish Cheese Pizza",
		"Extra Thick Crust Dough",
		"Plum Tomato Sauce",
		"Shredded Mozzarella Cheese")
	{

	}

	void cut()
	{
		std::cout << " Cutting the pizza into square slices" << std::endl;
	}
};

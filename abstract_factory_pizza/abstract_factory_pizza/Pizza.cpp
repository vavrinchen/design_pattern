#include <iostream>
#include "Pizza.h"

void Pizza::prepare()
{
	std::cout << "Preparing " + name << std::endl;
	std::cout << "Tossing dough ...." << std::endl;
	std::cout << "Adding sauce ...." << std::endl;
	std::cout << "Adding cheese ...." << std::endl;
	std::cout << "Adding toppings : " + toppings << std::endl;
}

void Pizza::bake()
{
	std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut()
{
	std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box()
{
	std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

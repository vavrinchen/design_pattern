/* In factory method, prepare() is not a abstract function; 
however, in abstract factory, prepare() need to be abstract, 
and let the CheesePizza or VeggiePizza to implement prepare() by ingredientFactory*/

#include <iostream>
#include "Pizza.h"


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

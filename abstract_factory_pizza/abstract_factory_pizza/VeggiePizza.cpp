#include "VeggiePizza.h"
#include <string>
#include <iostream>


void VeggiePizza::prepare()
{
	std::cout << "Preparing " + name << std::endl;
	dough = ingredientFactory->createDough();
	sauce = ingredientFactory->createSauce();
	cheese = ingredientFactory->createCheese();
	veggies = ingredientFactory->createVeggies();

}

#include "CheesePizza.h"
#include <string>
#include <iostream>


void CheesePizza::prepare()
{
	std::cout << "Preparing " + name << std::endl;
	dough = ingredientFactory->createDough();
	sauce = ingredientFactory->createSauce();
	cheese = ingredientFactory->createCheese();
	clam = ingredientFactory->createClams();

}
#pragma once

#include "PizzaIngredientFactory.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:

	Dough * createDough();
	Sauce* createSauce();
	Veggies* createVeggies();
	Cheese* createCheese();
	Clams* createClams();


};

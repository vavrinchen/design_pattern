#pragma once
#include "Dough.h"
#include "Sauce.h"
#include "Veggies.h"
#include "Cheese.h"
#include "Clams.h"


class PizzaIngredientFactory
{
public:

	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
	virtual Veggies* createVeggies() = 0;
	virtual Cheese* createCheese() = 0;
	virtual Clams* createClams() = 0;
};
#pragma once

#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class CheesePizza : public Pizza
{
public:
	CheesePizza(PizzaIngredientFactory* ingredientFactory)
	{
		this->ingredientFactory = ingredientFactory;
	}

	void prepare();

private:
	PizzaIngredientFactory * ingredientFactory;

};

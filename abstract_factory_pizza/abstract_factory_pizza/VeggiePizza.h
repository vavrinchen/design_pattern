#pragma once

#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class VeggiePizza : public Pizza
{
public:
	VeggiePizza(PizzaIngredientFactory* ingredientFactory)
	{
		this->ingredientFactory = ingredientFactory;
	}

	void prepare();

private:
	PizzaIngredientFactory * ingredientFactory;

};

#include "NYPizzastore.h"
#include "NYPizzaIngredientFactory.h"
#include "Pizza.h"
#include "CheesePizza.h"
#include "VeggiePizza.h"
#include <iostream>
#include <new>



Pizza* NYPizzaStore::createPizza(std::string type)
{
	Pizza* pizza = NULL;
	PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();

	if (type == "cheese")
	{
		pizza = new CheesePizza(ingredientFactory);
		pizza->setname("New York Style Cheese Pizza");
	}
	else if (type == "veggie")
	{
		pizza = new VeggiePizza(ingredientFactory);
		pizza->setname("New York Style Veggie Pizza");
	}

	return pizza;
}
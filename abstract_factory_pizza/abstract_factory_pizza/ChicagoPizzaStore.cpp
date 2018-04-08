/* In factory method, when type is cheese, return new ChicagoStyleCheesePizza(); 
however, whether the pizza is Chicacgo or NY style, the difference of their cheese pizza is ingredient,
so, in abstract factory, there's no need of class 'ChicagoStyleCheesePizza', just a class for ChessePizza.
Let the ingredientFactory to handle Chicago or NY style*/

#include "ChicagoPizzaStore.h"
#include "ChicagoPizzaIngredientFactory.h"
#include "Pizza.h"
#include "CheesePizza.h"
#include "VeggiePizza.h"
#include <iostream>
#include <new>


Pizza* ChicagoPizzaStore::createPizza(std::string type)
{
	Pizza* pizza = NULL;
	PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory(); 

	if (type == "cheese")
	{
		pizza = new CheesePizza(ingredientFactory);
		pizza->setname("Chicago Style Cheese Pizza");
	}
	else if (type == "veggie")
	{
		pizza = new VeggiePizza(ingredientFactory);
		pizza->setname("Chicago Style Veggie Pizza");
	}

	return pizza;
}
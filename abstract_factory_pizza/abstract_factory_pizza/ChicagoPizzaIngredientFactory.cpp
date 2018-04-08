#include "ChicagoPizzaIngredientFactory.h"
#include "FrozenClams.h"
#include "PlumTomatoSauce.h"
#include "ThickCrustDough.h"
#include "MozzarellaCheese.h"
#include "RoyalVeggies.h"
#include <new>


Dough* ChicagoPizzaIngredientFactory::createDough()
{
	return new ThickCrustDough();
}

Sauce* ChicagoPizzaIngredientFactory::createSauce()
{
	return new PlumTomatoSauce();
}

Cheese* ChicagoPizzaIngredientFactory::createCheese()
{
	return new MozzarellaCheese();
}

Veggies* ChicagoPizzaIngredientFactory::createVeggies()
{
	return new RoyalVeggies();
}

Clams* ChicagoPizzaIngredientFactory::createClams()
{
	return new FrozenClams();
}

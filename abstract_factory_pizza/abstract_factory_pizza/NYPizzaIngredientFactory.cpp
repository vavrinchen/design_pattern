
#include "NYPizzaIngredientFactory.h"
#include "ThinCrustDough.h"
#include "MarinaraSauce.h"
#include "ReggianoCheese.h"
#include "MixVeggies.h"
#include "FreshClams.h"
#include <new>


Dough* NYPizzaIngredientFactory::createDough()
{
	return new ThinCrustDough();
}

Sauce* NYPizzaIngredientFactory::createSauce()
{
	return new MarinaraSauce();
}

Cheese* NYPizzaIngredientFactory::createCheese()
{
	return new ReggianoCheese();
}

Veggies* NYPizzaIngredientFactory::createVeggies()
{
	return new MixVeggies();
}

Clams* NYPizzaIngredientFactory::createClams()
{
	return new FreshClams();
}
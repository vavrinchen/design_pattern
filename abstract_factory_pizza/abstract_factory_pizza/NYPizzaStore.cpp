#include "NYPizzaStore.h"
#include "NYStyleCheesePizza.h"
#include "NYStyleVeggiePizza.h"

Pizza* NYPizzaStore::createPizza(std::string type)
{
	if (type == "cheese")
	{
		return new NYStyleCheesePizza();
	}
	else if (type == "veggie")
	{
		return new NYStyleVeggiePizza();
	}
	else
		return NULL;
}
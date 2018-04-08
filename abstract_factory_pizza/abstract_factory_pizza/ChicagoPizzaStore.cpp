#include "ChicagoPizzaStore.h"
#include "ChicagoStyleCheesePizza.h"
#include "ChicagoStyleVeggiePizza.h"

Pizza* ChicagoPizzaStore::createPizza(std::string type)
{
	if (type == "cheese")
	{
		return new ChicagoStyleCheesePizza();
	}
	else if (type == "veggie")
	{
		return new ChicagoStyleVeggiePizza();
	}
	else
		return NULL;
}
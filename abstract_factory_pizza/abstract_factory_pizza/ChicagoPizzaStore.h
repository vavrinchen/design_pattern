#pragma once
#include "PizzaStore.h"

class ChicagoPizzaStore : public PizzaStore
{
	Pizza* createPizza(std::string type);
};


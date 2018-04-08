#pragma once
#include "PizzaStore.h"

class NYPizzaStore : public PizzaStore
{
	Pizza* createPizza(std::string type);
};

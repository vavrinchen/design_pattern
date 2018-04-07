#pragma once
#include "Pizza.h"


class PizzaStore
{
public:

	virtual Pizza* createPizza(std::string type) = 0;			// factory method

	Pizza* orderPizza(std::string type);
};



/* In factory method, prepare() is not a abstract function;
however, in abstract factory, prepare() need to be abstract,
and let the CheesePizza or VeggiePizza to implement prepare() by ingredientFactory*/
/*
In factory method, use Pizza() constructor to initialize the ingredient, 
and Pizza class has ingredient member, dough, sauce, toppings.
In abstract factory, no need of Pizza constructor, let the ingredientFactory to initail ingredient,
and Pizza class has ingredient class member, Dough, Sauce, Cheese, Veggie, Clam
*/

#pragma once
#include "Dough.h"
#include "Sauce.h"
#include "Veggies.h"
#include "Cheese.h"
#include "Clams.h"
#include <string>

class Pizza
{
public:

	virtual void prepare() = 0;

	virtual void bake();

	virtual void cut();

	virtual void box();

	std::string getname()
	{
		return name;
	}

	void setname(std::string name)
	{
		this->name = name;
	}

public:

	std::string name;
	Dough* dough;
	Sauce* sauce;
	Veggies* veggies;
	Cheese* cheese;
	Clams* clam;

};


#include "PizzaStore.h"

Pizza* PizzaStore::orderPizza(std::string type)
{
	Pizza *pizza = createPizza(type);

	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();

	return pizza;
}
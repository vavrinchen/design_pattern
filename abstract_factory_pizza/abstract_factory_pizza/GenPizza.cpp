#include <string>
#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"
#include "ChicagoPizzaStore.h"
#include "NYPizzaStore.h"


void main()
{
	PizzaStore *nyStore = new NYPizzaStore();
	PizzaStore *chicagoStore = new ChicagoPizzaStore();

	Pizza *pizza = nyStore->orderPizza("cheese");
	std::cout << "Ethan Ordered a " + pizza->getname() << std::endl;
	std::cout << std::endl; std::cout << std::endl;

	pizza = chicagoStore->orderPizza("veggie");
	std::cout << "Joel ordered a " + pizza->getname() << std::endl;
	std::cout << std::endl; std::cout << std::endl;

	char ch = std::cin.get();

}
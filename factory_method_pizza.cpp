#include <string>
#include <iostream>

class Pizza
{
public:

	Pizza(std::string n, std::string d, std::string s, std::string t) : name(n),
		dough(d), sauce(s), toppings(t) {}

	virtual void prepare();

	virtual void bake();

	virtual void cut();

	virtual void box();

	std::string getname()
	{
		return name;
	}

public:

	std::string name;
	std::string dough;
	std::string sauce;
	std::string toppings;

};

void Pizza::prepare()
{
	std::cout << "Preparing " + name << std::endl;
	std::cout << "Tossing dough ...." << std::endl;
	std::cout << "Adding sauce ...." << std::endl;
	std::cout << "Adding cheese ...." << std::endl;
	std::cout << "Adding toppings : " + toppings << std::endl;
}

void Pizza::bake()
{
	std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut()
{
	std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box()
{
	std::cout << "Place pizza in official PizzaStore box" << std::endl;
}


class ChicagoStyleCheesePizza : public Pizza
{
public:

	ChicagoStyleCheesePizza() : Pizza("Chicago Style Deep Dish Cheese Pizza",
		"Extra Thick Crust Dough",
		"Plum Tomato Sauce",
		"Shredded Mozzarella Cheese")
	{

	}

	void cut()
	{
		std::cout << " Cutting the pizza into square slices" << std::endl;
	}
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:

	ChicagoStyleVeggiePizza() : Pizza("Chicago Style Veggie Pizza",
		"Extra Thick Crust Sprouted Dough",
		"Chinese Hunan Sauce",
		"Thick grated cottage Cheese")
	{

	}

	void cut()
	{
		std::cout << " Cutting the pizza into rectangular slices" << std::endl;
	}
};


class NYStyleCheesePizza : public Pizza
{
public:

	NYStyleCheesePizza() : Pizza("NY Style Sauce and cheese Pizza",
		"Thin Crust Dough",
		"Marinara Sauce",
		"Grated Reggiano Cheese")
	{

	}
};

class NYStyleVeggiePizza : public Pizza
{
public:

	NYStyleVeggiePizza() : Pizza("NY Style Veggie Pizza",
		"Thin Crust Dough",
		"Tamarino Sauce",
		"Grated Mozerrela Cheese")
	{

	}
};

class PizzaStore
{
public:

	virtual Pizza* createPizza(std::string type) = 0;			// factory method

	Pizza* orderPizza(std::string type);
};

Pizza* PizzaStore::orderPizza(std::string type)
{
	Pizza *pizza = createPizza(type);

	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();

	return pizza;
}

class ChicagoPizzaStore : public PizzaStore
{
	Pizza* createPizza(std::string type);
};

Pizza* ChicagoPizzaStore::createPizza(std::string type)
{
	if (type == static_cast<std::string> ("cheese"))
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

class NYPizzaStore : public PizzaStore
{
	Pizza* createPizza(std::string type);
};


Pizza* NYPizzaStore::createPizza(std::string type)
{
	if (type == static_cast<std::string> ("cheese"))
	{
		return new NYStyleCheesePizza();
	}
	else if (type == static_cast<std::string> ("veggie"))
	{
		return new NYStyleVeggiePizza();
	}
	else
		return NULL;
}

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
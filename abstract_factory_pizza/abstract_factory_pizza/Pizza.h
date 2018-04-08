#pragma once

#include <string>

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

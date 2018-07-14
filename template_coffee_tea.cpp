#include <iostream>
 
//定義咖啡和茶的 base class
class CaffeineBeverage
{
public:
	void prepareRecipe()
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}
 
	void boilWater()
	{
		std::cout << "Boiling water" << std::endl;
	}
 
	void pourInCup()
	{
		std::cout << "Pouring into cup" << std::endl;
	}
 
	virtual void brew(){}
 
	virtual void addCondiments(){}
};

class Coffee : public CaffeineBeverage
{
public:
	void brew()
	{
		std::cout << "Dripping Coffee through filter" << std::endl;
	}
 
	void addCondiments()
	{
		std::cout << "Adding Sugar and Milk" << std::endl;
	}
};


class Tea : public CaffeineBeverage
{
public:
	void brew()
	{
		std::cout << "Steeping the tea" << std::endl;
	}
 
	void addCondiments()
	{
		std::cout << "Adding Lemon" << std::endl;
	}
};

int main()
{
	Coffee coffee;
	std::cout << "Making coffee..." << std::endl;
	coffee.prepareRecipe();
	std::cout << std::endl << std::endl;
 
	Tea tea;
	std::cout << "Make tea..." << std::endl;
	tea.prepareRecipe();
	return 0;
}

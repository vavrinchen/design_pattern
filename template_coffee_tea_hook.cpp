#include <iostream>
#include <string>

//定義咖啡和茶的 base class
class CaffeineBeverage
{
public:
	void prepareRecipe()
	{
		boilWater();
		brew();
		pourInCup();
        if(customerWantsCondiments()) {
		    addCondiments();
        }
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

    virtual bool customerWantsCondiments(){
        return true;
    }
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

    bool customerWantsCondiments() {
        std::string answer;
        return tolower(getUserInput(answer)[0]) == 'y';
    }

   std::string getUserInput(std::string& answer) {
        std::cout << "Would you like milk with your coffee (y/n)? " << std::endl;
        if (!std::cin.eof()) {
            std::cin >> answer;
            return answer;
        }
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

    bool customerWantsCondiments() {
        std::string answer;
        return tolower(getUserInput(answer)[0]) == 'y';
    }

   std::string getUserInput(std::string& answer) {
        std::cout << "Would you like milk with your coffee (y/n)? " << std::endl;
        if (!std::cin.eof()) {
            std::cin >> answer;
            return answer;
        }
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

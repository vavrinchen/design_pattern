#include <string>  
#include <iostream>
using namespace std;

class InterafaceBeverage
{
public:
	virtual string getDescription();
	virtual double cost() = 0;
protected:
	string description;

};

class InterafaceDecorator :public InterafaceBeverage
{
public:
	virtual string getDescription() = 0;

};



class Espresso :public InterafaceBeverage
{
public:
	Espresso();
	~Espresso();
	double cost();

};
class HouseBlend :public InterafaceBeverage
{
public:
	HouseBlend();
	~HouseBlend();
	double cost();
};



class Mocha :public InterafaceDecorator
{
public:
	Mocha(InterafaceBeverage *beverage);
	string getDescription();
	double cost();
private:
	InterafaceBeverage *beverage; 
};

using namespace std;
string InterafaceBeverage::getDescription()
{
	return description;
}



HouseBlend::HouseBlend()
{
	description = "House Blend Coffee";
}
HouseBlend::~HouseBlend()
{
	cout << "~HouseBlend()" << endl;

}

double HouseBlend::cost()
{
	return 5;
}


Espresso::Espresso()
{
	description = "Espresso";
}
Espresso::~Espresso()
{
	cout << "~Espresso()" << endl;
}
double Espresso::cost()
{
	return 10;
}



Mocha::Mocha(InterafaceBeverage *beverage)
{
	this->beverage = beverage;

}
string Mocha::getDescription()
{
	return beverage->getDescription() + ",Mocha";
}

double Mocha::cost()
{
	return 7 + beverage->cost();
}

int main(int argc, char* argv[])
{
	
	InterafaceBeverage *beverage = new Espresso();
	cout << beverage->getDescription() << " $" << beverage->cost() << endl;


	

	InterafaceBeverage *beverage2 = new HouseBlend();
	cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
	beverage2 = new Mocha(beverage2); //Mocha decorates HouseBlend  
	cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
	system("pause");
	return 0;
}
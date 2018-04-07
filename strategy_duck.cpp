#include <iostream>



class IQuackBehaviour
{
    
public:
	virtual void quack() = 0;
    
};

class Quack : public IQuackBehaviour
{
    
public:
	void quack()
	{
		std::cout << "Quack" << std::endl;
	}
    
};

class MuteQuack : public IQuackBehaviour
{
    
public:
	void quack()
	{
		std::cout << "< Silence >" << std::endl;
	}
    
};


class IFlyBehaviour
{
    
public:
	virtual void fly() = 0;
    
};

class FlyWithWings : public IFlyBehaviour
{
    
public:
	void fly()
	{
		std::cout << "I'm flying!!" << std::endl;
	}
    
};

class FlyNoWay : public IFlyBehaviour
{
    
public:
	void fly()
	{
		std::cout << "I can't fly!" << std::endl;
	}
    
};

class FlyRocketPowered : public IFlyBehaviour
{
    
public:
	void fly()
	{
		std::cout << "I'm flying with a rocket!" << std::endl;
	}
    
};


class Duck
{
    
public:
	IQuackBehaviour *quackBehaviour;
	IFlyBehaviour   *flyBehaviour;

	void performQuack()
	{
		quackBehaviour->quack();
	}

	void setQuackBehaviour(IQuackBehaviour *qb)
	{
		quackBehaviour = qb;
		std::cout << "Set quack behaviour" << std::endl;
	}

	void performFly()
	{
		flyBehaviour->fly();
	}

	void setFlyBehaviour(IFlyBehaviour *fb)
	{
		flyBehaviour = fb;
		std::cout << "Set fly behaviour" << std::endl;
	}

	void swim()
	{
		std::cout << "All ducks float, event decoys!" << std::endl;
	}

	virtual void display() = 0;

};


class MallardDuck : public Duck
{
    
public:
	MallardDuck()
	{
		quackBehaviour = new Quack();
		flyBehaviour = new FlyWithWings();
	}

	void display()
	{
		std::cout << "I'm a real Mallard duck!" << std::endl;
	}

};


class RubberDuck : public Duck
{
    
public:
	RubberDuck()
	{
		quackBehaviour = new MuteQuack();
		flyBehaviour = new FlyNoWay();
	}

	void display()
	{
		std::cout << "I'm a rubber duck!" << std::endl;
	}
};


class DecoyDuck : public Duck
{
    
public:
	DecoyDuck()
	{
		quackBehaviour = new MuteQuack();
		flyBehaviour = new FlyNoWay();
	}

	void display()
	{
		std::cout << "I'm a decoy duck!" << std::endl;
	}
};


int main()
{
	Duck *mallard = new MallardDuck();
	mallard->display();
	mallard->swim();
	mallard->performFly();
	mallard->performQuack();

	std::cout << std::endl << std::endl;

	Duck *rubber = new RubberDuck();
	rubber->display();
	rubber->swim();
	rubber->performFly();
	rubber->performQuack();

	std::cout << std::endl << std::endl;

	Duck *decoy = new DecoyDuck();
	decoy->display();
	decoy->swim();
	decoy->performFly();
	decoy->setFlyBehaviour(new FlyRocketPowered);
	decoy->performFly();
	decoy->performQuack();
	decoy->setQuackBehaviour(new Quack);
	decoy->performQuack();

	return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

//Item
class MenuItem
{
public:
	MenuItem(){}
	MenuItem(string set_name, string set_description, double set_price)
	{
		name = set_name;
		description = set_description;
		price = set_price;
	}

	string getName()
	{
		return name;
	}

	string getDescription()
	{
		return description;
	}
	
	double getPrice()
	{
		return price;
	}
private:
	string name;
	string description;
	double price;
};

//Iterator Interface
class Iterator
{
public:

	virtual bool hasNext(){
        throw std::runtime_error("ERROR");
    }

	virtual MenuItem next(){
        throw std::runtime_error("ERROR");
    }
};
//Concrete Iterator 1
class PancakeHouseMenuIterator : public Iterator
{
public:
	PancakeHouseMenuIterator(list<MenuItem> item)
	{
		items = item;
		iter = items.begin();
	}
	MenuItem next()
	{
		MenuItem menuItem = *iter;
		++iter;
		return menuItem;
	}

	bool hasNext()
	{
		if(iter == items.end())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	list<MenuItem> items;
	list<MenuItem>::const_iterator iter;
};
//Concrete Iterator 2
class DinerMenuIterator : public Iterator
{
public:
	DinerMenuIterator(vector<MenuItem> item):position(0)
	{
		items = item;
	}
	MenuItem next()
	{
		MenuItem menuItem = items[position];
		position = position + 1;
		return menuItem;
	}

	bool hasNext()
	{
		if(position >= items.size())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	vector<MenuItem> items;
	unsigned int position;
};

//Iterable Interface
class Menu
{
public:

	virtual Iterator* createIterator(){
        throw std::runtime_error("ERROR");
    }
};



//Concrete Iterable 1
class PancakeHouseMenu : public Menu
{
public:
	PancakeHouseMenu()
	{
		addItem("K&B'S Breakfase","pacakes with eggs",2.99);
		addItem("Buleberry Breakfase","pacakes with buleberries",3.99);
	}

	void addItem(string set_name, string set_description, double set_price)
	{
		MenuItem menuItem(set_name,set_description,set_price);
		menuItems.push_back(menuItem);
	}

	Iterator* createIterator()
	{
		return new PancakeHouseMenuIterator(menuItems);
	}
private:
	list<MenuItem> menuItems;
};

//Concrete Iterable 2
class DinerMenu : public Menu
{
public:
	DinerMenu()
	{
		addItem("Vegetarian BLT", "Bacon with lettuce", 2.99);
		addItem("BLT", "Bacon with tomato", 3.99);
	}
	void addItem(string set_name, string set_description, double set_price)
	{
		MenuItem menuItem(set_name,set_description,set_price);
		menuItems.push_back(menuItem);
	}
	Iterator* createIterator()
	{
		return new DinerMenuIterator(menuItems);
	}
private:
	vector<MenuItem> menuItems;
};

//Client
class Waitress
{
public:
	Waitress(Menu* p_PancakeHouseMenu, Menu* p_DinerMenu)
	{
		pPancakeHouseMenu = p_PancakeHouseMenu;
		pDinerMenu = p_DinerMenu;
	}

	void printMenu()
	{
		Iterator* pPancakeHouseIterator = pPancakeHouseMenu->createIterator();
		Iterator* pDinerIterator = pDinerMenu->createIterator();

		cout << "Menu"<< endl <<"----"<<endl << "BREAKFAST" <<endl;
		printMenu(pPancakeHouseIterator);
		cout << "LUNCH" << endl;
		printMenu(pDinerIterator);
	}

	void printMenu(Iterator* iter)
	{
		while(iter->hasNext())
		{
			MenuItem menuItem = (MenuItem)iter->next();
			cout << menuItem.getName() << "	"<< menuItem.getPrice()<<"	" 
			<< menuItem.getDescription() << endl;
		}
	}
private:
	Menu* pPancakeHouseMenu;
	Menu* pDinerMenu;
};

int main()
{
	Menu* pPancakeHouseMenu = new PancakeHouseMenu();
	Menu* pDinerMenu = new DinerMenu();

	Waitress waitress(pPancakeHouseMenu,pDinerMenu);
	waitress.printMenu();
	return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

//菜单和菜单项共同的组件
class MenuComponent
{
  public:
    virtual void add(MenuComponent *menuComponent)
    {
        throw std::runtime_error("add error!");
    }

    virtual void remove(MenuComponent *menuComponent)
    {
        throw std::runtime_error("remove error!");
    }

    virtual MenuComponent *getChild(int i)
    {
        throw std::runtime_error("getChild error");
    }

    virtual string getName()
    {
        throw std::runtime_error("getName error");
    }

    virtual string getDescription()
    {
        throw std::runtime_error("getDescription error");
    }

    virtual double getPrice()
    {
        throw std::runtime_error("getPrice error");
    }

    virtual void print()
    {
        throw std::runtime_error("print error");
    }
};

//菜单项类
class MenuItem : public MenuComponent
{
  public:
    MenuItem() {}
    MenuItem(string na, string descrip, double pric)
    {
        name = na;
        description = descrip;
        price = pric;
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

    void print()
    {
        cout << "	" << getName() << ",	" << getPrice()
             << "	---" << getDescription() << endl;
    }

  private:
    string name;
    string description;
    double price;
};
//组合菜单类
class Menu : public MenuComponent
{
  public:
    Menu(string nam, string descri)
    {
        name = nam;
        description = descri;
    }

    void add(MenuComponent *pMenuComponent)
    {
        pMenuComponents.push_back(pMenuComponent);
    }

    void remove(MenuComponent *pMenuComponent)
    {
        vector<MenuComponent *>::iterator iter = pMenuComponents.begin();
        for (; iter != pMenuComponents.end(); ++iter)
        {
            if (*iter == pMenuComponent)
            {
                pMenuComponents.erase(iter);
            }
        }
    }

    MenuComponent *getChild(int i)
    {
        return pMenuComponents[i];
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }

    void print()
    {
        cout << endl
             << getName() << ",	" << getDescription() << endl
             << "--------------" << endl;
        vector<MenuComponent *>::iterator iter = pMenuComponents.begin();
        while (iter != pMenuComponents.end())
        {
            MenuComponent *pMenuComponent = *iter;
            pMenuComponent->print();
            ++iter;
        }
    }

  private:
    vector<MenuComponent *> pMenuComponents;
    string name;
    string description;
};

//服务生类
class Waitress
{
  public:
    Waitress(MenuComponent *all_Menus)
    {
        allMenus = all_Menus;
    }

    void printMenu()
    {
        allMenus->print();
    }

  private:
    MenuComponent *allMenus;
};
//客户代码
int main()
{
    MenuComponent *pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent *dinerMenu = new Menu("Diner MENU", "Lunch");
    MenuComponent *dessertMenu = new Menu("DESSERT MENU", "Dessert of coure!");

    MenuComponent *allMenus = new Menu("ALL Menus", "All menus combined");

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    dinerMenu->add(new MenuItem("Pasta", "Spaheti with Sauce", 3.89));

    dinerMenu->add(dessertMenu);
    dessertMenu->add(new MenuItem("Apple Pie", "App pie with a cruse", 1.59));

    Waitress *waitress = new Waitress(allMenus);
    waitress->printMenu();
    return 0;
}
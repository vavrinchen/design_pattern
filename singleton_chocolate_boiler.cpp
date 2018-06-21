#include <iostream>

class ChocolateBoiler {
    private:
      static ChocolateBoiler *s1;
      bool empty = true;
      bool boiled = false;
      ChocolateBoiler(){};
    public:
      static ChocolateBoiler& getInstance();
      bool isEmpty() { return empty; }
      bool isBoiled() { return boiled; }

      void fill()
      {
          if (isEmpty())
          {
              empty = false;
              boiled = false;
              std::cout << "在鍋爐内填满巧克力和牛奶的混合物" << std::endl;
          }
      }

      void drain()
      {
          if (!isEmpty() && isBoiled())
          {
              std::cout << "排出煮沸的巧克力和牛奶" << std::endl;
              empty = true;
          }
      }

      void boil()
      {
          if (!isEmpty() && !isBoiled())
          {
              std::cout << "將爐內物煮沸" << std::endl;
              boiled = true;
          }
      }
};



ChocolateBoiler& ChocolateBoiler::getInstance(){
    if (s1 == nullptr){
       s1 = new ChocolateBoiler();
    } 
    return *s1;
}

ChocolateBoiler *ChocolateBoiler::s1 = nullptr;

int main()
{
    ChocolateBoiler &c1 = ChocolateBoiler::getInstance();
    c1.fill();
    ChocolateBoiler &c2 = ChocolateBoiler::getInstance();
    c2.boil();
    c1.drain();
    c2.fill();
    return 0;
}
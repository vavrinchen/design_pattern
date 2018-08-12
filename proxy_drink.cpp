#include <iostream>

class Wine //Interface Subject
{
  public:
    virtual void drink() = 0;
};

class Bear : public Wine //Real Subject
{
  public:
    virtual void drink()
    {
        std::cout << "drink the bear" << std::endl;
    }
};

class Drinker {
 public:
  explicit Drinker(int age) : age_(age) {
  }
  int age() { return age_; }
  void set_age(int age) { age_ = age; }

 private:
  int age_;
};

class ProxyBear : public Wine { //Proxy, which implement Interface Subject "Wine", and also has a Real Subject "Bear"
 public:
  explicit ProxyBear(Drinker *drinker);
  virtual void drink();

 private:
  Wine *real_bear_;
  Drinker *drinker_;
};



#define kDrinkAge 16
ProxyBear::ProxyBear(Drinker *drinker) : drinker_(drinker)
{
    real_bear_ = new Bear();
}


void ProxyBear::drink()
{
    if (drinker_->age() < kDrinkAge)
    {
        std::cout << "Sorry the drinker is too young to drink" << std::endl;
    }
    else
    {
        real_bear_->drink();
    }
}



int main(int argc, char *argv[])
{
    Wine *wine = new ProxyBear(new Drinker(15));
    wine->drink();
    
    wine = new ProxyBear(new Drinker(25));
    wine->drink();

}
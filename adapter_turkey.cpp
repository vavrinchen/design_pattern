#include <iostream>

class Duck {

  public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

// 綠頭鴨是鴨子的次類別
class MallardDuck : public Duck {

    void quack()
    {
        std::cout << "MallardDuck Quack" << std::endl;
    }

    void fly()
    {
        std::cout << "MallardDuck Fly" << std::endl;
    }
};

// 火雞介面
class Turkey {

    // 火雞只會喀喀叫
  public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};


class WildTurkey : public Turkey {

public:
    void gobble()
    {
        std::cout << "WildTurkey Gobble" << std::endl;
    }

    void fly()
    {
        std::cout << "WildTurkey Fly" << std::endl;
    }
};

class TurkeyAdapterInterface : public Duck, public WildTurkey
{
  public:
    void quack();
    void fly();
};



// 轉接器要實作要轉換的型態,
// 也就是你的客戶所希望看到的介面
class TurkeyAdapter : public Duck
{

  private:
    Turkey* mTurkey;

    // 需要取得被轉換者的物件參考
    // 範例是利用建構者取得
  public:
    TurkeyAdapter(Turkey* turkey)
    {
        mTurkey = turkey;
    }

    // 實作介面的方法，並把方法都導向
    // 使用被轉接者提供的方法
    void quack()
    {
        mTurkey->gobble();
    }

    void fly()
    {
        mTurkey->fly();
    }
};

int main()
{
    std::cout << "------------------------------------------" << std::endl;
    Turkey *tukey = new WildTurkey();
    TurkeyAdapter turkeyAdapter(tukey);
    turkeyAdapter.quack();
    turkeyAdapter.fly();
    std::cout << "------------------------------------------" << std::endl;
    return 0;
}

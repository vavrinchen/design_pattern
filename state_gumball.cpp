#include <iostream>
#include <memory>
#include <ctime>
#include <sstream>
using namespace std;

class State 
{
  public:
    virtual ~State() = 0;
    virtual void insertQuarter() const = 0;
    virtual void ejectQuarter() const = 0;
    virtual void turnCrank() const = 0;
    virtual void dispense() = 0;
    virtual string toString() const = 0;
};
State::~State() {}


class GumballMachine
{
  public:
    explicit GumballMachine(int numberGumballs);
    ~GumballMachine()
    {
        delete _soldOutState;
        delete _noQuarterState;
        delete _hasQuarterState;
        delete _soldState;
        delete _winnerState;
    }
    void insertQuarter() const
    {
        _state->insertQuarter();
    }
    void ejectQuarter() const
    {
        _state->ejectQuarter();
    }
    void turnCrank() const
    {
        _state->turnCrank();
        _state->dispense();
    }
    void setState(State *state)
    {
        _state = state;
    }
    void releaseBall()
    {
        cout << "A gumball comes rolling out the slot..." << endl;
        if (_count != 0)
        {
            _count--;
        }
    }
    int getCount() const
    {
        return _count;
    }
    void refill(int count)
    {
        _count = count;
        _state = _noQuarterState;
    }
    State *getState() const
    {
        return _state;
    }
    State *getSoldOutState() const
    {
        return _soldOutState;
    }
    State *getNoQuarterState() const
    {
        return _noQuarterState;
    }
    State *getHasQuarterState() const
    {
        return _hasQuarterState;
    }
    State *getSoldState() const
    {
        return _soldState;
    }
    State *getWinnerState() const
    {
        return _winnerState;
    }
    string toString() const
    {
        stringstream value;
        value << endl
              << "Inventory: " << _count << " gumball";
        if (_count > 1)
        {
            value << "s";
        }
        value << endl;
        value << "Machine is " << _state->toString() << endl;
        return value.str();
    }

  private:
    GumballMachine(const GumballMachine &); // Disable copy constructor
    void operator=(const GumballMachine &); // Disable assignment operator
  private:
    State *_soldOutState;
    State *_noQuarterState;
    State *_hasQuarterState;
    State *_soldState;
    State *_winnerState;
    State *_state;
    int _count;
};

class SoldOutState : public State
{
  public:
    explicit SoldOutState(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine)
    {
    }
    void insertQuarter() const
    {
        cout << "You can't insert a quarter, the machine is sold out" << endl;
    }
    void ejectQuarter() const
    {
        cout << "You can't eject, you haven't inserted a quarter yet" << endl;
    }
    void turnCrank() const
    {
        cout << "You turned, but there are no gumballs" << endl;
    }
    void dispense()
    {
        cout << "No gumball dispensed" << endl;
    }
    string toString() const
    {
        return "sold out";
    }

  private:
    SoldOutState(const SoldOutState &);   // Disable copy constructor
    void operator=(const SoldOutState &); // Disable assignment operator
  private:
    GumballMachine *_gumballMachine;
};

class NoQuarterState : public State
{
  public:
    explicit NoQuarterState(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine)
    {
    }
    void insertQuarter() const
    {
        cout << "You inserted a quarter" << endl;
        _gumballMachine->setState(_gumballMachine->getHasQuarterState());
    }
    void ejectQuarter() const
    {
        cout << "You haven't inserted a quarter" << endl;
    }
    void turnCrank() const
    {
        cout << "You turned, but there's no quarter" << endl;
    }
    void dispense()
    {
        cout << "You need to pay first" << endl;
    }
    string toString() const
    {
        return "waiting for quarter";
    }

  private:
    GumballMachine *_gumballMachine;

  private:
    NoQuarterState(const NoQuarterState &); // Disable copy constructor
    void operator=(const NoQuarterState &); // Disable assignment operator
};

class HasQuarterState : public State
{
  public:
    explicit HasQuarterState(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine), _random(0)
    {
    }
    void insertQuarter() const
    {
        cout << "You can't insert another quarter" << endl;
    }
    void ejectQuarter() const
    {
        cout << "Quarter returned" << endl;
        _gumballMachine->setState(_gumballMachine->getNoQuarterState());
    }
    void turnCrank() const
    {
        cout << "You turned..." << endl;
        int winner = 2; 
        if ((winner == 0) && (_gumballMachine->getCount() > 0))
        {
            _gumballMachine->setState(_gumballMachine->getWinnerState());
        }
        else
        {
            _gumballMachine->setState(_gumballMachine->getSoldState());
        }
    }
    void dispense()
    {
        cout << "No gumball dispensed" << endl;
    }
    string toString() const
    {
        return "waiting for turn of crank";
    }

  private:
    HasQuarterState(const HasQuarterState &); // Disable copy constructor
    void operator=(const HasQuarterState &);  // Disable assignment operator
  private:
    GumballMachine *_gumballMachine;
    int _random;
};

class WinnerState : public State
{
  private:
    GumballMachine *_gumballMachine;

  private:
    WinnerState(const WinnerState &);    // Disable copy constructor
    void operator=(const WinnerState &); // Disable assignment operator

  public:
    explicit WinnerState(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine)
    {
    }
    void insertQuarter() const
    {
        cout << "Please wait, we're already giving you a Gumball" << endl;
    }
    void ejectQuarter() const
    {
        cout << "Please wait, we're already giving you a Gumball" << endl;
    }
    void turnCrank() const
    {
        cout << "Turning again doesn't get you another gumball!" << endl;
    }
    void dispense()
    {
        cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << endl;
        _gumballMachine->releaseBall();
        if (_gumballMachine->getCount() == 0)
        {
            _gumballMachine->setState(_gumballMachine->getSoldOutState());
        }
        else
        {
            _gumballMachine->releaseBall();
            if (_gumballMachine->getCount() > 0)
            {
                _gumballMachine->setState(_gumballMachine->getNoQuarterState());
            }
            else
            {
                cout << "Oops, out of gumballs!" << endl;
                _gumballMachine->setState(_gumballMachine->getSoldOutState());
            }
        }
    }
    string toString() const
    {
        return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
    }
};

class SoldState : public State
{
  public:
    explicit SoldState(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine)
    {
    }
    void insertQuarter() const
    {
        cout << "Please wait, we're already giving you a gumball" << endl;
    }
    void ejectQuarter() const
    {
        cout << "Sorry, you already turned the crank" << endl;
    }
    void turnCrank() const
    {
        cout << "Turning twice doesn't get you another gumball!" << endl;
    }
    void dispense()
    {
        _gumballMachine->releaseBall();
        if (_gumballMachine->getCount() > 0)
        {
            _gumballMachine->setState(_gumballMachine->getNoQuarterState());
        }
        else
        {
            cout << "Oops, out of gumballs!" << endl;
            _gumballMachine->setState(_gumballMachine->getSoldOutState());
        }
    }
    string toString() const
    {
        return "dispensing a gumball";
    }

  private:
    SoldState(const SoldState &);      // Disable copy constructor
    void operator=(const SoldState &); // Disable assignment operator
  private:
    GumballMachine *_gumballMachine;
};

GumballMachine::GumballMachine(int numberGumballs) : _count(numberGumballs)
{
    _soldOutState = new SoldOutState(this);
    _noQuarterState = new NoQuarterState(this);
    _hasQuarterState = new HasQuarterState(this);
    _soldState = new SoldState(this);
    _winnerState = new WinnerState(this);
    _state = _soldOutState;
    if (_count > 0)
    {
        _state = _noQuarterState;
    }
}

int main()
{
    auto_ptr<GumballMachine> gumballMachine(new GumballMachine(10));
    cout << gumballMachine->toString() << endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    cout << gumballMachine->toString() << endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    cout << gumballMachine->toString() << endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    cout << gumballMachine->toString() << endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    cout << gumballMachine->toString() << endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    cout << gumballMachine->toString() << endl;
    return 0;
}
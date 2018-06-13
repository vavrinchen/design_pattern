#include <vector>
#include <algorithm>
#include <iostream>
#include "Subject.h"
#include "Observer.h"




class WeatherData : public Subject
{
	std::vector<Observer *> observers;

	float temp = 0.0;
	float humidity = 0.0;
	float pressure = 0.0;

  public:
	void registerObserver(Observer *observer) override;
	void removeObserver(Observer *observer) override;
	void notifyObservers() override;
	void setState(float temp, float humidity, float pressure);
	void getState() override;
};

class Display : public Observer
{

	int id;

  public:
	Display(int id);
	virtual void update(Subject *s) override;
};

void WeatherData::registerObserver(Observer *observer)
{
	observers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer)
{
	// find the observer
	auto iterator = std::find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end())
	{
		observers.erase(iterator);
	}
}

void WeatherData::notifyObservers()
{
	for (Observer *observer : observers)
	{ // notify all observers
		observer->update(this);
	}
}

void WeatherData::setState(float temp, float humidity, float pressure)
{
	this->temp = temp;
	this->humidity = humidity;
	this->pressure = pressure;
	std::cout << std::endl;
	notifyObservers();
}

void WeatherData::getState()
{
	std::cout << "---Get Data---\tTemperature: " << this->temp
			  << "\tHumidity: " << this->humidity
			  << "\tPressure: " << this->pressure
			  << std::endl;
}

class HealthData : public Subject
{
	std::vector<Observer *> observers;

	float height = 0.0;
	float weight = 0.0;

  public:
	void registerObserver(Observer *observer) override;
	void removeObserver(Observer *observer) override;
	void notifyObservers() override;
	void setState(float height, float weight);
	void getState() override;
};

void HealthData::registerObserver(Observer *observer)
{
	observers.push_back(observer);
}

void HealthData::removeObserver(Observer *observer)
{
	// find the observer
	auto iterator = std::find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end())
	{
		observers.erase(iterator);
	}
}

void HealthData::notifyObservers()
{
	for (Observer *observer : observers)
	{ // notify all observers
		observer->update(this);
	}
}

void HealthData::setState(float height, float weight)
{
	this->height = height;
	this->weight = weight;
	std::cout << std::endl;
	notifyObservers();
}

void HealthData::getState()
{
	std::cout << "---Get Data---\tHeight: " << this->height
			  << "\tWeight: " << this->weight
			  << std::endl;
}

void Display::update(Subject *s)
{
	s->getState();
	/*
	std::cout << "---Display (" << id << ") Data---\tTemperature: " << temp
			  << "\tHumidity: " << humidity
			  << "\tPressure: " << pressure
			  << std::endl;
			  */

}

Display::Display(int id)
{
	this->id = id;
}

int main()
{
	WeatherData weatherStation;
	HealthData healthStation;
	Display one(1), two(2), three(3);

	float temp, humidity, pressure, height, weight;

	weatherStation.registerObserver(&one);
	healthStation.registerObserver(&one);
	weatherStation.registerObserver(&two);
	healthStation.registerObserver(&two);
	weatherStation.registerObserver(&three);

	std::cout << "Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> temp >> humidity >> pressure;

	weatherStation.setState(temp, humidity, pressure);

	std::cout << "Enter Height, Weight (seperated by spaces) << ";
	std::cin >> height >> weight;

	healthStation.setState(height, weight);

	weatherStation.removeObserver(&two);
	healthStation.removeObserver(&two);

	std::cout << "\n\nEnter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> temp >> humidity >> pressure;

	std::cout << "\n\nEnter Height, Weight (seperated by spaces) << ";
	std::cin >> height >> weight;

	weatherStation.setState(temp, humidity, pressure);
	healthStation.setState(height, weight);

	return 0;
}

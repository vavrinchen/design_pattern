#include <vector>
#include <algorithm>
#include <iostream>

class Observer {

public:
	virtual void update(float temp, float humidity, float pressure) = 0;

};

class Subject {

public:
	virtual void registerObserver(Observer *observer) = 0;
	virtual void removeObserver(Observer *observer) = 0;
	virtual void notifyObservers() = 0;

};


class WeatherData : public Subject {
	std::vector<Observer *> observers; 

	float temp = 0.0;
	float humidity = 0.0;
	float pressure = 0.0;

public:
	void registerObserver(Observer *observer) override;
	void removeObserver(Observer *observer) override;
	void notifyObservers() override;
	void setState(float temp, float humidity, float pressure);

};

class Display : public Observer {

	int id;

public:
	Display(int id);
	virtual void update(float temp, float humidity, float pressure) override;

};

void WeatherData::registerObserver(Observer *observer) {
	observers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer) {
	// find the observer
	auto iterator = std::find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end()) { 
		observers.erase(iterator); 
	}
}

void WeatherData::notifyObservers() {
	for (Observer *observer : observers) { // notify all observers
		observer->update(temp, humidity, pressure);
	}
}

void WeatherData::setState(float temp, float humidity, float pressure) {
	this->temp = temp;
	this->humidity = humidity;
	this->pressure = pressure;
	std::cout << std::endl;
	notifyObservers();
}

void Display::update(float temp, float humidity, float pressure) {

	std::cout << "---Display (" << id << ") Data---\tTemperature: " << temp
		<< "\tHumidity: " << humidity
		<< "\tPressure: " << pressure
		<< std::endl;
}

Display::Display(int id) {
	this->id = id;
}


int main() {
	WeatherData weatherStation;
	Display one(1), two(2), three(3);

	float temp, humidity, pressure;

	weatherStation.registerObserver(&one);
	weatherStation.registerObserver(&two);
	weatherStation.registerObserver(&three);

	std::cout << "Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> temp >> humidity >> pressure;

	weatherStation.setState(temp, humidity, pressure);

	weatherStation.removeObserver(&two);

	std::cout << "\n\nEnter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> temp >> humidity >> pressure;

	weatherStation.setState(temp, humidity, pressure);

	return 0;
}
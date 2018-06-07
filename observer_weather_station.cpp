#include <vector>
#include <algorithm>
#include <iostream>

class Observer {

public:
	virtual void update(float temp, float humidity, float pressure) = 0;

};

class Subject {

public:
	
	class Item
	{
	public:
		virtual void showItem() = 0;
	};
	
	virtual void registerObserver(Observer *observer) = 0;
	virtual void removeObserver(Observer *observer) = 0;
	//virtual void notifyObservers(Item *item) = 0;

};

class WeatherData : public Subject {
	std::vector<Observer *> observers; 

public:
	
	class SubjectItem : public Subject::Item
	{
	public:
		float temp = 0.0;
		float humidity = 0.0;
		float pressure = 0.0;
		void showItem() override;
	};
	
	void registerObserver(Observer *observer) override;
	void removeObserver(Observer *observer) override;
	void notifyObservers(SubjectItem *subjectitem);
	void setState(SubjectItem *subjectitem);

};

class Display : public Observer {

	int id;

public:
	Display(int id);
	virtual void update(float temp, float humidity, float pressure) override;

};


void WeatherData::SubjectItem::showItem(){
	std::cout << "WeatherData Subject Item" << std::endl;
}


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

void WeatherData::notifyObservers(WeatherData::SubjectItem *ws) {
	for (Observer *observer : observers) { // notify all observers
		observer->update(ws->temp, ws->humidity, ws->pressure);
	}
}

void WeatherData::setState(WeatherData::SubjectItem *ws) {
	WeatherData::SubjectItem ws_o;
	ws_o.temp = ws->temp;
	ws_o.humidity = ws->humidity;
	ws_o.pressure = ws->pressure;
	std::cout << std::endl;
	notifyObservers(&ws_o);
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
	WeatherData::SubjectItem ws;
	Display one(1), two(2), three(3);

	ws.showItem();
	weatherStation.registerObserver(&one);
	weatherStation.registerObserver(&two);
	weatherStation.registerObserver(&three);

	std::cout << "Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> ws.temp >> ws.humidity >> ws.pressure;
	weatherStation.setState(&ws);

	weatherStation.removeObserver(&two);

	std::cout << "\n\nEnter Temperature, Humidity, Pressure (seperated by spaces) << ";
	std::cin >> ws.temp >> ws.humidity >> ws.pressure;

	weatherStation.setState(&ws);

	return 0;
}
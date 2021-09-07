#include<iostream>
#include"Builder.h"
#include"FactoryMethodh.h"
#include"Singleton.h"
#include"AbstractFactory.h"
#include"DVD.h"
#include"Prototype.h"
#include"Adapter.h"
using namespace std;
 




int main() {
	setlocale(0, "");

	Adapter::Driver * driver = new Adapter::Driver();
	Adapter::Car * car = new Adapter::Car();
	driver->travel(car);

	Adapter::Camel * camel = new Adapter::Camel();
	Adapter::CamelToTransport * adapter = new Adapter::CamelToTransport(camel);
	driver->travel(adapter);

	/*Creator * creator = new TruckCreator;
	Transport * truck = creator->create();
	truck->delivery("IT STEP");


	creator = new ShipCreator;
	Transport* ship = creator->create();
	ship->delivery("Port Nikolaev");


	creator = new PlaneCreator;

	Transport * plane = creator->create();
	plane->delivery("North Polus");
	system("pause");*/


	/*Creator * creator;
	Transport * transport;
	int n;
	cout << "1 - Truck, 2 - Ship, 3 - Plain";
	cin >> n;
	switch (n)
	{
	case 2:
		creator = new ShipCreator;
		break;
	case 3:
		creator = new PlaneCreator;
		break;
	default:
		creator = new TruckCreator;
		break;
	}
	transport = creator->create();
	transport->delivery("�� ������� �������");*/

	/*Logger * logger = Logger::getInstance();
	logger->sendMessage("Error #44");
	logger->sendMessage("Error #86");


	Logger * log2 = Logger::getInstance();
	log2->sendMessage("Error #1104");*/

	/*Car * car = new Car;
	CarConfigurator * configurator = new CarConfigurator;
	configurator->setFactory(new SportCarFactory);
	configurator->create(car);
	car->print();
	cout << endl;
	Car* bmw = new Car;
	configurator->setFactory(new BMWFactory);
	configurator->create(bmw);
	bmw->print();*/

	/*Disk * disk = new Disk(4);
	string data = "Konstantin";
	DVD_Drive* drive = new DVD_Drive;
	drive->open(disk);
	drive->write(data);
	drive->read();
	*/




	



	system("pause");
}
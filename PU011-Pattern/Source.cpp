#include<iostream>
#include"Builder.h"
#include"FactoryMethodh.h"
#include"Singleton.h"
#include"AbstractFactory.h"
#include"DVD.h"
#include"Prototype.h"
#include"Adapter.h"
#include"Bridge.h"
#include"Decorator.h"
#include"Composit.h"
#include"Flyweight.h"

using namespace std;
 




int main() {
	setlocale(0, "");



	HouseFactory * factory = new HouseFactory();
	vector<House*> houses;
	for (size_t i = 0; i < 5; i++) {
		houses.push_back(new House(rand() % 100, rand() % 100,factory->getHouse("Panel")));
	}

	cout << endl;

	for (size_t i = 0; i < 5; i++) {
		houses.push_back(new House(rand() % 100, rand() % 100, factory->getHouse("Brick")));
	}

	for (auto&h : houses)
		h->print();













	/*Componentt* fs = new Directory("FileSystem");

	Componentt* discC = new Directory("Disc C");

	Componentt* folder1 = new Directory("Folder 1");
	Componentt* folder2 = new Directory("Folder 2");
	Componentt* folder3 = new Directory("Folder 3");
	Componentt* folder4 = new Directory("Folder 4");
	Componentt* folder5 = new Directory("Folder 5");

	Componentt* file1 = new File("File 1");
	Componentt* file2 = new File("File 2");
	Componentt* file3 = new File("File 3");
	Componentt* file4 = new File("File 4");

	fs->addComponent(discC);
	discC->addComponent(folder1);
	discC->addComponent(folder2);
	discC->addComponent(file1);
	discC->addComponent(file2);
	folder1->addComponent(folder3);
	folder1->addComponent(folder4);
	folder4->addComponent(folder5);
	folder3->addComponent(file4);
	fs->print();*/






	//Pizza * pizza = new ItalianPizza();
	//pizza = new TomatoPizza(pizza); // помидоры
	//pizza = new CheesePizza(pizza); // сыр


	//cout << pizza->getName() << endl;
	//cout << "Price: " << pizza->getPrice() << endl;






	/*Programmer * freelancer = new FreeLancerProgrammer(new CPPLanguage());
	freelancer->work();
	freelancer->getMoney();
	cout << endl;

	freelancer->setLanguage(new CSharpLanguage());
	freelancer->work();
	freelancer->getMoney();
	cout << endl;

	Programmer* cmpProg = new CompanyProgrammer(new CSharpLanguage());
	cmpProg->work();
	cmpProg->getMoney();
	cout << endl;
	
	cmpProg->setLanguage(new CPPLanguage());
	cmpProg->work();
	cmpProg->getMoney();
	cout << endl;*/





	/*Adapter::Driver * driver = new Adapter::Driver();
	Adapter::Car * car = new Adapter::Car();
	driver->travel(car);

	Adapter::Camel * camel = new Adapter::Camel();
	Adapter::CamelToTransport * adapter = new Adapter::CamelToTransport(camel);
	driver->travel(adapter);*/

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
	transport->delivery("на деревню дедушке");*/

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
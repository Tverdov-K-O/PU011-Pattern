#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
namespace Adapter {

	class ITransport
	{
	public:
		virtual void drive() const  = 0;
	};

	class Car final: public ITransport 
	{
	public:
		void drive() const override
		{
			cout << "Машина едет по дороге" << endl;
		}
	};

	class Driver
	{
	public:
		void travel(ITransport* transport)
		{
			transport->drive();
		}
	};



	class Animal {
	public:
		virtual void move() const = 0;
	};

	class Camel final: public Animal
	{
	public:
		void move() const override
		{
			cout << "Верблюд идет по пескам пустыни" << endl;
		}
	};


	class CamelToTransport : public ITransport
	{
		Camel * camel;
	public:
		CamelToTransport(Camel* c) : camel(c) {}
		void drive() const 
		{
			camel->move();
		}
	};
}
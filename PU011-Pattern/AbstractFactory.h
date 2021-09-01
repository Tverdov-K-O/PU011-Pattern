#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Component
{
public:
	virtual string toString() const = 0;
};

class Engine : public Component
{

};
class Transmissin : public Component
{

};
class BodyType : public Component
{

};

class DiselEngine : public Engine
{
	string toString() const override
	{
		return "Disel Engine";
	}
};
class GasEngine : public Engine
{
	string toString() const override
	{
		return "Gas Engine";
	}
};
class ElectroEngine : public Engine
{
	string toString() const override
	{
		return "Electro Engine";
	}
};

class MechTrans : public Transmissin
{
	string toString() const override
	{
		return "Mech Trans";
	}
};

class AutomaticTrans : public Transmissin
{
	string toString() const override
	{
		return "Automatic Trans";
	}
};
class VariatorTrans : public Transmissin
{
	string toString() const override
	{
		return "Variator Trans";
	}
};

class SedanBodyType : public BodyType
{
	string toString() const override
	{
		return "Sedan BodyType";
	}
};

class SportBodyType : public BodyType
{
	string toString() const override
	{
		return "Sport BodyType";
	}
};

class UniversalBodyType : public BodyType
{
	string toString() const override
	{
		return "Universal BodyType";
	}
};

class Car
{
	Engine * engine;
	Transmissin * transmission;
	BodyType * bodytype;
	string name;

public:
	Car() {}
	virtual ~Car()
	{
		if (engine) delete engine;
		if (transmission) delete transmission;
		if (bodytype) delete bodytype;
	}
	void setEngine(Engine* e) { engine = e; }
	void setTransmission(Transmissin* t) { transmission = t; }
	void setEngine(BodyType* bt) { bodytype = bt; }
	void print()
	{
		cout << "Name : " << name << endl;
		cout << "Engine : " << engine->toString() << endl;
		cout << "Transmission : " << transmission->toString() << endl;
		cout << "BodyType : " << bodytype->toString() << endl;
	}
};
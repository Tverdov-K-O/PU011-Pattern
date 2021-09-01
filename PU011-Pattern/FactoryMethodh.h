#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;





class Transport
{
public:
	virtual ~Transport(){}
	virtual void delivery(string adress) const = 0;
	virtual string name() const = 0;
};

class Truck : public Transport
{
public:
	void delivery(string adress) const
	{
		cout << "  доставлен наземным способом по адресу: " << adress << endl;
	}
	string name() const 
	{
		return "«адействован грузовик : ";
	}
};

class Creator
{
public:
	virtual ~Creator(){}
	virtual Transport* createTransport() const = 0;// фабричный метод
	Transport * create()
	{
		Transport * transport = this->createTransport();
		cout << transport->name();
		return transport;
	}
};


class TruckCreator : public Creator
{
public:
	Transport* createTransport() const override
	{
		return new Truck();
	}
};




class Ship : public Transport
{
public:
	void delivery(string adress) const
	{
		cout << "  доставлен морем по адресу: " << adress << endl;
	}
	string name() const
	{
		return "«адействован параход : ";
	}
};

class ShipCreator : public Creator
{
public:
	Transport* createTransport() const override
	{
		return new Ship();
	}
};


class Plane : public Transport
{
public:
	void delivery(string adress) const
	{
		cout << "  доставлен по воздуху по адресу: " << adress << endl;
	}
	string name() const
	{
		return "«адействован самолет : ";
	}
};

class PlaneCreator : public Creator
{
public:
	Transport* createTransport() const override
	{
		return new Plane();
	}
};
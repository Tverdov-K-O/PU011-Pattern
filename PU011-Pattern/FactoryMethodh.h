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
		cout << "  ��������� �������� �������� �� ������: " << adress << endl;
	}
	string name() const 
	{
		return "������������ �������� : ";
	}
};

class Creator
{
public:
	virtual ~Creator(){}
	virtual Transport* createTransport() const = 0;// ��������� �����
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
		cout << "  ��������� ����� �� ������: " << adress << endl;
	}
	string name() const
	{
		return "������������ ������� : ";
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
		cout << "  ��������� �� ������� �� ������: " << adress << endl;
	}
	string name() const
	{
		return "������������ ������� : ";
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
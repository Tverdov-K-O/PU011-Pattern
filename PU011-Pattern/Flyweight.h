#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<map>

using namespace std;


class HouseFlyweight
{
protected:
	string name;
	int floor;
	
public:
	virtual void build(int x, int y) = 0;
	virtual string getName() { return name; };
};

class PanelHouse : public HouseFlyweight
{
public:
	PanelHouse() { floor = 9; name = "Panel"; }
	void build(int x, int y)
	{
		cout << "построен панельный дом из " << floor << "-этажей\nкоординаты: широта - " << x << ", долгота - " << y << endl << endl;;
	}
};

class BrickHouse : public HouseFlyweight
{
public:
	BrickHouse() { floor = 15; name = "Brick";}
	void build(int x, int y)
	{
		cout << "построен кирпичный дом из " << floor << "-этажей\nкоординаты: широта - " << x << ", долгота - " << y << endl << endl;;
	}
};

class HouseFactory
{
	map<string, HouseFlyweight*> pool;
public:
	HouseFactory()
	{
		pool["Panel"] = new PanelHouse();
		pool["Brick"] = new BrickHouse();
	}

	HouseFlyweight*getHouse(string key)
	{
		if (pool.count(key)) 
		{
			return pool[key];
		}
		return nullptr;
	}
};

class House
{
	int x, y;
	HouseFlyweight * house;
public:
	House(int x, int y, HouseFlyweight* h) : x(x), y(y), house(h) 
	{
		if(house)
			house->build(x, y);
		else cout << "Дом не построен! " << endl;
	}
	void print()
	{
		
		if (house) {
			cout << "House - ";
			cout << house->getName();
			cout << " X = " << x << " Y = " << y << endl;
		}
		
	}
};
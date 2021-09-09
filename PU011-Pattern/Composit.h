#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<list>

using namespace std;

class Componentt
{
protected:
	string name;
	static int t;
public:
	Componentt(string n) : name(n) {}
	virtual void addComponent(Componentt* c) {}
	virtual void print()
	{
		for (size_t i = 0; i < t; i++)
		{
			cout << "\t";
		}
		cout << name << endl;
	}

};
int Componentt::t = 0;

class Directory : public Componentt
{
	list<Componentt*> components;
public:
	Directory(string n) : Componentt(n){}
	void addComponent(Componentt* c) override
	{
		components.push_back(c);
	}
	void print()
	{
		t++;
		for (size_t i = 0; i < t; i++)
		{
			cout << "\t";
		}
		cout << "Dir: " << name << endl;
		for(auto&c : components)
		{
			c->print();
		}
	}
};

class File : public Componentt
{
	public:
		File(string n) : Componentt(n) {}
};
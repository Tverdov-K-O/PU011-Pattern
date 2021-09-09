#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;


class Pizza
{
	string name;

public:
	Pizza(string n) : name(n) {}
	string getName() { return name; }
	virtual int getPrice() = 0;
};

class ItalianPizza : public Pizza
{
public:
	ItalianPizza() :Pizza("Итальянская пицца") {}
	int getPrice() override { return 100; }
};

class PizzaDecorator : public Pizza
{
protected:
	Pizza * pizza;
public:
	PizzaDecorator(string n, Pizza*p):Pizza(n), pizza(p){}
	virtual ~PizzaDecorator() { delete pizza; }
};

class TomatoPizza : public PizzaDecorator
{
public:
	TomatoPizza(Pizza * p) : PizzaDecorator(p->getName()+" c помидорами",p ){}
	int getPrice() override { return pizza->getPrice() + 22; }

};

class CheesePizza : public PizzaDecorator
{
public:
	CheesePizza(Pizza * p) : PizzaDecorator(p->getName() + " c сыром", p) {}
	int getPrice() override { return pizza->getPrice() + 13; }

};
#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class IFigure
{
public:
	virtual IFigure* clone()	= 0 ;
	virtual void print() const	= 0;
};

class Rectangle : public IFigure
{
	int width, height;
public:
	Rectangle(int w, int h) : width(w),height(h){}
	void print() const override
	{
		cout << "W = " << width << ", H = " << height << endl;
	}
	IFigure* clone() override
	{
		return new Rectangle(*this);
	}
};

class Circle : public IFigure
{
	int radius;
public:
	Circle(int r): radius(r){}
	void print() const override
	{
		cout << "Radius = " << radius << endl;
	}

	IFigure* clone() override
	{
		return new Circle(radius);
	}
};

void method(IFigure * figure)
{
	IFigure * figure_copy = figure->clone();
	figure->print();
	figure_copy->print();
}


/*IFigure * f = new Rectangle(12, 5);
	method(f);*/
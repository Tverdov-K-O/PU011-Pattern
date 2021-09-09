#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class ILanguage
{
public:
	virtual void build() = 0;
	virtual void execute() = 0;
};


class CPPLanguage : public ILanguage
{
public:
	void build() override
	{
		cout << "С помощью компилятора C++ компилируем программу в бинарный код" << endl;
	}
	void execute() override
	{
		cout << "Запускаем испольняемый ***.exe файл" << endl;
	}
};


class CSharpLanguage : public ILanguage
{
public:
	void build() override
	{
		cout << "С помощью компилятора C# компилируем программу в CIL код" << endl;
	}
	void execute() override
	{
		cout << "Запускаем JIT и компилируем в бинарный  файл" << endl;
		cout << ".NET выполняет бинарный код" << endl;
	}
};


class Programmer
{
	ILanguage * language;

public:
	Programmer(ILanguage * l): language(l){}
	void setLanguage(ILanguage * l) { language = l; }
	void work()
	{
		language->build();
		language->execute();
	}
	virtual void getMoney() = 0;

};

class FreeLancerProgrammer : public Programmer
{
public:
	FreeLancerProgrammer(ILanguage* l): Programmer(l){}
	void getMoney() override
	{
		cout << "получаем оплату за выполненую работу" << endl;
	}
};


class CompanyProgrammer : public Programmer
{
public:
	CompanyProgrammer(ILanguage* l) : Programmer(l){}
	void getMoney() override
	{
		cout << "получает оплату в конце месяца" << endl;
	}
};
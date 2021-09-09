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
		cout << "� ������� ����������� C++ ����������� ��������� � �������� ���" << endl;
	}
	void execute() override
	{
		cout << "��������� ������������ ***.exe ����" << endl;
	}
};


class CSharpLanguage : public ILanguage
{
public:
	void build() override
	{
		cout << "� ������� ����������� C# ����������� ��������� � CIL ���" << endl;
	}
	void execute() override
	{
		cout << "��������� JIT � ����������� � ��������  ����" << endl;
		cout << ".NET ��������� �������� ���" << endl;
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
		cout << "�������� ������ �� ���������� ������" << endl;
	}
};


class CompanyProgrammer : public Programmer
{
public:
	CompanyProgrammer(ILanguage* l) : Programmer(l){}
	void getMoney() override
	{
		cout << "�������� ������ � ����� ������" << endl;
	}
};
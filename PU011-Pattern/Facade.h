#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<list>

using namespace std;

class TextEditor
{
public:
	void createCode() { cout << "��������� ����" << endl; }
	void save() { cout << "���������� ����" << endl; }
};

class Compiller
{
public:
	void compille() { cout << "���������� ����" << endl; }
};
class Debuger
{
public:
	void execute() { cout << "���������� ���� " << endl; }
	void finish() { cout << "���������� ������ ����������" << endl; }
};
class VisualStudio
{
	TextEditor * te;
	Compiller * c;
	Debuger * d;
public:
	VisualStudio(TextEditor * t , Compiller * c, Debuger * d) : te(t), d(d),c(c){}
	void F5()
};
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
	void createCode() { cout << "Написание кода" << endl; }
	void save() { cout << "сохранение кода" << endl; }
};

class Compiller
{
public:
	void compille() { cout << "компилация кода" << endl; }
};
class Debuger
{
public:
	void execute() { cout << "Выполнение кода " << endl; }
	void finish() { cout << "завершение работы приложения" << endl; }
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
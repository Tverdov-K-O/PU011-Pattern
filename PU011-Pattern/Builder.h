#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class MCComponent
{
public:
	virtual string toString() = 0;
};



class Radio : public MCComponent
{
public:
	string toString() override { return "Radio"; }
};

class CD : public MCComponent
{
public:
	string toString() override  { return "CD"; }
};

class BlueRay : public MCComponent
{
public:
	string toString() override { return "BlueRay"; }
};

class Karaoke : public MCComponent
{
public:
	string toString() override { return "Karaoke"; }
};


class MusicCenter
{
	

public:
	//MusicCenter(CD cd, BlueRay bd);
	vector<MCComponent*> parts;
	void print() const
	{
		cout << "Music Center: " << endl;
		for (auto&p : parts)
			cout << p->toString() << endl;
		cout << endl;
		
	}

};


class Builder
{
public:
	virtual			  ~Builder() {}
	virtual void   createRadio()		const = 0;
	virtual void	  createCD()			const = 0;
	virtual void	  createBR()			const = 0;
	virtual void createKaraoke()	const = 0;
	
};

class MusicCenterBuilder : public Builder
{
	MusicCenter * product;
public:
	MusicCenterBuilder()
	{
		Reset();
	}
	~MusicCenterBuilder()
	{
		delete product;
	}
	void Reset()
	{
		product = new MusicCenter;
	}

	MusicCenter* getResult()
	{
		MusicCenter* result = product;
		Reset();
		return result;
	}

	void createRadio()			const override
	{
		product->parts.push_back(new Radio);
	}
	void createCD()				const override
	{
		product->parts.push_back(new CD);
	}
	void	createBR()			const override
	{
		product->parts.push_back(new BlueRay);
	}
	void createKaraoke()		const override
	{
		product->parts.push_back(new Karaoke);
	}
	
};


class Director
{
	Builder * builder;

public:

	void setBuilder(Builder* b)
	{
		builder = b;
	}
	void BuildMegaMC()
	{
		builder->createRadio();
		builder->createCD();
		builder->createBR();
		builder->createKaraoke();

	}
};

class ManualMC
{
	string text = "MANUAL for MUSIC CENTER\n";
public:
	void addText(string text)
	{
		this->text += text;
	}

	string getText() { return text; }
};

class ManualMCBuilder : public Builder
{

	ManualMC* product;

public:
	ManualMCBuilder()
	{
		Reset();
	}
	~ManualMCBuilder()
	{
		delete product;
	}
	void Reset()
	{
		product = new ManualMC;
	}

	ManualMC* getResult()
	{
		ManualMC* result = product;
		Reset();
		return result;
	}

	void createRadio()			const override
	{
		product->addText("для запуска радио нажмите 1\n");
	}
	void createCD()				const override
	{
		product->addText("для запуска CD нажмите 2\n");
	}
	void	createBR()			const override
	{
		product->addText("для запуска BR нажмите 3\n");
	}
	void createKaraoke()		const override
	{
		product->addText("для запуска Karaoke нажмите 3\n");
	}
};
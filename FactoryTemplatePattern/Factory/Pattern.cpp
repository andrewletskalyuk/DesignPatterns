#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit abstract
{
public:
	virtual void Play() = 0;
	virtual ~Unit() {
	}
};

class Archer : public Unit
{
public:
	void Play()
	{
		cout << "Archer playing\n";
	}
};

class Mag : public Unit
{
public:
	void Play()
	{
		cout << "Mag playing\n";
	}
};

class Swardman : public Unit
{
public:
	void Play()
	{
		cout << "Swardman playing\n";
	}
};


enum Players
{
	archer = 1, mag, swardman
};


class FactoryMethod abstract
{
public:
	static Unit* CreatePlayer(Players type)
	{
		switch (type)
		{
		case archer:
			return new Archer();
			break;
		case mag:
			return new Mag();
			break;		
		default:
		case swardman:
			return new Swardman();
			break;
		}
	}
};

class FactoryMethodArcher : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Archer\n";
		return new Archer();
	}
};

class FactoryMethodMag : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Mag\n";
		return new Mag();
	}
};

class FactoryMethodSwardman : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Swardman\n";
		return new Swardman();
	}
};







